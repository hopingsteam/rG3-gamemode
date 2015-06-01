#include <a_samp>
#include <zcmd>
#include <streamer>
/*==============================================================================================================
													Settings
===============================================================================================================*/
//LIMITS
#define	M_VEHICLES			500		//maximum ammount of private vehicles
#define M_DEALERS			100     //maximum ammount of vehicleDealers
#define M_DEALER_VEHICLES   15      //maximum vehicles per dealer
#define M_PLAYERS			20      //Maximum playersin your server (should be equal to your ammount of serverslots)

//main settings
#define RESPAWN_DELAY       -1    //Respawn time in miliseconds
#define DIALOG_RANGE        0       //dialog range
#define DIALOG_STRING_SIZE  256     //string size of generated dialog
#define PICKUP_MODEL        1318    //ModelID for pickup
#define MAP_ICON            55      //mapicon for dealer
#define PICKUP_ANTISPAM     10000   //Antispam timer for OnPlayerPickupPickup (time in miliseconds)
#define USE_CP              false   //will use checkpoints instead of pickups
#define CP_SIZE             1

//sell vehicle settings
#define SELL_DIVIDE         5       //Original price / SELL_DIVIDE = sellback money you get

//streamer settings
#define STREAMER_DISTANCE	100     //Streamdistance for the build-in streamer
#define STREAMER_INTERVAL   1000    //Streamer tickratio (due to the loops, this shouldnt be really lower as 600-700 i think, i recommend setting it to 1000 though)

//FILEPATHS
#define VEHICLE_PATH		"vDealer_vehicles/%i.ini"

//SQL Settings:
#define USE_MYSQL_DATABASE  true
#define SQL_SERVER			"176.31.69.116"
#define SQL_TABLE           "vehicles"
#define SQL_USER            "3562_cars"
#define SQL_PASS            "hahafail"
/*==============================================================================================================
											Variables/Color defines
===============================================================================================================*/
#if USE_MYSQL_DATABASE == false
	#include <yoursql>
	#include <sscanf2>
#else
    #include <YSI/y_ini>
#endif
#define vDEALER: new
#define DIALOG_SELL DIALOG_RANGE
#define DIALOG_DEALER_VEHICLES DIALOG_RANGE +1
#define DIALOG_DEALER_PRIMARY_COLOR DIALOG_RANGE +2
#define DIALOG_DEALER_SECONDARY_COLOR DIALOG_RANGE +3
#define COLOR_RED 0xFF1400FF
#define COLOR_YELLOW 0xFFFF00FF
#define COLOR_WHITE 0xFFFFFFFF
//dealer vehicleinfo per dealer
enum vehicle
{
	_name[32],
	_modelid,
	_price,
	bool:_active
}
new DealerVehicles[M_DEALERS][M_DEALER_VEHICLES][vehicle];

//Dealers
enum _dealer
{
	_dealername[64],
	Float:_x,
	Float:_y,
	Float:_z,
	bool:_active,
	_pickupid,
	_mapicon,
	Text3D:_3dtextlabel
}
new Dealers[M_DEALERS][_dealer];

//vehicles
enum PrivateVehicle
{
	_owner[MAX_PLAYER_NAME],
	_modelid,
	Float:_x,
	Float:_y,
	Float:_z,
	Float:_rot,
	_c1,
	_c2,
	_price,
	_vehicleid
}
new PrivateVehicles[M_VEHICLES][PrivateVehicle];
/*==============================================================================================================
											Public player related functions
===============================================================================================================*/
#if defined FILTERSCRIPT
	public OnFilterScriptInit()
	{
		vdealer_init();
		return CallLocalFunction("vdealer_OnFilterScriptInit","");
	}
	#if defined _ALS_OnFilterScriptInit
	    #undef OnFilterScriptInit
	#else
	    #define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit vdealer_OnFilterScriptInit
	forward vdealer_OnFilterScriptInit();

	public OnFilterScriptExit()
	{
		vdealer_exit();
		return CallLocalFunction("vdealer_OnFilterScriptExit","");
	}
	#if defined _ALS_OnFilterScriptExit
	    #undef OnFilterScriptExit
	#else
	    #define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit vdealer_OnFilterScriptExit
	forward vdealer_OnFilterScriptExit();
#else
	public OnGameModeInit()
	{
		vdealer_init();
		return CallLocalFunction("vdealer_OnGameModeInit","");
	}
	#if defined _ALS_OnGameModeInit
	    #undef OnGameModeInit
	#else
	    #define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit vdealer_OnGameModeInit
	forward vdealer_OnGameModeInit();

	public OnGameModeExit()
	{
		vdealer_exit();
		return CallLocalFunction("vdealer_OnGameModeExit","");
	}
	#if defined _ALS_OnGameModeExit
	    #undef OnGameModeExit
	#else
	    #define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit vdealer_OnGameModeExit
	forward vdealer_OnGameModeExit();
#endif



public OnPlayerStateChange(playerid,newstate,oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
	    new veh = GetPlayerVehicleID(playerid);
	    new pName[MAX_PLAYER_NAME];
	    GetPlayerName(playerid,pName,sizeof pName);
	    if(IsVehiclePrivate(veh))
	    {
			if(!strcmp(pName,PrivateVehicles[ConvertVID(veh)][_owner])) return 0;
	        RemovePlayerFromVehicle(playerid);
	        SendClientMessageEx(playerid,COLOR_YELLOW,"sss","This vehicle is owned by ",PrivateVehicles[ConvertVID(veh)][_owner]," therefore you can't drive it.");
	    }
	}
	return CallLocalFunction("vdealer_OnPlayerStateChange","iii",playerid,newstate,oldstate);
}
#if defined _ALS_OnPlayerStateChange
    #undef OnPlayerStateChange
#else
    #define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange vdealer_OnPlayerStateChange
forward vdealer_OnPlayerStateChange(playerid,newstate,oldstate);

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(!response)
	{
		DeletePVar(playerid,"dealerid");
        DeletePVar(playerid,"modelid");
        DeletePVar(playerid,"c1");
        DeletePVar(playerid,"c2");
        DeletePVar(playerid,"price");
        #if USE_CP == true
			DeletePVar(playerid,"DisablePickups");
		#else
		    SetTimerEx("EnablePickups",PICKUP_ANTISPAM,false,"i",playerid);
		#endif
        return CallLocalFunction("vdealer_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, inputtext);
	}
	switch(dialogid)
	{
	    case DIALOG_SELL:
	    {
	        GivePlayerMoney(playerid,(PrivateVehicles[ConvertVID(GetPlayerVehicleID(playerid))][_price] / SELL_DIVIDE));
			SendClientMessageEx(playerid,COLOR_YELLOW,"si","You've succesfully sold your vehicle for {FFFFFF}$",(PrivateVehicles[ConvertVID(GetPlayerVehicleID(playerid))][_price] / SELL_DIVIDE));
			RemoveVehicle(GetPlayerVehicleID(playerid));
	    }
	    case DIALOG_DEALER_VEHICLES:
	    {
	        new dealerid = GetPVarInt(playerid,"dealerid");
	        DeletePVar(playerid,"dealerid");
	        if(GetPlayerMoney(playerid) - DealerVehicles[dealerid][listitem][_price] < 0)
			{
				DeletePVar(playerid,"DisabledPickups");
				return SendClientMessage(playerid,COLOR_RED,"You've got not enough money for this vehicle!");
			}
			SetPVarInt(playerid,"price",DealerVehicles[dealerid][listitem][_price]);
			SetPVarInt(playerid,"modelid",DealerVehicles[dealerid][listitem][_modelid]);
			ShowPlayerDialog(playerid,DIALOG_DEALER_PRIMARY_COLOR,DIALOG_STYLE_LIST,"Select primary color","Red\nGreen\nBlue\nOrange\nBlack\nWhite\nPink","OK","");
	    }
	    case DIALOG_DEALER_PRIMARY_COLOR:
	    {
	        switch(listitem)
	        {
	            case 0:
	            {
					SetPVarInt(playerid,"c1",3);
	            }
	            case 1:
	            {
                    SetPVarInt(playerid,"c1",86);
	            }
	            case 2:
	            {
                    SetPVarInt(playerid,"c1",79);
	            }
	            case 3:
	            {
                    SetPVarInt(playerid,"c1",6);
	            }
	            case 4:
	            {
                    SetPVarInt(playerid,"c1",0);
	            }
	            case 5:
	            {
                    SetPVarInt(playerid,"c1",1);
	            }
	            case 6:
	            {
                    SetPVarInt(playerid,"c1",183);
	            }
	        }
            ShowPlayerDialog(playerid,DIALOG_DEALER_SECONDARY_COLOR,DIALOG_STYLE_LIST,"Select secondary color","Red\nGreen\nBlue\nOrange\nBlack\nWhite\nPink","OK","");
	    }
	    case DIALOG_DEALER_SECONDARY_COLOR:
	    {
	        switch(listitem)
	        {
	            case 0:
	            {
					SetPVarInt(playerid,"c2",3);
	            }
	            case 1:
	            {
                    SetPVarInt(playerid,"c2",86);
	            }
	            case 2:
	            {
                    SetPVarInt(playerid,"c2",79);
	            }
	            case 3:
	            {
                    SetPVarInt(playerid,"c2",6);
	            }
	            case 4:
	            {
                    SetPVarInt(playerid,"c2",0);
	            }
	            case 5:
	            {
                    SetPVarInt(playerid,"c2",1);
	            }
	            case 6:
	            {
                    SetPVarInt(playerid,"c2",183);
	            }
	        }
	        new id,pName[MAX_PLAYER_NAME],Float:x,Float:y,Float:z,Float:angle;
			GetPlayerPos(playerid,x,y,z);GetPlayerName(playerid,pName,sizeof pName);GetPlayerFacingAngle(playerid,angle);
	        GivePlayerMoney(playerid,-DealerVehicles[GetPVarInt(playerid,"dealerid")][listitem][_price]);

	        id = CreatePrivateVehicle(pName,GetPVarInt(playerid,"modelid"),x,y,z,angle,GetPVarInt(playerid,"c1"),GetPVarInt(playerid,"c2"),GetPVarInt(playerid,"price"));

			PutPlayerInVehicle(playerid,id,0);

			SendClientMessage(playerid,COLOR_YELLOW,"You've succesfully bought a vehicle! You can use {FFFFFF}/park {FFFF00}to park your vehicle and {FFFFFF}/sellvehicle {FFFF00}to sell it!");

            DeletePVar(playerid,"dealerid");
	        DeletePVar(playerid,"modelid");
	        DeletePVar(playerid,"c1");
	        DeletePVar(playerid,"c2");
	        DeletePVar(playerid,"price");
	        DeletePVar(playerid,"DisablePickups");
	    }
	}
	return CallLocalFunction("vdealer_OnDialogResponse","iiiis",playerid, dialogid, response, listitem, inputtext);
}
#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse vdealer_OnDialogResponse
forward vdealer_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
forward EnablePickups(playerid);

public EnablePickups(playerid)
{
	DeletePVar(playerid,"DisablePickups");
	return 1;
}

#if USE_CP == true
	public OnPlayerEnterDynamicCP(playerid)
	{
	    if(IsPlayerInAnyVehicle(playerid)) return 1;
		new string[DIALOG_STRING_SIZE],dealerid = GetClosestDealerForPlayer(playerid);
		if(dealerid == -1) return 1;
		SetPVarInt(playerid,"dealerid",dealerid);
		for(new i = 0;i<M_DEALER_VEHICLES;i++)
		{
		    if(DealerVehicles[dealerid][i][_active] != true) continue;
			format(string,sizeof string,"%s%s - {00FF00}$%i\n",string,DealerVehicles[dealerid][i][_name],DealerVehicles[dealerid][i][_price]);
		}
		ShowPlayerDialog(playerid,DIALOG_DEALER_VEHICLES,DIALOG_STYLE_LIST,"Which vehicle do you want to buy?",string,"Buy","Leave");
	    return 1;
	}
#else
	public OnPlayerPickUpDynamicPickup(playerid, pickupid)
	{
		if(GetPVarInt(playerid,"DisablePickups") == 1) return 1;
		SetPVarInt(playerid,"DisablePickups",1);
		new string[DIALOG_STRING_SIZE],dealerid = GetClosestDealerForPlayer(playerid);
		if(dealerid == -1) return 1;
		SetPVarInt(playerid,"dealerid",dealerid);
		for(new i = 0;i<M_DEALER_VEHICLES;i++)
		{
		    if(DealerVehicles[dealerid][i][_active] != true) continue;
			format(string,sizeof string,"%s%s - {00FF00}$%i\n",string,DealerVehicles[dealerid][i][_name],DealerVehicles[dealerid][i][_price]);
		}
		ShowPlayerDialog(playerid,DIALOG_DEALER_VEHICLES,DIALOG_STYLE_LIST,"Which vehicle do you want to buy?",string,"Buy","Leave");
	    return 1;
	}
#endif
/*==============================================================================================================
											 Public Vehicle related functions
===============================================================================================================*/
public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
    new veh = GetPlayerVehicleID(playerid);
    PrivateVehicles[ConvertVID(veh)][_c1] = color1;
    PrivateVehicles[ConvertVID(veh)][_c2] = color2;
    return CallLocalFunction("vdealer_OnVehicleRespray","iiii",playerid,vehicleid,color1,color2);
}
#if defined _ALS_OnVehicleRespray
	#undef OnVehicleRespray
#else
	#define _ALS_OnVehicleRespray
#endif
#define OnVehicleRespray vdealer_OnVehicleRespray
forward vdealer_OnVehicleRespray(playerid,vehicleid,color1,color2);

public OnVehicleDeath(vehicleid)
{
	if(IsVehiclePrivate(vehicleid))
	{
	    SetVehicleToRespawn(vehicleid);
	    SetVehiclePos(vehicleid,-5,-5,-5);
	    SetTimerEx("Spawn_On_Park_Pos",RESPAWN_DELAY,false,"i",vehicleid);
	}
	return CallLocalFunction("OnVehicleDeath","i",vehicleid);
}
#if defined _ALS_OnVehicleDeath
	#undef OnVehicleDeath
#else
	#define _ALS_OnVehicleDeath
#endif
#define OnVehicleDeath vdealer_OnVehicleDeath
forward vdealer_OnVehicleDeath(vehicleid);

forward Spawn_On_Park_Pos(vehicleid);
public Spawn_On_Park_Pos(vehicleid)
{
	new pvid = ConvertVID(vehicleid);
	SetVehiclePos(vehicleid,PrivateVehicles[pvid][_x],PrivateVehicles[pvid][_y],PrivateVehicles[pvid][_z]);
	SetVehicleZAngle(vehicleid,PrivateVehicles[pvid][_rot]);
	return 1;
}
/*==============================================================================================================
												vDealer related functions
===============================================================================================================*/
//Public Functions:
stock CreateVehicleDealer(dealername[],Float:x,Float:y,Float:z)
{
	new id = GenerateID(1);
	format(Dealers[id][_dealername],64,"%s",dealername);
	Dealers[id][_x] = x;
	Dealers[id][_y] = y;
	Dealers[id][_z] = z;
	Dealers[id][_active] = true;
	#if USE_CP == true
	    Dealers[id][_pickupid] = CreateDynamicCP(x,y,z,CP_SIZE);
	#else
	    Dealers[id][_pickupid] = CreateDynamicPickup(PICKUP_MODEL,23,x,y,z);
	#endif
	Dealers[id][_3dtextlabel] = CreateDynamic3DTextLabel(dealername,COLOR_YELLOW,x,y,z +1,STREAMER_DISTANCE);
	Dealers[id][_mapicon] = CreateDynamicMapIcon(x,y,z,MAP_ICON,0);
	return id;
}
stock AddVehicleToDealer(dealerid,vehiclename[],modelid,price)
{
	new id = GenerateID(2,dealerid);
	format(DealerVehicles[dealerid][id][_name],32,"%s",vehiclename);
	DealerVehicles[dealerid][id][_modelid] = modelid;
	DealerVehicles[dealerid][id][_price] = price;
	DealerVehicles[dealerid][id][_active] = true;
	return id;
}
stock ToggleDealer(dealerid,toggle)
{
	switch(toggle)
	{
	    case 0:
	    {
			#if USE_CP == true
			    DestroyDynamicCP(Dealers[dealerid][_pickupid]);
			#else
	        	DestroyDynamicPickup(Dealers[dealerid][_pickupid]);
	        #endif
	        DestroyDynamic3DTextLabel(Dealers[dealerid][_3dtextlabel]);
	        DestroyDynamicMapIcon(Dealers[dealerid][_mapicon]);
	        Dealers[dealerid][_active] = false;
	    }
	    case 1:
	    {
			#if USE_CP == true
			    Dealers[dealerid][_pickupid] = CreateDynamicCP(Dealers[dealerid][_x],Dealers[dealerid][_y],Dealers[dealerid][_z],CP_SIZE);
			#else
			    Dealers[dealerid][_pickupid] = CreateDynamicPickup(PICKUP_MODEL,23,Dealers[dealerid][_x],Dealers[dealerid][_y],Dealers[dealerid][_z]);
			#endif
			Dealers[dealerid][_3dtextlabel] = CreateDynamic3DTextLabel(Dealers[dealerid][_dealername],COLOR_YELLOW,Dealers[dealerid][_x],Dealers[dealerid][_y],Dealers[dealerid][_z] +1,STREAMER_DISTANCE);
			Dealers[dealerid][_mapicon] = CreateDynamicMapIcon(Dealers[dealerid][_x],Dealers[dealerid][_y],Dealers[dealerid][_z],MAP_ICON,0);
	        Dealers[dealerid][_active] = true;
	    }
	}
	return 1;
}
stock ToggleDealerVehicle(dealerid,dealervehicleid,toggle)
{
	switch(toggle)
	{
	    case 0:
	    {
	        DealerVehicles[dealerid][dealervehicleid][_active] = false;
	    }
	    case 1:
	    {
	        DealerVehicles[dealerid][dealervehicleid][_active] = true;
	    }
	}
	return 1;
}


//Internal Functions
stock vdealer_init()
{
	#if USE_MYSQL_DATABASE == true
		yoursql_connect(SQL_SERVER,SQL_USER,SQL_TABLE,SQL_PASS);
	#endif
	SetTimer("stream",STREAMER_INTERVAL,true);
	LoadVehicles();
}

stock vdealer_exit()
{
	for(new i = 0;i < (M_VEHICLES); i++)
	{
	    DestroyVehicle(PrivateVehicles[i][_vehicleid]);
	}
	for(new i = 0;i<M_DEALERS;i++)
	{
	    DestroyDynamic3DTextLabel(Dealers[i][_3dtextlabel]);
	    #if USE_CP == true
	        DestroyDynamicCP(Dealers[i][_pickupid]);
	    #else
	    	DestroyDynamicPickup(Dealers[i][_pickupid]);
		#endif
	}
}
stock CreatePrivateVehicle(playername[],modelid,Float:x,Float:y,Float:z,Float:rot,c1,c2,price)
{
	new id = GenerateID();
	if(id == -1)
	{
		printf("vDealer: Error! Max ammount of private vehicles reached (%i)! could not create vehicle",M_VEHICLES);
		return 1;
	}

	format(PrivateVehicles[id][_owner],MAX_PLAYER_NAME,"%s",playername);
    PrivateVehicles[id][_modelid] = modelid;
    PrivateVehicles[id][_x] = x;
    PrivateVehicles[id][_y] = y;
    PrivateVehicles[id][_z] = z;
    PrivateVehicles[id][_rot] = rot;
    PrivateVehicles[id][_c1] = c1;
    PrivateVehicles[id][_c2] = c2;
    PrivateVehicles[id][_price] = price;

    #if USE_MYSQL_DATABASE == true
        yoursql_insert("vehicles","isiffffiii",id,playername,modelid,x,y,z,rot,c1,c2,price);
    #else
	    new file[64];
	    format(file,sizeof file,VEHICLE_PATH,id);
	    new INI:handler = INI_Open(file);
		INI_WriteString(handler,"_owner",playername);
		INI_WriteInt(handler,"_modelid",modelid);
		INI_WriteFloat(handler,"_x",x);
		INI_WriteFloat(handler,"_y",y);
		INI_WriteFloat(handler,"_z",z);
		INI_WriteFloat(handler,"_rot",rot);
		INI_WriteInt(handler,"_c1",c1);
		INI_WriteInt(handler,"_c2",c2);
		INI_WriteInt(handler,"_price",price);
	    INI_Close(handler);
    #endif
    PrivateVehicles[id][_vehicleid] = AddStaticVehicle(modelid,x,y,z,rot,c1,c2);
    SetVehicleNumberPlate(PrivateVehicles[id][_vehicleid],PrivateVehicles[id][_owner]);
    SetVehicleToRespawn(PrivateVehicles[id][_vehicleid]);
	return PrivateVehicles[id][_vehicleid];
}

stock SaveVehicle(vehicleid)
{
	new veh = ConvertVID(vehicleid);
    #if USE_MYSQL_DATABASE == true
        new identifier[64];format(identifier,sizeof identifier,"`id` = %i",veh);
        new query[164];format(query,sizeof query,"`x` = %f, `y` = %f, `z` = %f, `rot` = %f, `c1` = %i, `c2` = %i",PrivateVehicles[veh][_x],PrivateVehicles[veh][_y],PrivateVehicles[veh][_z],PrivateVehicles[veh][_rot],PrivateVehicles[veh][_c1],PrivateVehicles[veh][_c2]);
		yoursql_update("vehicles",query,identifier);
    #else
	    new file[64];
	    format(file,sizeof file,VEHICLE_PATH,veh);
	    new INI:handler = INI_Open(file);
		INI_WriteString(handler,"_owner",PrivateVehicles[veh][_owner]);
		INI_WriteInt(handler,"_modelid",PrivateVehicles[veh][_modelid]);
		INI_WriteFloat(handler,"_x",PrivateVehicles[veh][_x]);
		INI_WriteFloat(handler,"_y",PrivateVehicles[veh][_y]);
		INI_WriteFloat(handler,"_z",PrivateVehicles[veh][_z]);
		INI_WriteFloat(handler,"_rot",PrivateVehicles[veh][_rot]);
		INI_WriteInt(handler,"_c1",PrivateVehicles[veh][_c1]);
		INI_WriteInt(handler,"_c2",PrivateVehicles[veh][_c2]);
		INI_WriteInt(handler,"_price",PrivateVehicles[veh][_price]);
	    INI_Close(handler);
    #endif
	return 1;
}

stock LoadVehicles()
{
	#if USE_MYSQL_DATABASE == true
		new query[128],counter = 0,i = 0;
		format(query,sizeof query,"SELECT `owner`,`modelid`,`x`,`y`,`z`,`rot`,`c1`,`c2`,`price` FROM vehicles WHERE `id` = 0");
		for(i = 0;yoursql_countrows(query) != 0;i++)
		{
			new buffer[1];format(buffer,sizeof buffer,"%s",yoursql_receive(query));
			sscanf(query,"p<|>e<s[24]iffffiii>",PrivateVehicles[i]);
			PrivateVehicles[i][_vehicleid] = AddStaticVehicle(PrivateVehicles[i][_modelid],PrivateVehicles[i][_x],PrivateVehicles[i][_y],PrivateVehicles[i][_z],PrivateVehicles[i][_rot],PrivateVehicles[i][_c1],PrivateVehicles[i][_c2]);
			SetVehicleNumberPlate(PrivateVehicles[i][_vehicleid],PrivateVehicles[i][_owner]);
			SetVehicleToRespawn(PrivateVehicles[i][_vehicleid]);
			format(query,sizeof query,"SELECT `owner`,`modelid`,`x`,`y`,`z`,`rot`,`c1`,`c2`,`price` FROM vehicles WHERE `id` = %i", (i +1));
			counter++;
		}
	#else
	new counter = 0;
	for(new i = 0;i<M_VEHICLES;i++)
	{
		new file[64];format(file,sizeof file,VEHICLE_PATH,i);
		if(fexist(file))
		{
			new INI:handler = INI_Open(file);
			INI_ParseFile(file,"LoadVehicle",.bExtra = true, .extra = i);
			PrivateVehicles[i][_vehicleid] = AddStaticVehicle(PrivateVehicles[i][_modelid],PrivateVehicles[i][_x],PrivateVehicles[i][_y],PrivateVehicles[i][_z],PrivateVehicles[i][_rot],PrivateVehicles[i][_c1],PrivateVehicles[i][_c2]);
			SetVehicleNumberPlate(PrivateVehicles[i][_vehicleid],PrivateVehicles[i][_owner]);
			SetVehicleToRespawn(PrivateVehicles[i][_vehicleid]);
			INI_Close(handler);
			counter++;
		}
	}
	#endif
	printf("vDealer: %i vehicle(s) loaded.",counter);
}
#if USE_MYSQL_DATABASE == false
forward LoadVehicle(i,name[],value[]);
public LoadVehicle(i,name[],value[])
{
	if(!strcmp(name,"_owner")){format(PrivateVehicles[i][_owner],MAX_PLAYER_NAME,"%s",value);}
	INI_Int("_modelid",PrivateVehicles[i][_modelid]);
	INI_Float("_x",PrivateVehicles[i][_x]);
	INI_Float("_y",PrivateVehicles[i][_y]);
	INI_Float("_z",PrivateVehicles[i][_z]);
	INI_Float("_rot",PrivateVehicles[i][_rot]);
	INI_Int("_c1",PrivateVehicles[i][_c1]);
	INI_Int("_c2",PrivateVehicles[i][_c2]);
	INI_Int("_price",PrivateVehicles[i][_price]);
	return 1;
}
#endif

stock RemoveVehicle(vehicleid)
{
	new id = ConvertVID(vehicleid);
	format(PrivateVehicles[id][_owner],MAX_PLAYER_NAME,"");
	PrivateVehicles[id][_x] = 0;
	PrivateVehicles[id][_y] = 0;
	PrivateVehicles[id][_z] = 0;
	PrivateVehicles[id][_rot] = 0;
	PrivateVehicles[id][_c1] = 0;
	PrivateVehicles[id][_c2] = 0;
	PrivateVehicles[id][_price] = 0;
	DestroyVehicle(vehicleid);
	#if USE_MYSQL_DATABASE == true
		new identifier[64];
		format(identifier,sizeof identifier,"'id' = %i",id);
		yoursql_delete("vehicles",identifier);
	#else
		new file[64];
		format(file,sizeof file,VEHICLE_PATH,id);
		fremove(file);
	#endif
	return 1;
}

stock GenerateID(type = 0,dealer = 0)
{
	if(type == 0)                       //vehicle ids
	{
		for(new i = 0; i < M_VEHICLES; i++)
		{
		    #if USE_MYSQL_DATABASE == true
			    new query[64];format(query,sizeof query,"SELECT * FROM vehicles");
			    return yoursql_countrows(query);
		    #else
		        new file[64];format(file,sizeof file,VEHICLE_PATH,i);
		        if(!fexist(file)) return i;
		    #endif
		}
	} else if (type == 1) {             //dealer ids
		for(new i = 0; i < M_DEALERS; i++)
		{
  			if(Dealers[i][_active] == false) return i;
		}
	} else if (type == 2) {             //vehicle ids in dealermenu
		for(new i = 0; i < M_DEALER_VEHICLES; i++)
		{
  			if(DealerVehicles[dealer][i][_active] == false) return i;
		}
	}
	return -1;
}

stock ConvertVID(vehicleid)
{
	for(new i = 0;i < (M_VEHICLES); i++)
	{
	    if(PrivateVehicles[i][_vehicleid] == vehicleid)
	    {
	        return i;
	    }
	}
	return -1;
}

stock IsVehiclePrivate(vehicleid)
{
	for(new i = 0;i < (M_VEHICLES); i++)
	{
	    if(PrivateVehicles[i][_vehicleid] == vehicleid)
	    {
	        return 1;
	    }
	}
	return 0;
}

stock GetClosestDealerForPlayer(playerid)
{
	new dealer = -1;
	new Float:distance = STREAMER_DISTANCE;
	new Float:x,Float:y,Float:z;GetPlayerPos(playerid,x,y,z);
	for(new i = 0;i<M_DEALERS;i++)
	{
		new Float:temp1, Float:temp2;
		temp1 = x-Dealers[i][_x];temp2 = y-Dealers[i][_y];
		if(floatsqroot(temp1*temp1+temp2*temp2) < distance)
		{
		    distance = floatsqroot(temp1*temp1+temp2*temp2);
		    dealer = i;
		}
	}
	return dealer;
}
/*==============================================================================================================
											 			Player commands
===============================================================================================================*/
COMMAND:park(playerid,params[])
{
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_RED,"You are not in a vehicle!");
	new veh = GetPlayerVehicleID(playerid),Float:x,Float:y,Float:z,Float:rot;
	if(!IsVehiclePrivate(veh)) return SendClientMessage(playerid,COLOR_RED,"You are not in a private vehicle!");
	new pName[MAX_PLAYER_NAME];GetPlayerName(playerid,pName,sizeof pName);
	GetVehiclePos(veh,x,y,z);GetVehicleZAngle(veh,rot);

	if(strcmp(pName,PrivateVehicles[ConvertVID(veh)][_owner])) return SendClientMessage(playerid,COLOR_RED,"You are not the owner of this vehicle!");

	veh = ConvertVID(veh);
	PrivateVehicles[veh][_x] = x;
	PrivateVehicles[veh][_y] = y;
	PrivateVehicles[veh][_z] = z;
	PrivateVehicles[veh][_rot] = rot;

	SaveVehicle(PrivateVehicles[veh][_vehicleid]);
	SendClientMessage(playerid,COLOR_YELLOW,"You've succesfully parked your vehicle.");
	return 1;
}

COMMAND:sellvehicle(playerid,params)
{
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_RED,"You are not in a vehicle!");
	new veh = GetPlayerVehicleID(playerid);
	if(!IsVehiclePrivate(veh)) return SendClientMessage(playerid,COLOR_RED,"You are not in a private vehicle!");
	new pName[MAX_PLAYER_NAME];GetPlayerName(playerid,pName,sizeof pName);if(strcmp(pName,PrivateVehicles[ConvertVID(veh)][_owner])) return SendClientMessage(playerid,COLOR_RED,"You are not the owner of this vehicle!");

	new str[93];format(str,sizeof str,"{FFFF00}Are you sure you want to sell your vehicle ? You will receive {FFFFFF}$%i",(PrivateVehicles[ConvertVID(veh)][_price] / SELL_DIVIDE));
	ShowPlayerDialog(playerid,DIALOG_SELL,0,"Selling your vehicle",str,"Yes","no");
	return 1;
}
/*==============================================================================================================
											 Non-vDealer related functions
===============================================================================================================*/
stock SendClientMessageEx(playerid,color,type[],{Float,_}:...)
{
	new string[128];
	for(new i = 0;i<numargs() -2;i++)
	{
	    switch(type[i])
	    {
	        case 's':
	        {
				new result[128];
				for(new a= 0;getarg(i +3,a) != 0;a++)
				{
				    result[a] = getarg(i +3,a);
				}
				if(!strlen(string))
				{
				    format(string,sizeof string,"%s",result);
				} else format(string,sizeof string,"%s%s",string,result);
	        }

	        case 'i':
	        {
	            new result = getarg(i +3);
				if(!strlen(string))
				{
				    format(string,sizeof string,"%i",result);
				} else format(string,sizeof string,"%s%i",string,result);
	        }

	        case 'f':
	        {
				new Float:result = Float:getarg(i +3);
				if(!strlen(string))
				{
				    format(string,sizeof string,"%f",result);
				} else format(string,sizeof string,"%s%f",string,result);
	        }
	    }
	}
    SendClientMessage(playerid,color,string);
    return 1;
}

/*
//////////////////////////////////////////////////////////
//======================================================//
//== Anti Lag Shot Sync include made by BigETI © 2012 ==//
//======================================================//
//== You are not allowed to edit this include ==========//
//== and/or release it without my permissions! =========//
//======================================================//
//== File name: alss.inc ===============================//
//== Author: Ethem Kurt © ==============================//
//== Release Date: 19.03.2012 ==========================//
//== Version: V1.0.1 ===================================//
//== Lines: 209 ========================================//
//== File size: 8.25 KB ================================//
//======================================================//
//////////////////////////////////////////////////////////

||==================================================================================================================||
||	IMPORTANT: Define FILTERSCRIPT on top of your script to verify if you are yousing a filterscript or a gamemode! ||
||	If you want to use the functions at another scripts, so you have to include alls_remote.inc there!              ||
||  This is a NON PVar version include!                                                                             ||
||==================================================================================================================||
*/

//Do not edit those things below!
#if defined ALSS_INCLUDED_
	#endinput
#endif
#define ALSS_INCLUDED_
#if defined ALSS_REMOTE_INCLUDED_
	#error Do not include alss.inc and alss_remote.inc in one script.
#endif
#include <a_samp>
#define ALSS_OPC	0x1
#define ALSS_OPS	0x2
#define ALSS_OPD	0x4
#define ALSS_OPGD	0x8
new ALSS_CallBacks, ALSS_Team[MAX_PLAYERS] = {NO_TEAM, ...}, Float:ALSS_Health[MAX_PLAYERS] = {100.0, ...}, Float:ALSS_Armour[MAX_PLAYERS], ALSS_NoTakeDamage[MAX_PLAYERS], ALSS_NoGiveDamage[MAX_PLAYERS];
stock ALSS_SetPlayerHealth(playerid, Float:health)
{
	ALSS_Health[playerid] = health;
	return SetPlayerHealth(playerid, health);
}
#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth ALSS_SetPlayerHealth
stock ALSS_SetPlayerArmour(playerid, Float:armour)
{
	ALSS_Armour[playerid] = armour;
	return SetPlayerArmour(playerid, armour);
}
#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour ALSS_SetPlayerArmour
#if defined FILTERSCRIPT
public OnFilterScriptInit()
#else
public OnGameModeInit()
#endif
{
	ALSS_CallBacks |= (funcidx("ALSS_OnPlayerConnect") != -1 ? ALSS_OPC : 0x0);
	ALSS_CallBacks |= (funcidx("ALSS_OnPlayerSpawn") != -1 ? ALSS_OPS : 0x0);
	ALSS_CallBacks |= (funcidx("ALSS_OnPlayerGiveDamage") != -1 ? ALSS_OPGD : 0x0);
#if defined FILTERSCRIPT
	return (funcidx("ALSS_OnFilterScriptInit") != -1 ? CallLocalFunction("ALSS_OnFilterScriptInit", "") : 1);
}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit ALSS_OnFilterScriptInit
forward ALSS_OnFilterScriptInit();
#else
	return (funcidx("ALSS_OnGameModeInit") != -1 ? CallLocalFunction("ALSS_OnGameModeInit", "") : 1);
}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit ALSS_OnGameModeInit
forward ALSS_OnGameModeInit();
#endif
public OnPlayerConnect(playerid)
{
	ALSS_Team[playerid] = NO_TEAM;
	ALSS_Health[playerid] = 100.0;
	ALSS_Armour[playerid] = 0.0;
	ALSS_NoTakeDamage[playerid] = false;
	ALSS_NoGiveDamage[playerid] = false;
	return (ALSS_CallBacks & ALSS_OPC ? CallLocalFunction("ALSS_OnPlayerConnect", "i", playerid) : 1);
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect ALSS_OnPlayerConnect
forward ALSS_OnPlayerConnect(playerid);
public OnPlayerSpawn(playerid)
{
	ALSS_Health[playerid] = 100.0;
	SetPlayerArmour(playerid, 0.0);
	SetPlayerTeam(playerid, 1);
	return (ALSS_CallBacks & ALSS_OPS ? CallLocalFunction("ALSS_OnPlayerSpawn", "i", playerid) : 1);
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn ALSS_OnPlayerSpawn
forward ALSS_OnPlayerSpawn(playerid);
stock ALSS_SetPlayerTeam(playerid, teamid)
{
	ALSS_Team[playerid] = teamid;
	return 1;
}
#if defined _ALS_SetPlayerTeam
	#undef SetPlayerTeam
#else
	#define _ALS_SetPlayerTeam
#endif
#define SetPlayerTeam ALSS_SetPlayerTeam
public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
	if(damagedid != INVALID_PLAYER_ID)
	{
		if(ALSS_Team[playerid] != ALSS_Team[damagedid] || ALSS_Team[damagedid] == NO_TEAM && (!ALSS_NoGiveDamage[playerid] && !ALSS_NoTakeDamage[damagedid]))
		{
			new Float:ALSS_pHp = ALSS_Health[damagedid], Float:ALSS_pArmour = ALSS_Armour[damagedid];
			if(ALSS_pArmour-amount < 0.0)
			{
				SetPlayerArmour(damagedid, 0.0);
				if(ALSS_pHp-(ALSS_pArmour-amount) < 0.0)
				{
					SetPlayerHealth(damagedid, 0.0);
					OnPlayerDeath(damagedid,playerid,weaponid);
				}
				else SetPlayerHealth(damagedid, ALSS_pHp-(ALSS_pArmour+amount));
			}
			else SetPlayerArmour(damagedid, ALSS_pArmour-amount);
		}
	}
	return (ALSS_CallBacks & ALSS_OPGD ? CallLocalFunction("ALSS_OnPlayerGiveDamage", "iifi", playerid, damagedid, amount, weaponid) : 1);
}
#if defined _ALS_OnPlayerGiveDamage
	#undef OnPlayerGiveDamage
#else
	#define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage ALSS_OnPlayerGiveDamage
forward ALSS_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
forward ALSS_RemotePlayerHealth(playerid, Float:health);
public ALSS_RemotePlayerHealth(playerid, Float:health) return SetPlayerHealth(playerid, health);
forward ALSS_RemotePlayerArmour(playerid, Float:armour);
public ALSS_RemotePlayerArmour(playerid, Float:armour) return SetPlayerArmour(playerid, armour);
forward ALSS_RemotePlayerTeam(playerid, teamid);
public ALSS_RemotePlayerTeam(playerid, teamid) return SetPlayerTeam(playerid, teamid);
forward ALSS_RemoteTakeDamage(playerid, bool:isdisabled);
public ALSS_RemoteTakeDamage(playerid, bool:isdisabled) ALSS_NoTakeDamage[playerid] = isdisabled;
forward ALSS_RemoteGiveDamage(playerid, bool:isdisabled);
public ALSS_RemoteGiveDamage(playerid, bool:isdisabled) ALSS_NoGiveDamage[playerid] = isdisabled;
#define DisablePlayerTakeDamage(%0) ALSS_NoTakeDamage[%0] = true
#define EnablePlayerTakeDamage(%0) ALSS_NoTakeDamage[%0] = false
#define DisablePlayerGiveDamage(%0) ALSS_NoGiveDamage[%0] = true
#define EnablePlayerGiveDamage(%0) ALSS_NoGiveDamage[%0] = false
/*
ETIETIETIETI  	ETI		    ETIETIETIETI	BigBigBigBig	BigBigBigBigBig		Big
ETI       ETI 	ETI		  ETI           	Big         	      Big      		Big
ETI        ETI	ETI		 ETI            	Big         	      Big      		Big
ETI       ETI 	ETI		ETI             	Big         	      Big      		Big
ETIETIETIETI  	ETI		ETI    ETIETIETI	BigBigBig   	      Big      		Big
ETI       ETI 	ETI		ETI          ETI	Big         	      Big      		Big
ETI        ETI	ETI		 ETI         ETI	Big         	      Big      		Big
ETI       ETI 	ETI		  ETI        ETI	Big         	      Big      		Big
ETIETIETIETI  	ETI		    ETIETIETIETI	BigBigBigBig	      Big      		Big
*/
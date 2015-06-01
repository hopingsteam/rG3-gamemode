/*
//////////////////////////////////////////////////////////
//======================================================//
//== Anti Lag Shot Sync include made by BigETI © 2012 ==//
//======================================================//
//== You are not allowed to edit this include ==========//
//== and/or release it without my permissions! =========//
//======================================================//
//== File name: alss2.inc ==============================//
//== Author: Ethem Kurt © ==============================//
//== Release Date: 19.03.2012 ==========================//
//== Version: V1.0.1 ===================================//
//== Lines: 193 ========================================//
//== File size: 7.43 KB ================================//
//======================================================//
//////////////////////////////////////////////////////////

||==================================================================================================================||
||	IMPORTANT: Define FILTERSCRIPT on top of your script to verify if you are yousing a filterscript or a gamemode! ||
||	If you want to use the functions at another scripts, so you have to include alls_remote.inc there!              ||
||  This is a PVar version include!                                                                                 ||
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
new ALSS_CallBacks;
stock ALSS_SetPlayerHealth(playerid, Float:health)
{
	SetPVarFloat(playerid, "ALSS_Health", health);
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
	SetPVarFloat(playerid, "ALSS_Armour", armour);
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
	ALSS_CallBacks |= (funcidx("ALSS_OnPlayerDeath") != -1 ? ALSS_OPD : 0x0);
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
	SetPVarInt(playerid, "ALSS_Team", NO_TEAM);
	SetPVarFloat(playerid, "ALSS_Health", 100.0);
	SetPVarFloat(playerid, "ALSS_Armour", 0.0);
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
	SetPVarFloat(playerid, "ALSS_Health", 100.0);
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
stock ALSS_SetPlayerTeam(playerid, teamid) return SetPVarInt(playerid, "ALSS_Team", teamid);
#if defined _ALS_SetPlayerTeam
	#undef SetPlayerTeam
#else
	#define _ALS_SetPlayerTeam
#endif
#define SetPlayerTeam ALSS_SetPlayerTeam
public OnPlayerDeath(playerid, killerid, reason)
{
	if(GetPVarType(playerid, "ALSS_Killer") != 0)
	{
		killerid = GetPVarInt(playerid, "ALSS_Killer");
		reason = GetPVarInt(playerid, "ALSS_KillerReason");
		DeletePVar(playerid, "ALSS_Killer");
		DeletePVar(playerid, "ALSS_KillerReason");
	}
	return (ALSS_CallBacks & ALSS_OPD ? CallLocalFunction("ALSS_OnPlayerDeath", "iii", playerid, killerid, reason) : 1);
}
#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath ALSS_OnPlayerDeath
forward ALSS_OnPlayerDeath(playerid, killerid, reason);
public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
	if(damagedid != INVALID_PLAYER_ID)
	{
		new damagedidteam = GetPVarInt(damagedid, "ALSS_Team");
		if(GetPVarInt(playerid, "ALSS_Team") != damagedidteam || damagedidteam == NO_TEAM && (GetPVarType(playerid, "ALSS_NoGiveDamage") == 0 && GetPVarType(damagedid, "ALSS_NoTakeDamage") == 0))
		{
			new Float:ALSS_pHp = GetPVarFloat(damagedid, "ALSS_Health"), Float:ALSS_pArmour = GetPVarFloat(damagedid, "ALSS_Armour");
			if(ALSS_pArmour-amount < 0.0)
			{
				SetPlayerArmour(damagedid, 0.0);
				if(ALSS_pHp-(ALSS_pArmour-amount) < 0.0)
				{
					if(GetPVarType(damagedid, "ALSS_Killer") == 0)
					{
						SetPVarInt(damagedid, "ALSS_Killer", playerid);
						SetPVarInt(damagedid, "ALSS_KillerReason", weaponid);
					}
					SetPlayerHealth(damagedid, 0.0);
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
#define DisablePlayerTakeDamage(%0) SetPVarInt(%0, "ALSS_NoTakeDamage", 1)
#define EnablePlayerTakeDamage(%0) DeletePVar(%0, "ALSS_NoTakeDamage")
#define DisablePlayerGiveDamage(%0) SetPVarInt(%0, "ALSS_NoGiveDamage", 1)
#define EnablePlayerGiveDamage(%0) DeletePVar(%0, "ALSS_NoGiveDamage")
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
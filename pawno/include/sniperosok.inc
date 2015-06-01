#if defined _sniperosok_included
	#endinput
#endif
#define _sniperosok_included

#include <a_samp>

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
	if(weaponid == 34) 
	{
		SetPlayerHealth(playerid, -0);
		GameTextForPlayer(playerid, "~r~Headshot!", 3000, 5);
		GameTextForPlayer(issuerid, "~r~Headshot!", 3000, 5);
	}
	return CallLocalFunction("osok_OnPlayerTakeDamage", "iifi", playerid, issuerid, amount, weaponid);
}
#if defined _ALS_OnPlayerTakeDamage
    #undef OnPlayerTakeDamage
#else
    #define _ALS_OnPlayerTakeDamage
#endif
#define OnPlayerTakeDamage sniperosok_OnPlayerTakeDamage
forward sniperosok_OnPlayerTakeDamage();
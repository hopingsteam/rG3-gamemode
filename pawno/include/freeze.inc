#include <a_samp>
/*
|||||||||||||||||||||||||||||||||||||||||||||||||
||Freeze Include By AlexzzPro                  ||
||Good luck running my script without it pussys||
|||||||||||||||||||||||||||||||||||||||||||||||||
*/
forward unfreezetimer(playerid);

stock freeze(playerid)
{
	TogglePlayerControllable(playerid, 0);
	GameTextForPlayer(playerid, "~g~Frozen for 3 seconds for Object Load!", 3000, 5);
	SetTimerEx("unfreezetimer", 3000, false, "i", playerid);
}
public unfreezetimer(playerid)
{
	TogglePlayerControllable(playerid, 1);
	GameTextForPlayer(playerid, "~g~Unfrozen",2000, 5);
	return 1;
}

stock IsValidSkin(SkinID)
{
        if((SkinID >= 0) && (SkinID <= 3)||(SkinID == 7)||(SkinID >= 9 && SkinID <= 41)||(SkinID >= 43 && SkinID <= 64)||(SkinID >= 66 && SkinID <= 73)||(SkinID >= 75 && SkinID <= 85)||(SkinID >= 87 && SkinID <= 118)||(SkinID >= 120 && SkinID <= 148)||(SkinID >= 150 && SkinID <= 207)||(SkinID >= 209 && SkinID <= 264)||(SkinID >= 274 && SkinID <= 288)||(SkinID >= 290 && SkinID <= 299)) return true;
        else return false;
}

stock strvalEx( str[ ] )
{
    if( strlen( str ) >= 50 ) return -1;
    return strval( str );
}

stock PlayerName(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    return name;
}
stock GetClosestPlayer(playerid) // Not created by me, Dont know who made this.
{
    new Float:cdist, targetid = -1;
    for(new i; i<MAX_PLAYERS; i++)
    {
        if (IsPlayerConnected(i) && playerid != i && (targetid < 0 || cdist > GetDistanceBetweenPlayers(playerid, i)))
        {
            targetid = i;
            cdist = GetDistanceBetweenPlayers(playerid, i);
        }
    }
    return targetid;
}
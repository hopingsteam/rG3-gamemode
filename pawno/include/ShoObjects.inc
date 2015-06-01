#include "a_samp"

#if defined _ShoObjects_included
	#endinput
#endif

#define _ShoObjects_included

stock ShoObjectsLoad( playerid )
{
	TogglePlayerControllable( playerid, 0 );
	SetTimerEx( "ShoTimer", 3500, false, "i", playerid );
}

forward ShoTimer( playerid );
public ShoTimer( playerid )
{
	TogglePlayerControllable( playerid, 1 );
}

//native ShoObjectsLoad(playerid);

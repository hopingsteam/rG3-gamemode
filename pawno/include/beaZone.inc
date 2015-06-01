/*
        *****************
        
	        beaZone
	         v1.0
    Gang Zone Numbers & Borders
    
		    by beaz
    
    
        *****************
*/


#include <a_samp>

#define NUMDIS 40.0
#define MAX_GANGZONES 68

enum zoneInfo
{
	bool:zexist,
	npart[5],
	npart2[5],
	border[4],
}
new zGangZones[1024][zoneInfo];

public OnGameModeInit()
{
    for(new z=0;z<MAX_GANGZONES;z++)
	{
	 zGangZones[z][zexist] = false;
	 for(new nump=0;nump<5;nump++)
	 {
	   zGangZones[z][npart][nump] = -1;
	   zGangZones[z][npart2][nump] = -1;
	 }
	}
    return CallLocalFunction("Hook_OnGameModeInit", "");
}
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Hook_OnGameModeInit

forward OnGameModeInit();

public OnPlayerConnect(playerid)
{
    return CallLocalFunction("Hook_OnPlayerConnect", "i", playerid);
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Hook_OnPlayerConnect

forward OnPlayerConnect(playerid);

stock GangZoneCreateEx( Float:gzMinX,Float:gzMinY,Float:gzMaxX,Float:gzMaxY)
{
	new gid = GangZoneCreate(gzMinX,gzMinY,gzMaxX,gzMaxY);
	zGangZones[gid][zexist] = true;
	zGangZones[gid][border][0] = GangZoneCreate( gzMinX-2.0, gzMinY, gzMinX+2.0, gzMaxY );
	zGangZones[gid][border][1] = GangZoneCreate( gzMinX-2.0, gzMaxY-2.0, gzMaxX, gzMaxY+2.0 );
	zGangZones[gid][border][2] = GangZoneCreate( gzMaxX-2.0, gzMinY, gzMaxX+2.0, gzMaxY );
	zGangZones[gid][border][3] = GangZoneCreate( gzMinX-2.0, gzMinY-2.0, gzMaxX, gzMinY+2.0 );
	return gid;
}

stock GangZoneDestroyEx( gangzoneid )
{
  if(zGangZones[gangzoneid][zexist]) // Checking if gang zone was created with numbers and borders.
  {

   // Removing borders.
   for(new bord;bord < 4;bord++)GangZoneDestroy(zGangZones[ gangzoneid ][border][bord]);

   // Destroying main gang zone.
   GangZoneDestroy(gangzoneid);

   // Setting value to false, which means gang zone doesn't exist.
   zGangZones[gangzoneid][zexist] = false;
  }
}

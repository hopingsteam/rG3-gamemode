//***** Made by TopAz in 15 minutes.
 
 
//----- Header
#if defined _getnearest_included
        #endinput
#endif
#define _getnearest_included
#pragma library samp
//----------------
 
//----- External Library(ies)
#include <a_samp>
//------------------------
 
//----- Constants
/*#if defined USE_STREAMER
        #include "streamer"
#endif*/
 
#define OBJECT                          (0)
#define PLAYER                          (1)
#define VEHICLE                         (2)
#define DYNAMIC_OBJECT          (3)                    
//----------------
 
 
stock GetNearest(playerid, type, Float:distance)
{
        new ret;
        switch(type)
        {
                case OBJECT:
                {
                        ret = GetNearest_Object(playerid, distance);
                }
                case PLAYER:
                {
                        ret = GetNearest_Player(playerid, distance);
                }
                case VEHICLE:
                {
                        ret = GetNearest_Vehicle(playerid, distance);
                }
                case DYNAMIC_OBJECT:
                {
                        ret = GetNearest_DynObject(playerid, distance);
                }
        }
        return ret;
}
 
stock GetNearest_Object(playerid, Float:distance)
{
        new
                Float:xX,
                Float:yY,
                Float:zZ,
                retElement = -1
        ;
    for(new i = 0; i < MAX_OBJECTS; i++)
    {
                if(!IsValidObject(i)) continue;
        GetObjectPos(i, xX, yY, zZ);
        new Float:odist = GetPlayerDistanceFromPoint(playerid, xX, yY, zZ);
                if (retElement == -1)
        {
            retElement = i;
            distance = odist;
        }
                else if (odist < distance)
        {
            retElement = i;
            distance = odist;
        }
    }
    return retElement;
}
 
stock GetNearest_Player(playerid, Float:distance)
{
        new
                Float:xX,
                Float:yY,
                Float:zZ,
                retElement = -1
        ;
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
                if((i == playerid) || (i == INVALID_PLAYER_ID)) continue;
        GetPlayerPos(i, xX, yY, zZ);
        new Float:odist = GetPlayerDistanceFromPoint(playerid, xX, yY, zZ);
                if (retElement == -1)
        {
            retElement = i;
            distance = odist;
        }
                else if (odist < distance)
        {
            retElement = i;
            distance = odist;
        }
    }
    return retElement;
}
 
stock GetNearest_Vehicle(playerid, Float:distance)
{
        new
                Float:xX,
                Float:yY,
                Float:zZ,
                retElement = -1
        ;
    for(new i = 0; i < MAX_VEHICLES; i++)
    {
        GetVehiclePos(i, xX, yY, zZ);
        new Float:odist = GetPlayerDistanceFromPoint(playerid, xX, yY, zZ);
                if (retElement == -1)
        {
            retElement = i;
            distance = odist;
        }
                else if (odist < distance)
        {
            retElement = i;
            distance = odist;
        }
    }
    return retElement;
}
 
stock GetNearest_DynObject(playerid, Float:distance)
{
        new
                Float:xX,
                Float:yY,
                Float:zZ,
                retElement = -1
        ;
    for(new i = 0; i < CountDynamicObjects(); i++)
    {
        GetDynamicObjectPos(i, xX, yY, zZ);
        new Float:odist = GetPlayerDistanceFromPoint(playerid, xX, yY, zZ);
                if (retElement == -1)
        {
            retElement = i;
            distance = odist;
        }
                else if (odist < distance)
        {
            retElement = i;
            distance = odist;
        }
    }
    return retElement;
}
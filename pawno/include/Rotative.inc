/*
				+-------------------------------------------------+
				|	        Script created by Gantzyo.            |
				|                                                 |
				|	      You can contact with me in the	      |
				|                  official post:                 |
				| http://forum.sa-mp.com/index.php?topic=176846.0 |
				|                                                 |
				|             Don't delete credits!               |
				+-------------------------------------------------+
*/

#include <a_samp>
#if defined _G_ObjectsRot_included
	#endinput
#endif
#define _G_ObjectsRot_included
#pragma library G_ObjectsRot

#define SERVER_OBJECTS 1000 //1000 is the number of objects in the server
new Float:newrotX[SERVER_OBJECTS];
new Float:newrotY[SERVER_OBJECTS];
new Float:newrotZ[SERVER_OBJECTS];
new Float:odifX[SERVER_OBJECTS];
new Float:odifY[SERVER_OBJECTS];
new Float:odifZ[SERVER_OBJECTS];
new ospeed[SERVER_OBJECTS];
new oTimer[SERVER_OBJECTS];
new oState[SERVER_OBJECTS];
new opoints[SERVER_OBJECTS];

stock RotateObject(objectid,Float:rotX,Float:rotY,Float:rotZ,points,Float:speed)
{
	if(oState[objectid] == 1)KillTimer(oTimer[objectid]);
	ospeed[objectid] = floatround(floatdiv(1000,speed),floatround_round);
	oTimer[objectid] = SetTimerEx("RotateObj",ospeed[objectid],0,"dd",objectid,points);
	newrotX[objectid] = rotX;
	newrotY[objectid] = rotY;
	newrotZ[objectid] = rotZ;
	new Float:rot[3];
	GetObjectRot(objectid,rot[0],rot[1],rot[2]);
	odifX[objectid] = (rotX-rot[0])/points;
	odifY[objectid] = (rotY-rot[1])/points;
	odifZ[objectid] = (rotZ-rot[2])/points;
	oState[objectid] = 1;
	opoints[objectid] = 0;
	return 1;
}
stock SetObjectRotationSpeed(objectid,Float:speed)
{
	ospeed[objectid] = floatround(floatdiv(1000,speed),floatround_round);
	return 1;
}
stock StopRotatingObject(objectid)
{
	if(oState[objectid] == 1)KillTimer(oTimer[objectid]);
	oState[objectid] = 0;
	OnObjectStopRotate(objectid);
	return 1;
}
stock GenerateBucle(objectid,Float:offX,Float:offY,Float:offZ,Float:speed)
{
	if(oState[objectid] == 1)KillTimer(oTimer[objectid]);
	ospeed[objectid] = floatround(floatdiv(1000,speed),floatround_round);
	oTimer[objectid] = SetTimerEx("RotateObjBucle",ospeed[objectid],0,"d",objectid);
	odifX[objectid] = offX;
	odifY[objectid] = offY;
	odifZ[objectid] = offZ;
	oState[objectid] = 1;
	return 1;
}
stock StopBucle(objectid)
{
	if(oState[objectid] == 1)KillTimer(oTimer[objectid]);
	oState[objectid] = 0;
	OnObjectStopBucle(objectid);
	return 1;
}
forward RotateObj(objectid,points);
public RotateObj(objectid,points)
{
	if(oState[objectid] == 0) return 1;
	new Float:rot[3];
	GetObjectRot(objectid,rot[0],rot[1],rot[2]);
	if(newrotX[objectid] != rot[0])rot[0]+=odifX[objectid];
	if(newrotY[objectid] != rot[1])rot[1]+=odifY[objectid];
	if(newrotZ[objectid] != rot[2])rot[2]+=odifZ[objectid];
	SetObjectRot(objectid,rot[0],rot[1],rot[2]);
	opoints[objectid]++;
	if((newrotX[objectid] != rot[0] || newrotY[objectid] != rot[1] || newrotZ[objectid] != rot[2]) && opoints[objectid] != points)oTimer[objectid] = SetTimerEx("RotateObj",ospeed[objectid],0,"dd",objectid,points);
	else {oState[objectid] = 0;OnObjectRotated(objectid);}
	return 1;
}
forward RotateObjBucle(objectid);
public RotateObjBucle(objectid)
{
	if(oState[objectid] == 0) return 1;
	new Float:rot[3];
	GetObjectRot(objectid,rot[0],rot[1],rot[2]);
	SetObjectRot(objectid,rot[0]+odifX[objectid],rot[1]+odifY[objectid],rot[2]+odifZ[objectid]);
	oTimer[objectid] = SetTimerEx("RotateObjBucle",ospeed[objectid],0,"d",objectid);
	return 1;
}
forward OnObjectRotated(objectid);
forward OnObjectStopRotate(objectid);
forward OnObjectStopBucle(objectid);
/*
native RotateObject(objectid,Float:rotX,Float:rotY,Float:rotZ,points,Float:speed);
native SetObjectRotationSpeed(objectid,Float:speed);
native StopRotatingObject(objectid);
native GenerateBucle(objectid,Float:offX,Float:offY,Float:offZ,Float:speed)
native StopBucle(objectid);
native OnObjectRotated(objectid);
native OnObjectStopRotate(objectid);
native OnObjectStopBucle(objectid);
*/

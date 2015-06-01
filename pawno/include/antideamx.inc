#include <a_samp>

AntiDeAMX()
{
        new a[][] =
        {
                "Unarmed (Fist)",
                "Brass K"
        };
        #pragma unused a
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	AntiDeAMX();
	return 1;
}
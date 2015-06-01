//
// By Akord & Reachless for RedzMax pentru salvarea datelor. (MySql)
//

#include <a_samp>

#define MAX_HOUSES 400

forward Update(playerid,type);
forward vUpdate(vehicleid, type);
forward hUpdate(houseid, type);
forward OnPlayerDateUpdateX2(playerid);

#define	pLevelx					1  
#define	pAdminLevelx            2  
#define	pDonateRankx            3  
#define	pUpgradePointsx         4  
#define	pConnectedTimex         5  
#define	pRegisteredx            6  
#define	pSexx                   7  
#define	pAgex                   8  
#define	pOriginx                9  
#define	pCKx                    10 
#define	pMutedx                 11 
#define	pRespectx               12 
#define	pMoneyx                 13 
#define	pBankx                  14 
#define	pCrimesx                15 
#define	pKillsx                 16
#define	pDeathsx                17 
#define	pArrestedx              18 
#define	pWantedDeathsx          19 
#define	pPhonebookx             20 
#define	pLottoNrx               21 
#define	pFishesx                22 
#define	pBiggestFishx           23 
#define	pJobx                   24 
#define	pJob1x                  25 
#define	pPayCheckx              26
#define	pHeadValuex             27 
#define	pJailedx                28 
#define	pJailTimex              29 
#define	pMaterialsx             30 
#define	pDrugsx                 31 
#define	pLeaderx                32 
#define	pMemberx                33 
#define	pFMemberx               34 
#define	pRankx                  35 
#define	pCharx                  36 
#define	pContractTimex          37 
#define	pDetSkillx              38 
#define	pSexSkillx              39 
#define	pBoxSkillx              40 
#define	pLawSkillx              41 
#define	pMechSkillx             42 
#define	pJackSkillx             43 
#define	pCarSkillx              44 
#define	pNewsSkillx             45 
#define	pDrugsSkillx            46 
#define	pCookSkillx             47 
#define	pFishSkillx             48 
#define	pSHealthx               49 
#define	pHealthx                50 
#define	pIntx                   51 
#define	pLocalx                 52 
#define	pTeamx                  53 
#define	pModelx                 54 
#define	pPhoneNrx               55 
#define	pHousex                 56 
#define	pBizzx                  57 
#define	pPos_xx                 58 
#define	pPos_yx                 59 
#define	pPos_zx                 60 
#define	pCarLicx                61 
#define	pFlyLicx                62 
#define	pBoatLicx               63 
#define	pFishLicx               64 
#define	pGunLicx                65 
#define	pGun1x                  66 
#define	pGun2x                  67 
#define	pGun3x                  68 
#define	pGun4x                  69 
#define	pAmmo1x                 70 
#define	pAmmo2x                 71 
#define	pAmmo3x                 72 
#define	pAmmo4x                 73 
#define	pCarTimex               74 
#define	pPayDayx                75 
#define	pPayDayHadx             76 
#define	pCDPlayerx              77 
#define	pWinsx                  78 
#define	pLosesx                 79 
#define	pAlcoholPerkx           80 
#define	pDrugPerkx              81 
#define	pMiserPerkx             82 
#define	pPainPerkx              83 
#define	pTraderPerkx            84 
#define	pTutorialx              85 
#define	pMissionx               86 
#define	pWarningsx              87 
#define	pAdjustablex            88 
#define	pFuelx                  89 
#define	pMarriedx               90       
#define	pCar1x                  91 
#define	pCar2x                  92 
#define	pCar3x                  93 
#define	pAchievement1x          94 
#define	pAchievement3x          95 
#define	pAchievement2x          96 
#define	pAchievement4x          97 
#define	pAchievement5x          98 
#define	pAchievement6x          99 
#define	pAchievement7x          100
#define	pAchievement8x          101
#define	pAchievement9x          102
#define	pAchievement10x         103
#define	pAchievement11x         104
#define	pAchievement12x         105
#define	pAchievement13x         106
#define	pAchievement14x         107
#define	pAchievement15x         108
#define	pAchievement16x         109
#define	pAchievement17x         110
#define	pAchievement18x         111
#define	pAchievement19x         112
#define	pAchievement20x         113
#define	pAchievement21x         114
#define	pAchievement22x         115
#define	pAchievement23x         116
#define	pAchievement24x         117
#define	pAchievement25x         118
#define	pAchievement26x         119
#define	pAchievement27x         120
#define	pAchievement28x         121
#define	pAchievement29x         122
#define	pAchievement30x         123
#define	pAchievement31x         124
#define	pAchievement32x         125
#define	pAchievement33x         126
#define	pAchievement34x         127
#define	pAchievement35x         128
#define	pAchievement36x         129
#define	pAchievement37x         130
#define	pAchievement38x         131
#define	pAchievement39x         132
#define	pAchievement40x         133
#define	pPointsx                134
#define	pTrialx                 135
#define	pWantedx                136
#define	pSpawnChangex           137
#define	pBoostx                 138
#define	pIPx                    139
#define	pBoxingSkillx           140
#define	pKarateSkillx           141
#define	pBoxFightStylex         142
#define	pGrabkickSkillx         143
#define	pFSpawnx                144
#define	pStylex                 145
#define	pFwarnx                 146
#define	pPunishx                147
#define	pTowx                   148
#define	pRobbedHousex           149
#define	pCombinax               150
#define	pMAXerDayx              151
#define	pMAXerMonthx            152
#define	pMAXerYearx             153
#define	pLastLoginx             154
#define	pMarriedTox             155
#define pGPSx                   156

#define vCariDx 				1
#define vColor1x 				2
#define vColor2x 				3
#define vPricex 				4
#define vOwnerx 				5
#define vPosXx 					6
#define vPosYx 					7
#define vPosZx 					8
#define vPosAx	 				9
#define vPlatex 				10
#define vPaintJx 				11
#define vLockedx 				12
#define vTowedx 				13
#define vModsx 					14

#define hIDx                    1
#define hPosXx                  2
#define hPosYx                  3
#define hPosZx                  4
#define hPosX1x                 5
#define hPosY1x                 6
#define hPosZ1x                 7
#define hNamex                  8
#define hOwnerx                 9
#define hLocationx              10
#define hPasswordx              11
#define hValuex                 12
#define hStoragex               13
#define hWorldx                 14
#define hIntx             		15
#define hDogx                   16
#define hPrivacyx               17
#define hUpgradeLockx           18
#define hForSalex               19
#define hPricex                 20
#define hLockx                  21
#define hLevelx                 22
#define hProtection1x           23
#define hProtection2x           24
#define hProtection3x           25

#define OwnedVeh(%0) 		ivCreated[%0]
#define MAX_BUYABLE_VEH 	1500  // Change to the ammount of vehicles
#define MAX_VEH_MODS 		12  // Max mods ( Do not edit )
#define MAX_OWNABLE_VEH     3	// Change to the ammount of vehicles a player can own!

enum _VINFO
{
	vCariD,
	vModel,
	vColor1,
	vColor2,
	vPrice,
	vOwner[MAX_PLAYER_NAME],
	Float:vPosX,
	Float:vPosY,
	Float:vPosZ,
	Float:vPosA,
	vPlate[32],
	vPaintJ,
	vLocked,
	vTowed
}
new
	vInfo[MAX_BUYABLE_VEH][_VINFO],
	ivCreated[MAX_VEHICLES],
	Total_Veh_Created,
	Total_House_Created,
	vMods[MAX_BUYABLE_VEH][2000],
	Total_Player_Vehicles[MAX_PLAYERS];
	
enum hInfo
{
	hID,
	Float:hPosX,
	Float:hPosY,
	Float:hPosZ,
	Float:hPosX1,
	Float:hPosY1,
	Float:hPosZ1,
	//Float:hPosA,
	hName[100],
	hOwner[MAX_PLAYER_NAME],
	hLocation[30],
	hPassword[15],
	hCreator,
	hValue,
	hStorage,
	hWorld,
	hInt,
	//hSInt,
	hDog,
	hCamera,
	hPrivacy,
	hUpgradeLock,
	hForSale,
	hPrice,
	hLock,
	hLevel,
	hOwned,
	hProtection1,
	hProtection2,
	hProtection3
};

new HouseInfo[MAX_HOUSES][hInfo];

enum pInfo
{
	pRoadblock,pRadar,pTiredFromGym,pPunish,pTiredFromGrabkick,pTiredFromKarate,pKey[128],pLevel,pAdmin,pDonateRank,
	gPupgrade,pConnectTime,pReg,pSex,pAge,pOrigin[30],pGymEquiped,pKarateEquiped,pBoxFightStyle,pCK,pMuted,pExp,pCash,
	pAccount,pCrimes,pKills,pDeaths,pArrested,pWantedDeaths,pPhoneBook,pLottoNr,pFishes,pBiggestFish,pJob,pPayCheck,
	pHeadValue,pJailed,pJailTime,pMats,pDrugs,pTow,pLeader,pMember,pFMember,pRank,pChar,pContractTime,pDetSkill,pSexSkill,
	pBoxSkill,pLawSkill,pBoxingSkill,pGrabkickSkill,pKarateSkill,pMechSkill,pJackSkill,pCarSkill,
	pNewsSkill,pDrugsSkill,pCookSkill,pFishSkill,pDMVCar,Float:pHealth,Float:pSHealth,pInt,pLocal,pTeam,pModel,pPnumber,
	pPhousekey,pPbiskey,Float:pPos_x,Float:pPos_y,Float:pPos_z,pCarLic,pFlyLic,pBoatLic,pFishLic,pGunLic,pGun1,pGun2,pGun3,
	pGun4,pAmmo1,pAmmo2,pAmmo3,pAmmo4,pCarTime,pPayDay,pPayDayHad,pCDPlayer,pWins,pLoses,pAlcoholPerk,pDrugPerk,pMiserPerk,
	pPainPerk,pTraderPerk,pTut,pMissionNr,pWarns,pAdjustable,pFuel,pMarried,pMarriedTo[128],LastLogin[128],pRobbingBank,
	pJob1,pAchievement1,pAchievement2,pAchievement3,pAchievement4,pAchievement5,pAchievement6,pAchievement7,pAchievement8,
	pAchievement9,pTrial,pNewbTimer,pGPPoints,pRPBoost,pIP[256],pCar1,pCar2,pCar3,pAchievement10,pAchievement11,pAchievement12,
	pAchievement13,pAchievement14,pAchievement15,pAchievement16,pAchievement17,pAchievement18,pAchievement19,pAchievement20,
	pAchievement21,pAchievement22,pAchievement23,pAchievement24,pAchievement25,pAchievement26,pAchievement27,pAchievement28,
	pAchievement29,pAchievement30,pAchievement31,pAchievement32,pAchievement33,pAchievement34,pAchievement35,pAchievement36,
	pAchievement37,pFwarn,pAchievement38,pAchievement39,pAchievement40,pStyle,pSQLID,pCombina,pSText[100],pGPS,pEmail[50]
};

new PlayerInfo[MAX_PLAYERS][pInfo];
new WantedLevel[MAX_PLAYERS];
new SpawnChange[MAX_PLAYERS];
new FSpawn[MAX_PLAYERS];
new RobbedHouse[MAX_PLAYERS];
new MAXerDay[MAX_PLAYERS], MAXerMonth[MAX_PLAYERS], MAXerYear[MAX_PLAYERS];

public vUpdate(vehicleid, type)
{
	new var[100];
	switch(type)
	{
	    case vCariDx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `CarID`='%d' WHERE `CarID`='%d'",vInfo[vehicleid][vCariD],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vColor1x:
	    {
	        format(var,100,"UPDATE `vehicles` SET `Color1`='%d' WHERE `CarID`='%d'",vInfo[vehicleid][vColor1],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vColor2x:
	    {
	        format(var,100,"UPDATE `vehicles` SET `Color2`='%d' WHERE `CarID`='%d'",vInfo[vehicleid][vColor2],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vPricex:
	    {
	        format(var,100,"UPDATE `vehicles` SET `Price`='%d' WHERE `CarID`='%d'",vInfo[vehicleid][vPrice],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vOwnerx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `Owner`='%s' WHERE `CarID`='%d'",vInfo[vehicleid][vOwner],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vPosXx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `vPosX`='%.2f' WHERE `CarID`='%d'",vInfo[vehicleid][vPosX],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vPosYx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `vPosY`='%.2f' WHERE `CarID`='%d'",vInfo[vehicleid][vPosY],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vPosZx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `vPosZ`='%.2f' WHERE `CarID`='%d'",vInfo[vehicleid][vPosZ],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vPosAx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `vPosA`='%.2f' WHERE `CarID`='%d'",vInfo[vehicleid][vPosA],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vPlatex:
	    {
	        format(var,100,"UPDATE `vehicles` SET `Plate`='%s' WHERE `CarID`='%d'",vInfo[vehicleid][vPlate],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vPaintJx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `PaintJ`='%d' WHERE `CarID`='%d'",vInfo[vehicleid][vPaintJ],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vLockedx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `Locked`='%d' WHERE `CarID`='%d'",vInfo[vehicleid][vLocked],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vTowedx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `Towed`='%d' WHERE `CarID`='%d'",vInfo[vehicleid][vTowed],vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	    case vModsx:
	    {
	        format(var,100,"UPDATE `vehicles` SET `vMod1`='%d',`vMod2`='%d',`vMod3`='%d',`vMod4`='%d',`vMod5`='%d',`vMod6`='%d',`vMod7`='%d',`vMod8`='%d',`vMod9`='%d',`vMod10`='%d',`vMod11`='%d',`vMod12`='%d' WHERE `CarID`='%d'",
			vMods[vehicleid][0],
			vMods[vehicleid][1],
			vMods[vehicleid][2],
			vMods[vehicleid][3],
			vMods[vehicleid][4],
			vMods[vehicleid][5],
			vMods[vehicleid][6],
			vMods[vehicleid][7],
			vMods[vehicleid][8],
			vMods[vehicleid][9],
			vMods[vehicleid][10],
			vMods[vehicleid][11],
			vInfo[vehicleid][vCariD]);
			mysql_query(var);
	    }
	}
	return 1;
}

public hUpdate(houseid, type)
{
	new var[100];
	switch(type)
	{
	    case hIDx:
	    {
	        format(var,100,"UPDATE `houses` SET `hID`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hID],houseid);
			mysql_query(var);
	    }
	    case hPosXx:
	    {
	        format(var,100,"UPDATE `houses` SET `PosX`='%f' WHERE `hID`='%d'",HouseInfo[houseid][hPosX],houseid);
			mysql_query(var);
	    }
	    case hPosYx:
	    {
	        format(var,100,"UPDATE `houses` SET `PosY`='%f' WHERE `hID`='%d'",HouseInfo[houseid][hPosY],houseid);
			mysql_query(var);
	    }
	    case hPosZx:
	    {
	        format(var,100,"UPDATE `houses` SET `PosZ`='%f' WHERE `hID`='%d'",HouseInfo[houseid][hPosZ],houseid);
			mysql_query(var);
	    }
	    case hPosX1x:
	    {
	        format(var,100,"UPDATE `houses` SET `PosX1`='%f' WHERE `hID`='%d'",HouseInfo[houseid][hPosX1],houseid);
			mysql_query(var);
	    }
	    case hPosY1x:
	    {
	        format(var,100,"UPDATE `houses` SET `PosY1`='%f' WHERE `hID`='%d'",HouseInfo[houseid][hPosY1],houseid);
			mysql_query(var);
	    }
	    case hPosZ1x:
	    {
	        format(var,100,"UPDATE `houses` SET `PosZ1`='%f' WHERE `hID`='%d'",HouseInfo[houseid][hPosZ1],houseid);
			mysql_query(var);
	    }
	    case hNamex:
	    {
	        format(var,100,"UPDATE `houses` SET `Name`='%s' WHERE `hID`='%d'",HouseInfo[houseid][hName],houseid);
			mysql_query(var);
	    }
	    case hOwnerx:
	    {
	        format(var,100,"UPDATE `houses` SET `Owner`='%s' WHERE `hID`='%d'",HouseInfo[houseid][hOwner],houseid);
			mysql_query(var);
	    }
	    case hLocationx:
	    {
	        format(var,100,"UPDATE `houses` SET `Location`='%s' WHERE `hID`='%d'",HouseInfo[houseid][hLocation],houseid);
			mysql_query(var);
	    }
	    case hPasswordx:
	    {
	        format(var,100,"UPDATE `houses` SET `Password`='%s' WHERE `hID`='%d'",HouseInfo[houseid][hPassword],houseid);
			mysql_query(var);
	    }
	    case hValuex:
	    {
	        format(var,100,"UPDATE `houses` SET `Value`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hValue],houseid);
			mysql_query(var);
	    }
	    case hStoragex:
	    {
	        format(var,100,"UPDATE `houses` SET `Storage`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hStorage],houseid);
			mysql_query(var);
	    }
	    case hWorldx:
	    {
	        format(var,100,"UPDATE `houses` SET `World`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hWorld],houseid);
			mysql_query(var);
	    }
	    case hIntx:
	    {
	        format(var,100,"UPDATE `houses` SET `Interior`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hInt],houseid);
			mysql_query(var);
	    }
	    case hDogx:
	    {
	        format(var,100,"UPDATE `houses` SET `Dog`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hDog],houseid);
			mysql_query(var);
	    }
	    case hPrivacyx:
	    {
	        format(var,100,"UPDATE `houses` SET `Privacy`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hPrivacy],houseid);
			mysql_query(var);
	    }
        case hUpgradeLockx:
	    {
	        format(var,100,"UPDATE `houses` SET `UpgradeLock`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hUpgradeLock],houseid);
			mysql_query(var);
	    }
	    case hForSalex:
	    {
	        format(var,100,"UPDATE `houses` SET `ForSale`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hForSale],houseid);
			mysql_query(var);
	    }
	    case hPricex:
	    {
	        format(var,100,"UPDATE `houses` SET `Price`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hPrice],houseid);
			mysql_query(var);
	    }
	    case hLockx:
	    {
	        format(var,100,"UPDATE `houses` SET `Lock`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hLock],houseid);
			mysql_query(var);
	    }
	    case hLevelx:
	    {
	        format(var,100,"UPDATE `houses` SET `Level`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hLevel],houseid);
			mysql_query(var);
	    }
	    case hProtection1x:
	    {
	        format(var,100,"UPDATE `houses` SET `Alarma`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hProtection1],houseid);
			mysql_query(var);
	    }
        case hProtection2x:
	    {
	        format(var,100,"UPDATE `houses` SET `Camera`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hProtection2],houseid);
			mysql_query(var);
	    }
	    case hProtection3x:
	    {
	        format(var,100,"UPDATE `houses` SET `Caine`='%d' WHERE `hID`='%d'",HouseInfo[houseid][hProtection3],houseid);
			mysql_query(var);
	    }
	}
	return 1;
}

/*vCariD,
	vModel,
	vColor1,
	vColor2,
	vPrice,
	vOwner[MAX_PLAYER_NAME],
	Float:vPosX,
	Float:vPosY,
	Float:vPosZ,
	Float:vPosA,
	vPlate[32],
	vPaintJ,
	vLocked,
	vTowed*/

public Update(playerid,type)
{
	if(IsPlayerConnected(playerid))
	{
		new var[100];new playerName[MAX_PLAYER_NAME];
		GetPlayerName(playerid, playerName, sizeof(playerName));
		{
			switch(type)
			{
				case pLevelx:
				{
					format(var,100,"UPDATE `players` SET `Level`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pLevel],playerName);
					mysql_query(var);
				}
				case pAdminLevelx:
				{
					format(var,100,"UPDATE `players` SET `AdminLevel`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAdmin],playerName);
					mysql_query(var);
				}
				case pDonateRankx:
				{
					format(var,100,"UPDATE `players` SET `DonateRank`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pDonateRank],playerName);
					mysql_query(var);
				}
				case pUpgradePointsx:
				{
					format(var,100,"UPDATE `players` SET `UpgradePoints`='%d' WHERE `username`='%s'",PlayerInfo[playerid][gPupgrade],playerName);
					mysql_query(var);
				}
				case pConnectedTimex:
				{
					format(var,100,"UPDATE `players` SET `ConnectedTime`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pConnectTime],playerName);
					mysql_query(var);
				}
				case pRegisteredx:
				{
					format(var,100,"UPDATE `players` SET `Registered`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pReg],playerName);
					mysql_query(var);
				}
				case pSexx:
				{
					format(var,100,"UPDATE `players` SET `Sex`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pSex],playerName);
					mysql_query(var);
				}
				case pAgex:
				{
					format(var,100,"UPDATE `players` SET `Age`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAge],playerName);
					mysql_query(var);
				}
				case pOriginx:
				{
					format(var,100,"UPDATE `players` SET `Origin`='%s' WHERE `username`='%s'",PlayerInfo[playerid][pOrigin],playerName);
					mysql_query(var);
				}
				case pCKx:
				{
					format(var,100,"UPDATE `players` SET `CK`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCK],playerName);
					mysql_query(var);
				}
				case pMutedx:
				{
					format(var,100,"UPDATE `players` SET `Muted`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pMuted],playerName);
					mysql_query(var);
				}
				case pRespectx:
				{
					format(var,100,"UPDATE `players` SET `Respect`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pExp],playerName);
					mysql_query(var);
				}
				case pMoneyx:
				{
					format(var,100,"UPDATE `players` SET `Money`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCash],playerName);
					mysql_query(var);
				}
				case pBankx:
				{
					format(var,100,"UPDATE `players` SET `Bank`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAccount],playerName);
					mysql_query(var);
				}
				case pCrimesx:
				{
					format(var,100,"UPDATE `players` SET `Crimes`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCrimes],playerName);
					mysql_query(var);
				}
				case pKillsx:
				{
					format(var,100,"UPDATE `players` SET `Kills`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pKills],playerName);
					mysql_query(var);
				}
				case pDeathsx:
				{
					format(var,100,"UPDATE `players` SET `Deaths`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pDeaths],playerName);
					mysql_query(var);
				}
				case pArrestedx:
				{
					format(var,100,"UPDATE `players` SET `Arrested`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pArrested],playerName);
					mysql_query(var);
				}
				case pWantedDeathsx:
				{
					format(var,100,"UPDATE `players` SET `WantedDeaths`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pWantedDeaths],playerName);
					mysql_query(var);
				}
				case pPhonebookx:
				{
					format(var,100,"UPDATE `players` SET `Phonebook`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPhoneBook],playerName);
					mysql_query(var);
				}
				case pLottoNrx:
				{
					format(var,100,"UPDATE `players` SET `LottoNr`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pLottoNr],playerName);
					mysql_query(var);
				}
				case pFishesx:
				{
					format(var,100,"UPDATE `players` SET `Fishes`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pFishes],playerName);
					mysql_query(var);
				}
				case pBiggestFishx:
				{
					format(var,100,"UPDATE `players` SET `BiggestFish`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pBiggestFish],playerName);
					mysql_query(var);
				}
				case pJobx:
				{
					format(var,100,"UPDATE `players` SET `Job`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pJob],playerName);
					mysql_query(var);
				}
				case pJob1x:
				{
					format(var,100,"UPDATE `players` SET `Job1`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pJob1],playerName);
					mysql_query(var);
				}
				case pPayCheckx:
				{
					format(var,100,"UPDATE `players` SET `Paycheck`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPayDay],playerName);
					mysql_query(var);
				}
				case pHeadValuex:
				{
					format(var,100,"UPDATE `players` SET `HeadValue`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pHeadValue],playerName);
					mysql_query(var);
				}
				case pJailedx:
				{
					format(var,100,"UPDATE `players` SET `Jailed`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pJailed],playerName);
					mysql_query(var);
				}
				case pJailTimex:
				{
					format(var,100,"UPDATE `players` SET `JailTime`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pJailTime],playerName);
					mysql_query(var);
				}
				case pMaterialsx:
				{
					format(var,100,"UPDATE `players` SET `Materials`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pMats],playerName);
					mysql_query(var);
				}
				case pDrugsx:
				{
					format(var,100,"UPDATE `players` SET `Drugs`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pDrugs],playerName);
					mysql_query(var);
				}
				case pLeaderx:
				{
					format(var,100,"UPDATE `players` SET `Leader`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pLeader],playerName);
					mysql_query(var);
				}
				case pMemberx:
				{
					format(var,100,"UPDATE `players` SET `Member`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pMember],playerName);
					mysql_query(var);
				}
				case pFMemberx:
				{
					format(var,100,"UPDATE `players` SET `FMember`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pFMember],playerName);
					mysql_query(var);
				}
				case pRankx:
				{
					format(var,100,"UPDATE `players` SET `iRank`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pRank],playerName);
					mysql_query(var);
				}
				case pCharx:
				{
					format(var,100,"UPDATE `players` SET `iChar`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pChar],playerName);
					mysql_query(var);
				}
				case pContractTimex:
				{
					format(var,100,"UPDATE `players` SET `ContractTime`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pContractTime],playerName);
					mysql_query(var);
				}
				case pDetSkillx:
				{
					format(var,100,"UPDATE `players` SET `DetSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pDetSkill],playerName);
					mysql_query(var);
				}
				case pSexSkillx:
				{
					format(var,100,"UPDATE `players` SET `SexSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pSexSkill],playerName);
					mysql_query(var);
				}
				case pBoxSkillx:
				{
					format(var,100,"UPDATE `players` SET `BoxSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pBoxSkill],playerName);
					mysql_query(var);
				}
				#define PlayerInfo[%0][pHotdog] PlayerInfo[%0][pAdmin]
				case pLawSkillx:
				{
					format(var,100,"UPDATE `players` SET `LawSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pLawSkill],playerName);
					mysql_query(var);
				}
				case pMechSkillx:
				{
					format(var,100,"UPDATE `players` SET `MechSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pMechSkill],playerName);
					mysql_query(var);
				}
				case pJackSkillx:
				{
					format(var,100,"UPDATE `players` SET `JackSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pJackSkill],playerName);
					mysql_query(var);
				}
				case pCarSkillx:
				{
					format(var,100,"UPDATE `players` SET `CarSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCarSkill],playerName);
					mysql_query(var);
				}
				case pNewsSkillx:
				{
					format(var,100,"UPDATE `players` SET `NewsSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pNewsSkill],playerName);
					mysql_query(var);
				}
				case pDrugsSkillx:
				{
					format(var,100,"UPDATE `players` SET `DrugsSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pDrugsSkill],playerName);
					mysql_query(var);
				}
				case pCookSkillx:
				{
					format(var,100,"UPDATE `players` SET `CookSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCookSkill],playerName);
					mysql_query(var);
				}
				case pFishSkillx:
				{
					format(var,100,"UPDATE `players` SET `FishSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pFishSkill],playerName);
					mysql_query(var);
				}
				case pSHealthx:
				{
					format(var,100,"UPDATE `players` SET `pSHealth`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pSHealth],playerName);
					mysql_query(var);
				}
				case pHealthx:
				{
					format(var,100,"UPDATE `players` SET `pHealth`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pHealth],playerName);
					mysql_query(var);
				}
				case pIntx:
				{
					format(var,100,"UPDATE `players` SET `iInt`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pInt],playerName);
					mysql_query(var);
				}
				case pLocalx:
				{
					format(var,100,"UPDATE `players` SET `iLocal`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pLocal],playerName);
					mysql_query(var);
				}
				case pTeamx:
				{
					format(var,100,"UPDATE `players` SET `Team`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pTeam],playerName);
					mysql_query(var);
				}
				case pModelx:
				{
					format(var,100,"UPDATE `players` SET `Model`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pModel],playerName);
					mysql_query(var);
				}
				case pPhoneNrx:
				{
					format(var,100,"UPDATE `players` SET `PhoneNr`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPnumber],playerName);
					mysql_query(var);
				}
				case pHousex:
				{
					format(var,100,"UPDATE `players` SET `House`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPhousekey],playerName);
					mysql_query(var);
				}
				case pBizzx:
				{
					format(var,100,"UPDATE `players` SET `Bizz`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPbiskey],playerName);
					mysql_query(var);
				}
				case pPos_xx:
				{
					format(var,100,"UPDATE `players` SET `Pos_x`='%f' WHERE `username`='%s'",PlayerInfo[playerid][pPos_x],playerName);
					mysql_query(var);
				}
				case pPos_yx:
				{
					format(var,100,"UPDATE `players` SET `Pos_y`='%f' WHERE `username`='%s'",PlayerInfo[playerid][pPos_y],playerName);
					mysql_query(var);
				}
				case pPos_zx:
				{
					format(var,100,"UPDATE `players` SET `Pos_z`='%f' WHERE `username`='%s'",PlayerInfo[playerid][pPos_z],playerName);
					mysql_query(var);
				}
				case pCarLicx:
				{
					format(var,100,"UPDATE `players` SET `CarLic`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCarLic],playerName);
					mysql_query(var);
				}
				case pFlyLicx:
				{
					format(var,100,"UPDATE `players` SET `FlyLic`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pFlyLic],playerName);
					mysql_query(var);
				}
				case pBoatLicx:
				{
					format(var,100,"UPDATE `players` SET `BoatLic`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pBoatLic],playerName);
					mysql_query(var);
				}
				case pFishLicx:
				{
					format(var,100,"UPDATE `players` SET `FishLic`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pFishLic],playerName);
					mysql_query(var);
				}
				case pGunLicx:
				{
					format(var,100,"UPDATE `players` SET `GunLic`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGunLic],playerName);
					mysql_query(var);
				}
				case pGun1x:
				{
					format(var,100,"UPDATE `players` SET `Gun1`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGun1],playerName);
					mysql_query(var);
				}
				case pGun2x:
				{
					format(var,100,"UPDATE `players` SET `Gun2`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGun2],playerName);
					mysql_query(var);
				}
				case pGun3x:
				{
					format(var,100,"UPDATE `players` SET `Gun3`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGun3],playerName);
					mysql_query(var);
				}
				case pGun4x:
				{
					format(var,100,"UPDATE `players` SET `Gun4`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGun4],playerName);
					mysql_query(var);
				}
				case pAmmo1x:
				{
					format(var,100,"UPDATE `players` SET `Ammo1`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAmmo1],playerName);
					mysql_query(var);
				}
				case pAmmo2x:
				{
					format(var,100,"UPDATE `players` SET `Ammo2`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAmmo2],playerName);
					mysql_query(var);
				}
				case pAmmo3x:
				{
					format(var,100,"UPDATE `players` SET `Ammo3`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAmmo3],playerName);
					mysql_query(var);
				}
				case pAmmo4x:
				{
					format(var,100,"UPDATE `players` SET `Ammo4`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAmmo4],playerName);
					mysql_query(var);
				}
				case pCarTimex:
				{
					format(var,100,"UPDATE `players` SET `CarTime`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCarTime],playerName);
					mysql_query(var);
				}
				case pPayDayx:
				{
					format(var,100,"UPDATE `players` SET `PayDay`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPayDay],playerName);
					mysql_query(var);
				}
				case pPayDayHadx:
				{
					format(var,100,"UPDATE `players` SET `PayDayHad`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPayDayHad],playerName);
					mysql_query(var);
				}
				case pCDPlayerx:
				{
					format(var,100,"UPDATE `players` SET `CDPlayer`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCDPlayer],playerName);
					mysql_query(var);
				}
				case pWinsx:
				{
					format(var,100,"UPDATE `players` SET `Wins`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pWins],playerName);
					mysql_query(var);
				}
				case pLosesx:
				{
					format(var,100,"UPDATE `players` SET `Loses`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pLoses],playerName);
					mysql_query(var);
				}
				case pAlcoholPerkx:
				{
					format(var,100,"UPDATE `players` SET `AlcoholPerk`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAlcoholPerk],playerName);
					mysql_query(var);
				}
				case pDrugPerkx:
				{
					format(var,100,"UPDATE `players` SET `DrugPerk`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pDrugPerk],playerName);
					mysql_query(var);
				}
				case pMiserPerkx:
				{
					format(var,100,"UPDATE `players` SET `MiserPerk`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pMiserPerk],playerName);
					mysql_query(var);
				}
				case pPainPerkx:
				{
					format(var,100,"UPDATE `players` SET `PainPerk`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPainPerk],playerName);
					mysql_query(var);
				}
				case pTraderPerkx:
				{
					format(var,100,"UPDATE `players` SET `TraderPerk`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pTraderPerk],playerName);
					mysql_query(var);
				}
				case pTutorialx:
				{
					format(var,100,"UPDATE `players` SET `Tutorial`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pTut],playerName);
					mysql_query(var);
				}
				case pMissionx:
				{
					format(var,100,"UPDATE `players` SET `Mission`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pMissionNr],playerName);
					mysql_query(var);
				}
				case pWarningsx:
				{
					format(var,100,"UPDATE `players` SET `Warnings`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pWarns],playerName);
					mysql_query(var);
				}
				case pAdjustablex:
				{
					format(var,100,"UPDATE `players` SET `Adjustable`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAdjustable],playerName);
					mysql_query(var);
				}
				case pFuelx:
				{
					format(var,100,"UPDATE `players` SET `Fuel`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pFuel],playerName);
					mysql_query(var);
				}
				case pMarriedx:
				{
					format(var,100,"UPDATE `players` SET `Married`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pMarried],playerName);
					mysql_query(var);
				}
				case pCar1x:
				{
					format(var,100,"UPDATE `players` SET `Car1`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCar1],playerName);
					mysql_query(var);
				}
				case pCar2x:
				{
					format(var,100,"UPDATE `players` SET `Car2`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCar2],playerName);
					mysql_query(var);
				}
				case pCar3x:
				{
					format(var,100,"UPDATE `players` SET `Car3`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCar3],playerName);
					mysql_query(var);
				}
				case 94 .. 133:
				{
				    new achvar[200];
				    format(achvar, sizeof(achvar), "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
				    PlayerInfo[playerid][pAchievement1],
				    PlayerInfo[playerid][pAchievement2],
				    PlayerInfo[playerid][pAchievement3],
				    PlayerInfo[playerid][pAchievement4],
				    PlayerInfo[playerid][pAchievement5],
				    PlayerInfo[playerid][pAchievement6],
				    PlayerInfo[playerid][pAchievement7],
				    PlayerInfo[playerid][pAchievement8],
				    PlayerInfo[playerid][pAchievement9],
				    PlayerInfo[playerid][pAchievement10],
				    PlayerInfo[playerid][pAchievement11],
				    PlayerInfo[playerid][pAchievement12],
				    PlayerInfo[playerid][pAchievement13],
				    PlayerInfo[playerid][pAchievement14],
				    PlayerInfo[playerid][pAchievement15],
				    PlayerInfo[playerid][pAchievement16],
				    PlayerInfo[playerid][pAchievement17],
				    PlayerInfo[playerid][pAchievement18],
				    PlayerInfo[playerid][pAchievement19],
				    PlayerInfo[playerid][pAchievement20],
				    PlayerInfo[playerid][pAchievement21],
				    PlayerInfo[playerid][pAchievement22],
				    PlayerInfo[playerid][pAchievement23],
				    PlayerInfo[playerid][pAchievement24],
				    PlayerInfo[playerid][pAchievement25],
				    PlayerInfo[playerid][pAchievement26],
				    PlayerInfo[playerid][pAchievement27],
				    PlayerInfo[playerid][pAchievement28],
				    PlayerInfo[playerid][pAchievement29],
				    PlayerInfo[playerid][pAchievement30],
				    PlayerInfo[playerid][pAchievement31],
				    PlayerInfo[playerid][pAchievement32],
				    PlayerInfo[playerid][pAchievement33],
				    PlayerInfo[playerid][pAchievement34],
				    PlayerInfo[playerid][pAchievement35],
				    PlayerInfo[playerid][pAchievement36],
				    PlayerInfo[playerid][pAchievement37],
				    PlayerInfo[playerid][pAchievement38],
				    PlayerInfo[playerid][pAchievement39],
				    PlayerInfo[playerid][pAchievement40]);
				    
				    //achvarr = strval(achvar);
				    
				    new varf[200];
					format(varf,200,"UPDATE `players` SET `AchievementF`='%s' WHERE `username`='%s'",achvar,playerName);
					mysql_query(varf);
				}
				/*case pAchievement3x:
				{
					format(var,100,"UPDATE `players` SET `Achievement3`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement3],playerName);
					mysql_query(var);
				}
				case pAchievement2x:
				{
					format(var,100,"UPDATE `players` SET `Achievement2`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement2],playerName);
					mysql_query(var);
				}
				case pAchievement4x:
				{
					format(var,100,"UPDATE `players` SET `Achievement4`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement4],playerName);
					mysql_query(var);
				}
				case pAchievement5x:
				{
					format(var,100,"UPDATE `players` SET `Achievement5`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement5],playerName);
					mysql_query(var);
				}
				case pAchievement6x:
				{
					format(var,100,"UPDATE `players` SET `Achievement6`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement6],playerName);
					mysql_query(var);
				}
				case pAchievement7x:
				{
					format(var,100,"UPDATE `players` SET `Achievement7`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement7],playerName);
					mysql_query(var);
				}
				case pAchievement8x:
				{
					format(var,100,"UPDATE `players` SET `Achievement8`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement8],playerName);
					mysql_query(var);
				}
				case pAchievement9x:
				{
					format(var,100,"UPDATE `players` SET `Achievement9`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement9],playerName);
					mysql_query(var);
				}
				case pAchievement10x:
				{
					format(var,100,"UPDATE `players` SET `Achievement10`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement10],playerName);
					mysql_query(var);
				}
				case pAchievement11x:
				{
					format(var,100,"UPDATE `players` SET `Achievement11`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement11],playerName);
					mysql_query(var);
				}
				case pAchievement12x:
				{
					format(var,100,"UPDATE `players` SET `Achievement12`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement12],playerName);
					mysql_query(var);
				}
				case pAchievement13x:
				{
					format(var,100,"UPDATE `players` SET `Achievement13`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement13],playerName);
					mysql_query(var);
				}
				case pAchievement14x:
				{
					format(var,100,"UPDATE `players` SET `Achievement14`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement14],playerName);
					mysql_query(var);
				}
				case pAchievement15x:
				{
					format(var,100,"UPDATE `players` SET `Achievement15`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement15],playerName);
					mysql_query(var);
				}
				case pAchievement16x:
				{
					format(var,100,"UPDATE `players` SET `Achievement16`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement16],playerName);
					mysql_query(var);
				}
				case pAchievement17x:
				{
					format(var,100,"UPDATE `players` SET `Achievement17`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement17],playerName);
					mysql_query(var);
				}
				case pAchievement18x:
				{
					format(var,100,"UPDATE `players` SET `Achievement18`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement18],playerName);
					mysql_query(var);
				}
				case pAchievement19x:
				{
					format(var,100,"UPDATE `players` SET `Achievement19`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement19],playerName);
					mysql_query(var);
				}
				case pAchievement20x:
				{
					format(var,100,"UPDATE `players` SET `Achievement20`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement20],playerName);
					mysql_query(var);
				}
				case pAchievement21x:
				{
					format(var,100,"UPDATE `players` SET `Achievement21`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement21],playerName);
					mysql_query(var);
				}
				case pAchievement22x:
				{
					format(var,100,"UPDATE `players` SET `Achievement22`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement22],playerName);
					mysql_query(var);
				}
				case pAchievement23x:
				{
					format(var,100,"UPDATE `players` SET `Achievement23`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement23],playerName);
					mysql_query(var);
				}
				case pAchievement24x:
				{
					format(var,100,"UPDATE `players` SET `Achievement24`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement24],playerName);
					mysql_query(var);
				}
				case pAchievement25x:
				{
					format(var,100,"UPDATE `players` SET `Achievement25`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement25],playerName);
					mysql_query(var);
				}
				case pAchievement26x:
				{
					format(var,100,"UPDATE `players` SET `Achievement26`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement26],playerName);
					mysql_query(var);
				}
				case pAchievement27x:
				{
					format(var,100,"UPDATE `players` SET `Achievement27`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement27],playerName);
					mysql_query(var);
				}
				case pAchievement28x:
				{
					format(var,100,"UPDATE `players` SET `Achievement28`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement28],playerName);
					mysql_query(var);
				}
				case pAchievement29x:
				{
					format(var,100,"UPDATE `players` SET `Achievement29`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement29],playerName);
					mysql_query(var);
				}
				case pAchievement30x:
				{
					format(var,100,"UPDATE `players` SET `Achievement30`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement30],playerName);
					mysql_query(var);
				}
				case pAchievement31x:
				{
					format(var,100,"UPDATE `players` SET `Achievement31`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement31],playerName);
					mysql_query(var);
				}
				case pAchievement32x:
				{
					format(var,100,"UPDATE `players` SET `Achievement32`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement32],playerName);
					mysql_query(var);
				}
				case pAchievement33x:
				{
					format(var,100,"UPDATE `players` SET `Achievement33`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement33],playerName);
					mysql_query(var);
				}
				case pAchievement34x:
				{
					format(var,100,"UPDATE `players` SET `Achievement34`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement34],playerName);
					mysql_query(var);
				}
				case pAchievement35x:
				{
					format(var,100,"UPDATE `players` SET `Achievement35`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement35],playerName);
					mysql_query(var);
				}
				case pAchievement36x:
				{
					format(var,100,"UPDATE `players` SET `Achievement36`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement36],playerName);
					mysql_query(var);
				}
				case pAchievement37x:
				{
					format(var,100,"UPDATE `players` SET `Achievement37`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement37],playerName);
					mysql_query(var);
				}
				case pAchievement38x:
				{
					format(var,100,"UPDATE `players` SET `Achievement38`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement38],playerName);
					mysql_query(var);
				}
				case pAchievement39x:
				{
					format(var,100,"UPDATE `players` SET `Achievement39`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement39],playerName);
					mysql_query(var);
				}
				case pAchievement40x:
				{
					format(var,100,"UPDATE `players` SET `Achievement40`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pAchievement40],playerName);
					mysql_query(var);
				}*/
				case pPointsx:
				{
					format(var,100,"UPDATE `players` SET `Points`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGPPoints],playerName);
					mysql_query(var);
				}
				case pTrialx:
				{
					format(var,100,"UPDATE `players` SET `Trial`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pTrial],playerName);
					mysql_query(var);
				}
				case pWantedx:
				{
					format(var,100,"UPDATE `players` SET `Wanted`='%d' WHERE `username`='%s'",WantedLevel[playerid],playerName);
					mysql_query(var);
				}
				case pSpawnChangex:
				{
					format(var,100,"UPDATE `players` SET `SpawnChange`='%d' WHERE `username`='%s'",SpawnChange[playerid],playerName);
					mysql_query(var);
				}
				case pBoostx:
				{
					format(var,100,"UPDATE `players` SET `Boost`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pRPBoost],playerName);
					mysql_query(var);
				}
				case pIPx:
				{
					format(var,100,"UPDATE `players` SET `IP`='%s' WHERE `username`='%s'",PlayerInfo[playerid][pIP],playerName);
					mysql_query(var);
				}
				case pBoxingSkillx:
				{
					format(var,100,"UPDATE `players` SET `BoxingSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pBoxingSkill],playerName);
					mysql_query(var);
				}
				case pKarateSkillx:
				{
					format(var,100,"UPDATE `players` SET `KarateSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pKarateSkill],playerName);
					mysql_query(var);
				}
				case pBoxFightStylex:
				{
					format(var,100,"UPDATE `players` SET `BoxFightStyle`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pBoxFightStyle],playerName);
					mysql_query(var);
				}
				case pGrabkickSkillx:
				{
					format(var,100,"UPDATE `players` SET `GrabkickSkill`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGrabkickSkill],playerName);
					mysql_query(var);
				}
				case pFSpawnx:
				{
					format(var,100,"UPDATE `players` SET `FSpawn`='%d' WHERE `username`='%s'",FSpawn[playerid],playerName);
					mysql_query(var);
				}
				case pStylex:
				{
					format(var,100,"UPDATE `players` SET `Style`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pStyle],playerName);
					mysql_query(var);
				}
				case pFwarnx:
				{
					format(var,100,"UPDATE `players` SET `Fwarn`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pFwarn],playerName);
					mysql_query(var);
				}
				case pPunishx:
				{
					format(var,100,"UPDATE `players` SET `Punish`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pPunish],playerName);
					mysql_query(var);
				}
				case pTowx:
				{
					format(var,100,"UPDATE `players` SET `Tow`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pTow],playerName);
					mysql_query(var);
				}
				case pRobbedHousex:
				{
					format(var,100,"UPDATE `players` SET `RobbedHouse`='%d' WHERE `username`='%s'",RobbedHouse[playerid],playerName);
					mysql_query(var);
				}
				case pCombinax:
				{
					format(var,100,"UPDATE `players` SET `Combina`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pCombina],playerName);
					mysql_query(var);
				}
				case pMAXerDayx:
				{
					format(var,100,"UPDATE `players` SET `MAXerDay`='%d' WHERE `username`='%s'",MAXerDay[playerid],playerName);
					mysql_query(var);
				}
				case pMAXerMonthx:
				{
					format(var,100,"UPDATE `players` SET `MAXerMonth`='%d' WHERE `username`='%s'",MAXerMonth[playerid],playerName);
					mysql_query(var);
				}
				case pMAXerYearx:
				{
					format(var,100,"UPDATE `players` SET `MAXerYear`='%d' WHERE `username`='%s'",MAXerYear[playerid],playerName);
					mysql_query(var);
				}
				case pLastLoginx:
				{
					format(var,100,"UPDATE `players` SET `LastLogin`= CURRENT_TIMESTAMP WHERE `username`='%s'",playerName);
					mysql_query(var);
				}
				case pMarriedTox:
				{
					format(var,100,"UPDATE `players` SET `MarriedTo`='%s' WHERE `username`='%s'",PlayerInfo[playerid][pMarriedTo],playerName);
					mysql_query(var);
				}
				case pGPSx:
				{
					format(var,100,"UPDATE `players` SET `GPS`='%d' WHERE `username`='%s'",PlayerInfo[playerid][pGPS],playerName);
					mysql_query(var);
				}
			}
		}
	}
	return 1;
}	

public OnPlayerDateUpdateX2(playerid)
{
	if(IsPlayerConnected(playerid))
	{
		new playerName[MAX_PLAYER_NAME];
		GetPlayerName(playerid, playerName, sizeof(playerName));
		{
			new var[350];
			format(var, 350, "UPDATE `players` SET `Paycheck`='%d',`JailTime`='%d',`iInt`='%d',`iLocal`='%d',`Team`='%d',`Muted`='%d', `CarTime`='%d', `Level`='%d', `Respect`='%d' WHERE `username`='%s'",
			PlayerInfo[playerid][pPayCheck],PlayerInfo[playerid][pJailTime],PlayerInfo[playerid][pInt],PlayerInfo[playerid][pLocal],PlayerInfo[playerid][pTeam],PlayerInfo[playerid][pMuted],PlayerInfo[playerid][pCarTime], PlayerInfo[playerid][pLevel], PlayerInfo[playerid][pExp], playerName);
			mysql_query(var);
		}
	}
	return 1;
}

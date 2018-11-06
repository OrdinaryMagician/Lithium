// This file was generated by wepc.
// Edit only if you aren't going to recompile.
#include "lith_upgrades_common.h"

// Extern Objects ------------------------------------------------------------|

upgradeinfo_t const upgrinfobase[UPGR_BASE_MAX] = {
   {{"HeadsUpDisp", "HeadsUpDisp", 0}, pM, UC_Body, 1, UG_HUD, 0, -.05, UPGR_HeadsUpDisp},
   {{"HeadsUpDis2", "HeadsUpDisp", 0}, pC, UC_Body, 1, UG_HUD, 0, -.05, UPGR_HeadsUpDis2},
   {{"HeadsUpDis3", "HeadsUpDisp", 0}, pD, UC_Body, 1, UG_HUD, 0, -.05, UPGR_HeadsUpDis3},
   {{"JetBooster", "JetBooster", 0}, pM, UC_Body, 0, 0, 0, -.05, UPGR_JetBooster},
   {{"ReflexWetw", "ReflexWetw", 0}, gO, UC_Body, 5, 0, 0, -.05, UPGR_ReflexWetw},
   {{"Zoom", null, 0}, gA, UC_Body, 0, 0, 0, 0, UPGR_Zoom},
   {{"VitalScan", "VitalScanner", 0}, gA, UC_Body, 2, 0, 0, 0, UPGR_VitalScan},
   {{"CyberLegs", "CyberLegs", 1220000}, pM, UC_Body, 4, 0, 0, 0, UPGR_CyberLegs},
   {{"ReactArmor", "Yh0", 3500200}, pM, UC_Body, 20, 0, UR_AI, 0, UPGR_ReactArmor},
   {{"ReactArmor2", "Yh0", 2990200}, pM, UC_Body, 10, 0, UR_AI|UR_RA, 0, UPGR_ReactArmor2},
   {{"DefenseNuke", "DefenseNuke", 580030}, pM, UC_Body, 0, 0, UR_AI, 0, UPGR_DefenseNuke},
   {{"Adrenaline", "Adrenaline", 1801000}, pM, UC_Body, 10, 0, 0, 0, UPGR_Adrenaline},
   {{"Magic", "Magic", 0}, pC, UC_Body, 0, 0, 0, 0, UPGR_Magic},
   {{"SoulCleaver", "SoulCleaver", 1100000}, pC, UC_Body, 0, 0, 0, 0, UPGR_SoulCleaver},
   {{"StealthSys", "StealthSys", 1800450}, pC, UC_Body, 0, 0, 0, 0, UPGR_StealthSys},
   {{"Subweapons", "Subweapons", 0}, pD, UC_Body, 0, 0, 0, 0, UPGR_Subweapons},
   {{"AutoReload", "AutoReload", 950050}, gO, UC_Weap, 2, 0, 0, 0, UPGR_AutoReload},
   {{"AutoPistol", null, 140940}, pM, UC_Weap, 0, 0, 0, 0, UPGR_AutoPistol},
   {{"PlasPistol", null, 340000}, pM, UC_Weap, 0, 0, UR_WMD, 0, UPGR_PlasPistol},
   {{"GaussShotty", "ShotgunUpgr", 1079430}, pM, UC_Weap, 1, UG_Shotgun, UR_WMD, 0, UPGR_GaussShotty},
   {{"PoisonShot", "ShotgunUpg2", 1010420}, pM, UC_Weap, 0, UG_Shotgun, UR_WMD, 0, UPGR_PoisonShot},
   {{"RifleModes", "RifleUpgr", 340100}, pM, UC_Weap, 0, 0, 0, 0, UPGR_RifleModes},
   {{"LaserRCW", "RifleUpg2", 1008080}, pM, UC_Weap, 1, 0, UR_WMD, 0, UPGR_LaserRCW},
   {{"ChargeRPG", "LauncherUpgr", 1550000}, pM, UC_Weap, 0, UG_Launcher, UR_WMD|UR_WRD, 0, UPGR_ChargeRPG},
   {{"HomingRPG", "LauncherUpg2", 2505010}, pM, UC_Weap, 1, UG_Launcher, UR_WMD, 0, UPGR_HomingRPG},
   {{"PlasLaser", "PlasmaUpgr", 2250000}, pM, UC_Weap, 0, UG_Plasma, UR_WMD, 0, UPGR_PlasLaser},
   {{"PartBeam", "PlasmaUpg2", 2500000}, pM, UC_Weap, 1, UG_Plasma, UR_WMD|UR_WRD, 0, UPGR_PartBeam},
   {{"PunctCannon", "CannonUpgr", 5100700}, pM, UC_Weap, 0, UG_BFG, UR_WMD, 0, UPGR_PunctCannon},
   {{"OmegaRail", "CannonUpg2", 5800100}, pM, UC_Weap, 5, UG_BFG, UR_WMD|UR_WRD, 0, UPGR_OmegaRail},
   {{"Mateba_A", "MatebaUpgr", 614100}, pC, UC_Weap, 0, UG_Pistol, 0, 0, UPGR_Mateba_A},
   {{"ShockRif_A", "ShockRifUpgr", 1519590}, pC, UC_Weap, 0, UG_Shotgun, 0, 0, UPGR_ShockRif_A},
   {{"ShockRif_B", "ShockRifUpg2", 1911590}, pC, UC_Weap, 0, UG_Shotgun, 0, 0, UPGR_ShockRif_B},
   {{"SPAS_A", "SPASUpgr", 2140400}, pC, UC_Weap, 0, UG_SSG, 0, 0, UPGR_SPAS_A},
   {{"SPAS_B", "SPASUpg2", 1511100}, pC, UC_Weap, 0, UG_SSG, 0, 0, UPGR_SPAS_B},
   {{"SMG_A", "SMGUpgr", 2055000}, pC, UC_Weap, 0, 0, 0, 0, UPGR_SMG_A},
   {{"SMG_B", "SMGUpg2", 2888000}, pC, UC_Weap, 0, 0, 0, 0, UPGR_SMG_B},
   {{"SMG_C", "SMGUpg3", 998900}, pC, UC_Weap, 0, 0, 0, 0, UPGR_SMG_C},
   {{"IonRifle_A", "IonRifleUpgr", 1977000}, pC, UC_Weap, 0, 0, 0, 0, UPGR_IonRifle_A},
   {{"IonRifle_B", "IonRifleUpg2", 2855050}, pC, UC_Weap, 0, 0, 0, 0, UPGR_IonRifle_B},
   {{"CPlasma_A", "CPlasmaUpgr", 2230500}, pC, UC_Weap, 0, UG_Plasma, 0, 0, UPGR_CPlasma_A},
   {{"ShipGun_A", "ShipGunUpgr", 6988800}, pC, UC_Weap, 0, UG_BFG, 0, 0, UPGR_ShipGun_A},
   {{"ShipGun_B", "ShipGunUpg2", 7767700}, pC, UC_Weap, 0, UG_BFG, 0, 0, UPGR_ShipGun_B},
   {{"TorgueMode", null, 8000000}, gA, UC_Extr, 8, 0, UR_RDI, 0, UPGR_TorgueMode},
   {{"7777777", null, 8235430}, gA, UC_Extr, 7, 0, UR_RDI, .10, UPGR_7777777},
   {{"lolsords", null, 1000000}, gA, UC_Extr, 0, 0, UR_RDI, .20, UPGR_lolsords},
   {{"Goldeneye", null, 70000}, gA, UC_Extr, 0, 0, UR_RDI, .07, UPGR_Goldeneye},
   {{"DarkCannon", null, 0x7FFFFFFF}, pM, UC_Extr, 0, UG_BFG, UR_WMD|UR_WRD|UR_RDI, 0, UPGR_DarkCannon},
   {{"Implying", null, 0}, gA, UC_Down, 0, 0, 0, .20, UPGR_Implying},
   {{"UNCEUNCE", null, 0}, gA, UC_Down, 0, 0, 0, .30, UPGR_UNCEUNCE},
   {{"InstaDeath", null, 0}, gA, UC_Down, 0, 0, 0, .50, UPGR_InstaDeath},
};

// EOF

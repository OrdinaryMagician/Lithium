/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * ACS string table.
 *
 * ---------------------------------------------------------------------------|
 */

#if defined(X)

/* Strings */
X(s_BOSS,          "BOSS")
X(s_COUNTKILL,     "COUNTKILL")
X(s_DROPPED,       "DROPPED")
X(s_F_SKY1,        "F_SKY1")
X(s_INVULNERABLE,  "INVULNERABLE")
X(s_LITHCAM1,      "LITHCAM1")
X(s_LITHCAM2,      "LITHCAM2")
X(s_LITHCAM3,      "LITHCAM3")
X(s_LITHEND,       "LITHEND")
X(s_LITHSKDE,      "LITHSKDE")
X(s_LITHSKRD,      "LITHSKRD")
X(s_LITHSKS1,      "LITHSKS1")
X(s_NIL,           "")
X(s_NODAMAGE,      "NODAMAGE")
X(s_None,          "None")
X(s_OBJ,           OBJ)
X(s_RLFormer,      "RLFormer")
X(s_SHADOW,        "SHADOW")
X(s_SOLID,         "SOLID")
X(s_alienfont,     "alienfont")
X(s_areaname,      "areaname")
X(s_bigupper,      "bigupper")
X(s_chfont,        "chfont")
X(s_cnfont,        "cnfont")
X(s_lhudfont,      "lhudfont")
X(s_lhudfontsmall, "lhudfontsmall")
X(s_logfont,       "logfont")
X(s_ltrmfont,      "ltrmfont")
X(s_ob_crush,      "(crush)")
X(s_ob_default,    "(default)")
X(s_ob_drowning,   "(drowning)")
X(s_ob_exit,       "(exit)")
X(s_ob_falling,    "(falling)")
X(s_ob_fire,       "(fire)")
X(s_ob_slime,      "(slime)")
X(s_ob_suicide,    "(suicide)")
X(s_smallfnt,      "smallfnt")

/* Console Variables */
X(sc_debug_all,              DCVAR "debug_all")
X(sc_debug_bip,              DCVAR "debug_bip")
X(sc_debug_items,            DCVAR "debug_items")
X(sc_debug_level,            DCVAR "debug_level")
X(sc_debug_nomonsters,       DCVAR "debug_nomonsters")
X(sc_debug_save,             DCVAR "debug_save")
X(sc_debug_score,            DCVAR "debug_score")
X(sc_debug_upgrades,         DCVAR "debug_upgrades")
X(sc_drla_is_using_monsters, "DRLA_is_using_monsters")
X(sc_game,                   DCVAR "game")
X(sc_gui_cursor,             CVAR "gui_cursor")
X(sc_gui_jpfont,             CVAR "gui_jpfont")
X(sc_gui_theme,              CVAR "gui_theme")
X(sc_gui_xmul,               CVAR "gui_xmul")
X(sc_gui_ymul,               CVAR "gui_ymul")
X(sc_hud_logbig,             CVAR "hud_logbig")
X(sc_hud_logfromtop,         CVAR "hud_logfromtop")
X(sc_hud_showarmorind,       CVAR "hud_showarmorind")
X(sc_hud_showlog,            CVAR "hud_showlog")
X(sc_hud_showlvl,            CVAR "hud_showlvl")
X(sc_hud_showscore,          CVAR "hud_showscore")
X(sc_hud_showweapons,        CVAR "hud_showweapons")
X(sc_invertmouse,            "invertmouse")
X(sc_k_opencbi,              CVAR "k_opencbi")
X(sc_player_altinvuln,       CVAR "player_altinvuln")
X(sc_player_ammolog,         CVAR "player_ammolog")
X(sc_player_bosstexts,       CVAR "player_bosstexts")
X(sc_player_brightweps,      CVAR "player_brightweps")
X(sc_player_damagebob,       CVAR "player_damagebob")
X(sc_player_damagebobmul,    CVAR "player_damagebobmul")
X(sc_player_footstepvol,     CVAR "player_footstepvol")
X(sc_player_invertmouse,     CVAR "player_invertmouse")
X(sc_player_lvsys,           CVAR "player_lvsys")
X(sc_player_noitemfx,        CVAR "player_noitemfx")
X(sc_player_rainshader,      CVAR "player_rainshader")
X(sc_player_resultssound,    CVAR "player_resultssound")
X(sc_player_scorelog,        CVAR "player_scorelog")
X(sc_player_scoresound,      CVAR "player_scoresound")
X(sc_player_stupidpickups,   CVAR "player_stupidpickups")
X(sc_player_teleshop,        CVAR "player_teleshop")
X(sc_player_viewtilt,        CVAR "player_viewtilt")
X(sc_psave,                  CVAR "psave")
X(sc_scanner_altfont,        CVAR "scanner_altfont")
X(sc_scanner_bar,            CVAR "scanner_bar")
X(sc_scanner_bar,            CVAR "scanner_bar")
X(sc_scanner_color,          CVAR "scanner_color")
X(sc_scanner_slide,          CVAR "scanner_slide")
X(sc_scanner_xoffs,          CVAR "scanner_xoffs")
X(sc_scanner_yoffs,          CVAR "scanner_yoffs")
X(sc_sv_autosave,            CVAR "sv_autosave")
X(sc_sv_cooploseinventory,   "sv_cooploseinventory")
X(sc_sv_difficulty,          CVAR "sv_difficulty")
X(sc_sv_failtime,            CVAR "sv_failtime")
X(sc_sv_nobossdrop,          CVAR "sv_nobossdrop")
X(sc_sv_nobosses,            CVAR "sv_nobosses")
X(sc_sv_nofullammo,          CVAR "sv_nofullammo")
X(sc_sv_nomonsters,          "sv_nomonsters")
X(sc_sv_noscoreammo,         CVAR "sv_noscoreammo")
X(sc_sv_pauseinmenus,        CVAR "sv_pauseinmenus")
X(sc_sv_rain,                CVAR "sv_rain")
X(sc_sv_revenge,             CVAR "sv_revenge")
X(sc_sv_scoremul,            CVAR "sv_scoremul")
X(sc_sv_sky,                 CVAR "sv_sky")
X(sc_sv_weaponstay,          "sv_weaponstay")
X(sc_sv_wepdrop,             CVAR "sv_wepdrop")
X(sc_version,                DCVAR "version")
X(sc_weapons_alpha,          CVAR "weapons_alpha")
X(sc_weapons_casingfadeout,  CVAR "weapons_casingfadeout")
X(sc_weapons_casings,        CVAR "weapons_casings")
X(sc_weapons_fastlazshot,    CVAR "weapons_fastlazshot")
X(sc_weapons_magdrops,       CVAR "weapons_magdrops")
X(sc_weapons_magfadeout,     CVAR "weapons_magfadeout")
X(sc_weapons_magicselanims,  CVAR "weapons_magicselanims")
X(sc_weapons_nofirebob,      CVAR "weapons_nofirebob")
X(sc_weapons_rainbowlaser,   CVAR "weapons_rainbowlaser")
X(sc_weapons_recoil,         CVAR "weapons_recoil")
X(sc_weapons_reloadbob,      CVAR "weapons_reloadbob")
X(sc_weapons_reloadempty,    CVAR "weapons_reloadempty")
X(sc_weapons_ricochetvol,    CVAR "weapons_ricochetvol")
X(sc_weapons_riflemodeclear, CVAR "weapons_riflemodeclear")
X(sc_weapons_riflescope,     CVAR "weapons_riflescope")
X(sc_weapons_scopealpha,     CVAR "weapons_scopealpha")
X(sc_weapons_slot3ammo,      CVAR "weapons_slot3ammo")
X(sc_weapons_zoomfactor,     CVAR "weapons_zoomfactor")
X(sc_xhair_a,                CVAR "xhair_a")
X(sc_xhair_b,                CVAR "xhair_b")
X(sc_xhair_enable,           CVAR "xhair_enable")
X(sc_xhair_enablejuicer,     CVAR "xhair_enablejuicer")
X(sc_xhair_g,                CVAR "xhair_g")
X(sc_xhair_r,                CVAR "xhair_r")
X(sc_xhair_style,            CVAR "xhair_style")

/* Inventory Types */
X(si_Armor,       "Armor")
X(si_SlottedItem, "SlottedItem")

/* Methods / Members */
X(sm_AdrenalineCheck,    "AdrenalineCheck")
X(sm_AutoReload,         "AutoReload")
X(sm_DelearSprite,       "DelearSprite")
X(sm_DeleteItem,         "DeleteItem")
X(sm_DmgFac,             "m_DmgFac")
X(sm_FindLump,           "FindLump")
X(sm_ForceDraw,          "ForceDraw")
X(sm_Fun,                "Fun")
X(sm_FxTID,              "m_FxTID")
X(sm_GetArmorDT,         "GetArmorDT")
X(sm_GetArmorSlot,       "GetArmorSlot")
X(sm_GetBossLevel,       "GetBossLevel")
X(sm_GetCurMag,          "GetCurMag")
X(sm_GetLogName,         "GetLogName")
X(sm_GetMaxMag,          "GetMaxMag")
X(sm_GetObituary,        "GetObituary")
X(sm_GetOutOfDodge,      "GetOutOfDodge")
X(sm_GetPaused,          "GetPaused")
X(sm_GetRifleGrenade,    "GetRifleGrenade")
X(sm_GetTex,             "GetTex")
X(sm_GetTexH,            "GetTexH")
X(sm_GetTexW,            "GetTexW")
X(sm_GivePoison,         "GivePoison")
X(sm_GrabInput,          "m_GrabInput")
X(sm_InfoPage,           "m_InfoPage")
X(sm_InvName,            "m_InvName")
X(sm_InvSell,            "m_InvSell")
X(sm_InvType,            "m_InvType")
X(sm_IonizeFX,           OBJ "IonizeFX")
X(sm_IsChex,             "IsChex")
X(sm_IsHeretic,          "IsHeretic")
X(sm_IsRampancy,         "IsRampancy")
X(sm_LC,                 "LC")
X(sm_LE,                 "LE")
X(sm_LF,                 "LF")
X(sm_LR,                 "LR")
X(sm_LS,                 "LS")
X(sm_LT,                 "LT")
X(sm_LX,                 "LX")
X(sm_LZ,                 "LZ")
X(sm_MapNoRain,          "user_Lith_NoRain")
X(sm_MapUseRain,         "user_Lith_UseRain")
X(sm_MonsterBarrierLook, "MonsterBarrierLook")
X(sm_OnGround,           "m_OnGround")
X(sm_Overdrive,          "m_Overdrive")
X(sm_PauseTick,          "PauseTick")
X(sm_PoisonFX,           "PoisonFX")
X(sm_PureSteggleEnergy,  "PureSteggleEnergy")
X(sm_ReadLump,           "ReadLump")
X(sm_Set,                "Set")
X(sm_SetEnding,          "SetEnding")
X(sm_SetPaused,          "SetPaused")
X(sm_SpawnBoss,          "SpawnBoss")
X(sm_SpawnRain,          "SpawnRain")
X(sm_StartSound,         "StartSound")
X(sm_Trigger,            "m_Trigger")
X(sm_TriggerBoss,        "TriggerBoss")
X(sm_UpgradeBody,        "user_UpgradeBody")
X(sm_UpgradeExtr,        "user_UpgradeExtr")
X(sm_UpgradeId,          "user_UpgradeId")
X(sm_UpgradeWeap,        "user_UpgradeWeap")
X(sm_UseItem,            "UseItem")
X(sm_UserX,              "user_X")
X(sm_UserY,              "user_Y")
X(sm_UserZ,              "user_Z")

/* Objects */
X(so_Alerter,                     OBJ "Alerter")
X(so_AssassinPlayer,              OBJ "AssassinPlayer")
X(so_BarrierFX,                   OBJ "BarrierFX")
X(so_Blade,                       OBJ "Blade")
X(so_BloodRainDrop,               OBJ "BloodRainDrop")
X(so_BlueCard,                    "BlueCard")
X(so_BlueSkull,                   "BlueSkull")
X(so_BossReward1,                 OBJ "BossReward1")
X(so_BossReward2,                 OBJ "BossReward2")
X(so_BossReward3,                 OBJ "BossReward3")
X(so_BossReward4,                 OBJ "BossReward4")
X(so_BossReward5,                 OBJ "BossReward5")
X(so_BossReward6,                 OBJ "BossReward6")
X(so_BoughtItem,                  OBJ "BoughtItem")
X(so_CameraHax,                   OBJ "CameraHax")
X(so_CannonAmmo,                  OBJ "CannonAmmo")
X(so_Cercle,                      OBJ "Cercle")
X(so_ChexBlueCard,                "ChexBlueCard")
X(so_ChexRedCard,                 "ChexRedCard")
X(so_ChexYellowCard,              "ChexYellowCard")
X(so_CircleParticle,              OBJ "CircleParticle")
X(so_CircleSpearThrower,          OBJ "CircleSpearThrower")
X(so_ClawOfImp,                   OBJ "ClawOfImp")
X(so_CyberMagePlayer,             OBJ "CyberMagePlayer")
X(so_DarkLordPlayer,              OBJ "DarkLordPlayer")
X(so_DeVileSix,                   "RLDeVileSix")
X(so_Death,                       OBJ "Death")
X(so_Delear,                      OBJ "Delear")
X(so_Die,                         OBJ "Die")
X(so_Dummy,                       OBJ "Dummy")
X(so_EXPLOOOSION,                 OBJ "EXPLOOOSION")
X(so_ExplodoBoots,                OBJ "ExplodoBoots")
X(so_Feuer,                       OBJ "Feuer")
X(so_FeuerExplosion,              OBJ "FeuerExplosion")
X(so_FeuerFinal,                  OBJ "FeuerFinal")
X(so_FeuerTest,                   OBJ "FeuerTest")
X(so_FistCharge,                  OBJ "FistCharge")
X(so_GEExplosion,                 OBJ "GEExplosion")
X(so_GTFO,                        OBJ "GTFO")
X(so_Hulgyon,                     OBJ "Hulgyon")
X(so_InformantPlayer,             OBJ "InformantPlayer")
X(so_Ionized,                     OBJ "Ionized")
X(so_IsPhantom,                   OBJ "IsPhantom")
X(so_KeyBlue,                     "KeyBlue")
X(so_KeyGreen,                    "KeyGreen")
X(so_KeyYellow,                   "KeyYellow")
X(so_LegendaryMonsterMarker,      "LDLegendaryMonsterMarker")
X(so_LegendaryMonsterToken,       "LDLegendaryMonsterToken")
X(so_LegendaryMonsterTransformed, "LDLegendaryMonsterTransformed")
X(so_Mana,                        OBJ "Mana")
X(so_ManaLeak,                    OBJ "ManaLeak")
X(so_ManaPickup,                  OBJ "ManaPickup")
X(so_MarinePlayer,                OBJ "MarinePlayer")
X(so_MonsterBarrier,              OBJ "MonsterBarrier")
X(so_MonsterHeptaura,             OBJ "MonsterHeptaura")
X(so_MonsterID,                   OBJ "MonsterID")
X(so_MonsterInvalid,              OBJ "MonsterInvalid")
X(so_MonsterLevelUp,              OBJ "MonsterLevelUp")
X(so_MonsterSoul,                 OBJ "MonsterSoul")
X(so_NoDamage,                    OBJ "NoDamage")
X(so_Nuke,                        OBJ "Nuke")
X(so_PhantomOut,                  OBJ "PhantomOut")
X(so_PhantomTeleport,             OBJ "PhantomTeleport")
X(so_PlasmaAmmo,                  OBJ "PlasmaAmmo")
X(so_Player,                      OBJ "Player")
X(so_PlayerDeath,                 OBJ "PlayerDeath")
X(so_PlayerDeathNuke,             OBJ "PlayerDeathNuke")
X(so_PoisonFXReset,               OBJ "PoisonFXReset")
X(so_PoisonFXTimer,               OBJ "PoisonFXTimer")
X(so_PowerFlight,                 "PowerFlight")
X(so_PowerLightAmp,               "PowerLightAmp")
X(so_PowerStrength,               "PowerStrength")
X(so_PowerTimeFreezer,            "PowerTimeFreezer")
X(so_PunctuatorExplosion,         OBJ "PunctuatorExplosion")
X(so_PunctuatorPuff,              OBJ "PunctuatorPuff")
X(so_RLAdaptive,                  "RLAdaptive")
X(so_RainDrop,                    OBJ "RainDrop")
X(so_RandomSpawn,                 OBJ "RandomSpawn")
X(so_RedCard,                     "RedCard")
X(so_RedSkull,                    "RedSkull")
X(so_Rend,                        OBJ "Rend")
X(so_RocketAmmo,                  OBJ "RocketAmmo")
X(so_RocketBooster,               OBJ "RocketBooster")
X(so_SMGHeat,                     OBJ "SMGHeat")
X(so_ShellAmmo,                   OBJ "ShellAmmo")
X(so_Shotgun,                     "Shotgun")
X(so_StarShot,                    OBJ "StarShot")
X(so_StealthSystem,               OBJ "StealthSystem")
X(so_Steggles,                    OBJ "Steggles")
X(so_SubweaponCharge,             OBJ "SubweaponCharge")
X(so_SubweaponShots,              OBJ "SubweaponShots")
X(so_SurgeOfDestiny,              OBJ "SurgeOfDestiny")
X(so_Sword,                       OBJ "Sword")
X(so_TargetMarker,                OBJ "TargetMarker")
X(so_ThothPlayer,                 OBJ "ThothPlayer")
X(so_TimeHax,                     OBJ "TimeHax")
X(so_TimeHax2,                    OBJ "TimeHax2")
X(so_UniqueID,                    OBJ "UniqueID")
X(so_WandererPlayer,              OBJ "WandererPlayer")
X(so_WeaponScopedToken,           OBJ "WeaponScopedToken")
X(so_YellowCard,                  "YellowCard")
X(so_YellowSkull,                 "YellowSkull")
X(so_ZombieMan,                   "ZombieMan")

/* Paths */
X(sp_Any,                  "*")
X(sp_Background,           "Background")
X(sp_Dialogue_Back,        ":Dialogue:Back")
X(sp_HUD_AMMO,             ":HUD:AMMO")
X(sp_HUD_Bar,              ":HUD:Bar")
X(sp_HUD_BarBig,           ":HUD:BarBig")
X(sp_HUD_C_AMMO,           ":HUD_C:AMMO")
X(sp_HUD_C_Back,           ":HUD_C:Back")
X(sp_HUD_C_Bar,            ":HUD_C:Bar")
X(sp_HUD_C_BarSmall,       ":HUD_C:BarSmall")
X(sp_HUD_C_BarSmall2,      ":HUD_C:BarSmall2")
X(sp_HUD_C_HeatBar,        ":HUD_C:HeatBar")
X(sp_HUD_C_MAG,            ":HUD_C:MAG")
X(sp_HUD_C_MagicIcon,      ":HUD_C:MagicIcon")
X(sp_HUD_C_ManaBar1,       ":HUD_C:ManaBar1")
X(sp_HUD_C_ManaBar2,       ":HUD_C:ManaBar2")
X(sp_HUD_C_SplitBack,      ":HUD_C:SplitBack")
X(sp_HUD_C_SplitFront,     ":HUD_C:SplitFront")
X(sp_HUD_C_VIT,            ":HUD_C:VIT")
X(sp_HUD_D_AMM,            ":HUD_D:AMM")
X(sp_HUD_D_Ammo2Back,      ":HUD_D:Ammo2Back")
X(sp_HUD_D_AmmoBack,       ":HUD_D:AmmoBack")
X(sp_HUD_D_HPBack,         ":HUD_D:HPBack")
X(sp_HUD_D_MAG,            ":HUD_D:MAG")
X(sp_HUD_D_WepBack,        ":HUD_D:WepBack")
X(sp_HUD_H_B3,             ":HUD:H_B3")
X(sp_HUD_H_C1,             ":HUD:H_C1")
X(sp_HUD_H_C2,             ":HUD:H_C2")
X(sp_HUD_H_D14,            ":HUD:H_D14")
X(sp_HUD_H_D16,            ":HUD:H_D16")
X(sp_HUD_H_D21,            ":HUD:H_D21")
X(sp_HUD_H_D24,            ":HUD:H_D24")
X(sp_HUD_H_D41,            ":HUD:H_D41")
X(sp_HUD_H_D44,            ":HUD:H_D44")
X(sp_HUD_H_D46,            ":HUD:H_D46")
X(sp_HUD_H_KC1,            ":HUD:H_KC1")
X(sp_HUD_H_KC2,            ":HUD:H_KC2")
X(sp_HUD_H_KC3,            ":HUD:H_KC3")
X(sp_HUD_H_KS1,            ":HUD:H_KS1")
X(sp_HUD_H_KS2,            ":HUD:H_KS2")
X(sp_HUD_H_KS3,            ":HUD:H_KS3")
X(sp_HUD_H_W3,             ":HUD:H_W3")
X(sp_HUD_I_AMMO,           ":HUD_I:AMMO")
X(sp_HUD_I_AmmoExtend,     ":HUD_I:AmmoExtend")
X(sp_HUD_I_AmmoWepsBack,   ":HUD_I:AmmoWepsBack")
X(sp_HUD_I_HPAPBack,       ":HUD_I:HPAPBack")
X(sp_HUD_I_MAG,            ":HUD_I:MAG")
X(sp_HUD_I_ScopeOverlay,   ":HUD_I:ScopeOverlay")
X(sp_HUD_MAG,              ":HUD:MAG")
X(sp_HUD_SplitBack,        ":HUD:SplitBack")
X(sp_HUD_SplitBackRed,     ":HUD:SplitBackRed")
X(sp_HUD_SplitFront,       ":HUD:SplitFront")
X(sp_HUD_SplitLeft,        ":HUD:SplitLeft")
X(sp_HUD_SplitRight,       ":HUD:SplitRight")
X(sp_HUD_VIT,              ":HUD:VIT")
X(sp_RifleScope,           ":RifleScope")
X(sp_Terminal_Teleport,    ":Terminal:Teleport")
X(sp_UI_AttrBar1,          ":UI:AttrBar1")
X(sp_UI_AttrBar2,          ":UI:AttrBar2")
X(sp_UI_AttrBar4,          ":UI:AttrBar4")
X(sp_UI_Bag,               ":UI:Bag")
X(sp_UI_Body,              ":UI:Body")
X(sp_UI_Cursor,            ":UI:Cursor")
X(sp_UI_CursorBlue,        ":UI:CursorBlue")
X(sp_UI_CursorOrange,      ":UI:CursorOrange")
X(sp_UI_CursorOutline,     ":UI:CursorOutline")
X(sp_UI_CursorOutline2,    ":UI:CursorOutline2")
X(sp_UI_CursorOutline2Inv, ":UI:CursorOutline2Inv")
X(sp_UI_CursorOutlineInv,  ":UI:CursorOutlineInv")
X(sp_UI_CursorPink,        ":UI:CursorPink")
X(sp_UI_CursorRed,         ":UI:CursorRed")
X(sp_UI_CursorWhite,       ":UI:CursorWhite")
X(sp_UI_InvBack,           ":UI:InvBack")
X(sp_UI_InvSel,            ":UI:InvSel")
X(sp_UI_LogList,           ":UI:LogList")
X(sp_UI_MagicSelectBack,   ":UI:MagicSelectBack")
X(sp_UI_TextBoxBack,       ":UI:TextBoxBack")
X(sp_UI_bip,               ":UI:bip")
X(sp_Vignette,             ":Vignette")
X(sp_Weapon_Blade,         ":Weapon:Blade")
X(sp_Weapon_BladeHit,      ":Weapon:BladeHit")
X(sp_ZoomOverlay,          ":ZoomOverlay")
X(sp_lfiles_BIPInfo,       "lfiles/BIPInfo.txt")
X(sp_lfiles_Cyberspace,    "lfiles/Cyberspace.txt")
X(sp_lmusic_DOGS,          "lmusic/DOGS.ogg")
X(sp_lmusic_Unce,          "lmusic/Unce.ogg")
X(sp_lsounds_Silence,      "lsounds/Silence")

/* Sounds */
X(ss_amb_rain,                 "amb/rain")
X(ss_amb_wind,                 "amb/wind")
X(ss_enemies_boss_talk,        "enemies/boss/talk")
X(ss_enemies_phantom_escape,   "enemies/phantom/escape")
X(ss_enemies_phantom_spawned,  "enemies/phantom/spawned")
X(ss_marathon_pickup,          "marathon/pickup")
X(ss_misc_telein,              "misc/telein")
X(ss_misc_teleout,             "misc/teleout")
X(ss_player_YOUVEGOTMAIL,      "player/YOUVEGOTMAIL")
X(ss_player_adren_inj,         "player/adren/inj")
X(ss_player_adren_ready,       "player/adren/ready")
X(ss_player_cbi_auto_invalid,  "player/cbi/auto/invalid")
X(ss_player_cbi_dlgopen,       "player/cbi/dlgopen")
X(ss_player_cbi_find,          "player/cbi/find")
X(ss_player_cbi_finddone,      "player/cbi/finddone")
X(ss_player_cbi_findfail,      "player/cbi/findfail")
X(ss_player_cbi_invcur,        "player/cbi/invcur")
X(ss_player_cbi_invmov,        "player/cbi/invmov")
X(ss_player_cbi_invrem,        "player/cbi/invrem")
X(ss_player_cbi_keypress,      "player/cbi/keypress")
X(ss_player_cbi_mail,          "player/cbi/mail")
X(ss_player_cbi_scroll,        "player/cbi/scroll")
X(ss_player_cbi_scrollend,     "player/cbi/scrollend")
X(ss_player_cbi_win95,         "player/cbi/win95")
X(ss_player_counter,           "player/counter")
X(ss_player_counterdone,       "player/counterdone")
X(ss_player_death1,            "player/death1")
X(ss_player_doublejump,        "player/doublejump")
X(ss_player_glare,             "player/glare")
X(ss_player_infraredoff,       "player/infraredoff")
X(ss_player_levelup,           "player/levelup")
X(ss_player_manafull,          "player/manafull")
X(ss_player_pickup_item,       "player/pickup/item")
X(ss_player_pickup_upgrbody,   "player/pickup/upgrbody")
X(ss_player_pickup_upgrextr,   "player/pickup/upgrextr")
X(ss_player_pickup_upgrweap,   "player/pickup/upgrweap")
X(ss_player_rarmor_mode,       "player/rarmor/mode")
X(ss_player_rocketboost,       "player/rocketboost")
X(ss_player_score,             "player/score")
X(ss_player_slide,             "player/slide")
X(ss_player_trmopen,           "player/trmopen")
X(ss_player_trmswitch,         "player/trmswitch")
X(ss_player_zoomin,            "player/zoomin")
X(ss_player_zoomout,           "player/zoomout")
X(ss_weapons_cercle_attack,    "weapons/cercle/attack")
X(ss_weapons_cercle_begin,     "weapons/cercle/begin")
X(ss_weapons_rifle_firemode,   "weapons/rifle/firemode")
X(ss_weapons_rocket_mark,      "weapons/rocket/mark")
X(ss_weapons_subweapon_charge, "weapons/subweapon/charge")
X(ss_xx_pain25,                "*pain25")

/* Text */
X(st_0,                      "0")
X(st_barons,                 "Barons")
X(st_begin,                  "\Cd[Press any key to begin]")
X(st_bip_header,             "BIOTIC INFORMATION PANEL ver2.5")
X(st_cbi_armorinter,         LANG "CBI_ArmorInter")
X(st_cbi_rdistinter,         LANG "CBI_RDistInter")
X(st_cbi_reactarmor,         LANG "CBI_ReactArmor")
X(st_cbi_weapninte2,         LANG "CBI_WeapnInte2")
X(st_cbi_weapninter,         LANG "CBI_WeapnInter")
X(st_cyberdemon,             "CyberDemon")
X(st_disabling,              "Disabling")
X(st_div_get,                LANG "DIV_SIGIL_GET")
X(st_div_warning,            LANG "DIV_SIGIL_WARNING")
X(st_edit,                   LANG "EDIT")
X(st_enabling,               "Enabling")
X(st_exp,                    "EXP")
X(st_filter_all,             "Filter: \CjAll")
X(st_free,                   LANG "FREE")
X(st_gui_cursor,             LANG "gui_cursor")
X(st_gui_jpfont,             LANG "gui_jpfont")
X(st_gui_theme,              LANG "gui_theme")
X(st_gui_xmul,               LANG "gui_xmul")
X(st_gui_ymul,               LANG "gui_ymul")
X(st_hp,                     "HP")
X(st_hud_logbig,             LANG "hud_logbig")
X(st_hud_logfromtop,         LANG "hud_logfromtop")
X(st_hud_showarmorind,       LANG "hud_showarmorind")
X(st_hud_showlog,            LANG "hud_showlog")
X(st_hud_showlvl,            LANG "hud_showlvl")
X(st_hud_showscore,          LANG "hud_showscore")
X(st_hud_showweapons,        LANG "hud_showweapons")
X(st_iconofsin,              "IconOfSin")
X(st_info_categories,        "INFO CATEGORIES")
X(st_jet,                    "Jet")
X(st_lv,                     "Lv.")
X(st_mail_cluster1,          "Cluster1")
X(st_mail_cluster2,          "Cluster2")
X(st_mail_cluster3,          "Cluster3")
X(st_mail_internal,          LANG "MAIL_INTERNAL")
X(st_mail_intro,             "Intro")
X(st_mail_notitle,           LANG "MAIL_NOTITLE")
X(st_mail_phantom,           "Phantom")
X(st_mail_secret1,           "Secret1")
X(st_mail_secret2,           "Secret2")
X(st_mana_charge,            LANG "MANA_CHARGE")
X(st_mp,                     "MP")
X(st_next,                   "Next")
X(st_nl_bar,                 "\n|")
X(st_no_results,             "No results")
X(st_normal,                 "Normal")
X(st_out_blue,               CrBlue "OUT")
X(st_out_green,              CrGreen "OUT")
X(st_out_purple,             CrPurple "Out")
X(st_out_red,                CrRed "OUT")
X(st_player_altinvuln,       LANG "player_altinvuln")
X(st_player_ammolog,         LANG "player_ammolog")
X(st_player_bosstexts,       LANG "player_bosstexts")
X(st_player_brightweps,      LANG "player_brightweps")
X(st_player_damagebob,       LANG "player_damagebob")
X(st_player_damagebobmul,    LANG "player_damagebobmul")
X(st_player_footstepvol,     LANG "player_footstepvol")
X(st_player_invertmouse,     LANG "player_invertmouse")
X(st_player_lvsys,           LANG "player_lvsys")
X(st_player_noitemfx,        LANG "player_noitemfx")
X(st_player_rainshader,      LANG "player_rainshader")
X(st_player_resultssound,    LANG "player_resultssound")
X(st_player_scorelog,        LANG "player_scorelog")
X(st_player_scoresound,      LANG "player_scoresound")
X(st_player_stupidpickups,   LANG "player_stupidpickups")
X(st_player_teleshop,        LANG "player_teleshop")
X(st_player_viewtilt,        LANG "player_viewtilt")
X(st_red_six,                "\Cg6")
X(st_scanner_altfont,        LANG "scanner_altfont")
X(st_scanner_bar,            LANG "scanner_bar")
X(st_scanner_color,          LANG "scanner_color")
X(st_scanner_slide,          LANG "scanner_slide")
X(st_scanner_xoffs,          LANG "scanner_xoffs")
X(st_scanner_yoffs,          LANG "scanner_yoffs")
X(st_spiderdemon,            "SpiderDemon")
X(st_st_name_unknown,        LANG "ST_NAME_Unknown")
X(st_stx_boss_0,             LANG "stx_boss_0")
X(st_stx_boss_1,             LANG "stx_boss_1")
X(st_stx_boss_2,             LANG "stx_boss_2")
X(st_stx_boss_3,             LANG "stx_boss_3")
X(st_stx_gameplay,           LANG "stx_gameplay")
X(st_stx_gui,                LANG "stx_gui")
X(st_stx_hud,                LANG "stx_hud")
X(st_stx_items,              LANG "stx_items")
X(st_stx_jp_0,               LANG "stx_jp_0")
X(st_stx_jp_1,               LANG "stx_jp_1")
X(st_stx_jp_2,               LANG "stx_jp_2")
X(st_stx_jp_3,               LANG "stx_jp_3")
X(st_stx_player,             LANG "stx_player")
X(st_stx_vscan,              LANG "stx_vscan")
X(st_stx_weapons,            LANG "stx_weapons")
X(st_stx_world,              LANG "stx_world")
X(st_sv_autosave,            LANG "sv_autosave")
X(st_sv_difficulty,          LANG "sv_difficulty")
X(st_sv_nobossdrop,          LANG "sv_nobossdrop")
X(st_sv_nobosses,            LANG "sv_nobosses")
X(st_sv_nofullammo,          LANG "sv_nofullammo")
X(st_sv_noscoreammo,         LANG "sv_noscoreammo")
X(st_sv_pauseinmenus,        LANG "sv_pauseinmenus")
X(st_sv_rain,                LANG "sv_rain")
X(st_sv_revenge,             LANG "sv_revenge")
X(st_sv_scoremul,            LANG "sv_scoremul")
X(st_sv_sky,                 LANG "sv_sky")
X(st_sv_wepdrop,             LANG "sv_wepdrop")
X(st_term_disconnecting,     "Disconnecting...")
X(st_term_ip,                "<55.883.115.7>")
X(st_term_sgxline,           "SGXLine r4205")
X(st_term_use_to_ack,        "Use To Acknowledge")
X(st_timeout,                "TimeOut")
X(st_weapons_alpha,          LANG "weapons_alpha")
X(st_weapons_casingfadeout,  LANG "weapons_casingfadeout")
X(st_weapons_casings,        LANG "weapons_casings")
X(st_weapons_fastlazshot,    LANG "weapons_fastlazshot")
X(st_weapons_magdrops,       LANG "weapons_magdrops")
X(st_weapons_magfadeout,     LANG "weapons_magfadeout")
X(st_weapons_magicselanims,  LANG "weapons_magicselanims")
X(st_weapons_nofirebob,      LANG "weapons_nofirebob")
X(st_weapons_rainbowlaser,   LANG "weapons_rainbowlaser")
X(st_weapons_recoil,         LANG "weapons_recoil")
X(st_weapons_reloadbob,      LANG "weapons_reloadbob")
X(st_weapons_reloadempty,    LANG "weapons_reloadempty")
X(st_weapons_ricochetvol,    LANG "weapons_ricochetvol")
X(st_weapons_riflemodeclear, LANG "weapons_riflemodeclear")
X(st_weapons_riflescope,     LANG "weapons_riflescope")
X(st_weapons_scopealpha,     LANG "weapons_scopealpha")
X(st_weapons_slot3ammo,      LANG "weapons_slot3ammo")
X(st_weapons_zoomfactor,     LANG "weapons_zoomfactor")
X(st_xhair_a,                LANG "xhair_a")
X(st_xhair_b,                LANG "xhair_b")
X(st_xhair_enable,           LANG "xhair_enable")
X(st_xhair_enablejuicer,     LANG "xhair_enablejuicer")
X(st_xhair_g,                LANG "xhair_g")
X(st_xhair_r,                LANG "xhair_r")
X(st_xhair_style,            LANG "xhair_style")

/* Generated */
X(st_bip_help_search, LANG "BIP_HELP_Search")
#define LITH_X(name, capt) X(st_bip_help_##name, LANG "BIP_HELP_" capt)
#include "p_bip.h"

X(st_bipc_EXTRA, "EXTRA")
#define LITH_X(n, _) X(st_bipc_##n, #n)
#include "p_bip.h"

#define LITH_X(n, pc) X(st_##n, #n) X(st_##pc, #pc)
#include "p_player.h"

X(sm_Draw, OBJ "URANUS")
X(sm_Serv, OBJ "HERMES")

#undef X
#elif !defined(m_stab_h)
#define m_stab_h

#define X(n, s) extern str const n;
#include "m_stab.h"

#endif

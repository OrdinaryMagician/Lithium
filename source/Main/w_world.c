/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * World entry points.
 *
 * ---------------------------------------------------------------------------|
 */

#include "common.h"
#include "p_player.h"
#include "w_world.h"
#include "w_monster.h"
#include "m_version.h"

/* Extern Objects ---------------------------------------------------------- */

__addrdef __mod_arr lmvar;
__addrdef __hub_arr lhvar;

bool lmvar player_init;
struct payoutinfo payout;
bool singleplayer;
i32 mapscleared;
i32 prevcluster;
i32 mapseed;
bool unloaded;
bool islithmap;
i32 secretsfound;
k64 scoremul;
u64 ticks;
i32 game;
k32 apiversion = APIVersion;
i32 soulsfreed;
i32 fun;
bool bossspawned;
i32 cbiperf;
bool cbiupgr[cupg_max];
bool legendoom;
bool drlamonsters;
bool pauseinmenus;
enum mission_status lmvar mission = _unfinished;
struct payoutinfo payout;

bool dorain;

bool lmvar player_init;

/* Static Objects ---------------------------------------------------------- */

static bool reopen;

static i32 lmvar mapid;

static bool lmvar modinit;
static bool lhvar hubinit;
static bool       gblinit;

/* Extern Functions -------------------------------------------------------- */

script void SpawnBosses(i96 sum, bool force);

i32 UniqueID(i32 tid)
{
   i32 pn;

   /* Negative values are for players. */
   if((pn = PtrPlayerNumber(tid)) != -1) return -(pn + 1);

   /* If we already have a unique identifier, return that. */
   i32 id = PtrInvNum(tid, so_UniqueID);

   /* Otherwise we have to give a new unique identifier. */
   if(id == 0) PtrInvGive(tid, so_UniqueID, id = ++mapid);

   return id;
}

/* Static Functions -------------------------------------------------------- */

script
static void Boss_HInit(void)
{
   ACS_Delay(1); /* Delay another tic for monster spawners. */

   for_player() {
      SpawnBosses(p->scoresum, false);
      break;
   }
}

static void CheckModCompat(void)
{
   i32 tid;

   if((legendoom = ACS_SpawnForced(so_LegendaryMonsterMarker, 0, 0, 0, tid = ACS_UniqueTID(), 0))) ACS_Thing_Remove(tid);

   drlamonsters = ACS_GetCVar(sc_drla_is_using_monsters);
}

static void UpdateGame(void)
{
   #define Update(n) \
      if(ACS_GetCVarFixed(sc_version) < n) \
         __with(ACS_SetCVarFixed(sc_version, n);)

   Update(Lith_v1_5_1)
      ACS_SetCVarFixed(sc_sv_scoremul, 1.25); /* 2.0 => 1.25 */

   Update(Lith_v1_5_2)
      ACS_SetCVar(sc_sv_difficulty, 10); /* 1 => 10 */

   Update(Lith_v1_6_0)
   {
      for_player()
      {
         p->setCVarK(sc_player_footstepvol, 0.2); /* 1.0 => 0.2 */
         p->setCVarI(sc_player_ammolog, true); /* false => true */
      }
   }

   Update(Lith_v1_6_1)
   {
      for_player()
      {
         p->setCVarK(sc_weapons_zoomfactor, 1.5); /* 3.0 => 1.5 */
      }
   }
   #undef Update
}

static void GetDebugInfo(void)
{
   bool all = ACS_GetCVar(sc_debug_all);

   dbglevel = ACS_GetCVar(sc_debug_level);

   if(all || ACS_GetCVar(sc_debug_bip))        dbgflag |= dbgf_bip;
   if(all || ACS_GetCVar(sc_debug_items))      dbgflag |= dbgf_items;
   if(all || ACS_GetCVar(sc_debug_save))       dbgflag |= dbgf_save;
   if(all || ACS_GetCVar(sc_debug_score))      dbgflag |= dbgf_score;
   if(all || ACS_GetCVar(sc_debug_upgrades))   dbgflag |= dbgf_upgr;
}

static void MInitPre(void)
{
   Dbg_Log(log_dev, "%s", __func__);

   CheckModCompat();
   UpdateGame();
}

static void GInit(void)
{
   extern void Upgr_GInit(void);
   extern void Wep_GInit(void);

   Dbg_Log(log_dev, "%s", __func__);

   Upgr_GInit();
   Wep_GInit();

   game         = ACS_GetCVar(sc_game);
   singleplayer = ACS_GameType() == GAME_SINGLE_PLAYER;

   cbiperf = 10;

   gblinit = true;
}

static void MInitPst(void)
{
   script extern void W_DoRain();

   Dbg_Log(log_dev, "%s", __func__);

   payout.killmax += ACS_GetLevelInfo(LEVELINFO_TOTAL_MONSTERS);
   payout.itemmax += ACS_GetLevelInfo(LEVELINFO_TOTAL_ITEMS);

   /* Line 1888300 is used as a control line for mod features. */
   /* Check for if rain should be used. */
   if(!ACS_GetLineUDMFInt(1888300, sm_MapNoRain) &&
      (ACS_GetCVar(sc_sv_rain) || ACS_GetLineUDMFInt(1888300, sm_MapUseRain)) &&
      ACS_PlayerCount() <= 1)
   {
      dorain = true;
      W_DoRain();
   }

   modinit = true;
}

static void MInit(void)
{
   extern void Upgr_MInit(void);
   extern void Shop_MInit(void);
   extern void Dlg_MInit(void);

   Dbg_Log(log_dev, "%s", __func__);

   Dlg_MInit();

   islithmap = (MapNum & LithMapMask) == LithMapMagic;

   pauseinmenus = singleplayer && ACS_GetCVar(sc_sv_pauseinmenus);

   soulsfreed = 0;

   /* Init a random seed from the map. */
   mapseed = ACS_Random(0, INT32_MAX);

   /* Init global score multiplier per-map. */
   scoremul = roundlk(ACS_GetCVarFixed(sc_sv_scoremul) * 10, 10) / 10;

   /* Give players some extra score if they're playing on extra hard or above. */
   if(ACS_GameSkill() >= skill_extrahard)
      scoremul += 0.15;

   /* Set the air control because ZDoom's default sucks. */
   ACS_SetAirControl(0.77);

   Upgr_MInit();
   Shop_MInit();
}

static void HInitPre(void)
{
   extern void DmonInit();

   Dbg_Log(log_dev, "%s", __func__);

   if(unloaded)
      mapscleared++;

   DmonInit();
   bossspawned = false;

   if(ACS_GetCVar(sc_sv_sky) && !islithmap)
   {
      if(InHell)
      {
         ACS_ChangeSky(s_LITHSKRD, s_LITHSKRD);
         ACS_SetSkyScrollSpeed(1, 0.01);
      }
      else if(OnEarth)
         ACS_ChangeSky(s_LITHSKDE, s_LITHSKDE);
      else
         ACS_ChangeSky(s_LITHSKS1, s_LITHSKS1);
   }
}

static void HInit(void)
{
   extern void Scr_HInit(void);

   Dbg_Log(log_dev, "%s", __func__);

   if(!ACS_GetCVar(sc_sv_nobosses))
      Boss_HInit();

   /* Payout, which is not done on the first map. */
   if(mapscleared != 0) Scr_HInit();

   /* Cluster messages. */
   #define Message(cmp, n, name) \
      if(cmp && !(msgs & (1 << n))) { \
         for_player() P_BIP_GiveMail(p, name); \
         msgs |= 1 << n; \
      } else ((void)0)

   static i32 msgs;

   if(game == Game_Doom2)
   {
      Message(Cluster >= 6,  0, st_mail_cluster1);
      Message(Cluster >= 7,  1, st_mail_cluster2);
      Message(Cluster == 8,  2, st_mail_cluster3);
      Message(Cluster == 9,  3, st_mail_secret1);
      Message(Cluster == 10, 4, st_mail_secret2);
   }

   if(ACS_GetCVar(sc_sv_nobosses) ||
      ACS_GetCVar(sc_sv_nobossdrop) ||
      dbgflag & dbgf_items)
   {
      for(i32 i = 0; i < cupg_max; i++)
         CBI_Install(i);
   }

   hubinit = true;
}

/* Scripts ----------------------------------------------------------------- */

script_str ext("ACS") addr("Lith_PreInit")
void Sc_PreInit(void)
{
   GetDebugInfo();
}

script type("open")
static void Sc_World(void)
{
begin:
   /* yep. ZDoom doesn't actually clear hub variables in Doom-like map setups.
    * we can still detect it by using Timer, so correct this variable.
    */
   if(hubinit && ACS_Timer() < 2) hubinit = false;

   if(ACS_GameType() == GAME_TITLE_MAP) {
      script extern void W_Title(void);
      W_Title();
      return;
   } else if(MapNum == 1911777) {
      ACS_SetPlayerProperty(true, true, PROP_TOTALLYFROZEN);
      return;
   }

   Dbg_Log(log_dev, "%s", __func__);

   if(ACS_GetCVar(sc_sv_failtime) == 0) for(;;) {
      Log("\n=======\n"
          "The configuration for this mod has been wiped, or you accidentally "
          "set '" CVAR "sv_failtime' to 0 manually. If you did the latter, "
          "please set it to something else. Otherwise, please follow these "
          "instructions to fix your configuration:\n"
          "\n"
          "1. Navigate to your GZDoom folder.\n"
          "2. Find the configuration settings file (if you have extensions "
          "shown it will be the ini file in the folder) and open it.\n"
          "3. Find the heading '[Doom.Player.Mod]' and delete any lines "
          "starting with '" CVAR "' or '" DCVAR "' under it.\n"
          "4. Find the heading '[Doom.LocalServerInfo.Mod]' and delete any "
          "lines starting with '" CVAR "' or '" DCVAR "' under it.\n"
          "5. Save the file and start GZDoom again. If the issue persists "
          "try these steps again or delete your GZDoom configuration.\n"
          "\n\n\n\n\n\n"
          "Invalid settings detected. Please open the console"
          "(\"%jS\" or options menu) for more information.",
          s"toggleconsole");
      ACS_Delay(10);
   }

   dbgnotenum = 0;

   /* Let the map do... whatever. */
   ACS_Delay(1);

   if(!modinit) MInitPre();
   if(!gblinit) GInit();
   if(!modinit) MInit();

   /* Hub-static pre-player init. */
   if(!hubinit) HInitPre();

   unloaded = false; /* Unloaded flag can be reset now. */
   player_init = true;

   ACS_Delay(1); /* Wait for players to get initialized. */

   /* Hub-static post-player init. */
   if(!hubinit) HInit();

   /* Module-static post-hub init. */
   if(!modinit) MInitPst();

   /* Main loop. */
   i32 prevsecrets = 0;
   i32 prevkills   = 0;
   i32 previtems   = 0;

   i32 missionkill = 0;
   i32 missionprc  = 0;

   for(;;) {
      if(reopen) {
         player_init = reopen = false;
         goto begin;
      }

      if(ticks > ACS_GetCVar(sc_sv_failtime) * 35 * 60 * 60 && !islithmap) {
         ServCallI(sm_SetEnding, st_timeout);
         ACS_ChangeLevel(s_LITHEND, 0, CHANGELEVEL_NOINTERMISSION, -1);
         return;
      }

      i32 secrets = ACS_GetLevelInfo(LEVELINFO_FOUND_SECRETS);
      i32 kills   = ACS_GetLevelInfo(LEVELINFO_KILLED_MONSTERS);
      i32 items   = ACS_GetLevelInfo(LEVELINFO_FOUND_ITEMS);

      if(secrets > prevsecrets) {
         i32 delta = secrets - prevsecrets;
         P_GiveAllScore(9000 * delta, true);
         secretsfound += delta;
      }

      if(kills > prevkills) payout.killnum += kills - prevkills;
      if(items > previtems) payout.itemnum += items - previtems;

      prevsecrets = secrets;
      prevkills   = kills;
      previtems   = items;

      if(ACS_Timer() % 5 == 0 && missionkill < kills)
      {
         if(++missionprc >= 150) {
            SpawnBosses(0, true);
            missionprc = 0;
         }
         missionkill = kills;
      }

      Dbg_Stat("mission%%: %i\n", missionprc);

      ACS_Delay(1);

      dbgstatnum = 0;
      ticks++;

      i32 autosave = ACS_GetCVar(sc_sv_autosave);
      if(autosave && ticks % (35 * 60 * autosave) == 0) ACS_Autosave();
   }
}

script_str ext("ACS") addr("Lith_WorldReopen")
void Sc_WorldReopen(void)
{
   reopen = true;
}

script type("unloading")
static void Sc_WorldUnload(void)
{
   extern void CBI_InstallSpawned(void);
   unloaded = true;
   Dbg_Log(log_dev, "%s", __func__);

   CBI_InstallSpawned();

   for_player() {
      p->setActivator();
      P_Upg_PDeinit(p);
      P_GUI_Close(p);
      P_Dat_PTickPst(p);
   }
}

script_str ext("ACS") addr("Lith_Finale")
void Sc_Finale(void)
{
   i32 boss = ServCallI(sm_GetBossLevel);
   str which;
   switch(boss) {
      case boss_none:
      case boss_other:       which = st_normal;      break;
      case boss_barons:      which = st_barons;      break;
      case boss_cyberdemon:  which = st_cyberdemon;  break;
      case boss_spiderdemon: which = st_spiderdemon; break;
      case boss_iconofsin:   which = st_iconofsin;   break;
   }
   ServCallI(sm_SetEnding, which);
   ACS_ChangeLevel(s_LITHEND, 0, CHANGELEVEL_NOINTERMISSION|CHANGELEVEL_PRERAISEWEAPON, -1);
}

/* EOF */

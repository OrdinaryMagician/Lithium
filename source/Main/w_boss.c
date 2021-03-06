/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Phantom and boss handling.
 *
 * ---------------------------------------------------------------------------|
 */

#include "common.h"
#include "p_player.h"
#include "w_world.h"

/* Types ------------------------------------------------------------------- */

struct boss
{
   str const name;
   i32 const phasenum;

   i32  phase;
   bool dead;

   list link;
};

enum
{
   diff_easy,
   diff_medi,
   diff_hard,
   diff_any,
   diff_max
};

/* Static Objects ---------------------------------------------------------- */

static struct boss bosses_easy[] = {
   {s"James",   2},
};

static struct boss bosses_medi[] = {
   {s"Makarov", 3},
};

static struct boss bosses_hard[] = {
   {s"Isaac",   3},
};

static struct boss *lmvar boss;
static i32          lmvar bosstid;

static bool alldead[diff_max];

static i32 rewardnum;
static i32 difficulty;
static struct boss *lastboss;
static i96 scorethreshold = 1000000;

/* Static Functions -------------------------------------------------------- */

static void SpawnBossReward(void)
{
   k32 x = GetX(0);
   k32 y = GetY(0);
   k32 z = GetZ(0);

   switch(rewardnum++) {
   case 0: ACS_SpawnForced(so_BossReward1, x, y, z); break;
   case 1: ACS_SpawnForced(so_BossReward2, x, y, z); break;
   case 2: ACS_SpawnForced(so_BossReward3, x, y, z); break;
   case 3: ACS_SpawnForced(so_BossReward4, x, y, z); break;
   case 4: ACS_SpawnForced(so_BossReward5, x, y, z); break;
   case 7: ACS_SpawnForced(so_BossReward6, x, y, z); break;
   }
}

static void TriggerBoss(void)
{
   static bool firstboss = true;

   if(!boss) return;

   if(boss->dead) {
      Log("%s: %S is dead, invalid num", __func__, boss->name);
      boss = nil;
      return;
   }

   if(boss->phase > boss->phasenum) {
      Log("%s: invalid boss phase", __func__);
      boss = nil;
      return;
   }

   if(!boss->phase)
      boss->phase = 1;

   Dbg_Log(log_boss, "%s: Spawning boss %S phase %i", __func__, boss->name, boss->phase);

   ServCallI(sm_TriggerBoss);

   if(firstboss) {
      firstboss = false;
      for_player() P_BIP_GiveMail(p, st_mail_phantom);
   }
}

static bool CheckDead(struct boss *b, i32 num)
{
   for(i32 i = 0; i < num; i++)
      if(!b[i].dead) return false;
   return true;
}

/* Extern Functions -------------------------------------------------------- */

script
void SpawnBosses(i96 sum, bool force)
{
   if(islithmap || (!force && sum < scorethreshold)) return;

   alldead[diff_easy] = CheckDead(bosses_easy, countof(bosses_easy));
   alldead[diff_medi] = CheckDead(bosses_medi, countof(bosses_medi));
   alldead[diff_hard] = CheckDead(bosses_hard, countof(bosses_hard));

   i32 diff =
      difficulty == diff_any ? ACS_Random(diff_easy, diff_hard) : difficulty;

   if(alldead[diff])
   {
      Dbg_Log(log_boss, "%s: All dead, returning", __func__);
      return;
   }

   Dbg_Log(log_boss, "%s: Spawning boss, difficulty %i", __func__, diff);

   if(!lastboss || lastboss->dead) switch(diff)
   {
   case diff_easy: do boss = &bosses_easy[ACS_Random(1, countof(bosses_easy)) - 1]; while(boss->dead); break;
   case diff_medi: do boss = &bosses_medi[ACS_Random(1, countof(bosses_medi)) - 1]; while(boss->dead); break;
   case diff_hard: do boss = &bosses_hard[ACS_Random(1, countof(bosses_hard)) - 1]; while(boss->dead); break;
   }
   else
      boss = lastboss;

   TriggerBoss();
}

/* Scripts ----------------------------------------------------------------- */

script_str ext("ACS") addr("Lith_PhantomSound")
void Sc_PhantomSound(void)
{
   ACS_AmbientSound(ss_enemies_phantom_spawned, 127);
}

script_str ext("ACS") addr("Lith_PhantomTeleport")
void Sc_PhantomTeleport(void)
{
   k32 ang = ACS_GetActorAngle(0);

   ACS_ThrustThing(ang * 256, 64, true, 0);

   for(i32 i = 0; i < 15; i++) {
      InvGive(so_PhantomTeleport, 1);
      ACS_Delay(1);
   }
}

script_str ext("ACS") addr("Lith_PhantomDeath")
void Sc_PhantomDeath(void)
{
   ACS_StopSound(0, 7);

   if(boss->phase == boss->phasenum)
   {
      /* Death */
      ACS_AmbientSound(ss_player_death1, 127);
      ACS_Delay(35);
      InvGive(so_PlayerDeath, 1);
      ACS_Delay(25);
      InvGive(so_PlayerDeathNuke, 1);
      ACS_Delay(25);
      for_player() P_BIP_GiveMail(p, StrParam("%SDefeated", boss->name));
      boss->dead = true;

      if(difficulty != diff_any) difficulty++;
   }
   else
   {
      /* Escape */
      ACS_AmbientSound(ss_enemies_phantom_escape, 127);
      ACS_SetActorState(0, sm_GetOutOfDodge);
      ACS_Delay(5);
      InvGive(so_PhantomOut, 1);
      ACS_Delay(2);
   }

   Dbg_Log(log_boss, "Lith_PhantomDeath: %S phase %i defeated", boss->name, boss->phase);

   if(!ACS_GetCVar(sc_sv_nobossdrop))
      SpawnBossReward();

   soulsfreed++;

   scorethreshold = scorethreshold * 17 / 10;
   Dbg_Note(c"score threshold raised to %lli\n", scorethreshold);

   boss->phase++;
   boss = nil;

   bossspawned = false;
}

script_str ext("ACS") addr("Lith_SpawnBoss")
void Sc_SpawnBoss(void)
{
   if(!boss) return;

   bosstid = ACS_ActivatorTID();
   bosstid = bosstid ? bosstid : ACS_UniqueTID();

   ServCallI(sm_SpawnBoss, StrParam(OBJ "Boss_%S", boss->name), boss->phase);

   Dbg_Log(log_boss, "Lith_SpawnBoss: Boss %S phase %i spawned", boss->name, boss->phase);
   Dbg_Note("boss: %S phase %i spawned\n", boss->name, boss->phase);

   bossspawned = true;
}

script_str ext("ACS") addr("Lith_TriggerBoss") optargs(1)
void Sc_TriggerBoss(i32 diff, i32 num, i32 phase)
{
   switch(diff) {
   case diff_easy: boss = &bosses_easy[num]; break;
   case diff_medi: boss = &bosses_medi[num]; break;
   case diff_hard: boss = &bosses_hard[num]; break;
   }

   if(phase)
      {boss->dead = false; boss->phase = phase;}

   TriggerBoss();
}

/* EOF */

#include "lith_common.h"
#include "lith_player.h"
#include "lith_list.h"
#include "lith_hudid.h"
#include "lith_world.h"


//----------------------------------------------------------------------------
// Extern Objects
//

player_t players[MAX_PLAYERS];


//----------------------------------------------------------------------------
// Static Objects
//

static struct {__str on, off;} Lith_GUISounds[GUI_MAX] = {
   {},
   {"player/cbi/open", "player/cbi/close"},
   {"player/gb/open",  "player/gb/close" },
};


//----------------------------------------------------------------------------
// Static Functions
//

[[__call("ScriptS")]] static void Lith_PlayerRunScripts(player_t *p);
static void Lith_PlayerScore(player_t *p);
static void Lith_PlayerStats(player_t *p);
static void Lith_PlayerDeltaStats(player_t *p);


//----------------------------------------------------------------------------
// Scripts
//

//
// Lith_PlayerEntry
//
[[__call("ScriptS"), __script("Enter")]]
static void Lith_PlayerEntry(void)
{
   if(ACS_GameType() == GAME_TITLE_MAP)
      return;
   
   player_t *p = LocalPlayer;
   
reinit:
   while(!mapinit) ACS_Delay(1);
   
   Lith_ResetPlayer(p);
   Lith_PlayerLogEntry(p);
   Lith_PlayerEnterUpgrades(p);
   Lith_PlayerLoadData(p);
   
   while(p->active)
   {
      if(p->reinit)
         goto reinit;
      
      Lith_PlayerUpdateData(p);
      
      // This can be changed any time, so save it here.
      player_delta_t olddelta = p->cur;
      
      // Run logic and rendering
      Lith_PlayerRunScripts(p);
      
      // Update view
      ACS_SetActorAngle(0, ACS_GetActorAngle(0) - p->addyaw);
      ACS_SetActorPitch(0, ACS_GetActorPitch(0) - p->addpitch);
      
      // Tic passes
      ACS_Delay(1);
      
      // Update previous-tic values
      p->old = olddelta;
      
      // Reset view for next tic
      ACS_SetActorAngle(0, ACS_GetActorAngle(0) + p->addyaw);
      ACS_SetActorPitch(0, ACS_GetActorPitch(0) + p->addpitch);
      
      // If the map changes this we need to make sure it's still correct.
      Lith_ValidatePlayerTID(p);
      
      p->ticks++;
   }
}

//
// Lith_PlayerDeath
//
[[__call("ScriptS"), __script("Death")]]
static void Lith_PlayerDeath(void)
{
   player_t *p = LocalPlayer;
   bool singleplayer = ACS_GameType() == GAME_SINGLE_PLAYER;
   
   p->dead = true;
   
   Lith_PlayerDeinitUpgrades(p);
   
   if(singleplayer || ACS_GetCVar("sv_cooploseinventory"))
   {
      Lith_PlayerLoseUpgrades(p);
      Lith_PlayerLoseBIPPages(&p->bip);
      p->score = p->scoreaccum = p->scoreaccumtime = 0;
   }
   
   if(singleplayer)
   {
      if(ACS_GetCVar("lith_sv_revenge"))
      {
         ACS_LocalAmbientSound("player/death1", 127);
         ACS_Delay(35);
         ACS_GiveInventory("Lith_PlayerDeath", 1);
         ACS_Delay(25);
         ACS_GiveInventory("Lith_PlayerDeathNuke", 1);
         ACS_Delay(25);
      }
      
      for(;;)
      {
         ACS_Delay(35 * 5);
         Log("%S", Language("LITH_DEATHMSG_%.2i", ACS_Random(1, 20)));
      }
   }
}

//
// Lith_PlayerRespawn
//
[[__call("ScriptS"), __script("Respawn")]]
static void Lith_PlayerRespawn(void)
{
   LocalPlayer->reinit = true;
}

//
// Lith_PlayerReturn
//
[[__call("ScriptS"), __script("Return")]]
static void Lith_PlayerReturn(void)
{
   LocalPlayer->reinit = true;
}

//
// Lith_PlayerDisconnect
//
[[__call("ScriptS"), __script("Disconnect")]]
static void Lith_PlayerDisconnect(void)
{
   player_t *p = LocalPlayer;
   
   Lith_DeallocateBIP(&p->bip);
   
   Lith_ListFree(&p->loginfo.hud);
   Lith_ListFree(&p->hudstrlist,   free);
   Lith_ListFree(&p->loginfo.full, free);
   Lith_ListFree(&p->loginfo.maps, free);
   
   memset(p, 0, sizeof(player_t));
}


//----------------------------------------------------------------------------
// Extern Functions
//

//
// Lith_PlayerCloseGUI
//
void Lith_PlayerCloseGUI(player_t *p)
{
   if(p->activegui != GUI_NONE)
   {
      p->frozen--;
      ACS_LocalAmbientSound(Lith_GUISounds[p->activegui].off, 127);
      p->activegui = GUI_NONE;
   }
}

//
// Lith_PlayerUseGUI
//
void Lith_PlayerUseGUI(player_t *p, guiname_t type)
{
   if(p->activegui == GUI_NONE)
   {
      p->activegui = type;
      p->frozen++;
      ACS_LocalAmbientSound(Lith_GUISounds[type].on, 127);
   }
   else if(p->activegui == type)
   {
      p->activegui = GUI_NONE;
      p->frozen--;
      ACS_LocalAmbientSound(Lith_GUISounds[type].off, 127);
   }
   else
   {
      ACS_LocalAmbientSound(Lith_GUISounds[p->activegui].off, 127);
      ACS_LocalAmbientSound(Lith_GUISounds[type].on, 127);
      p->activegui = type;
   }
}

//
// Lith_GiveScore
//
void Lith_GiveScore(player_t *p, score_t score, bool nomul)
{
   // Could cause division by zero
   if(score == 0)
      return;
   
   // Multiply score by the player's multiplier
   if(!nomul)
      score *= p->scoremul;
   
   // Get a multiplier for the score accumulator and sound volume
   double mul = minmax(minmax(score, 0, 20000) / 20000.0f, 0.1f, 1.0f);
   double vol = 0.62 * mul;
   
   // Play a sound when we pick up score
   if(!IsSmallNumber(vol) && Lith_GetPCVarInt(p, "lith_player_scoresound"))
      ACS_PlaySound(p->tid, "player/score", CHAN_ITEM, vol, false, ATTN_STATIC);
   
   //
   if(p->upgrades[UPGR_CyberLegs].active && ACS_Random(0, 10000) == 0)
      Lith_Log(p, "> You gained brouzouf.");
   
   if(p->upgrades[UPGR_TorgueMode].active && ACS_Random(0, 10) == 0)
      ACS_SpawnForced("Lith_EXPLOOOSION", p->x, p->y, p->z);
   
   // Add score and set score accumulator
   p->score          += score;
   p->scoresum       += score;
   p->scoreaccum     += score;
   p->scoreaccumtime += 20 * (mul * 2.0);
   
   // Log score
   if(Lith_GetPCVarInt(p, "lith_player_scorelog"))
      Lith_LogH(p, "> +\Cj%lli\Cnscr", score);
}

//
// Lith_TakeScore
//
void Lith_TakeScore(player_t *p, score_t score)
{
   if(p->score - score >= 0)
   {
      p->score     -= score;
      p->scoreused += score;
   }
   else
   {
      score_t delta = p->score;
      p->score      = 0;
      p->scoreused += delta;
   }
   
   p->scoreaccum     = 0;
   p->scoreaccumtime = 0;
}


//----------------------------------------------------------------------------
// Static Functions
//

//
// Lith_PlayerRunScripts
//
// Run main loop scripts.
//
[[__call("ScriptS")]]
static void Lith_PlayerRunScripts(player_t *p)
{
   // Pre-logic: Update data from the engine.
   Lith_PlayerUpdateWeapon(p); // Update weapon info
   Lith_PlayerStats(p);        // Update statistics
   Lith_PlayerScore(p);        // Update score
   
   if(!p->dead)
   {
      // Logic: Update our data.
      switch(p->activegui)
      {
      case GUI_CBI: Lith_PlayerUpdateCBI(p); break; // Update CBI
      case GUI_GB:  Lith_PlayerUpdateGB(p);  break; // Update Gameboy
      }
      
      Lith_PlayerUpdateUpgrades(p); // Update upgrades
      Lith_PlayerUpdateLog(p);      // Update log data
      
      // Post-logic: Update the engine's data.
      Lith_PlayerDeltaStats(p); // Update delta'd info
   }
   
   // Rendering
   Lith_PlayerDamageBob(p);      // Update damage bobbing
   Lith_PlayerView(p);           // Update additive view
   Lith_PlayerRenderUpgrades(p); // Render Upgrades
   Lith_PlayerHUD(p);            // Draw HUD
   Lith_PlayerStyle(p);          // Change player render style
}

//
// Lith_PlayerScore
//
static void Lith_PlayerScore(player_t *p)
{
   if(!p->scoreaccumtime || p->score < p->old.score)
   {
      p->scoreaccum = 0;
      p->scoreaccumtime = 0;
   }
   
   if(p->scoreaccumtime > 0)
      p->scoreaccumtime--;
   else if(p->scoreaccumtime < 0)
      p->scoreaccumtime++;
}

//
// Lith_PlayerStats
//
static void Lith_PlayerStats(player_t *p)
{
   if(p->health < p->old.health)
      p->healthused += p->old.health - p->health;
   else if(p->health > p->old.health && ACS_Timer() != 1)
      p->healthsum += p->health - p->old.health;
   
   if(p->armor < p->old.armor)
      p->armorused += p->old.armor - p->armor;
   else if(p->armor > p->old.armor && ACS_Timer() != 1)
      p->armorsum += p->armor - p->old.armor;
   
   if(p->x != p->old.x) p->unitstravelled += abs(p->x - p->old.x);
   if(p->y != p->old.y) p->unitstravelled += abs(p->y - p->old.y);
   if(p->z != p->old.z) p->unitstravelled += abs(p->z - p->old.z);
}

//
// Lith_PlayerDeltaStats
//
static void Lith_PlayerDeltaStats(player_t *p)
{
   if(p->frozen    != p->old.frozen)    ACS_SetPlayerProperty(0, p->frozen > 0, PROP_TOTALLYFROZEN);
   if(p->speedmul  != p->old.speedmul)  ACS_SetActorPropertyFixed(0, APROP_Speed, 0.7 + p->speedmul);
   if(p->jumpboost != p->old.jumpboost) ACS_SetActorPropertyFixed(0, APROP_JumpZ, p->jumpheight * (1 + p->jumpboost));
}

// EOF

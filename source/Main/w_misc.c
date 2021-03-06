/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Miscellaneous scripts.
 *
 * ---------------------------------------------------------------------------|
 */

#include "common.h"
#include "p_player.h"
#include "w_world.h"

/* Static Functions -------------------------------------------------------- */

stkcall
static void SetInventory(str item, i32 amount)
{
   i32 s = InvNum(item) - amount;
        if(s < 0) InvTake(item, -s);
   else if(s > 0) InvGive(item,  s);
}

stkcall
static void SetActorInventory(i32 tid, str item, i32 amount)
{
   i32 s = ACS_CheckActorInventory(tid, item) - amount;
        if(s < 0) ACS_TakeActorInventory(tid, item, -s);
   else if(s > 0) ACS_GiveActorInventory(tid, item,  s);
}

/* Extern Functions -------------------------------------------------------- */

stkcall
void FadeFlash(i32 r, i32 g, i32 b, k32 amount, k32 seconds)
{
   ACS_FadeTo(r, g, b, amount, 0.0);
   ACS_FadeTo(r, g, b, 0.0, seconds);
}

script
i32 PtrTID(i32 tid, i32 ptr)
{
   if(tid || ptr)
      ACS_SetActivator(tid, ptr);
   return ACS_ActivatorTID();
}

script
i32 PtrPlayerNumber(i32 tid, i32 ptr)
{
   if(tid || ptr)
      ACS_SetActivator(tid, ptr);
   return ACS_PlayerNumber();
}

script
bool PtrValid(i32 tid, i32 ptr)
{
   if(tid || ptr)
      return ACS_SetActivator(tid, ptr);
   else
      return true;
}

script
bool PtrSet(i32 tid, i32 ptr, i32 assign, i32 tid2, i32 ptr2, i32 flags)
{
   if(tid || ptr)
      ACS_SetActivator(tid, ptr);
   return ACS_SetPointer(assign, tid2, ptr2, flags);
}

stkcall
i32 PtrInvNum(i32 tid, str item)
{
   if(tid == 0) return InvNum(item);
   else         return ACS_CheckActorInventory(tid, item);
}

stkcall
void PtrInvGive(i32 tid, str item, i32 amount)
{
   if(tid == 0) InvGive(item, amount);
   else         ACS_GiveActorInventory(tid, item, amount);
}

stkcall
void PtrInvTake(i32 tid, str item, i32 amount)
{
   if(tid == 0) InvTake(item, amount);
   else         ACS_TakeActorInventory(tid, item, amount);
}

stkcall
void PtrInvSet(i32 tid, str item, i32 amount)
{
   if(tid == 0) SetInventory(item, amount);
   else         SetActorInventory(tid, item, amount);
}

stkcall
void BeginAngles(i32 x, i32 y)
{
   a_cur = 0;
   for(i32 i = 0; i < countof(a_angles); i++)
   {
      a_angles[i].ang = 0;
      a_angles[i].dst = 0;
   }
   a_x = x;
   a_y = y;
}

stkcall
k32 AddAngle(i32 x, i32 y)
{
   if(a_cur >= countof(a_angles))
      return 0;

   struct polar *p = &a_angles[a_cur++];
   *p = ctopol(x - a_x, y - a_y);
   return p->ang;
}

/* Scripts ----------------------------------------------------------------- */

script ext("ACS") addr(lsc_addangle)
void Sc_AddAngle(i32 x, i32 y)
{
   AddAngle(x, y);
}

script_str ext("ACS") addr("Lith_EmitScore")
void Sc_EmitScore(i32 amount)
{
   /* dummied out */
}

script_str ext("ACS") addr("Lith_EmitEXP")
void Sc_EmitEXP(i32 amount)
{
   P_GiveAllEXP(amount);
}

script_str ext("ACS") addr("Lith_GiveScore")
void Sc_GiveScore(i32 score)
{
   P_GiveAllScore(score * (k64)ACS_RandomFixed(0.7, 1.2), false);
}

script_str ext("ACS") addr("Lith_BoughtItemPickup")
void Sc_BoughtItemPickup(i32 id)
{
   with_player(LocalPlayer) if(id)
   {
      struct upgrade *upgr = p->getUpgr(id);

      if(!upgr->owned)
      {
         switch(upgr->info->category) {
         case UC_Body: StartSound(ss_player_pickup_upgrbody, lch_item, CHANF_NOPAUSE, 1.0, ATTN_NONE); break;
         case UC_Weap: StartSound(ss_player_pickup_upgrweap, lch_item, CHANF_NOPAUSE, 1.0, ATTN_NONE); break;
         case UC_Extr: StartSound(ss_player_pickup_upgrextr, lch_item, CHANF_NOPAUSE, 1.0, ATTN_NONE); break;
         }

         P_Upg_SetOwned(p, upgr);
         P_Upg_Toggle(p, upgr);
      }
   }
   else
   {
      StartSound(ss_player_pickup_item, lch_item, CHANF_NOPAUSE, 1.0, ATTN_NONE);

      p->itemsbought++;
   }
}

/* EOF */

/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Unified shop definition handling.
 *
 * ---------------------------------------------------------------------------|
 */

#include "common.h"
#include "p_shopdef.h"
#include "p_player.h"
#include "w_world.h"

/* Extern Functions -------------------------------------------------------- */

i96 P_Shop_Cost(struct player *p, struct shopdef const *def)
{
   return P_Discount(def->cost);
}

bool P_Shop_CanBuy(struct player *p, struct shopdef const *def, void *obj)
{
   return p->score - P_Shop_Cost(p, def) >= 0 &&
          (def->ShopCanBuy ? def->ShopCanBuy(p, def, obj) : true);
}

bool P_Shop_Buy(struct player *p, struct shopdef const *def, void *obj, cstr namefmt, bool nodelivery, bool nolog)
{
   if(!P_Shop_CanBuy(p, def, obj))
      return false;

   if(!nolog) p->logF(LC(LANG "LOG_Bought"), LanguageC(namefmt, def->name));

   if(def->bipunlock)
   {
      bip_name_t tag; lstrcpy_str(tag, def->bipunlock);
      P_BIP_Unlock(p, tag);
   }

   P_Scr_Take(p, P_Shop_Cost(p, def));

   bool delivered = false;

   if(!nodelivery && p->getCVarI(sc_player_teleshop))
   {
      i32 pufftid;
      i32 tid;

      ACS_LineAttack(0, p->yaw, p->pitch, 0, so_Dummy, so_NoDamage, 128.0, FHF_NORANDOMPUFFZ | FHF_NOIMPACTDECAL, pufftid = ACS_UniqueTID());

      k32 x = GetX(pufftid);
      k32 y = GetY(pufftid);
      k32 z = GetZ(pufftid);

      if((x || y || z) && ACS_Spawn(so_BoughtItem, x, y, z, tid = ACS_UniqueTID()))
      {
         if(def->ShopGive(p, def, obj, tid))
            p->logH(1, LC(LANG "LOG_Delivered"));
         else
            ACS_Thing_Remove(tid);

         delivered = true;
      }
      else
         p->logH(1, LC(LANG "LOG_NoDeliver"));
   }

   if(!delivered) def->ShopBuy(p, def, obj);

   return true;
}

/* EOF */

/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Unified shop definitions.
 *
 * ---------------------------------------------------------------------------|
 */

#ifndef p_shopdef_h
#define p_shopdef_h

enum
{
   shoptype_items,
   shoptype_upgrades,
   shoptype_max
};

struct shopdef
{
   str name;
   str bipunlock;
   i96 cost;

   void (*ShopBuy)   (struct player *p, struct shopdef const *def, void *obj);
   bool (*ShopCanBuy)(struct player *p, struct shopdef const *def, void *obj);
   bool (*ShopGive)  (struct player *p, struct shopdef const *def, void *obj, i32 tid);
};

i96 P_Shop_Cost(struct player *p, struct shopdef const *def);
bool P_Shop_CanBuy(struct player *p, struct shopdef const *def, void *obj);
optargs(1) bool P_Shop_Buy(struct player *p, struct shopdef const *def, void *obj, cstr namefmt, bool nodelivery, bool nolog);

#endif

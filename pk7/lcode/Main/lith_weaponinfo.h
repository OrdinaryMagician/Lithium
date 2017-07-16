#ifndef LITH_WEAPONINFO_H
#define LITH_WEAPONINFO_H

#include "lith_weapons.h"

#define HasWeapon(p, w) (p)->weapon.inv[(w)].owned

#define SLOT_MAX 8

enum
{
   AT_None,
   AT_Mag,
   AT_Ammo
};

enum
{
   wf_magic = 1 << 0
};

typedef struct weaponinfo_s
{
   int slot;
   int pclass;
   __str name;
   __str pickupsound;
   int defammotype;
   __str defammoclass;
   __str classname;
   int type;
   int flags;
} weaponinfo_t;

typedef struct invweapon_s
{
   weaponinfo_t const *info;
   bool owned;
   int autoreload;
   int ammotype;
   __str ammoclass;
} invweapon_t;

typedef struct weapondata_s
{
   int slot[SLOT_MAX];
   invweapon_t inv[weapon_max];
   invweapon_t *cur;
   invweapon_t *prev;
} weapondata_t;

extern weaponinfo_t const weaponinfo[weapon_max];

void Lith_PlayerUpdateWeapon(struct player *p);
void Lith_PlayerUpdateWeapons(struct player *p);

#endif


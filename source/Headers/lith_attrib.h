// Copyright © 2017-2018 Alison Sanderson, all rights reserved.
#ifndef lith_attrib_h
#define lith_attrib_h

#define ATTR_BAS_MAX 60
#define ATTR_VIS_MAX 50
#define ATTR_VIS_DIFF (ATTR_BAS_MAX - ATTR_VIS_MAX)

enum
{
   atsys_auto,
   atsys_hybrid,
   atsys_manual,
};

enum
{
   at_acc,
   at_def,
   at_str,
   at_vit,
   at_stm,
   at_luk,
   at_spc,
   at_max
};

struct player_attributes
{
   u32 exp, expnext;
   u32 level;
   u32 points;
   u32 attrs[at_max];

   char names[at_max][3];
   char lvupstr[130];
};

#endif

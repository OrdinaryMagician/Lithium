// Copyright © 2016-2017 Graham Sanderson, all rights reserved.
#include "lith_upgrades_common.h"

// Extern Functions ----------------------------------------------------------|

//
// Update
//
[[__call("ScriptS")]]
void Upgr_Implying_Update(player_t *p, upgrade_t *upgr)
{
   static __str strings[] = {
      "\Cd>implying",
      "\Cd>doombabbies",
      "\Cd>implying",
      "\Cd>doom shitters",
      "\Cd>>>>>>>clip",
      "\Cd>implying",
      "\CjReport and ignore.",
      "\Cjcaleb when?",
      "\Cd>implying",
      "\Cd>",
      "\Cd>>>",
      "\Cd>>>>>>",
      "\Cjis this compatible with brutal doom?",
      "\Cd>>>>>>>>>",
      "\Cd>>>>>>>>>>>>",
      "\Cd>>>>>>>>>>>>>>>",
      "\Cd>doom >2012",
      "\Cq<",
   };

   srand(p->ticks / 7);

   for(int i = 0; i < 40; i++)
   {
      PrintTextStr(strings[rand() % countof(strings)]);
      PrintText("DBIGFONT", 0, rand() % 320,0, rand() % 240,0);
   }
}

// EOF


#include "lith_common.h"
#include "lith_player.h"
#include "lith_hudid.h"
#include "lith_list.h"
#include "lith_cbi_gui.h"

// ---------------------------------------------------------------------------
// Computer-Brain Interface (CBI) Scripts.
//

static
void Menu_TextUpdateFunc(cbi_node_t *node, player_t *p, cursor_t cur)
{
   cbi_text_t *text = (cbi_text_t *)node;
   cbi_node_t *node = &text->node;
   
   text->text = StrParam("yay it works %i", ACS_Timer());
}

static
bool Menu_ButtonClickFunc(cbi_node_t *node, player_t *p, cursor_t cur, bool left)
{
   cbi_button_t *button = (cbi_button_t *)node;
   cbi_node_t *node = &button->node;
   
   if(left && bpcldi(node->x, node->y, node->x + CBI_BUTTON_W, node->y + CBI_BUTTON_H, cur.x, cur.y))
      Log("yay it works");
   
   return false;
}

[[__call("ScriptI")]]
void Lith_PlayerInitCBI(player_t *p)
{
   cbi_t *cbi = &p->cbi;
   
   cbi_node_t *ctr;
   ctr = CBI_SpriteAlloc(SPRAF_ALPHA, 0, 0, 0, null, "H_Z1", 0.7);
   ctr->children = DList_Create();
   
   cbi_nodefuncs_t textfuncs = { .Update = Menu_TextUpdateFunc };
   cbi_nodefuncs_t btnfuncs = { .Click = Menu_ButtonClickFunc };
   CBI_InsertNode(ctr->children, CBI_ButtonAlloc(BTNAF_RESPOND_LEFT, 0, 20, 20, &btnfuncs, "button"));
   CBI_InsertNode(ctr->children, CBI_TextAlloc(0, 0, 8, 8, &textfuncs, "yay it works"));
   CBI_InsertNode(ctr->children, CBI_TextAlloc(TXTAF_RAINBOWS, 0, 10, 10, &textfuncs, "yay it works"));
   CBI_InsertNode(ctr->children, CBI_TextAlloc(0, 0, 12, 12, &textfuncs, "yay it works"));
   
   // Main list
   cbi->ui = DList_Create();
   CBI_InsertNode(cbi->ui, ctr);
   
   cbi->wasinit = true;
}

[[__call("ScriptI")]]
void Lith_PlayerUpdateCBI(player_t *p)
{
   register cbi_t *cbi = &p->cbi;
   
   if(cbi->open)
   {
      cbi->cur.x -= p->yawv * 800.0f;
      
      if(ACS_GetCVar("invertmouse"))
         cbi->cur.y += p->pitchv * 800.0f;
      else
         cbi->cur.y -= p->pitchv * 800.0f;
      
      if(cbi->cur.x < 0) cbi->cur.x = 0;
      if(cbi->cur.y < 0) cbi->cur.y = 0;
      if(cbi->cur.x > 320) cbi->cur.x = 320;
      if(cbi->cur.y > 200) cbi->cur.y = 200;
      
      CBI_NodeListUpdate(cbi->ui, p, cbi->cur);
      
      int click = 0;
      int hold = 0;
      if(ButtonPressed(p, BT_ATTACK))
         click = 2;
      else if(ButtonPressed(p, BT_ALTATTACK))
         click = 1;
      else if(p->buttons & BT_ATTACK)
         hold = 2;
      else if(p->buttons & BT_ALTATTACK)
         hold = 1;
      
      if(click && !CBI_NodeListClick(cbi->ui, p, cbi->cur, click == 2))
         ACS_LocalAmbientSound("player/cbi/clickinvalid", 127);
      else if(hold)
         CBI_NodeListHold(cbi->ui, p, cbi->cur, hold == 2);
   }
}

[[__call("ScriptI")]]
void Lith_PlayerDrawCBI(player_t *p)
{
   register cbi_t *cbi = &p->cbi;
   
   ACS_SetHudSize(320, 200);
   
   DrawSpritePlain("H_Z2", hid_cbi_cursor, 0.1 + (int)cbi->cur.x, 0.1 + (int)cbi->cur.y, TICSECOND);
   
   CBI_NodeListDraw(cbi->ui, hid_end_cbi);
}

//
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// Key Scripts.
//

[[__call("ScriptS"), __extern("ACS")]]
void Lith_KeyOpenCBI()
{
   player_t *p = &players[ACS_PlayerNumber()];
   
   if(p->health < 1)
      return;
   
   p->cbi.open = !p->cbi.open;
   
   if(p->cbi.open)
   {
      p->frozen++;
      ACS_LocalAmbientSound("player/cbi/open", 127);
   }
   else
   {
      p->frozen--;
      ACS_LocalAmbientSound("player/cbi/close", 127);
   }
}

//
// ---------------------------------------------------------------------------


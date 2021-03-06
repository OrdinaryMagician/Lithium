/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Miscellaneous GUI functions.
 *
 * ---------------------------------------------------------------------------|
 */

#include "common.h"
#include "p_player.h"
#include "w_world.h"

/* Static Objects ---------------------------------------------------------- */

noinit static char tcbuf[4096];

/* Extern Functions -------------------------------------------------------- */

stkcall
void G_Auto(struct gui_state *g, u32 id, i32 x, i32 y, i32 w, i32 h, bool slide)
{
   x += g->ox;
   y += g->oy;

   /* check clip versus cursor (if clipping), then check control versus cursor */
   if(!g->useclip || aabb(g->clpxS, g->clpyS, g->clpxE, g->clpyE, g->cx, g->cy))
      if(aabb(x, y, x + w, y + h, g->cx, g->cy))
   {
      g->hot = id;

      if(g->active == 0 && g->clicklft)
         g->active = id;
   }

   /* check slide state */
   if(slide && g->slide != id && g->active == id) {
      g->slide      = id;
      g->slidetime  = 1;
      g->slidecount = 0;
   }
}

stkcall
void G_Init(struct gui_state *g, void *state)
{
   g->state = state;
   g->gfxprefix = c":UI:";
}

stkcall
void G_UpdateState(struct gui_state *g, struct player *p)
{
   bool inverted = p->getCVarI(sc_player_invertmouse);

   /* Due to ZDoom being ZDoom, GetUserCVar with invertmouse does nothing. */
   /* This breaks network sync so we can only do it in singleplayer. */
   if(singleplayer) inverted |= ACS_GetCVar(sc_invertmouse);

   g->old = g->cur;

   k32 xmul = p->getCVarK(sc_gui_xmul);
   k32 ymul = p->getCVarK(sc_gui_xmul);

                g->cx -= p->yawv   * (800.0lk * xmul);
   if(inverted) g->cy += p->pitchv * (800.0lk * ymul);
   else         g->cy -= p->pitchv * (800.0lk * ymul);

   g->cx = minmax(g->cx, 0, g->w);
   g->cy = minmax(g->cy, 0, g->h);

   g->clicklft = p->buttons & BT_ATTACK;
   g->clickrgt = p->buttons & BT_ALTATTACK;
   g->clickany = g->clicklft || g->clickrgt;

   if(!g->clickany)
      g->slide = 0;
   else if(g->slidecount)
      g->slidetime++;
}

stkcall
void G_Begin(struct gui_state *g, i32 w, i32 h)
{
   if(!w) w = 320;
   if(!h) h = 200;

   g->hot = 0;

   ACS_SetHudSize(g->w = w, g->h = h);
   SetSize(g->w, g->h);
}

stkcall
void G_End(struct gui_state *g, enum cursor curs)
{
   str cgfx;

   switch(curs) {
   default:
   case gui_curs_green:       cgfx = sp_UI_Cursor;            break;
   case gui_curs_pink:        cgfx = sp_UI_CursorPink;        break;
   case gui_curs_blue:        cgfx = sp_UI_CursorBlue;        break;
   case gui_curs_orange:      cgfx = sp_UI_CursorOrange;      break;
   case gui_curs_red:         cgfx = sp_UI_CursorRed;         break;
   case gui_curs_white:       cgfx = sp_UI_CursorWhite;       break;
   case gui_curs_outline:     cgfx = sp_UI_CursorOutline;     break;
   case gui_curs_outline2:    cgfx = sp_UI_CursorOutline2;    break;
   case gui_curs_outlineinv:  cgfx = sp_UI_CursorOutlineInv;  break;
   case gui_curs_outline2inv: cgfx = sp_UI_CursorOutline2Inv; break;
   }

   PrintSprite(cgfx, g->cx,1, g->cy,1);

   if(!g->clickany)
      g->active = 0;
}

stkcall
void G_Clip(struct gui_state *g, i32 x, i32 y, i32 w, i32 h, i32 ww)
{
   g->useclip = true;
   g->clpxE = x + w;
   g->clpyE = y + h;

   if(ww == 0) ww = w;
   SetClipW(g->clpxS = x, g->clpyS = y, w, h, ww);
}

stkcall
void G_ClipRelease(struct gui_state *g)
{
   g->useclip = g->clpxS = g->clpyS = g->clpxE = g->clpyE = 0;
   ClearClip();
}

stkcall
void G_TypeOn(struct gui_state *g, struct gui_typ *typeon, str text)
{
   typeon->txt = text;
   typeon->len = ACS_StrLen(text);
   typeon->pos = 0;
}

#define RemoveTextColorsImpl() \
   i32 j = 0; \
   \
   if(size > countof(tcbuf)) return nil; \
   \
   for(i32 i = 0; i < size; i++) \
   { \
      if(s[i] == '\C') \
      { \
         i++; \
         if(s[i] == '[') \
            while(s[i] && s[i++] != ']'); \
         else \
            i++; \
      } \
      \
      if(i >= size || j >= size || !s[i]) \
         break; \
      \
      tcbuf[j++] = s[i]; \
   } \
   \
   tcbuf[j++] = '\0'; \
   \
   return tcbuf;

stkcall
cstr RemoveTextColors_str(astr s, i32 size)
{
   RemoveTextColorsImpl();
}

stkcall
cstr RemoveTextColors(cstr s, i32 size)
{
   RemoveTextColorsImpl();
}

stkcall
struct gui_typ const *G_TypeOnUpdate(struct gui_state *g, struct gui_typ *typeon)
{
   i32 num = ACS_Random(2, 15);

   if((typeon->pos += num) > typeon->len)
      typeon->pos = typeon->len;

   return typeon;
}

/* EOF */

/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Buffered token stream.
 *
 * ---------------------------------------------------------------------------|
 */

#ifndef m_tokbuf_h
#define m_tokbuf_h

#include "m_token.h"
#include "m_types.h"

#include <stdbool.h>

/* Extern Functions -------------------------------------------------------- */

        void          TBufCtor (struct tokbuf *tb);
        void          TBufDtor (struct tokbuf *tb);
        struct token *TBufGet  (struct tokbuf *tb);
        struct token *TBufPeek (struct tokbuf *tb);
stkcall struct token *TBufUnGet(struct tokbuf *tb);
stkcall struct token *TBufReGet(struct tokbuf *tb);
stkcall struct token *TBufBack (struct tokbuf *tb, i32 n);
        bool          TBufDrop (struct tokbuf *tb, i32 t);
stkcall i32           TBufProc (struct token *tok);
stkcall i32           TBufProcL(struct token *tok);

/* Types ------------------------------------------------------------------- */

enum
{
   tokproc_next,
   tokproc_done,
   tokproc_skip
};

struct tokbuf
{
   __prop get   {operator(): TBufGet  (this)}
   __prop peek  {operator(): TBufPeek (this)}
   __prop unget {operator(): TBufUnGet(this)}
   __prop reget {operator(): TBufReGet(this)}
   __prop back  {operator(): TBufBack (this)}
   __prop drop  {operator(): TBufDrop (this)}

   struct origin orig;

   FILE *fp;

   struct token *toks;

   i32 tpos, tend;
   i32 bbeg, bend;

   stkcall i32 (*tokProcess)(struct token *tok);
};

#endif

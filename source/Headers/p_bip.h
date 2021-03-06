/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Info page data.
 *
 * ---------------------------------------------------------------------------|
 */

#if defined(LITH_X)
LITH_X(WEAPONS,      "Weapons")
LITH_X(ENEMIES,      "Adversaries")
LITH_X(ITEMS,        "Items")
LITH_X(YOURSELF,     "Yourself")
LITH_X(UPGRADES,     "Upgrades")
LITH_X(PLACES,       "Locations")
LITH_X(CORPORATIONS, "Companies")
LITH_X(MAIL,         "Mail")
#undef LITH_X
#elif !defined(p_bip_h)
#define p_bip_h

#include "m_list.h"

#define ForCategory() for(i32 categ = BIPC_NONE + 1; categ < BIPC_MAX; categ++)
#define ForPage() for_list(struct page *page, bip->infogr[categ])
#define ForCategoryAndPage() ForCategory() ForPage()

/* Extern Functions -------------------------------------------------------- */

script void P_BIP_PInit(struct player *p);
optargs(1) struct page *P_BIP_Unlock(struct player *p, cstr name);
stkcall void P_BIP_PQuit(struct player *p);
script optargs(1) void P_BIP_GiveMail(struct player *p, str title, i32 flags);

/* Types ------------------------------------------------------------------- */

enum
{
   BIPC_NONE,
#define LITH_X(name, capt) BIPC_##name,
#include "p_bip.h"
   BIPC_EXTRA,
   BIPC_MAX,
   BIPC_MAIN,
   BIPC_SEARCH
};

enum
{
   MAILF_NoPrint    = 1 << 0,
   MAILF_AllPlayers = 1 << 1,
};

typedef char bip_name_t[20];
typedef bip_name_t bip_unlocks_t[5];

struct page
{
   bip_name_t name;
   str  shname;
   str  image;
   str  body;
   str  title;
   i32  height;
   i32  category;
   bool unlocked;
   list link;
   bip_unlocks_t unlocks;
};

struct page_info
{
   str shname;
   str flname;
   str body;
};

struct bip
{
   /* Stats */
   u32 categoryavail[BIPC_MAX];
   u32 categorymax[BIPC_MAX];

   u32 pageavail;
   u32 pagemax;

   u32 mailreceived;
   u32 mailtrulyreceived;

   /* State */
   bool init;

   struct page *curpage;
   struct page *result[8];

   u32 curcategory;
   u32 lastcategory;

   u32 resnum;
   u32 rescur;

   /* Info */
   list infogr[BIPC_MAX];
};

/* Extern Functions -------------------------------------------------------- */

struct page_info PageInfo(struct page const *page);

#endif

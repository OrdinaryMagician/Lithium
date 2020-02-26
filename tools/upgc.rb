#!/usr/bin/env ruby
LICENSE = <<_end_
 * ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
_end_
##
## Upgrade info text compiler.
##
## ---------------------------------------------------------------------------|

SCR = /[[:digit:]]/
PRF = /[[:digit:]]/
MUL = /-?\./
GRP = /[[:alpha:]]/

HEAD = <<_end_
 *
 * This file was generated by upgc.
 * Edit only if you aren't going to recompile.
 *
#{LICENSE}
_end_

def reqs res
   res[1...-1].split(?|).each{|a| a.replace "UR_#{a}"}.join(?|)
end

ifp, ofh = open(ARGV[0], "rt"), open(ARGV[1], "wt")
ofc, off = open(ARGV[2], "wt"), open(ARGV[3], "wt")

ofh.puts <<_end_h_; ofc.puts <<_end_c_; off.puts <<_end_f_
/* pk7/lzscript/Constants/u_names.zsc
 * ---------------------------------------------------------------------------|
#{HEAD}
 */

enum /* UpgradeName */
{
_end_h_
/* ---------------------------------------------------------------------------|
#{HEAD}
 */

#include "u_common.h"

StrEntON

/* Extern Objects ---------------------------------------------------------- */

struct upgradeinfo const upgrinfobase[UPGR_BASE_MAX] = {
_end_c_
/* ---------------------------------------------------------------------------|
#{HEAD}
 */

#include "u_func_beg.h"

_end_f_

cat = ""

for ln in ifp
   ln.chomp!
   next if ln.empty?

   res = ln[1..-1]
   case ln[0]
   when ?:; cat.replace "UC_#{res}"
   when ?+
      res = res.split
      nam = res.shift
      inf = res.shift
      inf.replace(inf == ?- ? "0" : %("#{inf}"))
      scr = if res[0][0] =~ SCR; res.shift else ?0 end
      pcl = res.shift
      flg = []

      for c, i in res.shift.chars.each_with_index
            if c == ?-;           next
         elsif c == ?A && i == 0; flg << c
         elsif c == ?D && i == 1; flg << c
         elsif c == ?U && i == 2; flg << c
         elsif c == ?R && i == 3; flg << c
         elsif c == ?E && i == 4; flg << c
         else raise "you done fucked up" end
      end

      prf = if res[0] && res[0][0] =~ PRF;       res.shift   else ?0 end
      mul = if res[0] && res[0]    =~ MUL;       res.shift   else ?0 end
      grp = if res[0] && res[0][0] =~ GRP; "UG_#{res.shift}" else ?0 end
      req = if res[0] && res[0][0] == ?(;  reqs  res.shift   else ?0 end

      ofh.puts "   UPGR_#{nam},"

      ofc.puts <<_end_
   {{"#{nam}", #{inf}, #{scr}}, #{pcl}, #{cat}, #{prf}, #{grp}, #{req}, #{mul}, UPGR_#{nam}},
_end_

      unless flg.empty?
         off.puts <<_end_
Case(#{nam})
   #{flg.map{|a| "#{a}(#{nam})\n"}.join("   ")}
_end_
      end
   end
end

ofh.puts <<_end_h_; ofc.puts <<_end_c_; off.puts <<_end_f_
   UPGR_BASE_MAX
};

/* EOF */
_end_h_
};

/* EOF */
_end_c_
#include "u_func_end.h"

/* EOF */
_end_f_

## EOF

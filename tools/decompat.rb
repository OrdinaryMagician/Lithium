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
## ZScript ↔ C shared syntax preprocessor.
##
## ---------------------------------------------------------------------------|

def tozsc lns, out
   out.write <<_end_
/* ---------------------------------------------------------------------------|
 *
 * This file was generated by decompat.
 * Edit only if you aren't going to recompile.
 *
#{LICENSE}
 */
_end_

   for ln in lns
      out.write ln.chomp.sub(/enum \/\* (.+) \*\//, 'enum \1') + ?\n
   end
end

for arg in ARGV
   lns = open(arg, "rt").readlines()
   zscs = []
   loop do
      ln = lns.shift
      if ln =~ /^.. (.+\.zsc)$/
         zscs << $~[1]
      else
         break
      end
   end
   for zsc in zscs
      tozsc lns, open(zsc, "wt")
   end
end

## EOF

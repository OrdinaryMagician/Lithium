#!/usr/bin/env ruby
# frozen_string_literal: true
## ---------------------------------------------------------------------------|
##
## Distributed under the CC0 public domain license.
## By Alison Sanderson. Attribution is encouraged, though not required.
## See licenses/cc0.txt for more information.
##
## ---------------------------------------------------------------------------|
##
## Token stream.
##
## ---------------------------------------------------------------------------|

class TokenStream
   def initialize inner, eof
      @inner = inner
      @eof   = eof
   end

   def peek
      begin
         @inner.peek
      rescue StopIteration
         @eof
      end
   end

   def next
      begin
         @inner.next
      rescue StopIteration
         @eof
      end
   end

   def peek_or type, default = nil
      if self.peek.type == type
         tok = self.next
         if block_given?
            yield tok
         else
            tok.text
         end
      else
         default
      end
   end

   def drop type
      if self.peek.type == type
         self.next
      else
         nil
      end
   end

   def while_drop type
      loop do
         yield
         break unless self.drop type
      end
   end

   def until_drop type
      loop do
         break if self.drop type
         yield
      end
   end
end

## EOF

#!/usr/bin/env ruby

def escape text
   text.gsub(/((?<m>\\)(?!c))|(?<m>")/, "\\\\\\k<m>").gsub(/\n/, "\\n")
end

def split_arg text, sp
   text.split(sp, 2).map {|s| s.strip}
end

def single_line outf, out, set
   outf.write "\"#{out}\" = \"#{escape set}\";\n"
end

def comment outf, arg
   outf.write "\n//#{arg}\n"
end

def buf_lines outf, type, buf
   buf.pop if buf.last.chomp.empty?
   case type
   when :just
      outf.write(buf.each.with_index.inject("") do |sum, (s, i)|
         if i < buf.size-1 then sum + "   \"#{escape s.chomp}\\n\"\n"
         else                   sum + "   \"#{escape s.chomp}\";\n" end
      end)
   when :conc
      buf = [*buf, "\n"].each_cons(2).map do |s, n|
            if s == "\n" then "\n\n"
         elsif n == "\n" then s.chomp
         else                 s.chomp + " " end
      end
      outf.write(buf.each.with_index.inject("") do |sum, (s, i)|
         if i < buf.size-1 then sum + "   \"#{escape s}\"\n"
         else                   sum + "   \"#{escape s.chomp}\";\n" end
      end)
   end
end

def parse_file outf, fp
   wr, buf = nil, nil
   for ln in fp
      type, arg = ln[0..1], ln.chomp[2..-1]
      case type
      when "##"
         buf_lines outf, wr, buf and wr = nil if wr
         comment outf, arg
      when "=="
         buf_lines outf, wr, buf and wr = nil if wr
         out, set = split_arg arg, "|"
         single_line outf, out, set
      when "%%"
         buf_lines outf, wr, buf if wr
         wr, buf = :just, []
         outf.write "\"#{arg.strip}\" =\n"
      when "@@"
         buf_lines outf, wr, buf if wr
         wr, buf = :conc, []
         outf.write "\"#{arg.strip}\" =\n"
      else
         buf << ln if wr
      end
   end
   buf_lines outf, wr, buf if wr
end

def procdir inf, type, arg
   case type
   when "comment"
      comment inf[:f], " " + arg
   when "put data"
      set, out = split_arg arg, "->"
      single_line inf[:f], out, set
   when "put file"
      fnam, out = split_arg arg, "->"
      inf[:f].write "\"#{out}\" =\n"
      buf_lines inf[:f], :just, open(fnam, "rt").read.chomp.lines
   when "parse file"
      parse_file inf[:f], open(arg, "rt")
   end
end

def procfdr inf, type, arg
   case type
   when "in"
      if (type, arg = split_arg arg, " ") and type == "directory"
         inf[:d] = arg
      elsif type == "file"
         inf[:f] = open("#{inf[:d]}/#{arg}", "wb")
         inf[:f].write "// This file was generated by compilefs.\n" +
                       "// Edit only if you aren't going to recompile.\n" +
                       "[enu default]\n\n"
      end
   when "include"
      run_file open(arg, "rt"), inf
   end
end

def run_file fp, inf = nil
   inf = {f: nil, d: nil} unless inf
   for ln in fp
      if (type, arg = split_arg ln, ":") and arg
         procdir inf, type, arg
      elsif (type, arg = split_arg ln, " ") and arg
         procfdr inf, type, arg
      end
   end
end

for arg in ARGV
   run_file open(arg, "rt")
end

## EOF
![Lithium](http://mab.greyserv.net/f/Lithium_logo.png)

# Overview

A mod in which you shoot things until they die. See the ZDoom forums thread linked above for more details.

# Running

If you wish to run an in-development version of the mod, you can click the "Clone or download" button and then "Download ZIP".

Once you've done that you can then load the `pk7` folder into ZDoom as you would any other mod.

# Code

The code in Lithium is half C and half DECORATE. The C code is compiled to ACS bytecode with [GDCC](https://github.com/DavidPH/GDCC), an awesome compiler made by a crazy compiler man.

The C code is rather terse at times, and scarcely commented, but hopefully it should be understandable enough.

I tend to use a lot of GDCC's C extensions, so some of the code may be a bit confusing for purists.

# Licensing

All of the content and source code in this project is copyrighted unless otherwise stated. Do not use it elsewhere without permission. See pk7/credits.txt for more information.

All DECORATE code in the `pk7/lscripts` folder is public domain as defined by [the CC0 license](http://creativecommons.org/publicdomain/zero/1.0/).

The LithOS3 library is distributed under the MIT license as detailed in `pk7/licenses/LICENSE.lithos3.txt`.

GDCC's libc is distributed under the LGPL license as detailed in `pk7/licenses/copylib.txt`.

Respect content creators, ask permission before using something from this mod.


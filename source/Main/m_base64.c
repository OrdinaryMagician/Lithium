/*
 * Base64 encoding/decoding (RFC1341)
 *
 * Copyright (c) 2005-2011, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed, used, and modified under the terms of
 * BSD license:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name(s) of the above-listed copyright holder(s) nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "m_base64.h"
#include "m_memory.h"
#include "m_types.h"
#include "m_str.h"

#include <stdlib.h>
#include <string.h>

static byte const base64_table[65] =
   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/**
 * base64_encode - Base64 encode
 * @src: Data to be encoded
 * @len: Length of the data to be encoded
 * @out_len: Pointer to output length variable, or %nil if not used
 * Returns: Allocated buffer of out_len bytes of encoded data,
 * or %nil on failure
 *
 * Caller is responsible for freeing the returned buffer. Returned buffer is
 * nul terminated to make it easier to use as a C string. The nul terminator is
 * not included in out_len.
 */
byte *base64_encode(const byte *src, size_t len, size_t *out_len)
{
   byte *out, *pos;
   const byte *end, *in;
   size_t olen;

   olen = len * 4 / 3 + 4; /* 3-byte blocks to 4-byte */
   olen++; /* nul termination */
   if (olen < len)
      return nil; /* integer overflow */
   out = Malloc(olen);
   if (out == nil)
      return nil;

   end = src + len;
   in = src;
   pos = out;
   while (end - in >= 3) {
      *pos++ = base64_table[in[0] >> 2];
      *pos++ = base64_table[((in[0] & 0x03) << 4) | (in[1] >> 4)];
      *pos++ = base64_table[((in[1] & 0x0f) << 2) | (in[2] >> 6)];
      *pos++ = base64_table[in[2] & 0x3f];
      in += 3;
   }

   if (end - in) {
      *pos++ = base64_table[in[0] >> 2];
      if (end - in == 1) {
         *pos++ = base64_table[(in[0] & 0x03) << 4];
         *pos++ = '=';
      } else {
         *pos++ = base64_table[((in[0] & 0x03) << 4) |
                     (in[1] >> 4)];
         *pos++ = base64_table[(in[1] & 0x0f) << 2];
      }
      *pos++ = '=';
   }

   *pos = '\0';
   if (out_len)
      *out_len = pos - out;
   return out;
}

/**
 * base64_decode - Base64 decode
 * @src: Data to be decoded
 * @len: Length of the data to be decoded
 * @out_len: Pointer to output length variable
 * Returns: Allocated buffer of out_len bytes of decoded data,
 * or %nil on failure
 *
 * Caller is responsible for freeing the returned buffer.
 */
byte *base64_decode(const byte *src, size_t len, size_t *out_len)
{
   noinit
   static byte dtable[256];
   static bool dtable_init;

   byte *out, *pos, block[4], tmp;
   size_t i, count, olen;
   i32 pad = 0;

   if(!dtable_init)
   {
      dtable_init = true;
      fastmemset(dtable, 0x80, 256);
      for (i = 0; i < sizeof base64_table - 1; i++)
         dtable[base64_table[i]] = (byte)i;
      dtable['='] = 0;

      count = 0;
      for (i = 0; i < len; i++) {
         if (dtable[src[i]] != 0x80)
            count++;
      }
   }

   if (count == 0 || count % 4)
      return nil;

   olen = count / 4 * 3;
   pos = out = Malloc(olen);
   if (out == nil)
      return nil;

   count = 0;
   for (i = 0; i < len; i++) {
      tmp = dtable[src[i]];
      if (tmp == 0x80)
         continue;

      if (src[i] == '=')
         pad++;
      block[count] = tmp;
      count++;
      if (count == 4) {
         *pos++ = ((block[0] << 2) | (block[1] >> 4)) & 0xFF;
         *pos++ = ((block[1] << 4) | (block[2] >> 2)) & 0xFF;
         *pos++ = ((block[2] << 6) | block[3])        & 0xFF;
         count = 0;
         if (pad) {
            if (pad == 1)
               pos--;
            else if (pad == 2)
               pos -= 2;
            else {
               /* Invalid padding */
               Dalloc(out);
               return nil;
            }
            break;
         }
      }
   }

   *out_len = pos - out;
   return out;
}


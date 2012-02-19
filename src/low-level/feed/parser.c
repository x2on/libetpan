/*
 * libEtPan! -- a mail stuff library
 *
 * Copyright (C) 2001, 2005 - DINH Viet Hoa
 * Copyright (C) 2006 Andrej Kacian <andrej@kacian.sk>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the libEtPan! project nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "parser.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>

#ifdef HAVE_ICONV
#include <iconv.h>
#endif

#include "newsfeed.h"

#include "newsfeed_private.h"
#include "parser_rss20.h"
#include "parser_rdf.h"
#include "parser_atom10.h"
#include "parser_atom03.h"

enum {
  FEED_TYPE_NONE,
  FEED_TYPE_RDF,
  FEED_TYPE_RSS_20,
  FEED_TYPE_ATOM_03,
  FEED_TYPE_ATOM_10
};


void newsfeed_parser_set_expat_handlers(struct newsfeed_parser_context * ctx)
{
}

size_t newsfeed_writefunc(void * ptr, size_t size, size_t nmemb, void * data)
{
    return 0;
}

const char * newsfeed_parser_get_attribute_value(const char ** attr,
    const char * name)
{
  unsigned int i;
  
  if ((attr == NULL) || (name == NULL))
    return NULL;
  
  for(i = 0 ; attr[i] != NULL && attr[i + 1] != NULL ; i += 2 ) {
    if (strcmp(attr[i], name) == 0)
      return attr[i + 1];
  }
  
  /* We haven't found anything. */
  return NULL;
}

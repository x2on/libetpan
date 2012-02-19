#ifndef NEWSFEED_PRIVATE_H

#define NEWSFEED_PRIVATE_H

#include "newsfeed_types.h"
#include "mmapstring.h"


struct newsfeed_parser_context {
  unsigned int depth;
  unsigned int location;
  MMAPString *str;
  
  struct newsfeed * feed;
  struct newsfeed_item * curitem;
  
  int error;
  
};

time_t newsfeed_rfc822_date_parse(char * text);

#endif

#ifndef REQUEST_HEADER_H_
#define REQUEST_HEADER_H_
#include <glib.h>
#include <stdlib.h>

#include "cookie.h"

#define CRLF "\n\r"

typedef struct RequestHeader{
  gchar *method;
  gchar *url;
  gchar *http_version;

  gchar *accept;
  gchar *accept_charset;
  gchar *accept_encoding;
  gchar *accept_language;
  gchar *accept_datetime;
  gchar *authorization;
  gchar *cache_control;
  gchar *connection;
//  gchar *cookie;
  GPtrArray* cookies;
  gchar *content_length;
  gchar *content_md5;
  gchar *content_type;
  gchar *date;
  gchar *expect;
  gchar *from;
  gchar *host;
  gchar *if_match;
  gchar *if_modified_since;
  gchar *if_none_match;
  gchar *if_range;
  gchar *if_unmodified_since;
  gchar *max_forwards;
  gchar *pragma;
  gchar *proxy_authorization;
  gchar *range;
  gchar *referer;
  gchar *te;
  gchar *upgrade;
  gchar *user_agent;
  gchar *via;
  gchar *warning;
} RequestHeader;

extern RequestHeader* voy_request_header_initialize();
extern void           voy_request_header_set(gchar* const key,  gchar* const value, RequestHeader *request_header);
extern gchar*         voy_request_header_get(gchar* const key, RequestHeader *request_header);
extern void           voy_request_header_print(RequestHeader *request_header);
extern void           voy_request_header_free(RequestHeader *request_header);
extern void           voy_request_header_create(GPtrArray *request_query, RequestHeader *request_header);
extern void           voy_request_header_set_request(gchar* const request_string, RequestHeader *request_header);
#endif /*REQUEST_HEADER_H_*/
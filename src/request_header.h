#ifndef REQUEST_HEADER_H_
#define REQUEST_HEADER_H_
#include <glib.h>

typedef struct RequestHeader{
  gchar *accept;
  gchar *accept_charset;
  gchar *accept_encoding;
  gchar *accept_language;
  gchar *accept_datetime;
  gchar *authorization;
  gchar *cache_control;
  gchar *connection;
  gchar *cookie;
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

extern struct RequestHeader* initialize_request_header(GPtrArray *request_query);
extern void set_request_fields(gchar* const key,  gchar* const value, RequestHeader *request_header);
extern void g_print_request_fields(RequestHeader *request_header);
extern void g_free_request_header(RequestHeader *request_header);
#endif /*REQUEST_HEADER_H_*/
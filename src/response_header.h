#ifndef VOY_RESPONSE_HEADER_H
#define VOY_RESPONSE_HEADER_H
#include <glib.h>

typedef struct VoyResponseHeader{
  gchar *access_control_allow_origin;
  gchar *accept_ranges;
  gchar *age;
  gchar *allow;
  gchar *cache_control;
  gchar *connection;
  gchar *content_encoding;
  gchar *content_language;
  gchar *content_length;
  gchar *content_location;
  gchar *content_md5;
  gchar *content_disposition;
  gchar *content_range;
  gchar *content_type;
  gchar *date;
  gchar *e_tag;
  gchar *expires;
  gchar *last_modified;
  gchar *link;
  gchar *location;
  gchar *p3p;
  gchar *pragma;
  gchar *proxy_authenticate;
  gchar *refresh;
  gchar *retry_after;
  gchar *server;
  gchar *set_cookie;
  gchar *status;
  gchar *strict_transport_security;
  gchar *trailer;
  gchar *transfer_encoding;
  gchar *vary;
  gchar *via;
  gchar *warning;
  gchar *www_authenticate;
} VoyResponseHeader;

#endif
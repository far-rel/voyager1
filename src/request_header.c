#include <glib.h>
#include <stdlib.h>

#include "request_header.h"

static struct RequestHeader* initialize_request_header(GPtrArray *request_query) {
  struct RequestHeader *header = malloc(sizeof(struct RequestHeader));
  int i;

  for(i = 0; i < request_query->len; i++) {
    gchar* tmp;
    gchar **splitted;
    tmp = (gchar*)g_ptr_array_index(request_query, i);
    splitted = g_strsplit(tmp, ": ", 0);
    set_request_fields(splitted[0], splitted[1], header);
    g_strfreev(splitted);
  }
  return header;
}

void set_request_fields(const gchar* key, const gchar* value, RequestHeader *request_header) {
  gchar* tmp = value;
  if(key == NULL || value == NULL) {
    return;
  }
  
  if (g_strcmp0(key, "Accept") == 0) {
     request_header->accept = tmp;
  }
  else if (g_strcmp0(key, "AcceptCharset") == 0) {
     request_header->accept_charset = tmp;
  }
  else if (g_strcmp0(key, "AcceptEncoding") == 0) {
     request_header->accept_encoding = tmp;
  }
  else if (g_strcmp0(key, "AcceptLanguage") == 0) {
     request_header->accept_language = tmp;
  }
  else if (g_strcmp0(key, "AcceptDatetime") == 0) {
     request_header->accept_datetime = tmp;
  }
  else if (g_strcmp0(key, "Authorization") == 0) {
     request_header->authorization = tmp;
  }
  else if (g_strcmp0(key, "CacheControl") == 0) {
     request_header->cache_control = tmp;
  }
  else if (g_strcmp0(key, "Connection") == 0) {
     request_header->connection = tmp;
  }
  else if (g_strcmp0(key, "Cookie") == 0) {
     request_header->cookie = tmp;
  }
  else if (g_strcmp0(key, "ContentLength") == 0) {
     request_header->content_length = tmp;
  }
  else if (g_strcmp0(key, "ContentMD5") == 0) {
     request_header->content_m_d5 = tmp;
  }
  else if (g_strcmp0(key, "ContentType") == 0) {
     request_header->content_type = tmp;
  }
  else if (g_strcmp0(key, "Date") == 0) {
     request_header->date = tmp;
  }
  else if (g_strcmp0(key, "Expect") == 0) {
     request_header->expect = tmp;
  }
  else if (g_strcmp0(key, "From") == 0) {
     request_header->from = tmp;
  }
  else if (g_strcmp0(key, "Host") == 0) {
     request_header->host = tmp;
  }
  else if (g_strcmp0(key, "IfMatch") == 0) {
     request_header->if_match = tmp;
  }
  else if (g_strcmp0(key, "IfModifiedSince") == 0) {
     request_header->if_modified_since = tmp;
  }
  else if (g_strcmp0(key, "IfNoneMatch") == 0) {
     request_header->if_none_match = tmp;
  }
  else if (g_strcmp0(key, "IfRange") == 0) {
     request_header->if_range = tmp;
  }
  else if (g_strcmp0(key, "IfUnmodifiedSince") == 0) {
     request_header->if_unmodified_since = tmp;
  }
  else if (g_strcmp0(key, "MaxForwards") == 0) {
     request_header->max_forwards = tmp;
  }
  else if (g_strcmp0(key, "Pragma") == 0) {
     request_header->pragma = tmp;
  }
  else if (g_strcmp0(key, "ProxyAuthorization") == 0) {
     request_header->proxy_authorization = tmp;
  }
  else if (g_strcmp0(key, "Range") == 0) {
     request_header->range = tmp;
  }
  else if (g_strcmp0(key, "Referer") == 0) {
     request_header->referer = tmp;
  }
  else if (g_strcmp0(key, "Te") == 0) {
     request_header->te = tmp;
  }
  else if (g_strcmp0(key, "Upgrade") == 0) {
     request_header->upgrade = tmp;
  }
  else if (g_strcmp0(key, "UserAgent") == 0) {
     request_header->user_agent = tmp;
  }
  else if (g_strcmp0(key, "Via") == 0) {
     request_header->via = tmp;
  }
  else if (g_strcmp0(key, "Warning") == 0) {
     request_header->warning = tmp;
  }
}

static void g_print_request_fields(RequestHeader *request_header) {
  g_print("Printing request_headers: \n");
  if(request_header->accept != NULL) {
    g_print("\taccept: %s\n", request_header->accept);
  }
  if(request_header->accept_charset != NULL) {
    g_print("\taccept_charset: %s\n", request_header->accept_charset);
  }
  if(request_header->accept_encoding != NULL) {
    g_print("\taccept_encoding: %s\n", request_header->accept_encoding);
  }
  if(request_header->accept_language != NULL) {
    g_print("\taccept_language: %s\n", request_header->accept_language);
  }
  if(request_header->accept_datetime != NULL) {
    g_print("\taccept_datetime: %s\n", request_header->accept_datetime);
  }
  if(request_header->authorization != NULL) {
    g_print("\tauthorization: %s\n", request_header->authorization);
  }
  if(request_header->cache_control != NULL) {
    g_print("\tcache_control: %s\n", request_header->cache_control);
  }
  if(request_header->connection != NULL) {
    g_print("\tconnection: %s\n", request_header->connection);
  }
  if(request_header->cookie != NULL) {
    g_print("\tcookie: %s\n", request_header->cookie);
  }
  if(request_header->content_length != NULL) {
    g_print("\tcontent_length: %s\n", request_header->content_length);
  }
  if(request_header->content_m_d5 != NULL) {
    g_print("\tcontent_m_d5: %s\n", request_header->content_m_d5);
  }
  if(request_header->content_type != NULL) {
    g_print("\tcontent_type: %s\n", request_header->content_type);
  }
  if(request_header->date != NULL) {
    g_print("\tdate: %s\n", request_header->date);
  }
  if(request_header->expect != NULL) {
    g_print("\texpect: %s\n", request_header->expect);
  }
  if(request_header->from != NULL) {
    g_print("\tfrom: %s\n", request_header->from);
  }
  if(request_header->host != NULL) {
    g_print("\thost: %s\n", request_header->host);
  }
  if(request_header->if_match != NULL) {
    g_print("\tif_match: %s\n", request_header->if_match);
  }
  if(request_header->if_modified_since != NULL) {
    g_print("\tif_modified_since: %s\n", request_header->if_modified_since);
  }
  if(request_header->if_none_match != NULL) {
    g_print("\tif_none_match: %s\n", request_header->if_none_match);
  }
  if(request_header->if_range != NULL) {
    g_print("\tif_range: %s\n", request_header->if_range);
  }
  if(request_header->if_unmodified_since != NULL) {
    g_print("\tif_unmodified_since: %s\n", request_header->if_unmodified_since);
  }
  if(request_header->max_forwards != NULL) {
    g_print("\tmax_forwards: %s\n", request_header->max_forwards);
  }
  if(request_header->pragma != NULL) {
    g_print("\tpragma: %s\n", request_header->pragma);
  }
  if(request_header->proxy_authorization != NULL) {
    g_print("\tproxy_authorization: %s\n", request_header->proxy_authorization);
  }
  if(request_header->range != NULL) {
    g_print("\trange: %s\n", request_header->range);
  }
  if(request_header->referer != NULL) {
    g_print("\treferer: %s\n", request_header->referer);
  }
  if(request_header->te != NULL) {
    g_print("\tte: %s\n", request_header->te);
  }
  if(request_header->upgrade != NULL) {
    g_print("\tupgrade: %s\n", request_header->upgrade);
  }
  if(request_header->user_agent != NULL) {
    g_print("\tuser_agent: %s\n", request_header->user_agent);
  }
  if(request_header->via != NULL) {
    g_print("\tvia: %s\n", request_header->via);
  }
  if(request_header->warning != NULL) {
    g_print("\twarning: %s\n", request_header->warning);
  }
}
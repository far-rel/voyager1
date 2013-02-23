#include <glib.h>
#include <stdlib.h>

#include "request_header.h"

struct RequestHeader* initialize_request_header(GPtrArray *request_query) {
  RequestHeader *header = calloc(1, sizeof(struct RequestHeader));
  int i;

  for(i = 0; i < request_query->len; i++) {
    gchar* tmp;
    gchar **splitted;
    tmp = (gchar*)g_ptr_array_index(request_query, i);
    splitted = g_strsplit(tmp, ": ", 0);
    g_print("%s\n", tmp);
    set_request_fields(splitted[0], splitted[1], header);
    g_strfreev(splitted);
  }
  return header;
}

void set_request_fields(gchar* const key, gchar* const value, RequestHeader *request_header) {
  if(key == NULL || value == NULL) {
    return;
  }
  
  if (g_strcmp0(key, "Accept") == 0) {
     request_header->accept = g_strdup(value);
  }
  else if (g_strcmp0(key, "Accept-Charset") == 0) {
     request_header->accept_charset = g_strdup(value);
  }
  else if (g_strcmp0(key, "Accept-Encoding") == 0) {
     request_header->accept_encoding = g_strdup(value);
  }
  else if (g_strcmp0(key, "Accept-Language") == 0) {
     request_header->accept_language = g_strdup(value);
  }
  else if (g_strcmp0(key, "Accept-Datetime") == 0) {
     request_header->accept_datetime = g_strdup(value);
  }
  else if (g_strcmp0(key, "Authorization") == 0) {
     request_header->authorization = g_strdup(value);
  }
  else if (g_strcmp0(key, "Cache-Control") == 0) {
     request_header->cache_control = g_strdup(value);
  }
  else if (g_strcmp0(key, "Connection") == 0) {
     request_header->connection = g_strdup(value);
  }
  else if (g_strcmp0(key, "Cookie") == 0) {
     request_header->cookie = g_strdup(value);
  }
  else if (g_strcmp0(key, "Content-Length") == 0) {
     request_header->content_length = g_strdup(value);
  }
  else if (g_strcmp0(key, "Content-MD5") == 0) {
     request_header->content_md5 = g_strdup(value);
  }
  else if (g_strcmp0(key, "Content-Type") == 0) {
     request_header->content_type = g_strdup(value);
  }
  else if (g_strcmp0(key, "Date") == 0) {
     request_header->date = g_strdup(value);
  }
  else if (g_strcmp0(key, "Expect") == 0) {
     request_header->expect = g_strdup(value);
  }
  else if (g_strcmp0(key, "From") == 0) {
     request_header->from = g_strdup(value);
  }
  else if (g_strcmp0(key, "Host") == 0) {
     request_header->host = g_strdup(value);
  }
  else if (g_strcmp0(key, "If-Match") == 0) {
     request_header->if_match = g_strdup(value);
  }
  else if (g_strcmp0(key, "If-Modified-Since") == 0) {
     request_header->if_modified_since = g_strdup(value);
  }
  else if (g_strcmp0(key, "If-None-Match") == 0) {
     request_header->if_none_match = g_strdup(value);
  }
  else if (g_strcmp0(key, "If-Range") == 0) {
     request_header->if_range = g_strdup(value);
  }
  else if (g_strcmp0(key, "If-Unmodified-Since") == 0) {
     request_header->if_unmodified_since = g_strdup(value);
  }
  else if (g_strcmp0(key, "Max-Forwards") == 0) {
     request_header->max_forwards = g_strdup(value);
  }
  else if (g_strcmp0(key, "Pragma") == 0) {
     request_header->pragma = g_strdup(value);
  }
  else if (g_strcmp0(key, "Proxy-Authorization") == 0) {
     request_header->proxy_authorization = g_strdup(value);
  }
  else if (g_strcmp0(key, "Range") == 0) {
     request_header->range = g_strdup(value);
  }
  else if (g_strcmp0(key, "Referer") == 0) {
     request_header->referer = g_strdup(value);
  }
  else if (g_strcmp0(key, "TE") == 0) {
     request_header->te = g_strdup(value);
  }
  else if (g_strcmp0(key, "Upgrade") == 0) {
     request_header->upgrade = g_strdup(value);
  }
  else if (g_strcmp0(key, "User-Agent") == 0) {
     request_header->user_agent = g_strdup(value);
  }
  else if (g_strcmp0(key, "Via") == 0) {
     request_header->via = g_strdup(value);
  }
  else if (g_strcmp0(key, "Warning") == 0) {
     request_header->warning = g_strdup(value);
  }
}

void g_print_request_fields(RequestHeader *request_header) {
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
  if(request_header->content_md5 != NULL) {
    g_print("\tcontent_md5: %s\n", request_header->content_md5);
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

void g_free_request_header(RequestHeader *request_header) {
  if(request_header != NULL) {
    if(request_header->accept != NULL) {
      g_free(request_header->accept);
    }
    if(request_header->accept_charset != NULL) {
      g_free(request_header->accept_charset);
    }
    if(request_header->accept_encoding != NULL) {
      g_free(request_header->accept_encoding);
    }
    if(request_header->accept_language != NULL) {
      g_free(request_header->accept_language);
    }
    if(request_header->accept_datetime != NULL) {
      g_free(request_header->accept_datetime);
    }
    if(request_header->authorization != NULL) {
      g_free(request_header->authorization);
    }
    if(request_header->cache_control != NULL) {
      g_free(request_header->cache_control);
    }
    if(request_header->connection != NULL) {
      g_free(request_header->connection);
    }
    if(request_header->cookie != NULL) {
      g_free(request_header->cookie);
    }
    if(request_header->content_length != NULL) {
      g_free(request_header->content_length);
    }
    if(request_header->content_md5 != NULL) {
      g_free(request_header->content_md5);
    }
    if(request_header->content_type != NULL) {
      g_free(request_header->content_type);
    }
    if(request_header->date != NULL) {
      g_free(request_header->date);
    }
    if(request_header->expect != NULL) {
      g_free(request_header->expect);
    }
    if(request_header->from != NULL) {
      g_free(request_header->from);
    }
    if(request_header->host != NULL) {
      g_free(request_header->host);
    }
    if(request_header->if_match != NULL) {
      g_free(request_header->if_match);
    }
    if(request_header->if_modified_since != NULL) {
      g_free(request_header->if_modified_since);
    }
    if(request_header->if_none_match != NULL) {
      g_free(request_header->if_none_match);
    }
    if(request_header->if_range != NULL) {
      g_free(request_header->if_range);
    }
    if(request_header->if_unmodified_since != NULL) {
      g_free(request_header->if_unmodified_since);
    }
    if(request_header->max_forwards != NULL) {
      g_free(request_header->max_forwards);
    }
    if(request_header->pragma != NULL) {
      g_free(request_header->pragma);
    }
    if(request_header->proxy_authorization != NULL) {
      g_free(request_header->proxy_authorization);
    }
    if(request_header->range != NULL) {
      g_free(request_header->range);
    }
    if(request_header->referer != NULL) {
      g_free(request_header->referer);
    }
    if(request_header->te != NULL) {
      g_free(request_header->te);
    }
    if(request_header->upgrade != NULL) {
      g_free(request_header->upgrade);
    }
    if(request_header->user_agent != NULL) {
      g_free(request_header->user_agent);
    }
    if(request_header->via != NULL) {
      g_free(request_header->via);
    }
    if(request_header->warning   != NULL) {
      g_free(request_header->warning);
    }
    g_free(request_header);
  }
}
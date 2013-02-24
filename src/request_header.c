#include <glib.h>
#include <stdlib.h>

#include "request_header.h"


void voy_request_header_set(gchar* const key, gchar* const value, RequestHeader *request_header) {
  if(key == NULL || value == NULL) {
    return;
  }
  
  if (g_strcmp0(key, "Method") == 0) {
   request_header->method = g_strdup(value);
  }
  else if (g_strcmp0(key, "URL") == 0) {
   request_header->url = g_strdup(value);
  }
  else if (g_strcmp0(key, "HTTP-Version") == 0) {
   request_header->http_version = g_strdup(value);
  }
  else if (g_strcmp0(key, "Accept") == 0) {
   request_header->accept = g_strdup(value);
  }
  else if (g_strcmp0(key, "AcceptCharset") == 0) {
  request_header->accept_charset = g_strdup(value);
  }
  else if (g_strcmp0(key, "AcceptEncoding") == 0) {
  request_header->accept_encoding = g_strdup(value);
  }
  else if (g_strcmp0(key, "AcceptLanguage") == 0) {
  request_header->accept_language = g_strdup(value);
  }
  else if (g_strcmp0(key, "AcceptDatetime") == 0) {
  request_header->accept_datetime = g_strdup(value);
  }
  else if (g_strcmp0(key, "Authorization") == 0) {
  request_header->authorization = g_strdup(value);
  }
  else if (g_strcmp0(key, "CacheControl") == 0) {
  request_header->cache_control = g_strdup(value);
  }
  else if (g_strcmp0(key, "Connection") == 0) {
  request_header->connection = g_strdup(value);
  }
  else if (g_strcmp0(key, "Cookie") == 0) {
  request_header->cookie = g_strdup(value);
  }
  else if (g_strcmp0(key, "ContentLength") == 0) {
  request_header->content_length = g_strdup(value);
  }
  else if (g_strcmp0(key, "ContentMD5") == 0) {
  request_header->content_md5 = g_strdup(value);
  }
  else if (g_strcmp0(key, "ContentType") == 0) {
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
  else if (g_strcmp0(key, "IfMatch") == 0) {
  request_header->if_match = g_strdup(value);
  }
  else if (g_strcmp0(key, "IfModifiedSince") == 0) {
  request_header->if_modified_since = g_strdup(value);
  }
  else if (g_strcmp0(key, "IfNoneMatch") == 0) {
  request_header->if_none_match = g_strdup(value);
  }
  else if (g_strcmp0(key, "IfRange") == 0) {
  request_header->if_range = g_strdup(value);
  }
  else if (g_strcmp0(key, "IfUnmodifiedSince") == 0) {
  request_header->if_unmodified_since = g_strdup(value);
  }
  else if (g_strcmp0(key, "MaxForwards") == 0) {
  request_header->max_forwards = g_strdup(value);
  }
  else if (g_strcmp0(key, "Pragma") == 0) {
  request_header->pragma = g_strdup(value);
  }
  else if (g_strcmp0(key, "ProxyAuthorization") == 0) {
  request_header->proxy_authorization = g_strdup(value);
  }
  else if (g_strcmp0(key, "Range") == 0) {
  request_header->range = g_strdup(value);
  }
  else if (g_strcmp0(key, "Referer") == 0) {
  request_header->referer = g_strdup(value);
  }
  else if (g_strcmp0(key, "te") == 0) {
  request_header->te = g_strdup(value);
  }
  else if (g_strcmp0(key, "Upgrade") == 0) {
  request_header->upgrade = g_strdup(value);
  }
  else if (g_strcmp0(key, "UserAgent") == 0) {
  request_header->user_agent = g_strdup(value);
  }
  else if (g_strcmp0(key, "Via") == 0) {
  request_header->via = g_strdup(value);
  }
  else if (g_strcmp0(key, "Warning") == 0) {
  request_header->warning = g_strdup(value);
  }
}

gchar* voy_request_header_get(gchar* const key, RequestHeader *request_header) {
  if(key == NULL) 
    return "";

  if (g_strcmp0(key, "method") == 0 && (request_header->method != NULL))
    return request_header->method;

  else if (g_strcmp0(key, "url") == 0 && (request_header->url != NULL))
    return request_header->url;

  else if (g_strcmp0(key, "http_version") == 0 && (request_header->http_version != NULL))
    return request_header->http_version;

  else if (g_strcmp0(key, "accept") == 0 && (request_header->accept != NULL))
    return request_header->accept;

  else if (g_strcmp0(key, "accept_charset") == 0 && (request_header->accept_charset != NULL))
    return request_header->accept_charset;

  else if (g_strcmp0(key, "accept_encoding") == 0 && (request_header->accept_encoding != NULL))
    return request_header->accept_encoding;

  else if (g_strcmp0(key, "accept_language") == 0 && (request_header->accept_language != NULL))
    return request_header->accept_language;

  else if (g_strcmp0(key, "accept_datetime") == 0 && (request_header->accept_datetime != NULL))
    return request_header->accept_datetime;

  else if (g_strcmp0(key, "accept_datetime") == 0 && (request_header->accept_datetime != NULL))
    return request_header->authorization;

  else if (g_strcmp0(key, "cache_control") == 0 && (request_header->cache_control != NULL))
    return request_header->cache_control;

  else if (g_strcmp0(key, "connection") == 0 && (request_header->connection != NULL))
    return request_header->connection;

  else if (g_strcmp0(key, "cookie") == 0 && (request_header->cookie != NULL))
    return request_header->cookie;

  else if (g_strcmp0(key, "content_length") == 0 && (request_header->content_length != NULL))
    return request_header->content_length;

  else if (g_strcmp0(key, "content_md5") == 0 && (request_header->content_md5 != NULL))
    return request_header->content_md5;

  else if (g_strcmp0(key, "content_type") == 0 && (request_header->content_type != NULL))
    return request_header->content_type;

  else if (g_strcmp0(key, "date") == 0 && (request_header->date != NULL))
    return request_header->date;

  else if (g_strcmp0(key, "expect") == 0 && (request_header->expect != NULL))
    return request_header->expect;

  else if (g_strcmp0(key, "from") == 0 && (request_header->from != NULL))
    return request_header->from;

  else if (g_strcmp0(key, "host") == 0 && (request_header->host != NULL))
    return request_header->host;

  else if (g_strcmp0(key, "if_match") == 0 && (request_header->if_match != NULL))
    return request_header->if_match;

  else if (g_strcmp0(key, "if_modified_since") == 0 && (request_header->if_modified_since != NULL))
    return request_header->if_modified_since;

  else if (g_strcmp0(key, "if_none_match") == 0 && (request_header->if_none_match != NULL))
    return request_header->if_none_match;

  else if (g_strcmp0(key, "if_range") == 0 && (request_header->if_range != NULL))
    return request_header->if_range;

  else if (g_strcmp0(key, "if_unmodified_since") == 0 && (request_header->if_unmodified_since != NULL))
    return request_header->if_unmodified_since;

  else if (g_strcmp0(key, "max_forwards") == 0 && (request_header->max_forwards != NULL))
    return request_header->max_forwards;

  else if (g_strcmp0(key, "pragma") == 0 && (request_header->pragma != NULL))
    return request_header->pragma;

  else if (g_strcmp0(key, "proxy_authorization") == 0 && (request_header->proxy_authorization != NULL))
    return request_header->proxy_authorization;

  else if (g_strcmp0(key, "range") == 0 && (request_header->range != NULL))
    return request_header->range;

  else if (g_strcmp0(key, "referer") == 0 && (request_header->referer != NULL))
    return request_header->referer;

  else if (g_strcmp0(key, "te") == 0 && (request_header->te != NULL))
    return request_header->te;

  else if (g_strcmp0(key, "upgrade") == 0 && (request_header->upgrade != NULL))
    return request_header->upgrade;

  else if (g_strcmp0(key, "user_agent") == 0 && (request_header->user_agent != NULL))
    return request_header->user_agent;

  else if (g_strcmp0(key, "via") == 0 && (request_header->via != NULL))
    return request_header->via;

  else if (g_strcmp0(key, "warning") == 0 && (request_header->warning != NULL))
    return request_header->warning;
  else 
    return "";

}

void voy_request_header_print(RequestHeader *request_header) {
  g_print("\tmethod:%s\n", voy_request_header_get("method", request_header));
  g_print("\turl:%s\n", voy_request_header_get("url", request_header)); 
  g_print("\thttp_version:%s\n", voy_request_header_get("http_version", request_header));
  g_print("\taccept:%s\n", voy_request_header_get("accept", request_header));
  g_print("\taccept_charset:%s\n", voy_request_header_get("accept_charset", request_header));
  g_print("\taccept_encoding:%s\n", voy_request_header_get("accept_encoding", request_header));
  g_print("\taccept_language:%s\n", voy_request_header_get("accept_language", request_header));
  g_print("\taccept_datetime:%s\n", voy_request_header_get("accept_datetime", request_header));
  g_print("\tauthorization:%s\n", voy_request_header_get("authorization", request_header));
  g_print("\tcache_control:%s\n", voy_request_header_get("cache_control", request_header));
  g_print("\tconnection:%s\n", voy_request_header_get("connection", request_header));
  g_print("\tcookie:%s\n", voy_request_header_get("cookie", request_header));
  g_print("\tcontent_length:%s\n", voy_request_header_get("content_length", request_header));
  g_print("\tcontent_md5:%s\n", voy_request_header_get("content_md5", request_header));
  g_print("\tcontent_type:%s\n", voy_request_header_get("content_type", request_header));
  g_print("\tdate:%s\n", voy_request_header_get("date", request_header));
  g_print("\texpect:%s\n", voy_request_header_get("expect", request_header));
  g_print("\tfrom:%s\n", voy_request_header_get("from", request_header));
  g_print("\thost:%s\n", voy_request_header_get("host", request_header));
  g_print("\tif_match:%s\n", voy_request_header_get("if_match", request_header));
  g_print("\tif_modified_since:%s\n", voy_request_header_get("if_modified_since", request_header));
  g_print("\tif_none_match:%s\n", voy_request_header_get("if_none_match", request_header));
  g_print("\tif_range:%s\n", voy_request_header_get("if_range", request_header));
  g_print("\tif_unmodified_since:%s\n", voy_request_header_get("if_unmodified_since", request_header));
  g_print("\tmax_forwards:%s\n", voy_request_header_get("max_forwards", request_header));
  g_print("\tpragma:%s\n", voy_request_header_get("pragma", request_header));
  g_print("\tproxy_authorization:%s\n", voy_request_header_get("proxy_authorization", request_header));
  g_print("\trange:%s\n", voy_request_header_get("range", request_header));
  g_print("\treferer:%s\n", voy_request_header_get("referer", request_header));
  g_print("\tte:%s\n", voy_request_header_get("te", request_header));
  g_print("\tupgrade:%s\n", voy_request_header_get("upgrade", request_header));
  g_print("\tuser_agent:%s\n", voy_request_header_get("user_agent", request_header));
  g_print("\tvia:%s\n", voy_request_header_get("via", request_header));
  g_print("\twarning:%s\n", voy_request_header_get("warning", request_header));
}

void voy_request_header_free(RequestHeader *request_header) {
  if(request_header != NULL) {
    if(request_header->method != NULL) {
      g_free(request_header->method);
    }
    if(request_header->url != NULL) {
      g_free(request_header->url);
    }
    if(request_header->http_version != NULL) {
      g_free(request_header->http_version);
    }
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



RequestHeader* voy_request_header_initialize() {
  RequestHeader *header = calloc(1, sizeof(struct RequestHeader));
  return header;
}

void voy_request_header_create(GPtrArray *request_query, RequestHeader *request_header) {
  int i;
  gchar* request_params;

  //Header is ok, first line is our request
  if(request_query->len > 0) {
    request_params = (gchar*)g_ptr_array_index(request_query, 0);
    voy_request_header_set_request(request_params, request_header);
    g_free(request_params);
  }

  //Iterate over request fields, and populate request_header
  for(i = 1; i < request_query->len; i++) {
    gchar **request_fragment;
    gchar *tmp;
    tmp = (gchar*)g_ptr_array_index(request_query, i);

    //Split request_fragment into two strings: key, value
    request_fragment = g_strsplit(tmp, ": ", 2);
    voy_request_header_set(request_fragment[0], g_strstrip(request_fragment[1]), request_header);

    g_strfreev(request_fragment);
    g_free(tmp);
  }
}

void voy_request_header_set_request(gchar* const request_string, RequestHeader *request_header) {
  g_assert(request_string);
  gchar **request_params;
  request_params = g_strsplit(request_string, " ", 0);
  voy_request_header_set("Method", g_strstrip(g_strdup(request_params[0])), request_header);
  voy_request_header_set("URL", g_strstrip(g_strdup(request_params[1])), request_header);
  voy_request_header_set("HTTP-Version", g_strstrip(g_strdup(request_params[2])), request_header);
  g_strfreev(request_params);
}

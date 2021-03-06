#include <glib.h>
#include <stdlib.h>
#include <time.h>

#include "cookie.h"

struct VoyCookie *voy_cookie_parse(gchar const *cookie_string) {
  struct VoyCookie *cookie;
  cookie = calloc(sizeof (struct VoyCookie), 1);
  gchar **splitted;
  int i = 0;
  gchar *token;
  splitted = g_strsplit(cookie_string, "; ", -1);
  token = splitted[i];
  while (token != NULL) {
    gchar **key_value = g_strsplit(token, "=", 2);
    voy_cookie_set_value(cookie, key_value[0], key_value[1]);
    g_free(key_value[0]);
    g_free(key_value[1]);
    g_free(key_value);
    g_free(token);
    ++i;
    token = splitted[i];
  }
  g_free(splitted);
  return cookie;
}

gchar *voy_cookie_print(struct VoyCookie const *cookie) {
  gchar *result;
  gchar *tmp;
  result = g_strconcat(cookie->name, "=", cookie->value, NULL);
  if (cookie->domain != NULL) {
    tmp = result;
    result = g_strconcat(tmp, "; Domain=", cookie->domain, NULL);
    g_free(tmp);
  }
  if (cookie->path != NULL) {
    tmp = result;
    result = g_strconcat(tmp, "; Path=", cookie->path, NULL);
    g_free(tmp);
  }
  if (cookie->expires != NULL) {
    gchar *date_time = g_date_time_format(cookie->expires, VOY_COOKIE_TIME_FORMAT);
    tmp = result;
    result = g_strconcat(tmp, "; Expires=", date_time, NULL);
    g_free(date_time);
    g_free(tmp);
  }
  if (cookie->secure == TRUE) {
    tmp = result;
    result = g_strconcat(tmp, "; Secure", NULL);
    g_free(tmp);
  }
  if (cookie->http_only == TRUE) {
    tmp = result;
    result = g_strconcat(tmp, "; HttpOnly", NULL);
    g_free(tmp);
  }
  return result;
}

void voy_cookie_set_value(struct VoyCookie *cookie, gchar const *key, gchar const *value) {
  if (g_strcmp0(key, "Domain") == 0) {
    if (cookie->domain != NULL) g_free(cookie->domain);
    cookie->domain = g_strdup(value);
  } else if (g_strcmp0(key, "Path") == 0) {
    if (cookie->path != NULL) g_free(cookie->path);
    cookie->path = g_strdup(value);
  } else if (g_strcmp0(key, "Expires") == 0) {
    if (cookie->expires != NULL) g_date_time_unref(cookie->expires);
      cookie->expires = voy_cookie_parse_expires_date(value);
  } else if (g_strcmp0(key, "Secure") == 0) {
    cookie->secure = TRUE;
  } else if (g_strcmp0(key, "HttpOnly") == 0) {
    cookie->http_only = TRUE;
  } else {
    if (cookie->name != NULL) g_free(cookie->name);
    if (cookie->value != NULL) g_free(cookie->value);
    cookie->name = g_strdup(key);
    cookie->value = g_strdup(value);
  }

}

void voy_cookie_print_screen(struct VoyCookie const *cookie) {
  if (cookie->name != NULL) {
    g_print("\t\tname: %s\n", cookie->name);
  }
  if (cookie->value != NULL) {
    g_print("\t\tvalue: %s\n", cookie->value);
  }
  if (cookie->expires != NULL) {
    gchar *date_time = g_date_time_format(cookie->expires, VOY_COOKIE_TIME_FORMAT);
    g_print("\t\texpires: %s\n", date_time);
    g_free(date_time);
  }
  if (cookie->domain != NULL) {
    g_print("\t\tdomain: %s\n", cookie->domain);
  }
  if (cookie->path != NULL) {
    g_print("\t\tpath: %s\n", cookie->path);
  }
  if (cookie->secure != NULL) {
    g_print("\t\tsecure: %d\n", cookie->secure);
  }
  if (cookie->http_only != NULL) {
    g_print("\t\thttp_only: %d\n", cookie->http_only);
  }
}

struct GDateTime *voy_cookie_parse_expires_date(char const *date_string) {
  struct tm tm;
  strptime(date_string, VOY_COOKIE_TIME_FORMAT, &tm);
  struct GDateTime *date_time = g_date_time_new(g_time_zone_new("Z"), tm.tm_year + 1900,
    tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  return date_time;
}

void voy_cookie_free(struct VoyCookie *cookie) {
  if (cookie != NULL) {
    if (cookie->name != NULL) {
      g_free(cookie->name);
    }
    if (cookie->value != NULL) {
      g_free(cookie->value);
    }
    if (cookie->domain != NULL) {
      g_free(cookie->domain);
    }
    if (cookie->path != NULL) {
      g_free(cookie->path);
    }
    if (cookie->expires != NULL) {
      g_date_time_unref(cookie->expires);
    }
    g_free(cookie);
  }
}

#include <glib.h>
#include <stdlib.h>

#include "cookie.h"

struct VoyCookie* voy_cookie_parse(gchar const *cookie_string) {
  struct VoyCookie* cookie;
  cookie = malloc(sizeof (struct VoyCookie));
  gchar **splitted;
  int i = 0;
  gchar* token;
  splitted = g_strsplit(cookie_string, "; ", -1);
  token = splitted[i];
  while (token != NULL) {
    char** key_value = g_strsplit(token, "=", 2);
    voy_cookie_set_value(cookie, key_value[0], key_value[1]);
    i++;
    token=splitted[i];
  }
  return cookie;
}

char* voy_cookie_print(struct VoyCookie const *cookie) {
  char* result;
  char* tmp;
  result = g_strconcat(cookie->name, "=", cookie->value, NULL);
  if (cookie->domain != NULL){
    tmp = result;
    result = g_strconcat(tmp, "; Domain=", cookie->domain, NULL);
    g_free(tmp);
  }
  if (cookie->path != NULL){
    tmp = result;
    result = g_strconcat(tmp, "; Path=", cookie->path, NULL);
    g_free(tmp);
  }
  if (cookie->secure == TRUE){
    tmp = result;
    result = g_strconcat(tmp, "; Secure", NULL);
    g_free(tmp);
  }
  if (cookie->http_only == TRUE){
    tmp = result;
    result = g_strconcat(tmp, "; HttpOnly", NULL);
    g_free(tmp);
  }
  return result;
}

void voy_cookie_set_value(struct VoyCookie *cookie, gchar * const key, gchar * const value) {
  if (g_strcmp0(key, "Domain") == 0) {
    cookie->domain = value;
  } else if(g_strcmp0(key, "Path") == 0){
    cookie->path = value;
  } else if(g_strcmp0(key, "Expires") == 0){
    
  } else if(g_strcmp0(key, "Secure") == 0){
    cookie->secure = TRUE;
  } else if(g_strcmp0(key, "HttpOnly") == 0){
    cookie->http_only = TRUE;
  } else {
    cookie->name = key;
    cookie->value = value;
  }

}

void voy_cookie_print_screen(struct VoyCookie const *cookie){
  if (cookie->name != NULL){
    g_print("\tname: %s\n", cookie->name);
  }
  if (cookie->value != NULL){
    g_print("\tvalue: %s\n", cookie->value);
  }
  if (cookie->domain != NULL){
    g_print("\tdomain: %s\n", cookie->domain);
  }
  if (cookie->path != NULL){
    g_print("\tpath: %s\n", cookie->path);
  }
  if (cookie->secure != NULL){
    g_print("\tsecure: %d\n", cookie->secure);
  }
  if (cookie->http_only != NULL){
    g_print("\thttp_only: %d\n", cookie->http_only);
  }
}

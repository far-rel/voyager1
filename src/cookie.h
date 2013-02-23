#ifndef VOY_COOKIE_H
#define	VOY_COOKIE_H

#include <glib.h>

char *VOY_COOKIE_TIME_FORMAT = "%a, %e-%b-%y %T %Z";

typedef struct VoyCookie{
  gchar* name;
  gchar* value;
  gchar* domain;
  gchar* path;
  GDateTime* expires;
  gboolean secure;
  gboolean http_only;
} VoyCookie;

extern struct VoyCookie* voy_cookie_parse(gchar const *cookie_string);
extern char* voy_cookie_print(struct VoyCookie const *cookie);
extern void voy_cookie_set_value(struct VoyCookie *cookie, gchar * const key, gchar * const value);
extern void voy_cookie_print_screen(struct VoyCookie const *cookie);

#endif	/* VOY_COOKIE_H */


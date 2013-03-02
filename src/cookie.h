#ifndef VOY_COOKIE_H
#define	VOY_COOKIE_H

#include <glib.h>

#define VOY_COOKIE_TIME_FORMAT "%a, %d-%b-%Y %H:%M:%S GMT"

typedef struct VoyCookie{
  gchar *name;
  gchar *value;
  gchar *domain;
  gchar *path;
  GDateTime *expires;
  gboolean secure;
  gboolean http_only;
} VoyCookie;

extern struct VoyCookie *voy_cookie_parse(gchar const *cookie_string);
extern gchar *voy_cookie_print(struct VoyCookie const *cookie);
extern void voy_cookie_set_value(struct VoyCookie *cookie, gchar const * key, gchar const * value);
extern void voy_cookie_print_screen(struct VoyCookie const *cookie);
extern struct GDateTime* voy_cookie_parse_expires_date(gchar const *date_string);
extern void voy_cookie_free(struct VoyCookie *cookie);

#endif	/* VOY_COOKIE_H */


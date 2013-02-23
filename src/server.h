#ifndef SERVER_H
#define	SERVER_H

#include <glib.h>
#include <gnet.h>

#define TIMEOUT 10000
#define BLANK_LINE "\r\n"

static GTcpSocket* normal_server = NULL;
static void normal_sig_int (int signum);
static GTcpSocket* initialize_server(gint port);
static void handle_client(GTcpSocket* client);

#endif	/* SERVER_H */


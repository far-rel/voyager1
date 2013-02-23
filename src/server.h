#ifndef SERVER_H
#define	SERVER_H

#include <glib.h>
#include <gnet.h>

#define TIMEOUT 10000
#define BLANK_LINE "\r\n"

extern void normal_sig_int (int signum);
extern GTcpSocket* initialize_server(gint port);
extern void handle_client(GTcpSocket* client);

#endif	/* SERVER_H */


#include <glib.h>
#include <gnet.h>

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "request_header.h"
#include "response_header.h"
#include "server.h"


int main(int argc, char **argv) {
  GTcpSocket *server;
  GTcpSocket *client = NULL;
  server = initialize_server(3000);
  g_assert(server);

  signal (SIGINT, normal_sig_int);

  while ((client = gnet_tcp_socket_server_accept (server)) != NULL) {
    GTimer *benchmark_time = g_timer_new();
    g_timer_start(benchmark_time);

    handle_client(client);
    g_timer_stop(benchmark_time);
    g_print("Client handled within: %2.2fms\n\n", g_timer_elapsed(benchmark_time, NULL) * 1000);
    gnet_tcp_socket_delete (client);
    g_timer_reset(benchmark_time);   
    g_timer_destroy(benchmark_time);   
  }
  
  exit(EXIT_SUCCESS);
  return 0;
}

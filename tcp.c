#include <glib.h>
#include <gnet.h>

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "include/request_header.c"

#define TIMEOUT 10000
#define BLANK_LINE "\r\n"

static GTcpSocket* normal_server = NULL;
static void normal_sig_int (int signum);
static GTcpSocket* initialize_server(gint port);
static void handle_client(GTcpSocket* client);

int main(int argc, char **argv) {
  GTcpSocket *server;
  GTcpSocket *client = NULL;
  GTimer *benchmark_time;
  server = initialize_server(3000);
  g_assert(server);

  signal (SIGINT, normal_sig_int);

  while ((client = gnet_tcp_socket_server_accept (server)) != NULL) {
    benchmark_time = g_timer_new();
    g_timer_start(benchmark_time);

    handle_client(client);
    gnet_tcp_socket_delete (client);

    g_timer_stop(benchmark_time);
    g_print("Client handled within: %2.2fms\n\n", g_timer_elapsed(benchmark_time, NULL) * 1000);
  }
  g_timer_reset(benchmark_time);

  exit(EXIT_SUCCESS);
  return 0;
}


static void 
normal_sig_int (int signum) {
  gnet_tcp_socket_delete (normal_server);
  exit (EXIT_FAILURE);
}

static GTcpSocket*
initialize_server(gint server_port) {
  GTcpSocket *server;
  GInetAddr *addr;
  gint port;
  gchar *name;

  server = gnet_tcp_socket_server_new_with_port(server_port);
  normal_server = server;
  
  addr = gnet_tcp_socket_get_local_inetaddr(server);
  g_assert(addr);

  name = gnet_inetaddr_get_canonical_name(addr);
  g_assert(name);

  port = gnet_inetaddr_get_port(addr);
  g_print("Voyager1 started at %s:%d\n\n", name, port);

  gnet_inetaddr_delete (addr);
  g_free(name);

  return server;
}

static void
handle_client(GTcpSocket *client) {
  RequestHeader *request_header;
  GIOChannel *ioclient;
  GInetAddr *addr;
  GIOError error;
  GPtrArray *request_query;

  gchar* name;
  gint port;

  gchar read_buffer[1024];
  gchar write_buffer[1024];

  gsize read_buffer_n;
  gsize write_buffer_n;

  
  ioclient = gnet_tcp_socket_get_io_channel(client);
  g_assert (ioclient);

  addr = gnet_tcp_socket_get_remote_inetaddr(client);
  g_assert (addr);
  name = gnet_inetaddr_get_canonical_name (addr);
  g_assert (name);
  port = gnet_inetaddr_get_port (addr);
  g_print ("Accepted connection from %s:%d\n", name, port);
  g_free(name);
  
  request_query = g_ptr_array_new();

  while ((error = gnet_io_channel_readline(ioclient, 
                                            read_buffer, 
                                            sizeof(read_buffer), 
                                            &read_buffer_n)) == G_IO_ERROR_NONE && (read_buffer_n > 0))
  {
    gchar* tmp;
    if(g_strcmp0(read_buffer, BLANK_LINE) == 0) {
      break;
    }else {
      tmp = g_strdup(read_buffer);
      g_ptr_array_add(request_query, tmp);
    }
  }

  
  request_header = initialize_request_header(request_query);
  
  g_stpcpy(write_buffer, "HTTP/1.0 200 OK\r\nContent-type: text/html; charset=utf-8\r\n\r\n<h1>Hello from server!</h1>");
  write_buffer_n = strlen(write_buffer);
  gnet_io_channel_writen(ioclient, write_buffer, write_buffer_n, &write_buffer_n);
  g_ptr_array_free(request_query, TRUE);
}

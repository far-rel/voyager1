#include <glib.h>
#include <gnet.h>
#include <stdlib.h>
#include <string.h>


#include "server.h"
#include "request_header.h"

void 
normal_sig_int (int signum) {
  exit (EXIT_FAILURE);
}

GTcpSocket*
initialize_server(gint server_port) {
  GTcpSocket *server;
  GInetAddr *addr;
  gint port;
  gchar *name;

  server = gnet_tcp_socket_server_new_with_port(server_port);
  
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

void
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
  g_print_request_fields(request_header);
  
  g_stpcpy(write_buffer, "HTTP/1.0 200 OK\r\nContent-type: text/html; charset=utf-8\r\n\r\n<h1>Hello from server!</h1>");
  write_buffer_n = strlen(write_buffer);
  gnet_io_channel_writen(ioclient, write_buffer, write_buffer_n, &write_buffer_n);
  g_ptr_array_free(request_query, TRUE);
  
}


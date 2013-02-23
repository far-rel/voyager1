CFLAGS=-Wall
GLIB=`pkg-config --cflags --libs glib-2.0` 
GNET=`pkg-config --cflags --libs gnet-2.0`
all: voyager1

request_header.o: src/request_header.c
	gcc $(GLIB) $(CFLAGS) -c src/request_header.c -o request_header.o
	
response_header.o: src/response_header.c
	gcc $(GLIB) $(CFLAGS) -c src/response_header.c -o response_header.o	
	
server.o: src/server.c response_header.o request_header.o
	gcc $(GLIB) $(GNET) $(CFLAGS) -c src/server.c response_header.o request_header.o -o server.o	
	
voyager1: src/voyager1.c server.o
	gcc $(GLIB) $(GNET) $(CFLAGS) src/voyager1.c server.o -o voyager1
CFLAGS=-Wall -lm
GLIB=$(shell pkg-config --cflags --libs glib-2.0)
GNET=$(shell pkg-config --cflags --libs gnet-2.0)
GFLAGS=$(shell pkg-config --cflags glib-2.0) $(shell pkg-config --cflags gnet-2.0)
GLIBS=$(shell pkg-config --libs glib-2.0) $(shell pkg-config --libs gnet-2.0)

all: voyager1

request_header.o: src/request_header.c
	gcc $(GLIB) $(CFLAGS) -c src/request_header.c -o request_header.o
	
response_header.o: src/response_header.c
	gcc $(GLIB) $(CFLAGS) -c src/response_header.c -o response_header.o	
	
server.o: response_header.o request_header.o src/server.c 
	gcc $(GLIB) $(GNET) $(CFLAGS) -c src/server.c response_header.o request_header.o -o server.o
	ar rcs libvoyager.a server.o request_header.o response_header.o
	
voyager1: src/voyager1.c server.o
	gcc src/voyager1.c  $(GFLAGS) -Wl,-Bdynamic $(GLIBS) -Wl,-Bstatic -L. -lvoyager  -o voyager1
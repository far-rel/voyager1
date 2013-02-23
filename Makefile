CFLAGS=-Wall -lm

GLIB=$(shell pkg-config --cflags --libs glib-2.0)
GNET=$(shell pkg-config --cflags --libs gnet-2.0)

GFLAGS=$(shell pkg-config --cflags glib-2.0) $(shell pkg-config --cflags gnet-2.0)
GLIBS=$(shell pkg-config --libs glib-2.0) $(shell pkg-config --libs gnet-2.0)

FILES=request_header.o response_header.o server.o

all: voyager1

request_header.o: src/request_header.c
	gcc $(GLIB) $(CFLAGS) src/request_header.c -c 
	
response_header.o: src/response_header.c
	gcc $(GLIB) $(CFLAGS) src/response_header.c -c
	
server.o: src/server.c
	gcc $(GLIB) $(GNET) $(CFLAGS) src/server.c -c 

libvoyager: $(FILES)
	ar rcs libvoyager.a $(FILES)

clean:
	rm -f request_header.o response_header.o server.o libvoyager.a

voyager1: clean libvoyager src/voyager1.c 
	gcc src/voyager1.c  $(GFLAGS) $(GLIBS) -lvoyager -L. -o voyager1.out
	chmod +x voyager1.out
	rm -f request_header.o response_header.o server.o libvoyager.a	

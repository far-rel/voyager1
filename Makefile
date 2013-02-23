request_header.o: src/request_header.c
	gcc -c src/request_header.c -o request_header.o
	
response_header.o: src/response_header.c
	gcc -c src/response_header.c -o response_header.o	
	
server.o: src/server.c response_header.o request_header.o
	gcc -c src/server.c response_header.o request_header.o -o server.o	
	
voyager1.o: src/voyager.c
	gcc src/request_header.c -o voyager1
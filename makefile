All: server client
	rm *.o

server: server.o server.h
	gcc -o server server.o server.h

server.o: server.c server.h
	gcc -c server.c

client: client.o client.h
	gcc -o client client.o client.h

client.o: client.c client.h
	gcc -c client.c

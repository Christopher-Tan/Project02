All: server client
	rm *.o

server: server.o networking.o
	gcc -o server server.o networking.o

client: client.o networking.o
	gcc -o client client.o networking.o

networking.o: networking.c networking.h
	gcc -c networking.c

server.o: server.c server.h
	gcc -c server.c

client.o: client.c client.h
	gcc -c client.c
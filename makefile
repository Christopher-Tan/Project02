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

test: game
	./game

game: game.o render.o moving.o
	gcc -o game game.o render.o moving.o `sdl2-config --cflags --libs` -Wall

game.o: game.c game.h
	gcc -c game.c

render.o: render.c render.h
	gcc -c render.c

moving.o: moving.c moving.h
	gcc -c moving.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef server_info
#define server_info

#define PORT "9001"
#define IP "127.0.0.1"

int server_setup();
int server_accept();
int client_setup();

#endif

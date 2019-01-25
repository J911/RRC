#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int server_connect(char *ip, int port);
void write_data(char *buffer, int client_socket);
void read_data(char *buffer, int client_socket);

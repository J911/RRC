#include "message-handler.h"

void write_data(char *buffer, int client_socket) 
{
    write(client_socket, buffer, strlen(buffer) + 1); 
}

void read_data(char *buffer, int client_socket)
{
    read(client_socket, buffer, BUFFER_SIZE);
}
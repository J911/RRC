#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

void write_data(char *buffer, int client_socket);
void read_data(char *buffer, int client_socket);
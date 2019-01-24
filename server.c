#include "server.h"

struct sockaddr_in server_addr;
struct sockaddr_in client_addr;

int build_server (int port)
{
    int server_socket;
    int client_socket;
    
    server_socket  = socket(PF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
        printf("socket creation failed\n");
        return -1;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("bind failed\n");
        exit(1);
    }
    if(listen(server_socket, BACKLOG) == -1)
    {
        printf("listen failed\n");
        return -1;
    }
    return server_socket;
}

void write_data(char *buffer, int client_socket) 
{
    write(client_socket, buffer, strlen(buffer) + 1); 
}

void read_data(char *buffer, int client_socket)
{
    read(client_socket, buffer, BUFFER_SIZE);
}

void close_socket(int client_socket)
{
    close(client_socket);
}

int accept_client(int server_socket) 
{
    int client_addr_size = sizeof(client_addr);
    int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, (unsigned int *)&client_addr_size);
    return client_socket;
}
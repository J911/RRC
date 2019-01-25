#include "client.h"


int server_connect(char *ip, int port)
{
    struct sockaddr_in server_addr;
    int client_socket;
    
    client_socket  = socket(PF_INET, SOCK_STREAM, 0);

    if(client_socket == -1)
    {
        printf("create socket failed\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(*ip);

    if(connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("connect failed\n");
        exit(1);
    }

    return client_socket;
}

void write_data(char *buffer, int client_socket) 
{
    write(client_socket, buffer, strlen(buffer) + 1); 
}

void read_data(char *buffer, int client_socket)
{
    read(client_socket, buffer, BUFFER_SIZE);
}

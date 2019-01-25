#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"
#include "client.h"
#include "message-handler.h"

#define DEFAULT_PORT 911
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_MODE "client"

#define SERVER_MODE "server"
#define CLIENT_MODE "client"

int main(int argc, char *argv[]) 
{
    static struct option long_options[] = {
        { "help", no_argument, 0, 'h' },
        { "version", no_argument, 0, 'v' },
        { "mode", required_argument, 0, 'm' },
        { "port", required_argument, 0, 'p' },
        { "ip", required_argument, 0, 'i' },
        { 0, 0, 0, 0 }
    };

    char opt;
    int port = DEFAULT_PORT;
    char* mode = DEFAULT_MODE;
    char* ip = malloc(sizeof(char) * 15);
    char send_buffer[BUFFER_SIZE + 5];
    char recv_buffer[BUFFER_SIZE + 5];

    ip = DEFAULT_IP;

    while ((opt = getopt_long(argc, argv, "hvm:p:i:", long_options, NULL)) != -1)
    {
        switch (opt) 
        {
            case 'h':
                printf("Usage: %s [options] [command [arg ...]]\n", argv[0]);
                printf("Options:\n");
                printf("  -h, --help     Show this help.\n");
                printf("  -v, --version  Display version information.\n");
                printf("  -m, --mode     Default: client (client / server) \n");
                printf("  -p, --port     Default: 911 \n");
                return 0;
            case 'v':
                printf("remote_command 0.1.0\n");
                return 0;
            case 'm':
                mode = optarg;
                break;
            case 'p':
                port = atoi(optarg);
                break;
            case 'i':
                ip = optarg;
                break;
        }

    }

    if (strcmp(mode, SERVER_MODE) == 0)
    {
        int server_socket;
        server_socket = build_server(port);
        while(1)
        {
            int client_socket = accept_client(server_socket);
            read_data(recv_buffer, client_socket);
            write_data("MESSAGE", client_socket);
            close_socket(client_socket);
        }
    }
    
    return 0;
}
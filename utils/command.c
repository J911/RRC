#include "command.h"

void exec(char *cmd, CallBackPtr callback) 
{
    FILE *fp;
    char path[RESULT_SIZE];
    fp = popen(cmd, "r");

    if (fp == NULL) 
    {
        printf("Failed to run command\n" );
        exit(1);
    }

    while (fgets(cmd, sizeof(cmd)-1, fp) != NULL) 
    {        
        callback(cmd);
    }

    pclose(fp);
}
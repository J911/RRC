#include "command.h"

void exec(char *cmd) 
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
        printf("%s", cmd);
    }

    pclose(fp);
}
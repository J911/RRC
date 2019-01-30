#include <stdio.h>
#include <stdlib.h>

#define RESULT_SIZE 1035

typedef void (*CallBackPtr)(char *);

void exec(char *cmd, CallBackPtr callback);
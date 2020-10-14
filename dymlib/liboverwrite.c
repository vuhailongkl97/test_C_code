#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int rand(void)
{
    int (*original_rand)(void);
    original_rand = dlsym( RTLD_NEXT, "rand");
    if(NULL != original_rand)
    {
        printf("here is overwritten\n");
        srand(time(NULL));
        return original_rand()%100;
    }

    perror("faild find dsym\n");
    return 0;
}

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

void* memcpy(void* dest, void *src, size_t n)
{
    void* (*original_memcpy)(void *, void*, size_t);
    original_memcpy = dlsym( RTLD_NEXT, "memcpy");
    if(NULL != original_memcpy)
    {
        printf("here is overwritten memcpy\n");
        printf("dest %s\n", src);
        return original_memcpy(dest, src, n);
    }

    perror("faild find dsym\n");
    return 0;
}

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
    int i = 0;
    original_memcpy = dlsym( RTLD_NEXT, "memcpy");
    if(NULL != original_memcpy)
    {
        printf("%s fake:%d\n", __func__, __LINE__);
        for(i = 0; i < n ; i++)
            printf("0x%x ", *((char*)src + i));
        printf("\n");
        return original_memcpy(dest, src, n);
    }

    return NULL;
}

char* strcpy(char* dest, char *src)
{
    char* (*original_strcpy)(char* dest, char *src);
    int i = 0;
    original_strcpy = dlsym( RTLD_NEXT, "strcpy");
    if(NULL != original_strcpy)
    {
        printf("%s fake:%d\n", __func__, __LINE__);
        for(i = 0; i < strlen(src) ; i++)
            printf("0x%x ", *((char*)src + i));
        printf("\n");
        return original_strcpy(dest, src);
    }

    printf("error %s\n", __func__);
    return NULL;
}

char* strncpy(char* dest, char *src, size_t n)
{
    char* (*original_strncpy)(char* dest, char *src, size_t);
    int i = 0;
    original_strncpy = dlsym( RTLD_NEXT, "strncpy");
    if(NULL != original_strncpy)
    {
        printf("%s fake:%d\n", __func__, __LINE__);
        for(i = 0; i < n ; i++)
            printf("0x%x ", *((char*)src + i));
        printf("\n");
        return original_strncpy(dest, src, n);
    }
    printf("error %s\n", __func__);

    return NULL;
}


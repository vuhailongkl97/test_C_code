#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void *pthread_create(pthread_t *pt, const pthread_attr_t *attr, \
        void *(*start_routine) (void *), void *arg)
{
    void *(*original_pthread_create)(pthread_t *p, const pthread_attr_t *att, \
        void *(*func) (void *), void *a);
    void *result = NULL;

    original_pthread_create = dlsym(RTLD_NEXT, "pthread_create");

    if(NULL == original_pthread_create)
    {
        perror("dlsym failed\n");

    else
    {
        printf("overwrite here\n");
        result = original_pthread_create(pt , attr, start_routine, arg);
    }

    return result;
}

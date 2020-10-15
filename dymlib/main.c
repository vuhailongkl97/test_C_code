#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func(void *argv)
{
    while(1)
    {
        printf(".");
        sleep(1);
    }
    pthread_exit(NULL);
}
int main(void)
{
    pthread_t pt1;
    void **retval;
    printf("random number is %d\n", rand());
    if (0 < pthread_create(&pt1, NULL, thread_func, NULL))
    {
        printf("pthread failed\n");
        return -1;
    }
    if( 0 != pthread_join(pt, retval))
    {
        printf("pthread join failed\n");
        return -1;
    }

    pthread_exit(NULL);
}

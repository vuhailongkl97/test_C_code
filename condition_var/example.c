#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define THRESHOLD     5

pthread_t tid;

/*Counter la bien toan cuc duoc 2 thread su dung*/
int counter;
pthread_mutex_t mutex;   //khai bao mutex

void threadFunc(void)
{
   pthread_mutex_lock(&mutex);
   printf("pthread has started\n");

   while(counter < THRESHOLD)
   {
       counter += 1;
       sleep(5);
   }

   printf("pthread has finished, counter = %d\n", counter);
   pthread_mutex_unlock(&mutex);

   pthread_exit(NULL);
}

int main(void)
{
   int ret = 0;

   ret = pthread_create(&tid, NULL, &(threadFunc), NULL);
   if (ret != 0)
   {
       printf("pthread created fail\n");
   }

   while(1)
   {
       if(counter == THRESHOLD)
       {
           printf("Global variable counter = %d.\n", counter);
           break;
       }
   }

   pthread_join(tid, NULL);

   return 0;
}


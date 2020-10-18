#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SHARE_FILE "main.c.x"
#define PAGE_SIZE 4096

int main(void)
{
    /*
     * 1. get key with ftok
     * 2. get block with shmget
     * 3. get pointer with shmat
     * */

    /*example read from sharemem*/
    char *str = "hello kkkkk 22222222";
    int block  = 0;
    char *share_ptr = NULL;

    key_t key = ftok(SHARE_FILE, 1);
    assert(-1 != key);

    block = shmget(key, PAGE_SIZE, 0644 | IPC_CREAT );
    assert(-1 != block);

    share_ptr = (char *)shmat(block, NULL, 0);
    assert((char*)-1 != share_ptr);

    printf("content in share_ptr is \"%s\" with block id %d and key %d\n", \
            share_ptr, block, key);
    printf("write \"%s\" to %s\n", str, SHARE_FILE);

    strncpy(share_ptr, str, PAGE_SIZE-1);

    assert(0 == shmdt(share_ptr));

    return 0;
}

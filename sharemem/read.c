#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <error.h>
#include <sys/shm.h>
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

    key_t key = ftok(SHARE_FILE, 1);
    int block;
    char *share_ptr = NULL;

    assert(-1 != key);
    printf("get key successfully :%s's key is %d\n", SHARE_FILE, key);

    block = shmget(key, PAGE_SIZE, 0 );

    assert(-1 != block);

    share_ptr = (char *)shmat(block, NULL, 0);
    assert((char*)-1 != share_ptr);

    printf("content in share_ptr is \"%s\"\n", share_ptr);
    assert(!shmdt(share_ptr));

    return 0;
}

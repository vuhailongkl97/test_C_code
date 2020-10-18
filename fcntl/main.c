#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * use fcntl to check status file
 * may be it's same other api like dup , dup2 , stat ,.. but we can use it for all
 * 1. test status file , permission
 * 2. test locking file
 * */

void show_status_fd(int fd)
{
    int flag = 0;
    printf("%s:%d\n", __func__, __LINE__);
    flag = fcntl(fd, F_GETFL);
    printf("flag of fd %d is %d\n", fd, flag);
}
void lock_file(int fd)
{
  struct flock lock, savelock;

  lock.l_type    = F_WRLCK;   /* Test for any lock on any part of file. */
  lock.l_start   = 0;
  lock.l_whence  = SEEK_SET;
  lock.l_len     = 0;
  savelock = lock;
  fcntl(fd, F_GETLK, &lock);  /* Overwrites lock structure with preventors. */
  if (lock.l_type == F_WRLCK)
  {
     printf("Process %d has a write lock already!\n", lock.l_pid);
     exit(1);
  }
  else if (lock.l_type == F_RDLCK)
  {
     printf("Process %d has a read lock already!\n", lock.l_pid);
     exit(1);
  }
  else
  {
     fcntl(fd, F_SETLK, &savelock);
  }
}

int main(void)
{
    int fd = open("vv", O_RDWR);
    if(fd < 0)
    {
        printf("open file failed %s:%d\n", __func__, __LINE__);
        return -1;
    }

    lock_file(fd);
    sleep(50);
    close(fd);

    return 0;
}

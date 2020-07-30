#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
	int  fd;
	struct flock lock;

	if( argc < 2 )	
	{
		puts("missing argument");
		exit(0);
	}

	/*preparing lock struct */
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start=0; 
	lock.l_le2n=0;
	fd =  open(argv[1], O_RDWR);
	printf("return after call fcntl is %d \n" ,\
		       	fcntl(fd,F_SETLK, &lock));

	sleep(1000);
	close(fd);

	return 0;
}

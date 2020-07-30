#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
int main(int argc , char *argv[])
{
	int fd ;
	
	
        if ( argc < 2) 	
	{
		puts("./execute path_to_file");
		return -1;
	}
	FILE *fp = fopen(argv[1], "r");
	assert(fp);

	char tmp[100];
	memset(tmp, 0, sizeof(tmp));
	fgets(tmp, 100, fp);

	puts(tmp);

	return 0;
}

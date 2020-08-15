#include <stdio.h>
#include <strings.h>


int main(int argc , char *argv[])
{

	int ret = 0;
	//if (argc < 3 ) 
	//{
	//	puts("pass argument 1, 2\n");
	//	return ;
	//}

	//ret = strcasecmp(argv[1], argv[2]);
	printf("ret %d\n", ret);
	int c = atoi(argv[1]);
	printf("%d \n", !c);
	return 0;
}

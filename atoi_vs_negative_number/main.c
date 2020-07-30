#include <stdio.h>
#include <string.h>

int main(void)
{
	char uchar = 0;
	char* negative_str = "-1";

	uchar = atoi(negative_str) ;
	printf("uchar is %d\n", uchar);
	uchar /=8;
	printf("after divide, uchar is %d\n", uchar);

    return 0;
}

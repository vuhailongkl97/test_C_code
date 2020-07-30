#include <stdio.h>

int main(void)
{
	int pid = 0;



	pid = fork();
	if ( pid > 0)
	{
		printf("now, parrent session id is  %d\n", getsid());
		printf("Parrent");
		puts("exitting");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("now, session id is  %d\n", getsid());
		setsid();
		printf("child");
		printf("now, session id is  %d\n", getsid());
		while(1){
			sleep(1);
			printf("now, session id is  %d\n", getsid());
		}

	}
	return 0;
}

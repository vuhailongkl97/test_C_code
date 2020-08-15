#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 

main() {
char *buf;
buf=(char *)malloc(10*sizeof(char));
buf=getlogin();
printf("\n %s \n",buf);
}

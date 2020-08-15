#include <stdio.h>
int main(void)
{
    FILE *fp = fopen("./main.c", "r");

    char buf[100];

    if( NULL == fp)
    {
        return 0;
    }

    char tmp[100];
    while(fgets(buf, 100, fp))
    {
        bzero(tmp, 100);
        sscanf(buf, "%*s%s", tmp);
        puts(tmp);
    }
    fclose(fp);
}

#include <stdlib.h>
#include <stdio.h>
int main()
{
#define mac "longkl"

        char str[101];
        bzero(str, 100);
        FILE *fp = fopen("kkkkk.sh", "a");
        system("./long1.sh");
        fprintf(fp, "bcdf");
        fclose(fp);

        return 0;
}


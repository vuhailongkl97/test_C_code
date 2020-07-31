#include <stdio.h>

int main()
{
    int number;
    FILE* fp = popen("echo 233 ", "r");  
    fscanf(fp, "%d", &number);
    printf("number %d\n", number);
    pclose(fp);

    return 0;
}

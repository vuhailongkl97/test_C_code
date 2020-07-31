#include <stdio.h>
#include <arpa/inet.h>
int main(void)
{
    int ret = 0;
    char tmp[16];

    ret = inet_pton(AF_INET, "1.1.1", tmp);
    printf("ret = %d", ret);
    symlink("./main.c", "abc");
    return 0;
}


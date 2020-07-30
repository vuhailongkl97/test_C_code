#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("./resolv.conf", "r");

    char s[100];
    char name_server[20] = {0}, ip[16] = {0};

    if(fp < 0)
    {
        perror("fopen");
        return -1;
    }
    while(fgets(s, sizeof(s), fp))
    {
        sscanf(s, "%s%s", name_server, ip); 
        if(0 == strncmp(name_server, "nameserver", sizeof(name_server)))
        {
            printf("ip is %s\n", ip);
        }
    }
    fclose(fp);
    return 0;
}


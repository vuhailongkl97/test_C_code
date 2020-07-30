#include <stdio.h> 

int main(void)
{
    char *str = "6,5.5.5.6,4.3.4.2.,fds";
    char a[20], b[20]; 

    sscanf(str, "%*d,%s,%s", a , b);

    printf("a %s\nb: %s\n\n", a, b);
    
    return 0;
}

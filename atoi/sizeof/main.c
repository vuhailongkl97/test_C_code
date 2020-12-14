#include <stdio.h>

typedef struct {
    int x ;
    char b;
    int d;
}test;

int main(void)
{
    int x ; 

    x = ({
            int ret = 10;
            do
            {
                break;
            }while(0);
            ret;

            });
    printf("x = %d\n", x);

    printf("%ld\n", sizeof(typeof(x)));

    printf("addr %p\n", &((test*)0)->d);

    return 0;
}

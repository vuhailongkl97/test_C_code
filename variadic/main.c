#include <stdio.h>
#include <stdarg.h>

int sum_all(int n , ...)
{
    int sum = 0;

    va_list args;
    if(args == NULL)
    {
        printf("no arg");
        return 0;
    }

    va_start(args, n);
    sum = 0;
    for(int i = 0; i< n ; i++)
        sum += va_arg(args, int);

    va_end(args);

    return sum;
}

int main(void)
{
    //printf("%d\n", sum_all(3));
    int n = 10;

    while(n--)
        printf("%d\n", n);

    return 0;
}

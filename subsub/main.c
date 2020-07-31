#include <stdio.h>

#define TRACE(fmt,...) fprintf(stderr, "TRACE @ %s - %d "fmt "\n", __func__, __LINE__, ##__VA_ARGS__)

int main(void)
{
    TRACE("long123 %d", 123);

    return 0;
}

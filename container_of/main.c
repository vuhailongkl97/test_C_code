#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x ;
    char b;
    int d;
}test;

#define containter_of(mstruct, addr, name) ({ \
    int offset = (int)(&((mstruct *)0)->name); \
    addr - offset; \
})

int main(void)
{
    int x ;
    test a;

    memset(&a, 0, sizeof(a));
    char *pb = &(a.d);
    char *parrent_p = containter_of(test, pb, d);


    printf("parent addr = %p\n", &a);
    printf("parent addr = %p with containter of\n", parrent_p);

    printf("same = %d\n", &a == parrent_p);

    return 0;
}

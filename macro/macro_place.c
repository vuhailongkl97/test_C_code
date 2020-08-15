#include <stdio.h>
#define MACROS "longkkl"
#define CONCATENATE_DETAIL(x, y) WAN##x##y
int
main(void)
{
    int WAN1smp = 10;
    printf("%d\n", CONCATENATE_DETAIL(1,smp));
}

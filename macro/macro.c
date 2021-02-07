/*!
 * @file macro.c
 *
 * out MACRO in C language.
 */
#include <stdio.h>

/*!
    @brief concatenation variable

    Output WANxy
 */
#define CONCATENATE_DETAIL(x, y) ( WAN##x##y )

/*!
    @brief concatenation string

    Output abc<str a>
 */
#define CONCATENATION_STR(a) "abc"#a

/*!
    @brief use __VA_ARGS__ in MACRO

 */
#ifdef DEBUG
#define DBG(str,...) \
    fprintf(stderr, "%s:%d "str "\n", __func__, __LINE__ , ##__VA_ARGS__)
#else
#define DBG(str,...)
#endif

int
main(void)
{
    int WAN1smp = 10;
    printf("%d\n", CONCATENATE_DETAIL(1,smp));
    printf("string is %s\n", CONCATENATION_STR(123));
    DBG();
}

/*!
Output:
```
10
0
string is abc123
```
*/

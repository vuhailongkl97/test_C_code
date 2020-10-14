#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    int old;
    char *name;
    int class;
}student;

enum week{ MON = 2, TUE, WEB, THU, FRI, SAT, SUN };

typedef union {
    char* key;
    int length;
}pw;
int passwd;

void test(int x)
{
    printf("hello world\n");
}

int main(void)
{
    student st1 = {SAT, "long", 11};
    pw pass1 ;
    char *const_str = "abcdef";
    pass1.length = 123455;

    test(12);
    srand(time(NULL));
    printf("%d\n", rand());

    return 0;
}

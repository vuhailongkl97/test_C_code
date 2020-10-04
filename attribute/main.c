#include <stdio.h>
#include "main.h"
#include "main.h"
#include "main.h"
#include "main.h"

void __attribute__((constructor)) before_main() {
	puts("hello");

}

int main(void)
{
    printf("\n\nhello2");
    return 0;
}

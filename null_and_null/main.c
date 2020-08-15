#include <stdio.h>

int main(void)
{
	if ("" == NULL)
		puts("okay");
	char abc[100];
	snprintf(abc, 100, "%sabc%s", NULL, "def");
	puts(abc);
	puts("not okay");
}

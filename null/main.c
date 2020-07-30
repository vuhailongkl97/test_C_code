#include <stdio.h>
#include <string.h>

typedef struct m_struct{
   char *x;
   char *y;
}my;

const my myst[] =
{
    {"long1", "1"},
    {"long2", "2"},
    {"long3", "3"},
    {NULL, NULL},
};

int check_contain_str(const char *str, const char *test)
{
    char *tmp_str = NULL;
    char *tmp_test = NULL;
    int ret = -1;

    if(NULL == str || NULL == test)
        return -1;

    tmp_str = (char *)malloc(strlen(str) + 10);

    if (NULL == tmp_str)
    {
        return -1;
    }

    tmp_test = (char *)malloc(strlen(test) + 10);
    if (NULL == tmp_test)
    {
        free(tmp_str);
        return -1;
    }

    sprintf(tmp_str," %s ", str);
    sprintf(tmp_test," %s ", test);

    ret = (NULL != strstr(tmp_test,tmp_str));

    free(tmp_test);
    free(tmp_str);

    return ret;
}

int main ()
{
    const my *p = myst;
char str[100] = {0};

    for (; p->x != NULL; p ++)
{
strcat(str,p->x);
}
puts(str);

    return 0;
}

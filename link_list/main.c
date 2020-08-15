#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

void *fill(void *d);
int  compare(void*d1, void *d2);
int  mfree(void*d);
void  show(void*d);

typedef struct my_data_type{
    char name[10];
    int age;
}my_data_t;

int mfree(void*d)
{
    my_data_t *pd = (my_data_t*)d;

    free(pd);

    return 0;
}

void show(void*d)
{
    my_data_t *pd = (my_data_t*)d;

    printf("data is %s %d\n", pd->name, pd->age);

}
void *fill(void *type)
{

    return NULL;
}

int compare(void*d1, void *d2)
{
    int ret = 0;

    return ret;
}


int main(void)
{
    /*
     * create struct which is used for save data
     *
     * func:
     *  add head, add tail , add after a node
     *  del head, tail , after a node
     *  update head, tail , after a node
     *
     * */
    mdata_init(fill, compare, mfree, show);
    list_t list ;
    my_data_t *x;

    list_init(&list);
    for (int i = 0; i < 100; i++)
    {
        x = (my_data_t *)malloc(sizeof(my_data_t));
        snprintf(x->name, sizeof(x->name), "long%d", i);
        x->age = i;

        list.add(&list,(void*)x);
    }

    //list.show(&list);
    list.free(&list);

    return 0;
}

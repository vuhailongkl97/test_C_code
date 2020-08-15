#define __line__ __LINE__

#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

typedef struct _data {
    void* (*fill)(void *);
    int (*cmp)(void *, void*);
    int (*free)(void *);
    void (*show)(void *);

}data;

static data mdata;

void mdata_init(void* (*fill)(void *), int (*cmp)(void*, void*), int (*mfree)(void*), void (*show)(void*))
{
    mdata.fill = fill;
    mdata.cmp = cmp;
    mdata.free = mfree;
    mdata.show = show;
}

static int _list_init(struct _list_t *self, node_t* (*node_creat)(void *),\
        int (*add)(struct _list_t *, void*), int (*del)(struct _list_t *, void*),\
        void (*free)(struct _list_t *), int (*show)(struct _list_t *))
{
    if(NULL == self)
        self = (list_t*)malloc(sizeof(list_t));
    if(NULL == self)
    {
        printf("%s init failed", __func__ );
        return -1;
    }

    self->head = NULL;
	self->node_creat = node_creat;
	self->add = add;
	self->del = del;
	self->show = show;
	self->free = free;

    return 0;
}

node_t* create_node(void *info)
{
    node_t *out = NULL;

    out = (node_t *)malloc(sizeof(node_t));
    if(NULL != out)
    {
        out->info = info;
        out->pnext = NULL;
    }

    return out;
}

static int list_add(struct _list_t *self, void* info)
{
    int ret = 0;

    printf("adding \n");
    node_t *new_node = self->node_creat(info);
    if(NULL == new_node)
    {
        printf("%s:%d can't alloct new node", __func__, __line__);
        ret = -1;
    }
    else
    {
        mdata.show(new_node->info);
        if(self->head == NULL)
        {
            self->head = new_node;
        }
        else
        {
            new_node->pnext = self->head;
            self->head = new_node;
        }
    }

	return ret;
}

static int list_del(struct _list_t *self, void* a)
{
    mdata.show(a);
    node_t *p = self->head, *q = NULL;

    q = p;
    while(p)
    {
        /* same */
        if(0 == mdata.cmp(a, p->info))
        {
            if(q == self->head)
            {
                self->head = self->head->pnext;
                mdata.free(q->info);
                free(q);
            }
            else
            {
                q->pnext = p->pnext;
                mdata.free(p->info);
                free(p);
            }
            break;
        }
        q = p;
        p = p->pnext;
    }

	return 0;
}

static int list_show(struct _list_t *self)
{
	printf("show \n");
    node_t *p = self->head;
    while(p)
    {
        mdata.show(p->info);
        p = p->pnext;
    }

	return 0;
}

static void list_free(list_t *self)
{
    node_t *p = self->head;
	printf("Deallocating ... \n");
    while(p)
    {
        self->head = self->head->pnext;

        mdata.show(p->info);
        mdata.free(p->info);
        free(p);

        p = self->head;
    }
}

void list_init(list_t *self)
{
    _list_init(self, create_node, list_add, list_del, list_free, list_show);
}

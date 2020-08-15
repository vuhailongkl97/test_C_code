#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

typedef struct _node{
    void *info;
    struct _node *pnext;
}node_t;

typedef struct _list_t{
    node_t *head;

    node_t* (*node_creat)();
    void (*init)(struct _list_t *);
    int (*add)(struct _list_t *, void *);
    int (*del)(struct _list_t *, void *);
    void (*free)(struct _list_t *);
    int (*show)(struct _list_t *);
}list_t;

void mdata_init(void* (*fill)(void *), int (*cmp)(void*, void*), int (*mfree)(void*), void (*show)(void*));
void list_init(list_t *self);

#endif

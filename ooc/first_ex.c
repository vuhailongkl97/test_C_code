#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

typedef struct  {
	int x , y;
	void (*cstructor)(void *self, int x , int y);
	void (*move)(void *self, int x, int y);
	void (*des)(void *self);
	void (*show)(void *self);

}mouse;
void * new(int x, int y, void (*cs), void (*move), void (*des), void (*show))
{
	
	mouse *m = calloc(1, sizeof(mouse));		
	
	assert(m);
	m->cstructor = cs;
	m->move = move;
	m->des = des;
	m->show = show;

	m->cstructor(m, x , y);
	m->show(m);	

	return m;	
}
void destructor(void *_self)
{
	mouse *self = _self;	
	free(self);

}
void constructor(void * _self , int x , int y)
{
	mouse *self = _self;	

	self->x = x ;
	self->y = y ;
}
void move(void *_self , int x, int y)
{
	mouse *self = _self;

	printf("move from (%d, %d) -> (%d, %d)\n", self->x, self->y,
				self->x + x, self->y + y );
	self->x += x ;
	self->y += y ;
}
void test_args(mouse x,int num, ...) 
{
	int i = 0;

	va_list ap;
	va_start(ap, num);

	for( i = 0; i< num ; i++)
	{
		printf("arg[%d] = %d\n", i, va_arg(ap, int));
	}

	va_end(ap);
}
void show(const void *_self)
{
	const mouse *self = _self;
	printf("current pos of mouse is (%d, %d)\n", self->x, self->y);

}
int main(void)
{
	mouse *x = new(1,2,constructor, move, destructor, show);

	x->move(x, 20,30);	

	x->show(x);
	x->des(x);

	return 0;
}

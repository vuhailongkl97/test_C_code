#include <stdio.h>
#include <stdlib.h>

int x = 10;

int *test()
{
    return &x;
}
int test_ret_int()
{
    return x;
}
typedef int *(*test_ptr_t)();
typedef int (*vvmai_ptr_t)();

vvmai_ptr_t vvvmai()
{
    return test_ret_int;
}

test_ptr_t test2()
{
    return test;
}
int main(void)
{
#if 0  
            int *x1[100];
            int *p = malloc(sizeof(int)*10) ;
            for (i = 0; i< 100; i++)
            {
		x1[i] = p;
		printf("%p\n", x1[i]);
            }
#endif

#if 0
            int (*x2)[100];

            int arr[100];
            x2 = &arr;

            printf("%ld d is %ld\n", sizeof(x2), sizeof(int));

#endif
#if 0
            int *(*x3)[100];
            int * arr[100];

            x3 = &arr;
            printf("%p\n", x3[0]);

#endif
#if 0
            int (*x4)(void);
            x4 = main;
            printf("%p\n", x4);
#endif
#if 0

            int (*x5[100])();
            x5[0] = main;
            printf("%p\n", x5[0]);
#endif
#if 0
            //int *(*(*x6[100])())();
            /* pointer to function which return integer pointer*/
            //int *(*a)(); 
            
            int *(*(*x6[100])())();

            x6[0] = test2;

            /* 1 ham return pointer integer  */
            /*100 ham return  return pointer function void */
            //(x6[0]) = test2;
           // printf("%p\n", x6[0]);
#endif
#if 0

            int (*vvvmai())();

            //*mai = main;

            printf("%ld f2 = %p" , sizeof(vvvmai), vvvmai);

            
#endif
#if 0
            int *(*test2())();
            printf("%ld prototype function return other function which return address of integer = %p\n" , sizeof(test2), test2);

#endif
#if 1
            int (*F3())[30];
            printf("%ld " , sizeof(F3()));
            
#endif
#if 0
            int (*(*F4())[])();
            int *(*(*F5())[])();
#endif

            return 0;
}


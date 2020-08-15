int 
main(void)
{
    int x;
#if defined(abcd)
    x = 10;
#else
    x = 100;
#endif
    printf("x is %d\n", x);
    return 0;
}



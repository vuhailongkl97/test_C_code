int main()
{
    char *s = "2,3.3.3.5,34.4.44.5";

    char a[10], b[10];
    sscanf(s, " %*d,%[^,],%s", a, b);

    printf("a is %s, b is %s\n", a , b);

    return 0;
}

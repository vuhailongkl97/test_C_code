/*!
 * @file sscanf.c
 * use sscanf to get varible like regex in C
 *
 */

/*!
 * @brief get 2 substring from parent string with sscanf   
 *
 * read first number but don't assign to any variable   
 * read string until comma(,) to a and * remaining characters is b   
 *
 * @param in input
 * @param a output
 * @param b output
 */
void get_sub_str_with_regex(char *in, char *a, char *b)
{
    sscanf(s, " %*d,%[^,],%s", a, b);
}

int main()
{
    char *s = "2,3.3.3.5,34.4.44.5";
    char a[10], b[10];

    get_sub_str_with_regex(s, a, b);
    printf("a is %s, b is %s\n", a , b);

    return 0;
}

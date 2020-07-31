#include <stdio.h>

int check_contain_str(const char *str, const char *test)
{
   int ret = 0;
   const char *tmp_test = test;

   if(NULL == str || NULL == test)
       return 0;

   while(*tmp_test != '\0')
   {
       const char *p = strstr(tmp_test, str);
       if (p)
       {
          if (p == test || *(p-1) == ' ')
          {
               p += strlen(str);
               if (*p == ' ' || *p == '\0')
               {
                   ret = 1;
                   break;
               }
           }
       }
       tmp_test ++;
   }

   return ret;
}

int main(void)
{

     printf("result : %d \n", check_contain_str("a", " ab bcdefa "));
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return (strcmp(a, b) < 0 );
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return !lexicographic_sort(a, b);
}

int count_distinct_char(const char *a)
{
    int n_disa = 0;
    int arr[128] = {0};
    for (int i = 0; i< strlen(a); i++)
    {
        if(a[i] - '0' < sizeof(arr)/sizeof(int))
              arr [a[i] - '0'] +=1;
    }

    for(int i = 0; i< sizeof(arr)/sizeof(int); i++)
        n_disa += (arr[i] > 0 );
   // printf("distinct %s %d\n", a, n_disa);
    return n_disa;

}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int ret =  (count_distinct_char(a) - count_distinct_char(b));
    if ( ret == 0)
    {
        return lexicographic_sort(a,b);
    }
    else
        return (ret < 0);
}

int sort_by_length(const char* a, const char* b) {
    int ret = strlen(a) - strlen(b);
    if ( ret == 0)
    {
        return lexicographic_sort(a,b);
    }
    else
        return (ret < 0);
}

void swap(char ***arr , int i , int j)
{
  char *temp = (char *)malloc(strlen(*(*arr + i)) + 1);
  bzero(temp, (strlen(*(*arr + i)) + 1));

  int arr_leni = strlen(*(*arr + i));
  int arr_lenj = strlen(*(*arr + j));
 
  (*arr)[i]= (char *)realloc(*((*arr) + i), arr_lenj + 1);
  if( arr_leni < arr_lenj)
  	(*arr)[i][arr_lenj] = '\0';
  else
  	(*arr)[i][arr_leni] = '\0';
  
  (*arr)[j]=  (char *)realloc(*((*arr) + j),  arr_leni + 1);
  if( arr_leni < arr_lenj)
  	(*arr)[j][arr_leni] = '\0';
  else
  	(*arr)[j][arr_lenj] = '\0';
   
  strncpy(temp, *(*arr +i), arr_leni); 
  strncpy(*(*arr +i), *(*arr +j), arr_lenj); 
  strncpy(*(*arr +j), temp, arr_leni); 
 
  free(temp); 
}


char **des = NULL;
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int min_idx = 0;
    
    if( NULL == des)
    {
        des = (char **)malloc(sizeof(char*)*len);
        for (int i = 0; i< len ; i++)
        {
            des[i] = (char *)malloc(strlen(*(arr + i))+1);
            strcpy(des[i], *(arr +i));
        }
    }
    else
    {
        for (int i = 0; i< len ; i++)
        {
            *(arr + i) = (char *)realloc(*(arr + i), strlen(*(des + i)));
            strcpy(*(arr + i), *(des +i));
        }
    }
    
    for(int i = 0; i< len; i ++)
    {
        min_idx = i;
        for(int j = i + 1; j < len; j ++)
        {   
            if(cmp_func(arr[j], arr[min_idx]))
            {
                swap(&arr, j, min_idx);
            }
        }
    }
u

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int i, j, k;  
    triangle tmp;
    for (i = 0; i < n-1; i++)      
    // Last i elements are already in place  
    for (k = 0; k < n-i-1; k++)
    {
		j = k ;
        float p1 = ((tr + j )->a + (tr +j )->b + (tr+j)->c   )/2.0;
        float S1 = sqrt(  p1 * (p1 - ((tr+j)->a)) *(p1-((tr+j)->b)) *(p1-((tr+j)->c))  );

        float p2 = ((tr +j +1)->a + (tr +j +1)->b + (tr+j +1)->c  )/2.0;
        float S2 = sqrt(p2 * (p2 - ((tr+j+1)->a)) *(p2-((tr+j+1)->b)) *(p2-((tr+j+1)->c)));
    
        
        printf("tr i %d %d %d %f\n", (tr + j )->a , (tr +j )->b , (tr+j)->c, p1 );
        printf("tr i %d %d %d %f\n", (tr + j +1 )->a , (tr +j +1 )->b , (tr+j + 1)->c, p2 );
        printf("S1 is %f S2 %f , p1 is %f, p2 %f\n", S1, S2, p1, p2);
        if (S1 > S2) 
        {
puts("ff");
            memcpy(&tmp, tr + j, sizeof(tmp));
            memcpy(tr +j, tr + j + 1, sizeof(tmp));
            memcpy(tr + j +1, &tmp, sizeof(tmp));
        }  
    }  
  

}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
puts("------------------\n\n\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

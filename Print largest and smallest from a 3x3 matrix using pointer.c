/* min_max_3x3.c
   Compile: gcc -o min_max_3x3 min_max_3x3.c
*/
#include <stdio.h>

int main(){
    int a[3][3];
    int *p = &a[0][0];

    printf("Enter 9 integers for 3x3 matrix:\n");
    for(int i=0;i<9;i++) scanf("%d", p + i);

    int max = *(p+0);
    int min = *(p+0);
    for(int i=1;i<9;i++){
        if(*(p+i) > max) max = *(p+i);
        if(*(p+i) < min) min = *(p+i);
    }
    printf("Largest = %d\nSmallest = %d\n", max, min);
    return 0;
}

/* sort_4x4.c
   Compile: gcc -o sort_4x4 sort_4x4.c
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int a[4][4];
    int flat[16];
    printf("Enter 16 integers (4x4 matrix row-wise):\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }

    // flatten
    int idx = 0;
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) flat[idx++] = a[i][j];

    // sort ascending
    qsort(flat, 16, sizeof(int), cmp);

    printf("Sorted elements in 1D array:\n");
    for(int i=0;i<16;i++) printf("%d ", flat[i]);
    printf("\n");
    return 0;
}

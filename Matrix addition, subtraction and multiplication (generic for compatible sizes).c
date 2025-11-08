/* matrix_ops.c
   Compile: gcc -o matrix_ops matrix_ops.c
*/
#include <stdio.h>
#include <stdlib.h>

void read_matrix(int **a, int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void print_matrix(int **a,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) printf("%d\t", a[i][j]);
        printf("\n");
    }
}

int main(){
    int r1,c1,r2,c2;
    printf("Enter rows and columns of first matrix: ");
    if(scanf("%d %d",&r1,&c1)!=2) return 0;
    printf("Enter rows and columns of second matrix: ");
    if(scanf("%d %d",&r2,&c2)!=2) return 0;

    // allocate
    int **A = malloc(r1 * sizeof(int*));
    for(int i=0;i<r1;i++) A[i] = malloc(c1 * sizeof(int));
    int **B = malloc(r2 * sizeof(int*));
    for(int i=0;i<r2;i++) B[i] = malloc(c2 * sizeof(int));

    printf("Enter elements of first matrix (%dx%d):\n", r1,c1);
    read_matrix(A,r1,c1);
    printf("Enter elements of second matrix (%dx%d):\n", r2,c2);
    read_matrix(B,r2,c2);

    // Addition and subtraction: only if same dimensions
    if(r1==r2 && c1==c2){
        int **S = malloc(r1 * sizeof(int*));
        int **D = malloc(r1 * sizeof(int*));
        for(int i=0;i<r1;i++){ S[i]=malloc(c1*sizeof(int)); D[i]=malloc(c1*sizeof(int)); }
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                S[i][j] = A[i][j] + B[i][j];
                D[i][j] = A[i][j] - B[i][j];
            }
        }
        printf("\nSum matrix:\n"); print_matrix(S,r1,c1);
        printf("\nDifference (A - B):\n"); print_matrix(D,r1,c1);
        for(int i=0;i<r1;i++){ free(S[i]); free(D[i]); } free(S); free(D);
    } else {
        printf("\nAddition/Subtraction: dimensions do not match, skipping.\n");
    }

    // Multiplication: columns of A must equal rows of B
    if(c1 == r2){
        int **P = malloc(r1 * sizeof(int*));
        for(int i=0;i<r1;i++){ P[i]=malloc(c2*sizeof(int)); for(int j=0;j<c2;j++) P[i][j]=0; }
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                for(int k=0;k<c1;k++) P[i][j] += A[i][k] * B[k][j];
            }
        }
        printf("\nProduct matrix (A x B):\n"); print_matrix(P,r1,c2);
        for(int i=0;i<r1;i++) free(P[i]); free(P);
    } else {
        printf("\nMultiplication not possible: columns of A != rows of B.\n");
    }

    // free A,B
    for(int i=0;i<r1;i++) free(A[i]); free(A);
    for(int i=0;i<r2;i++) free(B[i]); free(B);
    return 0;
}

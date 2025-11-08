/* books.c
   Compile: gcc -o books books.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *books[3];               // pointers to strings
    char buffer[256];

    printf("Enter 3 book names (one per line):\n");
    for(int i=0;i<3;i++){
        if(!fgets(buffer, sizeof(buffer), stdin)){ i--; continue; } // handle stray newline
        // remove trailing newline
        size_t len = strlen(buffer);
        if(len && buffer[len-1]=='\n') buffer[len-1] = '\0';
        books[i] = malloc(strlen(buffer)+1);
        strcpy(books[i], buffer);
    }

    printf("\nYou entered (printed later):\n");
    for(int i=0;i<3;i++){
        printf("%d: %s\n", i+1, books[i]);
        free(books[i]);
    }
    return 0;
}

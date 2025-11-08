/* abbrev_names.c
   Compile: gcc -o abbrev_names abbrev_names.c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char line[512];
    printf("Enter full name (first middle ... last):\n");
    if(!fgets(line, sizeof(line), stdin)) return 0;
    size_t L = strlen(line);
    if(L && line[L-1]=='\n') line[L-1] = '\0';

    // split tokens (space separated)
    char *tokens[50];
    int tcount = 0;
    char *tok = strtok(line, " \t");
    while(tok && tcount < 50){
        tokens[tcount++] = tok;
        tok = strtok(NULL, " \t");
    }

    if(tcount == 0) return 0;
    if(tcount == 1){
        printf("%s\n", tokens[0]); // single name
        return 0;
    }

    // print initials for all except last
    for(int i=0;i<tcount-1;i++){
        printf("%c. ", tokens[i][0]);
    }
    // print last name in full
    printf("%s\n", tokens[tcount-1]);

    return 0;
}

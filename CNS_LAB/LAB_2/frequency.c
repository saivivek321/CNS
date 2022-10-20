#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 1024
#define ASCII 256

int main() {
    char *str;
    int *frq, i = 0;

    str = (char *)calloc(MAX_LIMIT, sizeof(char));
    frq = (int *)calloc(ASCII, sizeof(int));
    
    printf("Enter the string : ");
    fgets(str, MAX_LIMIT, stdin);

    for(i = 0; i < MAX_LIMIT && str[i] != '\n'; i++)
        frq[str[i]] = frq[str[i]] + 1;

    for(i = 0; i < 256; i++) {
        if(frq[i] > 0) {
            printf("%c -> %d\n", i, frq[i]);
        }
    }

    free(str);
}
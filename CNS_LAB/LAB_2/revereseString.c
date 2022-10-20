#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 1024
#define ASCII 256


void reverseString(char* s, int i ,int j) {
    if(i < j) { 
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverseString(s, i + 1, j - 1);
    }
    
    return;
}


int main() {
    
    int i = 0;
    char *str;

    str = (char *)calloc(MAX_LIMIT, sizeof(char));

    printf("Enter the string : ");
    fgets(str, MAX_LIMIT, stdin);

    for(i = 0; i < MAX_LIMIT && str[i] != '\n'; i++);

    reverseString(str, 0, i - 1);

    printf("Reverse string : %s", str);

    free(str);
}
#include "../cns.h"

int main() {
    char *str, key;
    int i = 0, j = 0, n;

    str = (char *)calloc(MAX_LIMIT, sizeof(char));

    printf("Enter the string : ");
    fgets(str, MAX_LIMIT, stdin);

    for(i = 1; i < MAX_LIMIT && str[i] != '\n'; i++) {
        j = i - 1;
        key = str[j + 1];

        while(j >= 0 && str[j] > key) { 
            str[j + 1] = str[j];
            j = j - 1;
        }
        
        str[j+1] = key;
    }

    printf("Sorted string : %s", str);

    free(str);
}
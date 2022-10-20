#include "../cns.h"

int main() {
    char *str;
    int i = 0, j = 0;

    str = (char *)calloc(MAX_LIMIT, sizeof(char));

    printf("Enter the string : ");
    fgets(str, MAX_LIMIT, stdin);

    for(i = 0, j = 0; i < MAX_LIMIT && str[i] != '\n'; i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            str[j] = str[i];
            j++;
        }
    }

    for(; j < MAX_LIMIT && str[j] != '\0'; j++) 
        str[j] = '\0';

    printf("String containing only alphabets : %s\n", str);

    free(str);
}
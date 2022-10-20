#include "../cns.h"

int main() {

    char *m;
    int i, n, parity = 0;
    
    scanf("%d", &n);

    m = (char *)calloc(n + 1, sizeof(char));

    printf("Enter the message : ");
    gets(m);

    for(int i = 0; i < n; i++){
        if(m[i] == '1')
            parity++;
    }

    printf("%d", parity);

    printf("CodeWord : %s", m);

}
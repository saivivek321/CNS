#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main() {
    mpz_t a, b, r; 

    mpz_init_set_ui(a, 0);
    mpz_init_set_ui(b, 0);

    printf("Enter a : ");
    gmp_scanf("%Zd", a);

    printf("Enter b : ");
    gmp_scanf("%Zd", b);

    while(mpz_cmp_ui(a,0) != 0) {
        mpz_set(r, a);
        mpz_mod(a, b, a);
        mpz_set(b, r);
    }

    printf("gcd(a, b) = ");
    mpz_out_str(stdout, 10, b);
    printf("\n");

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);
}

#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main() {
    mpz_t a, b, a1, b1, x0, y0, x1, y1; 

    mpz_init_set_ui(a, 0);
    mpz_init_set_ui(b, 0);
    mpz_init_set_ui(a1, 0);
    mpz_init_set_ui(b1, 0);
    mpz_init_set_ui(x0, 1);
    mpz_init_set_ui(y0, 0);
    mpz_init_set_ui(x1, 0);
    mpz_init_set_ui(y1, 1);

    printf("Enter a : ");
    gmp_scanf("%Zd", a);

    printf("Enter b : ");
    gmp_scanf("%Zd", b);

    mpz_set(a1, a);
    mpz_set(b1, b);

    while(mpz_cmp_ui(b1, 0) != 0) {
        mpz_t q, xt, yt, qx, qy, t, qt;

        mpz_init_set_ui(q, 0);
        mpz_init_set_ui(xt, 0);
        mpz_init_set_ui(yt, 0);
        mpz_init_set_ui(qx, 0);
        mpz_init_set_ui(qy, 0);
        mpz_init_set_ui(t, 0);
        mpz_init_set_ui(qt, 0);
        
        mpz_div(q, a1, b1);

        mpz_set(xt, x1);
        mpz_mul(qx, q, x1);
        mpz_sub(x1, x0, qx);
        mpz_set(x0, xt);

        mpz_set(yt, y1);
        mpz_mul(qy, q, y1);
        mpz_sub(y1, y0, qy);
        mpz_set(y0, yt);

        mpz_set(t, b1);
        mpz_mul(qt, q, b1);
        mpz_sub(b1, a1, qt);
        mpz_set(a1, t);
    }

    printf("gcd(a, b) = ");
    mpz_out_str(stdout, 10, a1);
    printf("\n");
    gmp_printf("(x, y) = (%Zd, %Zd)", x0, y0);
    printf("\n");
}

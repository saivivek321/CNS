#include <gmp.h>
#include <stdio.h>

mpz_t n1, n2;

void extended(mpz_t x0, mpz_t y0, mpz_t x1, mpz_t y1, mpz_t a, mpz_t b) {
    mpz_t r, q, t1, t2, x2, y2;
    mpz_inits(r, q, t1, t2, x2, y2, 0);
    mpz_mod(r, a, b);

    if(mpz_cmp_ui(r,0) == 0) {
        mpz_mod(x1, x1, n2);
        mpz_add(x1, x1, n2);
        mpz_mod(x1, x1, n2);

        gmp_printf("Modular Multiplicative Inverse of %Zd  : %Zd \n", n1, x1);
        return; 
    }

    mpz_fdiv_q(q, a, b);
    mpz_mul(t1, q, x1);
    mpz_mul(t2, q, y1);
    mpz_sub(x2, x0, t1);
    mpz_sub(y2, y0, t2);
    extended(x1, y1, x2, y2, b, r);
}


void euclidian(mpz_t a, mpz_t b) {
    if(mpz_cmp_ui(b, 0) == 0) {
        if(mpz_cmp_ui(a, 1) == 0) {
            mpz_t x0, y0, x1, y1;
            mpz_inits(x0, y0, x1, y1, 0);
            mpz_set_si(x0, 1);  
            mpz_set_si(y0, 0);  
            mpz_set_si(x1, 0);  
            mpz_set_si(y1, 1);

            extended(x0, y0, x1, y1, n1, n2);
        }
        else gmp_printf("Inverse doesn't exist\n");

        return;
    }

    mpz_mod(a, a, b);
    euclidian(b, a);
}

int main() {
    mpz_t m1, m2;
    mpz_inits(n1, n2, m1, m2, 0);
    gmp_printf("Enter first number : ");
    gmp_scanf("%Zd", m1);
    gmp_printf("Enter second number : ");
    gmp_scanf("%Zd", m2);
    mpz_set(n1, m1);
    mpz_set(n2, m2);
    euclidian(m1, m2);
}

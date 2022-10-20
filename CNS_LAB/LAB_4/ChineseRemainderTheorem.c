#include <gmp.h>
#include <stdio.h>

mpz_t n1,n2;

void extended(mpz_t x0, mpz_t y0, mpz_t x1, mpz_t y1, mpz_t a, mpz_t b, mpz_t res) {
    mpz_t r, q, t1, t2, x2, y2;
    mpz_inits(r, q, t1, t2, x2, y2, 0);
    mpz_mod(r, a, b);

    if(mpz_cmp_ui(r, 0) == 0) {
        mpz_mod(x1, x1, n2);
        mpz_add(x1, x1, n2);
        mpz_mod(x1, x1, n2);
        gmp_printf("Multiplicative Inverse : %Zd \n", x1);
        mpz_set(res, x1);
        return; 
    }

    mpz_fdiv_q(q, a, b);
    mpz_mul(t1, q, x1);
    mpz_mul(t2, q, y1);
    mpz_sub(x2, x0, t1);
    mpz_sub(y2, y0, t2);
    extended(x1, y1, x2, y2, b, r, res);
}


void euclidian(mpz_t a, mpz_t b, mpz_t res) {
    if(mpz_cmp_ui(b, 0) == 0) {
        if(mpz_cmp_ui(a, 1) == 0) {
            mpz_t x0, y0, x1, y1;
            mpz_inits(x0, y0, x1, y1, 0);
            mpz_set_si(x0, 1);  
            mpz_set_si(y0, 0);  
            mpz_set_si(x1, 0);  
            mpz_set_si(y1, 1);
            extended(x0, y0, x1, y1, n1, n2, res);
        }
        else gmp_printf("Inverse doesn't exist.\n");
    
        return;
    }

    mpz_mod(a, a, b);
    euclidian(b, a, res);
}

int main() {
    mpz_t n, M, res, m1, m2, t, t1;
    mpz_t a[100], m[100], Mi[100], mpz_t y[100];

    mpz_inits(n, res, 0); 
    mpz_init(M); 
    mpz_set_si(M, 1);

    gmp_scanf("%Zd", n);

    for(int i = 0;i < 100; i++) 
        mpz_inits(a[i], m[i], Mi[i], y[i],0);


    for(unsigned long int j = 0; j < mpz_get_ui(n); j++) {
        gmp_scanf("%Zd", a[j]);  
        gmp_scanf("%Zd", m[j]);
    }

    for(unsigned long int j = 0; j < mpz_get_ui(n); j++) 
        mpz_mul(M, M, m[j]);

    for(unsigned long int j = 0; j < mpz_get_ui(n); j++)
        mpz_cdiv_q(Mi[j], M, m[j]);

    mpz_inits(n1, n2, m1, m2, 0);

    for(unsigned long int j = 0; j < mpz_get_ui(n); j++) {
        mpz_set(m1, Mi[j]);  
        mpz_set(m2, m[j]);
        mpz_set(n1, Mi[j]);  
        mpz_set(n2, m[j]);
        euclidian(m1, m2, y[j]);
    }

    for(unsigned long int j = 0; j < mpz_get_ui(n); j++) 
        gmp_printf("%Zd ",y[j]);
     
    mpz_inits(t, t1, 0);

    for(unsigned long int j = 0; j < mpz_get_ui(n); j++) {
        mpz_set_si(t, 1);
        mpz_mul(t, t, a[j]);
        mpz_mul(t, t, y[j]);
        mpz_mul(t, t, Mi[j]);
        mpz_add(t1, t1, t);
        mpz_mod(t1, t1, M);
    }

    gmp_printf("\n X : %Zd \n", t1);
}
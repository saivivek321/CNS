#include<gmp.h>
#include<stdio.h>

void rabinMiller(mpz_t n) {
    mpz_t q, a, r, k, t, t1; 
    mpz_inits(t, t1, a, r, k, 0);

    mpz_sub_ui(t1, n, 1); 
    mpz_set(q, t1);
    mpz_mod_ui(r, q, 2);
    
    while(mpz_cmp_ui(r, 1) != 0) {
        mpz_add_ui(k, k, 1);
        mpz_cdiv_q_ui(q, q, 2);
        mpz_mod_ui(r, q, 2);
    }

    gmp_randstate_t st;
    gmp_randinit_mt(st);

    mpz_sub_ui(r, n, 3);

    mpz_urandomm(a, st, r); 
    mpz_add_ui(a, a, 2);
    mpz_powm(a, a, q, n);
    
    if(mpz_cmp_ui(a, 1) == 0 || mpz_cmp(a, t1) == 0)  {
        gmp_printf("Inconclusive\n");
        return;
    }

    for(unsigned long int j = 0; j < mpz_get_ui(k); j++) {
        mpz_powm_ui(a, a, 2, n);

        if(mpz_cmp(a, t1) == 0) {
            gmp_printf("Inconclusive\n"); 
            return;
        }
        if(mpz_cmp_ui(a, 1) == 0) {
            gmp_printf("Composite\n"); 
            return;
        }
    }

    gmp_printf("Composite\n");
}

int main() {
    mpz_t n;
    mpz_init(n);
    gmp_printf("Enter the number : ");
    gmp_scanf("%Zd", n);
    rabinMiller(n);
}

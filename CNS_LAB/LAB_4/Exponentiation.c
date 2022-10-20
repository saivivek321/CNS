#include<gmp.h>
#include<stdio.h>

void expon(mpz_t rem[], mpz_t r, mpz_t n, mpz_t e, mpz_t m) {
    if(mpz_cmp_ui(e,1) == 0){
        mpz_mod(r,n,m);
        return;
    }

    mpz_t t, i, res, ex;
    mpz_inits(t, i, ex, 0); 
    mpz_set(ex,e);
    mpz_init(res); 
    mpz_set_ui(res,1);
    
    while(mpz_cmp_ui(e,0) != 0) {
        mpz_cdiv_q_ui(t,e,2); 
        mpz_set(i,t);
        mpz_sub(e,e,t);
        
        if(mpz_cmp_si(rem[mpz_get_ui(t)], -1) == 0) {
            expon(rem,rem[mpz_get_ui(t)],n,t,m);
        }

        mpz_mul(res,res,rem[mpz_get_ui(i)]);
        mpz_mod(res,res,m);
    }

    mpz_set(r,res);
}


int main() {
    mpz_t rem[100];
    mpz_t n,e,m,t,res,j;
    mpz_inits(n,e,m,j,t,0); 
    mpz_init(res); 
    mpz_set_si(res,1);

    gmp_scanf("%Zd",n);
    gmp_scanf("%Zd",e);
    gmp_scanf("%Zd",m);

    for(int i = 0; i < 100; i++) {
        mpz_init(rem[i]); 
        mpz_set_si(rem[i], -1);
    }

    while(mpz_cmp_ui(e,0) != 0) {
        mpz_cdiv_q_ui(t,e,2);
        mpz_sub(e,e,t); 
        mpz_set(j,t);

        if(mpz_cmp_si(rem[mpz_get_ui(j)],-1) == 0) 
            expon(rem,rem[mpz_get_ui(t)],n,t,m);
        
        mpz_mul(res,res,rem[mpz_get_ui(j)]);
        mpz_mod(res,res,m);
    }

    gmp_printf("Remainder : %Zd \n", res);
}

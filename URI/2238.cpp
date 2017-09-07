#include <cstdio>
#include <bitset>
int mmc(int a, int b){
    return a*(b/mdc(a,b));
}
int mdc(int a, int b){
    if(b == 0) return a;
    return mmc(b,a%b);
}
bitset<10000010> primes;
int sieve_len = 10000010;
primes[0] = primes[1] = 0;
void sieve(){
    primes.set();
    for(int i = 2; i < sieve_len; i++)
        if(primes[i]){
            for(int j = i*i; j < sieve_len; j+=i)
                primes[j] = 0;
        }
}
int main(){
    int a, b, c, d, i, d_cd, m_ab;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(c%a != 0){
        printf("-1\n");
        return 0;
    }
    d_cd = mdc(c,d);
    m_ab = mmc(a,b);
    if(d_cd%a != 0 && c%m_ab != 0){
        printf("%d\n",a);
        return 0;
    } else {
        sieve();
        
    }
    return 0;
}


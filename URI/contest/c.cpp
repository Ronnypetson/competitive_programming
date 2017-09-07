#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll _sieve_size;
bitset<1000010> bs;
vi primes;

void sieve(ll upperbound){
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++){
        if(bs[i]){
            for(ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
            //printf("%d ",(int)i);
            primes.push_back((int)i);
        }
    }
}

ll pow(int a, int b){
    if(b == 0) return 1;
    ll r = pow(a,b/2);
    //printf("%d ",r);
    if(b%2){        
        return r*r*a;
    } else {
        return r*r;
    }
}

ll sumDiv(ll N){
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while(PF*PF <= N){
        ll power = 0;
        while(N%PF == 0) { N /= PF; power++; }
        ans *= ((ll)pow(PF,power+1)-1)/(PF-1);
        PF = primes[++PF_idx];
    }
    if(N != 1) ans *= ((ll)pow(N,2)-1)/(N-1);
    return ans;
}

int main(){
    int n, i, m;
    scanf("%d",&n);
    sieve(1000000);
    for(i = 0; i < n; i++){
        scanf("%d",&m);
        printf("%d\n",sumDiv((ll)m));
    }
    return 0;
}


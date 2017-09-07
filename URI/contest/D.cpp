#include <cstdio>
#define secs 86400
using namespace std;
typedef long long ll;

ll pow(int a, int b){
    if(b == 0) return 1;
    ll r = pow(a,b/2);
    if(b%2){        
        return (r*r*a)%secs;
    } else {
        return (r*r)%secs;
    }
}

void convert(int a, char ca[2]){
    ca[0] = '0'+a/10;
    ca[1] = '0'+a%10;
}

int main(){
    ll n;
    int h,m,s;
    char ch[2],cm[2],cs[2];
    ll t;
    scanf("%ull",&n);
    t = pow(2,n)-1;
    h = t/3600;
    m = (t-h*3600)/60;
    s = t-h*3600-m*60;
    convert(h,ch);
    convert(m,cm);
    convert(s,cs);
    printf("%c%c:%c%c:%c%c\n",ch[0],ch[1],cm[0],cm[1],cs[0],cs[1]);
    return 0;
}


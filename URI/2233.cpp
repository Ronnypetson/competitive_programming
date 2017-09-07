#include <cstdio>
using namespace std;
int main(){
    long long int r, g, b, rg, gb;
    scanf("%llx",&r);
    scanf("%llx",&g);
    scanf("%llx",&b);
    rg = r/g;
    gb = g/b;
    printf("%llx\n",1+rg*rg+rg*rg*gb*gb);
}


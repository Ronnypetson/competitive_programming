#include <cstdio>
inline int max(int a, int b){
    return (a > b) ? a : b;
}
int main(){
    int n, c, last = 0, prev = 0, put, i;
    scanf("%d %d",&n,&c);
    int p[n],mx[n];
    for(i = 0; i < n; i++){
        scanf("%d",&p[i]);
    }
    mx[0] = 0;
    for(i = 1; i < n; i++){
        put = mx[max(0,last-1)]+p[i]-p[last]-c;
        if(put > mx[i-1]){
            mx[i] = put;
            prev = i;
        } else {
            mx[i] = mx[i-1];
        }
        if(p[prev]-p[i] > c
        && p[prev]-p[last] > c){    // p[i]-p[last]
            last = i;
            prev = i;
        }
        if(p[i] <= p[last]){
            last = i;
            prev = i;
        }
    }
    printf("%d\n",mx[n-1]);
}


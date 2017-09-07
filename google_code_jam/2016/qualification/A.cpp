#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
    int t, n;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        scanf("%d",&n);
        if(n == 0){
            printf("Case #%d: INSOMNIA\n",i);
            continue;
        }
        int dcount = 0;
        char digits[10]; // bool mask
        memset(digits,0,10);
        int m = n;
        while(true){
            char str_m[10];
            snprintf(str_m,10, "%d",m);
            //printf("%d %s\n",m,str_m);
            for(int j = 0; str_m[j] != '\0'; j++){
                int ind = str_m[j] - '0';
                if(digits[ind] == 0){
                    digits[ind] = 1;
                    dcount++;
                    if(dcount == 10) break;
                }
            }
            if(dcount == 10){
                printf("Case #%d: %d\n",i,m);
                break;
            }
            m += n;
        }
    }
    return 0;
}

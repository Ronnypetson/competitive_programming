#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        string s;
        cin >> s;
        int li = s.size() - 1;
        int cnt = (s[li] == '-') ? 1 : 0;
        for(int j = li-1; j >= 0; j--)
            if(s[j] != s[j+1]) cnt++;
        printf("Case #%d: %d\n",i,cnt);
    }
}

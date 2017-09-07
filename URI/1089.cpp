#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,p;
    while(cin >> n){
        if(n == 0) break;
        p = 0;
        vector<int> h(n);
        for(int i = 0; i < n; i++)
            cin >> h[i];
        for(int i = 0; i < n; i++){
            int prev = (i-1+n)%n;
            int next = (i+1+n)%n;
            if(h[prev] < h[i] && h[next] < h[i]
            || h[prev] > h[i] && h[next] > h[i])
                p++;
        }
        cout << p << endl;
    }
}


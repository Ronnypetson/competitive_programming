#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
int main(){
    int a, c, prev, tot;
    while(cin >> a >> c){
        if(a == 0 && c == 0) break;
        vi alt(c,0); prev = a; tot = 0;
        for(int i = 0; i < c; i++){
            cin >> alt[i];
            if(prev > alt[i])
                tot += (prev-alt[i]);
            prev = alt[i];
        }
        cout << tot << endl;
    }
}


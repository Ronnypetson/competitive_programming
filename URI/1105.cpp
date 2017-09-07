#include <iostream>
using namespace std;
int main(){
    int b, n, d, c, v, reservas[21];
    while(cin >> b >> n){
        if(b == 0 && n == 0) break;
        for(int i = 1; i <= b; i++)
            cin >> reservas[i];
        for(int i = 0; i < n; i++){
            cin >> d >> c >> v;
            reservas[d] -= v; reservas[c] += v;
        }
        int i;
        for(i = 1; i <= b; i++)
            if(reservas[i] < 0) break;
        if(i > b) cout << "S" << endl;
        else cout << "N" << endl;
    }
}


#include <iostream>
using namespace std;
int main(){
    int n,p=-1,found=0;
    while(cin >> n){
        if(n <= p && found == 0){
            cout << p+1 << endl;
            found = 1;
        }
        p = n;
    }
    if(found == 0)
        cout << p+1 << endl;
    return 0;
}


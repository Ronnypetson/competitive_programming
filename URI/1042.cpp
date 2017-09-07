#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[3], b[3];
    cin >> a[0] >> a[1] >> a[2];
    b[0] = a[0], b[1] = a[1], b[2] = a[2];
    sort(a,a+3);
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << endl;
    cout << b[0] << endl;
    cout << b[1] << endl;
    cout << b[2] << endl;
}


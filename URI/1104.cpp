#include <iostream>
#include <map>
using namespace std;
typedef map<int,int> mii;
int main(){
    int a, b, carta;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        mii alice, beatriz;
        for(int i = 0; i < a; i++){
            cin >> carta;
            alice.insert(pair<int,int>(carta,i));
        }
        for(int i = 0; i < b; i++){
            cin >> carta;
            beatriz.insert(pair<int,int>(carta,i));
        }
        int max_alice = 0, max_beatriz = 0;
        for(map<int,int>::iterator it = alice.begin(); it != alice.end(); it++){
            if(beatriz.find(it->first) == beatriz.end()) max_beatriz++;
        }
        for(map<int,int>::iterator it = beatriz.begin(); it != beatriz.end(); it++){
            if(alice.find(it->first) == alice.end()) max_alice++;
        }
        int maximo = (max_alice > max_beatriz) ? max_beatriz : max_alice;
        cout << maximo << endl;
    }
}


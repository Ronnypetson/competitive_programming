#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int types[3][3],total;
int index(char* s){
    if(s[0] == 'u' || s[0] == 'c') return 1;
    else if(s[0] == 'd' || s[0] == 'q') return 2;
    else if(s[0] == 't') return 0;
    else return -1;
}
void mSet(){
    total = 0;
    // Row equal
    for(int i = 0; i < 3; i++){
        if(types[i][0] > 0 && types[i][1] > 0 && types[i][2] > 0){
            int minimum = min(types[i][0],min(types[i][1],types[i][2]));
            types[i][0] -= minimum; types[i][1] -= minimum; types[i][2] -= minimum;
            total += minimum;
        }
    }
    // Column equal
    for(int i = 0; i < 3; i++){
        if(types[0][i] > 0 && types[1][i] > 0 && types[2][i] > 0){
            int minimum = min(types[0][i],min(types[1][i],types[2][i]));
            types[0][i] -= minimum; types[1][i] -= minimum; types[2][i] -= minimum;
            total += minimum;
        }
    }
    // All different
    for(int i = 0; i < 3; i++){
        if(types[0][i] > 0){
            for(int j = 0; j < 3; j++){
                if(j != i && types[1][j] > 0){
                    int k = 3 - i - j;
                    if(types[2][k] > 0){
                        int minimum = min(types[0][i],min(types[1][j],types[2][k]));
                        types[0][i] -= minimum; types[1][j] -= minimum; types[2][k] -= minimum;
                        total += minimum;
                    }
                }
            }
        }
    }
    // All equal
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            total += types[i][j]/3;
}
int main(){
    int n;
    char num[5], tipo[10];
    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                types[i][j] = 0;
        for(int i = 0; i < n; i++){
            scanf("%s %s",num,tipo); //cin >> num >> tipo;
            types[index(num)][index(tipo)]++;
        }
        mSet();
        cout << total << endl;
    }
}


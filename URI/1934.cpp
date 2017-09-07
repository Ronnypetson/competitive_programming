#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef map<string,int> si;
int mvars = ('z'-'a'+1)*('z'-'a'+1);
int main(){
    int l, c;
    cin >> l >> c;
    vi lines(l), cols(c);
    vvs grid(l,*(new vs(c)));
    si val,used;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j];
            if(used.find(grid[i][j]) == used.end())
                used.insert(make_pair(grid[i][j],1));
        }
        cin >> lines[i];
    }
    for(int i = 0; i < c; i++){
        cin >> cols[i];
    }
    //
    // cout << mvars << endl;
    for(int k = 0; k < used.size(); k++){
        for(int i = 0; i < l; i++){
            int j,cnt=0,t=0;
            string prev = grid[i][0],v="-";
            for(j = 0; j < c; j++){
                si::iterator it = val.find(grid[i][j]);
                if(it != val.end()){
                    t += it->second;
                } else if(v[0] == '-') {
                    v = grid[i][j];
                    cnt = 1;
                } else if(grid[i][j] != v){
                    break;
                } else {
                    cnt++;
                }
                prev = grid[i][j];
            }
            if(j == c && v[0] != '-'){
                val.insert(make_pair(v,(lines[i]-t)/cnt));
            }
        }
        //
        for(int i = 0; i < c; i++){
            int j,cnt=0,t=0;
            string prev = grid[0][i],v="-";
            for(j = 0; j < l; j++){
                si::iterator it = val.find(grid[j][i]);
                if(it != val.end()){
                    t += it->second;
                } else if(v[0] == '-') {
                    v = grid[j][i];
                    cnt = 1;
                } else if(grid[j][i] != v){
                    break;
                } else {
                    cnt++;
                }
                prev = grid[j][i];
            }
            if(j == l && v[0] != '-'){
                val.insert(make_pair(v,(cols[i]-t)/cnt));
            }
        }
    }
    //
    for(si::iterator i = val.begin(); i != val.end(); i++){
        cout << i->first << " " << i->second << endl;
    }
    return 0;
}


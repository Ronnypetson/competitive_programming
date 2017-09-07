#include <iostream>
using namespace std;
char orientations[4] = {'N','L','S','O'};
int getIndex(char c){
    if(c == 'N') return 0;
    if(c == 'L') return 1;
    if(c == 'S') return 2;
    if(c == 'O') return 3;
    return -1;
}
int main(){
    int n, m, s, x, y;
    char grid[101][101], seq, ori;
    while(cin >> n >> m >> s){
        if(n == 0 && m == 0 && s == 0) break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(getIndex(grid[i][j]) > -1){
                    x = i, y = j;
                    ori = grid[i][j];
                }
            }
        int count = 0;
        for(int i = 0; i < s; i++){
            cin >> seq;
            int current;
            if(seq == 'D'){
                current = getIndex(ori);
                ori = orientations[(current+1)%4];
            } else if(seq == 'E'){
                current = getIndex(ori);
                ori = orientations[(current+3)%4];
            } else if(seq == 'F'){
                int vx = x, vy = y;
                if(ori == 'N') vx -= 1;
                else if(ori == 'S') vx += 1;
                else if(ori == 'L') vy += 1;
                else if(ori == 'O') vy -= 1;
                if(grid[vx][vy] != '#'){
                    if(vx >= 0 && vx < n && vy >= 0 && vy < m){
                        x = vx, y = vy;
                        if(grid[x][y] == '*'){
                            count++;
                            grid[x][y] = '-';
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
}


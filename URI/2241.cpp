#include <cstdio>
#include <vector>
using namespace std;
enum state{
    empty,conf,black,white
};
typedef vector<state> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
int b,w;
int min_(int a, int b){
    return (a < b) ? a : b;
}
void dp(vvvs &table, vvs &board){
    b=0,w=0;
    for(int i = 1; i < table.size(); i++)
        for(int j = 1; j < table.size(); j++){
            table[i][j].push_back(state::empty);
            table[i][j].push_back(board[i][j]);
            if(board[i][j] == state::white) w++;
            else if(board[i][j] == state::black) b++;
        }
    for(int d = 2; d < table.size(); d++){
        for(int i = 1; i < table.size()-d+1; i++)
            for(int j = 1; j < table.size()-d+1; j++){
                state s00 = table[i][j][d-1];
                state s01 = table[i][j+1][d-1];
                state s10 = table[i+1][j][d-1];
                state s11 = table[i+1][j+1][d-1];
                if(s00 == state::conf || s01 == state::conf
                || s10 == state::conf || s11 == state::conf){
                    // table[i][j][d] = state::conf;
                    table[i][j].push_back(state::conf);
                } else if(s00 == state::empty && s01 == state::empty
                       && s10 == state::empty && s11 == state::empty){
                    // table[i][j][d] = state::empty;
                    table[i][j].push_back(state::empty);
                } else if(s00 != state::white && s01 != state::white
                       && s10 != state::white && s11 != state::white){
                    // table[i][j][d] = state::black;
                    table[i][j].push_back(state::black);
                    b++;
                } else if(s00 != state::black && s01 != state::black
                       && s10 != state::black && s11 != state::black){
                    // table[i][j][d] = state::white;
                    table[i][j].push_back(state::white);
                    w++;
                } else {
                    // table[i][j][d] = state::conf;
                    table[i][j].push_back(state::conf);
                }
            }
    }
}
int main(){
    int n, p, r, c;
    scanf("%d %d",&n,&p);
    vvs board(n+1,*(new vs(n+1)));
    // vvvs table(n+1,*(new vvs(n+1,*(new vs(n+1)))));
    vvvs table(n+1,*(new vvs(n+1,*(new vs()))));
    for(int i = 0; i < p; i++){
        scanf("%d %d",&r,&c);
        board[r][c] = state::black;
    }
    for(int i = 0; i < p; i++){
        scanf("%d %d",&r,&c);
        board[r][c] = state::white;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i][j] != state::white && board[i][j] != state::black)
                board[i][j] = state::empty;
    /* for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%d",board[i][j]);
        printf("\n");
    } */
    dp(table,board);
    printf("%d %d\n",b,w);
    return 0;
}


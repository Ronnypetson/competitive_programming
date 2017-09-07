#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int nvis;
vi visited;

void dfs(int u, vvi &ug){
    if(visited[u] == 1) return;
    visited[u] = 1; nvis++;
    for(int i = 0; i < ug[u].size(); i++){
        dfs(ug[u][i],ug);
    }
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    vvi dir(n+1), un(n+1);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        dir[a].push_back(b);
        un[a].push_back(b);
        un[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < dir[i].size(); j++){
            int u = dir[i][j];
            // DFS from u on un
            nvis = 1;
            visited.assign(n+1,0);
            visited[i] = 1;
            dfs(u,un);
            //cout << nvis << " ";
            if(nvis == n){
                cout << "S" << endl;
                return 0;
            }
        }
    }
    cout << "N" << endl;
    return 0;
}


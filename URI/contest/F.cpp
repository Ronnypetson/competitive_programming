#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
class UnionFind{
private: vi p, rank;
public:
    UnionFind(int N) {
        rank.assign(N,0);
        p.assign(N,0);
        for(int i = 0; i < N; i++) p [i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]){
                    rank[y]++;
                }
            }
        }
    }
};

bool comp(pair<int,ii> a, pair<int,ii> b){
    return a.first > b.first;
}

int main(){
    int n,u,v,w;
    cin >> n;
    vector< pair<int,ii> > EdgeList;
    for(int i = 0; i < n; i++){
        cin >> u >> v >> w;
        EdgeList.push_back(make_pair(w,ii(u,v)));
    }
    sort(EdgeList.begin(),EdgeList.end());
    int mst_cost = 0, mx_cost = 0;
    UnionFind UF(1001);
    for(int i = 0; i < n; i++){
        pair<int,ii> front = EdgeList[i];
        if(!UF.isSameSet(front.second.first,front.second.second)){
            mst_cost += front.first;
            UF.unionSet(front.second.first,front.second.second);
        }
    }
    sort(EdgeList.begin(),EdgeList.end(),comp);
    UnionFind UFmx(1001);
    for(int i = 0; i < n; i++){
        pair<int,ii> front = EdgeList[i];
        if(!UFmx.isSameSet(front.second.first,front.second.second)){
            mx_cost += front.first;
            UFmx.unionSet(front.second.first,front.second.second);
        }
    }
    cout << mx_cost << endl << mst_cost << endl;
    return 0;
}


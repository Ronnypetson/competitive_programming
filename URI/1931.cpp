#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int,int> ii;
typedef map<int,int> mii;
typedef vector<mii> vmii;
typedef vector<int> vi;
int main(){
    int c, v, a, b, g;
    cin >> c >> v;
    vmii city(c+1,*(new mii));
    vmii dcity(c+1,*(new mii));
    for(int i = 0; i < v; i++){
        cin >> a >> b >> g;
        city[a].insert(make_pair(b,g));
        city[b].insert(make_pair(a,g));
        for(mii::iterator j = city[a].begin(); j != city[a].end(); j++){
            if(dcity[b].find(j->first) == dcity[b].end()){
                dcity[j->first].insert(make_pair(b,g+j->second));
                dcity[b].insert(make_pair(j->first,g+j->second));
            } else if(dcity[b][j->first]>g+j->second){
                dcity[b][j->first] = g+j->second;
                dcity[j->first][b] = g+j->second;
            }
        }
        for(mii::iterator j = city[b].begin(); j != city[b].end(); j++){
            if(dcity[a].find(j->first) == dcity[a].end()){
                dcity[j->first].insert(make_pair(a,g+j->second));
                dcity[a].insert(make_pair(j->first,g+j->second));
            } else if(dcity[a][j->first]>g+j->second){
                dcity[a][j->first] = g+j->second;
                dcity[j->first][a] = g+j->second;
            }
        }
    }
    vi dist(c+1,INF); dist[1] = 0;
    priority_queue<ii,vector<ii>, greater<ii> > pq; pq.push(ii(0,1));
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if(d > dist[u]) continue;
        for(mii::iterator j = dcity[u].begin(); j != dcity[u].end(); j++){
            if(dist[u]+j->second < dist[j->first]){
                dist[j->first] = dist[u] + j->second;
                pq.push(ii(dist[j->first],j->first));
            }
        }
    }
    if(dist[c] == INF){
        cout << "-1" << endl;
    } else {
        cout << dist[c] << endl;
    }
}


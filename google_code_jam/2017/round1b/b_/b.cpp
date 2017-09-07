#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1000000001
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
	int t,n,q,d[101][101],h[101][2],hr[101],query[100][3],ch[101];
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d",&n,&q);
		for(int j = 1; j <= n; j++){
			scanf("%d %d",&h[j][0],&h[j][1]);
		}
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				int cd;
				cin >> cd;
				if(cd == -1)
					cd = INF;
				d[j][k] = cd;
			}
		}
		printf("Case #%d:",i);
		for(int j = 0; j < q; j++){
			scanf("%d %d",&query[j][0],&query[j][1]);
			for(int k = 1; k <= n; k++){
				ch[k] = k;
				hr[k] = h[k][0];
			}
			//
			int s = query[j][0];
			vector<double> dist(n+1,INF);
			dist[s] = 0;
			priority_queue<ii,vector<ii>, greater<ii> > pq;
			pq.push(ii(0,s));
			while(!pq.empty()){
				ii front = pq.top(); pq.pop();
				int d_ = front.first, u = front.second;
				if(d_ > dist[u]) continue;
				int cav = ch[u];
				for(int k = 1; k <= n; k++){
					int v = d[u][k];
					if(v == INF) continue;
					//
					double cost,c1,c2;
					int ucav;
					c1 = 1.0*v/h[cav][1];
					c2 = 1.0*v/h[u][1];
					if(hr[cav] < v && hr[u] < v)
						continue;
					if(hr[cav] >= v && hr[u] < v)
						cost = c1, ucav = cav;
					else if(hr[cav] < v && hr[u] >= v)
						cost = c2, ucav = u;
					else{
						if(c1 == c2)
							if(hr[cav] > hr[u])
								ucav = cav, cost = c1;
							else
								ucav = u, cost = c2;
						else if(c1 < c2)
							ucav = cav, cost = c1;
						else
							ucav = u, cost = c2;
					}
					if(dist[u] + cost < dist[k]){
						dist[k] = dist[u] + cost;
						hr[ucav] -= v;
						ch[k] = ucav;
						pq.push(ii(dist[k], k));
					}
				}
			}
			printf(" %lf",dist[query[j][1]]);
		}
		printf("\n");
	}
}


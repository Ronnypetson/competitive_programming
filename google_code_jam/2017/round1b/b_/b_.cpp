#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1000000001
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adj;
int main(){
	int t,n,q,h[101][2],hr[101],query[100][3],ch[101];
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d",&n,&q);
		adj d(n+1,*(new vii));
		for(int j = 1; j <= n; j++){
			scanf("%d %d",&h[j][0],&h[j][1]);
		}
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				int cd;
				cin >> cd;
				if(cd != -1)
					cd = INF;
				d[j].push_back(ii(k,cd));
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
			int cav = 1;
			double dist = 0.0;
			for(int u = 2; u <= n; u++){
				ii v = d[u-1][u];
				double cost,c1,c2;
				int ucav;
				c1 = 1.0*h[cav][1]/v.second;
				c2 = 1.0*h[u-1][1]/v.second;
				if(hr[cav] < v.second && hr[u-1] < v.second)
					continue;
				if(hr[cav] >= v.second && hr[u-1] < v.second)
					cost = c1, ucav = cav;
				else if(hr[cav] < v.second && hr[u-1] >= v.second)
					cost = c2, ucav = u-1;
				else{
					if(c1 == c2)
						if(hr[cav] > hr[u-1])
							ucav = cav, cost = c1;
						else
							ucav = u-1, cost = c2;
					else if(c1 > c2)
						ucav = u-1, cost = c2;
					else
						ucav = cav, cost = c1;
				}
				printf("%lf ",cost);
				hr[ucav] -= v.second;
				dist += cost;
				cav = ucav;
			}
			//
			printf(" %lf",dist);
		}
		printf("\n");
	}
}


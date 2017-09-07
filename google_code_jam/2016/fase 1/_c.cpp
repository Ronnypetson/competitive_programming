#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int t,n,m,bff[1001],v[1001],ds[1001],mx[1001],vis[1001];
void dfs(int i, int d){
	if(v[i]){
		m = max(m,d-ds[i]+1);
		return;
	}
	vis[i] = 1;
	v[i] = 1;
	ds[i] = d+1;
	int b = bff[i];
	if(bff[b] != i && bff[bff[b]] == b){
		mx[b] = max(mx[b],d+2);
		// m = max(m,mx[b]+mx[bff[b]]);
	}
	dfs(b,d+1);
}
int main() {
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d",&n);
		set<int> s;
		for(int j = 1; j <= n; j++)
			s.insert(j);
		for(int j = 1; j <= n; j++){
			scanf("%d",&bff[j]);
			vis[j] = 0; mx[j] = 1;
			v[j] = 0; ds[j] = 0;
			s.erase(bff[j]);
		}
		m = 0;
		while(!s.empty()){
			int e = *s.begin();
			s.erase(e);
			dfs(e,0);
			for(int j = 1; j <= n; j++)
				v[j] = ds[j] = 0;
		}
		int sum = 0,b;
		for(int j = 1; j <= n; j++){
			b = bff[j];
			if(bff[b] == j)
				sum += mx[j];
		}
		m = max(m,sum);
		for(int j = 1; j <= n; j++)
			if(vis[j] == 0){
				ds[j] = 0;
				dfs(j,0);
			}
		printf("Case #%d: %d\n",i,m);
	}
	return 0;
}


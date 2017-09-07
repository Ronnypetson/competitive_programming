#include <cstdio>
#define LIM 1001
int t, n, bff[LIM], cnt[LIM], b, m, c, l;
void dfs(int i){ // printf("%d ",i);
	printf("%d %d %d\n",i,cnt[i],l);
	if(cnt[i] == -1){
		c = 1; // printf("1 ");
		return;
	}
	if(cnt[i] > 0){
		if(bff[bff[i]] == i) c = l;
		else{ c = l-cnt[i]+1; } // 5
		cnt[i] = -1; // printf("%d ",c);
		return;
	}
	cnt[i] = ++l;
	dfs(bff[i]);
	cnt[i] = -1;
}
int main(){
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d",&n);
		for(int j = 0; j < LIM; j++)
			bff[j] = cnt[j] = 0;
		for(int j = 1; j <= n; j++){
			scanf("%d",&b);
			bff[j] = b;
		}
		m = 0;
		for(int j = 1; j <= n; j++){
			if(cnt[j] == 0){
				l = 0; dfs(j);
				m = (c > m) ? c : m;
				//printf("%d %d\n",m,c);
			}
		}
		printf("Case #%d: %d\n",i,m);
	}
}


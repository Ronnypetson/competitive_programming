#include <cstdio>
int n,m,total,diff,h[1000];
int abs(int a){
	return (a > 0)? a : -a;
}
void change(int i, int k){
	h[i]+=k;h[i+1]+=k;
}
int main(){
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i = 0; i < n; i++)
			scanf("%d",&h[i]);
		total = 0;
		for(int i = 0; i <= n/2; i++){
			diff = m-h[i];
			change(i,diff);
			total += abs(diff);
			diff = m-h[n-i-1];
			change(n-i-2,diff);
			total += abs(diff);
		}
		printf("%d\n",total);
	}
}


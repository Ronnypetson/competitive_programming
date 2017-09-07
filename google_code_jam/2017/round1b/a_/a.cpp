#include <cstdio>
int main(){
	int t,d,n,k,s;
	double m,v;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d",&d,&n);
		m = 0.0;
		for(int j = 0; j < n; j++){
			scanf("%d %d",&k,&s);
			v = 1.0*(d-k)/s;
			m = (v > m) ? v : m;
		}
		v = d/m;
		printf("Case #%d: %lf\n",i,v);
	}
}


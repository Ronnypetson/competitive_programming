#include <cstdio>
#define LIM 2501
int t,n,h;
int hfreq[LIM];
int main(){
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d",&n);
		for(int j = 1; j < LIM; j++)
			hfreq[j] = 0;
		for(int j = 0; j < 2*n-1; j++)
			for(int k = 0; k < n; k++){
				scanf("%d",&h);
				hfreq[h]++;
			}
		printf("Case #%d:", i);
		for(int j = 1; j < LIM; j++)
			if(hfreq[j]%2)
				printf(" %d", j);
		printf("\n");
	}
}


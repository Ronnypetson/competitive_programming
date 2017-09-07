#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int t,n,p,cnt,qr[51],q[51][51];
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d",&n,&p);
		for(int j = 0; j < n; j++)
			scanf("%d",&qr[j]);
		for(int j = 0; j < n; j++)
			for(int k = 0; k < p; k++)
				scanf("%d",&q[j][k]);
		printf("Case #%d: %d\n",i,cnt);
	}
}


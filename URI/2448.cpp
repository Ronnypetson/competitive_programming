#include <cstdio>
// #include <map>
// using namespace std;
int abs(int a){
	return (a > 0) ? a : -a;
}
int pos[45001];
int main(){
	int n,m,num,cost,prev,current;
	while(scanf("%d %d",&n,&m) != EOF){
		// map<int,int> pos;
		for(int i = 1; i <= n; i++){
			scanf("%d",&num);
			pos[num] = i;
			// pos.insert(make_pair(num,i));
		}
		scanf("%d",&num);
		prev = pos[num]; // pos.at(num);
		cost = prev-1;
		for(int i = 1; i < m; i++){
			scanf("%d",&num);
			current = pos[num]; // pos.at(num);
			cost += abs(prev-current);
			prev = current;
		}
		printf("%d\n",cost);
	}
}


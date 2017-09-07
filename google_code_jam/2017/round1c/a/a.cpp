#include <cstdio>
#include <algorithm>
#include <vector>
#define PI 3.14159265359
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int t,n,k,h,r;
double m;
bool comp1(ii a, ii b){
	return a.first >= b.first;
}
bool comp2(ii a, ii b){
	return 2*PI*a.first*a.second > 2*PI*b.first*b.second;
}
int main(){
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d",&n,&k);
		vii pancakes;
		for(int j = 0; j < n; j++){
			scanf("%d %d",&r,&h);
			pancakes.push_back(make_pair(r,h));
		}
		m = 0.0;
		sort(pancakes.begin(),pancakes.end(),comp2);
		for(int j = 0; j < n; j++){
			ii current = pancakes[j];
			r = current.first;
			h = current.second;
			int cnt = 1;
			double c_j = PI*r*r + 2*PI*r*h;
			for(int l = 0; l < n; l++){
				if(cnt == k) break;
				if(l == j) continue;
				if(pancakes[l].first <= r){
					int r2 = pancakes[l].first;
					int h2 = pancakes[l].second;
					c_j += 2*PI*r2*h2;
					cnt++;
				}
			}
			m = (c_j > m) ? c_j : m;
		}
		printf("Case #%d: %lf\n",i,m);
	}
}


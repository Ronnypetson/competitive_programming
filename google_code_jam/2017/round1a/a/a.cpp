#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
	int t,r,c,lines[26];
	char cake[26][26],ch;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d",&r,&c);
		vii pos;
		for(int j = 0; j < r; j++)
			lines[j] = 0;	// Vazia
		for(int j = 0; j < r; j++){
			scanf("%c",&ch);
			for(int k = 0; k < c; k++){
				scanf("%c",&cake[j][k]);
				if(cake[j][k] != '?'){
					lines[j] = 1;
					pos.push_back(make_pair(j,k));
				}
			}
		}
		for(int j = 0; j < pos.size(); j++){
			int row = pos[j].first;
			int col = pos[j].second;
			for(int k = col-1; k >= 0; k--)
				if(cake[row][k] == '?')
					cake[row][k] = cake[row][col];
		}
		int next;
		for(int j = 0; j < r; j++)
			for(int k = 0; k < c; k++)
				if(cake[j][k] == '?' && lines[j]){
					next = k-1;
					while(next >= 0 && cake[j][next] == '?')next--;
					cake[j][k] = cake[j][next];
				}
		for(int j = 0; j < r; j++)
			if(lines[j] == 0){
				next = j+1;
				while(next < r && lines[next] == 0)next++;
				if(next < r)
					for(int l = 0; l < c; l++)
						cake[j][l] = cake[next][l];
			}
		for(int j = r-1; j >= 0; j--){
			if(lines[j]){
				next = j;
				break;
			}
		}
		for(int j = next+1; j < r; j++)
			for(int k = 0; k < c; k++)
				cake[j][k] = cake[next][k];
		printf("Case #%d:\n",i);
		for(int j = 0; j < r; j++){
			for(int k = 0; k < c; k++)
				printf("%c",cake[j][k]);
			printf("\n");
		}
	}
}


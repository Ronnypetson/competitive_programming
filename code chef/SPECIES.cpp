#include <cstdio>
#define N 50
#define M 1000000007
typedef unsigned int ui;
int clusters[N+2][N+2], vcluster[N*N], t, n, cl;
char grid[N+2][N+2], cc;
void set_clusters(int i, int j, char c){
	if(i > n || j > n || i < 1 || j < 1)
		return;
	if(grid[i][j] != c && grid[i][j] != '?')
		return;
	if(clusters[i][j] > 0)
		return;
	grid[i][j] = c;
	clusters[i][j] = cl;
	if(grid[i][j+1] == c || grid[i][j+1] == '?')
		set_clusters(i,j+1,c);
	if(grid[i+1][j] == c || grid[i+1][j] == '?')
		set_clusters(i+1,j,c);
	if(grid[i-1][j] == c || grid[i-1][j] == '?')
		set_clusters(i-1,j,c);
	if(grid[i][j-1] == c || grid[i][j-1] == '?')
		set_clusters(i,j-1,c);
}
int num_poss(int i, int j){
	int neigh[82];
	neigh['.'] = neigh['?'] = neigh['B'] = neigh['G'] = neigh['P'] = 0;
	neigh[grid[i-1][j]] = 1; neigh[grid[i][j-1]] = 1;
	neigh[grid[i+1][j]] = 1; neigh[grid[i][j+1]] = 1;
	if(grid[i][j] != '?'){
		if(grid[i][j] == '.') return 1;
		else if(neigh['G']) return 0; 
		else if(grid[i][j] == 'B' && neigh['P'])
			return 0;
		else if(grid[i][j] == 'P' && neigh['B'])
			return 0;
		else if(grid[i][j] == 'G' && (neigh['B'] || neigh['P'] || neigh['?']))
			return 0;
		else return 1;
	} else if(neigh['G']) return 0;
	else if(vcluster[clusters[i][j]] == 0){
		vcluster[clusters[i][j]] = 1;
		return 2;
	} else return 1;
}
ui poss(){
	ui p = 1;
	for(int i = 1; i <= n && p != 0; i++)
		for(int j = 1; j <= n && p != 0; j++){
			p *= num_poss(i,j);
			p %= M;
		}
	return p;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0; i <= n+1; i++)
			grid[0][i] = grid[n+1][i] = grid[i][0] = grid[i][n+1] = '.';
		for(int i = 0; i <= n+1; i++)
			for(int j = 0; j <= n+1; j++)
				clusters[i][j] = 0;
		for(int i = 0; i < N*N; i++)
				vcluster[i] = 0;
		scanf("%c",&cc);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				scanf("%c",&grid[i][j]);
			scanf("%c",&cc);
		}
		cl = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if((grid[i][j] == 'B' || grid[i][j] == 'P') && clusters[i][j] == 0){
					cl++;
					set_clusters(i,j,grid[i][j]);
				}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				printf("%c ",grid[i][j]);
			printf("\n");
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(grid[i][j] == '?' && clusters[i][j] == 0){
					cl++;
					set_clusters(i,j,'?');
				}
		printf("%u\n",poss());
	}
	return 0;
}


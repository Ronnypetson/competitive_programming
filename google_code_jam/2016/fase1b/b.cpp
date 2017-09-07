#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	string c,j;
	char g;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> c >> j; g = 'n';
		for(int k = 0; k < c.size(); k++){ // cout << c << " " << j << endl;
			if(g == 'n' && c[k] != '?' && j[k] != '?'){ // cout << "here ";
				if(c[k] > j[k])
					g = 'c';
				else if(j[k] > c[k])
					g = 'j';
			}
			// ? ?
			if(c[k] == '?' && j[k] == '?'){
				if(g == 'n')
					c[k] = j[k] = '0';
				else if(g == 'c')
					c[k] = '0', j[k] = '9';
				else if(g == 'j')
					c[k] = '9', j[k] = '0';
			}
			// ? d
			else if(c[k] == '?' && j[k] != '?'){ // cout << "here c ";
				if(g == 'n'){
					if(k+1 < c.size() && c[k+1] != '?' && j[k+1] != '?'){
						if(c[k+1]-j[k+1] >= 5)
							c[k] = max((int)'0',j[k]-1);
						else if(c[k+1]-j[k+1] < -5)
							c[k] = min((int)'9',j[k]+1);
						else c[k] = j[k];
					} else c[k] = j[k];
					if(c[k] < j[k]) g = 'j';
				} else if(g == 'c')
					c[k] = '0';
				else if(g == 'j')
					c[k] = '9';
			}
			// d ?
			else if(j[k] == '?' && c[k] != '?'){ // cout << "here j ";
				if(g == 'n'){
					if(k+1 < j.size() && j[k+1] != '?' && c[k+1] != '?'){
						if(j[k+1]-c[k+1] >= 5)
							j[k] = max((int)'0',c[k]-1);
						else if(j[k+1]-c[k+1] < -5)
							j[k] = min((int)'9',c[k]+1);
						else j[k] = c[k];
					} else j[k] = c[k];
					if(j[k] < c[k]) g = 'c';
				} else if(g == 'j')
					j[k] = '0';
				else if(g == 'c')
					j[k] = '9';
			}
		}
		cout << "Case #" << i << ": " << c << " " << j << endl;
	}
}


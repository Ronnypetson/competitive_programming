#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int t,d[10];
int count(string s, char c){
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == c) cnt++;
	return cnt;
}
void attrib(map<char,int> m, string& s){
	s = "";
	for(auto i = m.begin(); i != m.end(); i++)
		s += i->first;
	cout << s << endl;
}
int main(){
	string s;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> s;
		map<char,int> s_;
		for(int j = 1; j <= s.size(); j++)
			s_.insert(make_pair(s[j],j));
		d[0] = count(s,'Z');
		for(int j = 0; j < d[0]; j++){
			s_.erase('Z');
			s_.erase('E');
			s_.erase('R');
			s_.erase('O');
		}
		attrib(s_,s);
		d[2] = count(s,'W');
		for(int j = 0; j < d[2]; j++){
			s_.erase('T');
			s_.erase('W');
			s_.erase('O');
		}
		attrib(s_,s);
		d[4] = count(s,'U');
		for(int j = 0; j < d[4]; j++){
			s_.erase('F');
			s_.erase('O');
			s_.erase('U');
			s_.erase('R');
		}
		attrib(s_,s);
		d[6] = count(s,'X');
		for(int j = 0; j < d[6]; j++){
			s_.erase('S');
			s_.erase('I');
			s_.erase('X');
		}
		attrib(s_,s);
		d[8] = count(s,'G');
		for(int j = 0; j < d[8]; j++){
			s_.erase('E');
			s_.erase('I');
			s_.erase('G');
			s_.erase('H');
			s_.erase('T');
		}
		attrib(s_,s);
		//
		d[1] = count(s,'O');
		for(int j = 0; j < d[1]; j++){
			s_.erase('O');
			s_.erase('N');
			s_.erase('E');
		}
		attrib(s_,s);
		d[3] = count(s,'H');
		for(int j = 0; j < d[3]; j++){
			s_.erase('T');
			s_.erase('H');
			s_.erase('R');
			s_.erase('E');
			s_.erase('E');
		}
		attrib(s_,s);
		d[5] = count(s,'F');
		for(int j = 0; j < d[5]; j++){
			s_.erase('F');
			s_.erase('I');
			s_.erase('V');
			s_.erase('E');
		}
		attrib(s_,s);
		d[7] = count(s,'S');
		for(int j = 0; j < d[7]; j++){
			s_.erase('S');
			s_.erase('E');
			s_.erase('V');
			s_.erase('E');
			s_.erase('N');
		}
		attrib(s_,s);
		d[9] = count(s,'I');
		for(int j = 0; j < d[9]; j++){
			s_.erase('N');
			s_.erase('I');
			s_.erase('N');
			s_.erase('E');
		}
		attrib(s_,s);
		//
		printf("Case #%d: ",i);
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < d[j]; k++)
				printf("%d",j);
		printf("\n");
		/* s = clean(s,'Z');
		s = clean(s,'G');
		s = clean(s,'W');
		s = clean(s,'U');
		s = clean(s,'X');
		//
		s = clean(s,'H');
		s = clean(s,'O');
		s = clean(s,'S');
		//
		s = clean(s,'F');
		s = clean(s,'I'); */
	}
}


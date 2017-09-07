#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int slen(vvi &t){
    int len = 1, u = 1;
    while(t[u][0] != 0){
        len++;
        u = t[u][0];
    }
    return len;
}
int mlen(vvi &t){
    int m = 0, node;
    queue<ii> q;
    q.push(make_pair(1,1));
    while(!q.empty()){
        ii u = q.front(); q.pop();
        node = u.first;
        m = (m < u.second) ? u.second : m;
        if(t[node][0] != 0)
            q.push(make_pair(t[node][0],u.second+1));
        if(t[node][1] != 0)
            q.push(make_pair(t[node][1],1));
    }
    return m;
}
int min_(int a, int b){
    return (a < b) ? a : b;
}
int main(){
    int n,i,l,k,m,p,q,r,ans;
    scanf("%d",&n);
    vvi can(n+1);
    for(int a = 1; a <= n; a++){
        scanf("%d %d %d",&i,&l,&k);
        vi children = { k, l };
        can[i] = children;
    }
    scanf("%d",&m);
    vvi des(m+1);
    for(int a = 1; a <= m; a++){
        scanf("%d %d %d",&p,&q,&r);
        vi children = { q, r };
        des[p] = children;
    }
    int s_can = slen(can), s_des = slen(des);
    int m_can = mlen(can), m_des = mlen(des);
    if(s_can == s_des){
        if(m_can > m_des){
            ans = min_(m_can,s_des);
        } else {
            ans = min_(m_des,s_can);
        }
    } else if(s_can > s_des){
        ans = min_(m_des,s_can);
    } else {
        ans = min_(m_can,s_des);
    }
    printf("%d\n",m+n-ans);
    return 0;
}


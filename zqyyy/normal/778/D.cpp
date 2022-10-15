#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define pii pair<int,int>
const int N=55;
int n,m,_n,_m;
char s[N][N],t[N][N];
vector<pii>pre,suf,st;
inline void rotate(int x,int y){
    st.push_back({x,y});
    if(s[x][y]=='L'){
	s[x][y]='U',s[x][y+1]='U';
	s[x+1][y]='D',s[x+1][y+1]='D';
    }else{
	s[x][y]='L',s[x][y+1]='R';
	s[x+1][y]='L',s[x+1][y+1]='R';
    }
}
void dfs(int x,int y){
    if(s[x][y]=='L')return;
    if(s[x][y+1]=='L')dfs(x+1,y+1),rotate(x,y+1);
    rotate(x,y);
}
inline vector<pii> work(){
    n=_n,m=_m;
    if(_m&1){
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
		if(s[i][j]=='L')t[j][i]='U';
		else if(s[i][j]=='R')t[j][i]='D';
		else if(s[i][j]=='U')t[j][i]='L';
		else t[j][i]='R';
	swap(n,m);
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)s[i][j]=t[i][j];
    }
    st.clear();
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    if(s[i][j]=='U')dfs(i,j);
    if(_m&1)for(auto& [x,y]:st)swap(x,y);
    return st;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    _n=read(),_m=read();
    for(int i=1;i<=_n;i++)scanf("%s",s[i]+1);
    pre=work();
    for(int i=1;i<=_n;i++)scanf("%s",s[i]+1);
    suf=work();
    reverse(suf.begin(),suf.end());
    printf("%lu\n",pre.size()+suf.size());
    for(auto [x,y]:pre)printf("%d %d\n",x,y);
    for(auto [x,y]:suf)printf("%d %d\n",x,y);
    return 0;
}
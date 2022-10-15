#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int pa[N];
int find(int x){return x==pa[x]?x:pa[x]=find(pa[x]);}
inline void unin(int x,int y){
	x=find(x),y=find(y);if(x==y)return;
	pa[x]=y;
}
struct Edge{
	int to,nxt;
}e[N];
int cnt,head[N];
inline void add_e(int from,int to){
	e[++cnt].to=to;
	e[cnt].nxt=head[from];
	head[from]=cnt;
}
int n,m;
bool vis[N],in[N],flg;
vector<int>c[N];
void dfs(int x){
	if(in[x]){flg=0;return;}
	if(vis[x])return;
	vis[x]=in[x]=1;
	for(int i=head[x];i;i=e[i].nxt)dfs(e[i].to);
	in[x]=0;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add_e(x,y);unin(x,y);
	}
	for(int i=1;i<=n;i++)c[find(i)].push_back(i);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!c[i].size())continue;
		flg=1;
		for(auto x:c[i])dfs(x);
		ans+=c[i].size()-flg;
	}
	return cout<<ans,0;
}
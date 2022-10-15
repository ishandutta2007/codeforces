#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
struct Edge{
	int to,nxt,w;
}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]={y,head[x],w},head[x]=s_e;
}
int n,m,Q,scc,bel[N];
ll dis[N],f[N];
bool vis[N];
vector<int>rG[N],vec;
void dfs1(int x){
	vis[x]=1;
	for(int y:rG[x])
		if(!vis[y])dfs1(y);
	vec.push_back(x);
}
void dfs(int x){
	vis[x]=1,bel[x]=scc;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(!vis[y])dis[y]=dis[x]+e[i].w,dfs(y);
		else if(bel[y]==scc)f[scc]=gcd(f[scc],dis[x]+e[i].w-dis[y]);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),w=read();
		add_e(x,y,w),rG[y].push_back(x);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs1(i);
	reverse(vec.begin(),vec.end());
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int x:vec)if(!vis[x])scc++,dfs(x);
	Q=read();
	while(Q--){
		int v=bel[read()],s=read(),t=read();
		if(s && !f[v])puts("NO");
		else if(s%gcd(f[v],t)==0)puts("YES");
		else puts("NO");
	}
	return 0;
}
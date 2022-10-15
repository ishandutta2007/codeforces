#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=3e5+7;
int n,m,Q,s_dfn,dfn[N],f[N][19];
ll dp[N];
bool vis[N],v[N];
vector<int>G[N],g[N];
void dfs1(int x){
	vis[x]=1;
	for(int y:g[x])
		if(!vis[y]){
			G[x].push_back(y);
			G[y].push_back(x);
			dfs1(y);	
		}
}
void dfs(int x,int fa){
	f[x][0]=fa,dfn[x]=++s_dfn;
	for(int i=1;i<=18;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int y:G[x])if(y^fa)dfs(y,x);	
}
inline int LCA(int x,int y){
	if(x==y)return x;if(dfn[x]>dfn[y])swap(x,y);
	for(int i=18;~i;i--)
		if(dfn[f[y][i]]>dfn[x])y=f[y][i];
	return f[y][0];
}
vector<int>vec[N];
void dfs2(int x,int fa){
	int num=0;
	for(int y:G[x]){
		if(y==fa)continue;
		dfs2(y,x),dp[x]+=dp[y],num+=v[y];
	}
	if(v[x] && num%2==0)dp[x]++;
	dp[x]-=num/2;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		g[x].push_back(y),g[y].push_back(x);	
	}
	dfs1(1),dfs(1,0);
	Q=read();
	for(int i=1;i<=Q;i++){
		int x=read(),y=read(),lca=LCA(x,y);
		while(x^lca)v[x]^=1,vec[i].push_back(x),x=f[x][0];
		vec[i].push_back(lca);vector<int>buf;
		while(y^lca)v[y]^=1,buf.push_back(y),y=f[y][0];
		for(int j=buf.size()-1;~j;j--)vec[i].push_back(buf[j]);
	}
	dfs2(1,0);
	if(!dp[1]){
		puts("YES");
		for(int i=1;i<=Q;i++){
			printf("%lu\n",vec[i].size());
			for(int x:vec[i])printf("%d ",x);
			puts("");
		}
		return 0;
	}
	printf("NO\n%lld\n",dp[1]);
	return 0;
}
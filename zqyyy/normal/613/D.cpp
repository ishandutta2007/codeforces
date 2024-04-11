#include <bits/stdc++.h>
using namespace std;
#define pb push_back
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,m,Q,tot,dfn[N],f[N][17],a[N<<1];
bool flg[N];
vector<int>G[N],g[N];
void dfs(int x,int fa){
	dfn[x]=++tot,f[x][0]=fa;
	for(int i=1;i<=16;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:G[x])if(y^fa)dfs(y,x);
}
inline int LCA(int x,int y){
	if(x==y)return x;if(dfn[x]>dfn[y])swap(x,y);
	for(int i=16;~i;i--)
		if(dfn[f[y][i]]>dfn[x])y=f[y][i];
	return f[y][0];
}
int dp(int x){
	int ans=0;
	for(auto y:g[x])ans+=dp(y);
	if(flg[x])for(auto y:g[x])ans+=flg[y];
	else{
		int cnt=0;
		for(auto y:g[x])cnt+=flg[y];
		if(cnt==1)flg[x]=1;
		else if(cnt>1)ans++;
	}
	return ans;
}
inline void work(){
	m=read();
	for(int i=1;i<=m;i++)a[i]=read(),flg[a[i]]=1;
	for(int i=1;i<=m;i++)
		if(flg[f[a[i]][0]]){
			for(int j=1;j<=m;j++)flg[a[j]]=0;
			puts("-1");return;
		}
	sort(a+1,a+m+1,[&](int x,int y){return dfn[x]<dfn[y];});
	int res=m;
	for(int i=1;i<res;i++){
		int lca=LCA(a[i],a[i+1]);
		if(lca!=a[i] && lca!=a[i+1])a[++m]=lca;
	}
	sort(a+1,a+m+1),m=unique(a+1,a+m+1)-a-1;
	sort(a+1,a+m+1,[&](int x,int y){return dfn[x]<dfn[y];});
	for(int i=2;i<=m;i++)g[LCA(a[i-1],a[i])].pb(a[i]);
	printf("%d\n",dp(a[1]));
	for(int i=1;i<=m;i++)flg[a[i]]=0,g[a[i]].clear();
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].pb(y),G[y].pb(x);
	}
	dfs(1,0);Q=read();
	while(Q--)work();
	return 0;
}
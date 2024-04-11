#include<bits/stdc++.h>
#define maxn 101000
using namespace std;
int dp[maxn][2],nxt[maxn][2],f[maxn][2],n,m;
vector<int>G[maxn];
int dfs(int u,int p){
//	printf("{%d,%d}",u,p);
	if(dp[u][p]==1)return f[u][p];
	if(dp[u][p]==-1)return -1;
	if(G[u].size()==0){
		f[u][p]=(p==1?1:0);
		dp[u][p]=1;
		return f[u][p];
	}
	dp[u][p]=-1,f[u][p]=0;
	for(auto v:G[u]){
		int x=dfs(v,p^1);
		if(x==1)f[u][p]=1,nxt[u][p]=v;
		else if(x==-1&&f[u][p]==0)f[u][p]=-1;
	}
	dp[u][p]=1;
	return f[u][p];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=n;++i){
		scanf("%d",&u);
		for(int j=1;j<=u;++j)
			scanf("%d",&v),G[i].push_back(v);
	}
	int s;
	scanf("%d",&s);
	int x=dfs(s,0);
	if(x==1){
		puts("Win");
		int rt=s,p=0;
		while(rt)printf("%d ",rt),rt=nxt[rt][p],p^=1;
	} else puts(x==-1?"Draw":"Lose");
}
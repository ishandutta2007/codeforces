#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=5e5+10;
int f[maxn][2],n,g[maxn][2];
vector<int>G[maxn];
void dfs(int u,int fa){
	int g0=1,gall=1;
	int f0=0,fall=0;
	for(auto v:G[u])if(v!=fa){
		dfs(v,u);
		fall=(2ll*(g[v][0]+g[v][1])*fall%mod+(1ll*f[v][0]+f[v][1]+f[v][0]+f[v][1])*gall)%mod;
		f0=((1ll*g[v][1]+g[v][0]+g[v][1])*f0%mod+(1ll*f[v][1]+f[v][0]+f[v][1])*g0)%mod;
		gall=2ll*gall*(g[v][0]+g[v][1])%mod;
		g0=1ll*g0*(1ll*g[v][0]+g[v][1]+g[v][1])%mod;
	}
	g[u][0]=g0;
	g[u][1]=(gall-g0+mod)%mod;
	f[u][0]=f0;
	f[u][1]=(2ll*g[u][1]+fall-f0+mod)%mod;
//	printf("[%d:(%d,%d)]\n",u,g[u][0],g[u][1]);
}
int main(){
//	n=5e5;
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
	//	u=1,v=i;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	printf("%d",(f[1][0]+f[1][1])%mod);
}
#include<bits/stdc++.h>
#define maxn 4010
#define mod 998244353
using namespace std;
typedef long long ll;
int inv[maxn],fac[maxn],pre[maxn][80],anses[maxn][80];
int C[80][80],ans1,ans2,n1,n2,K,dp[maxn][80],f[80],g[80];
vector<int>G[maxn];
void upd(int& x,int y){
	(x+=y)>=mod?x-=mod:0;
}
void dfs1(int u,int f){
	dp[u][0]=1;
	for(auto v:G[u])if(v!=f)
		dfs1(v,u);
	for(int i=0;i<K;++i)if(dp[u][i])
		for(auto v:G[u])if(v!=f)
			for(int j=0;dp[v][j]&&i+j+1<=K;++j)
				dp[u][i+j+1]=(dp[u][i+j+1]+1ll*dp[u][i]*dp[v][j])%mod;
}
void dfs2(int u,int f){
	int ls[80]={0},_ls[80]={0};
	for(auto v:G[u])if(v!=f)
		for(int i=0;i<K;++i)upd(ls[i+1],dp[v][i]);
	for(int i=0;i<K;++i)upd(ls[i+1],pre[u][i]);
	auto cal=[&](int to[]){
		for(int i=0;i<=K;++i)to[i]=0,_ls[i]=0;
		to[0]=1,_ls[0]=1;
		for(int i=1;i<=K;++i)
			for(int j=i;j>=1;--j)
				to[i]=(to[i]+1ll*to[i-j]*ls[j])%mod;
	};
	cal(anses[u]);
	for(auto v:G[u])if(v!=f){
		for(int i=0;i<K;++i)
			upd(ls[i+1],mod-dp[v][i]);
		cal(pre[v]);
		dfs2(v,u);
		for(int i=0;i<K;++i)
			upd(ls[i+1],dp[v][i]);
	}
}
void sol(int n,int f[]){
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<=n;++i)
		for(int j=0;j<=K;++j)
			dp[i][j]=anses[i][j]=pre[i][j]=0;
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=K;++j)
			upd(f[j],anses[i][j]);
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d%d%d",&n1,&n2,&K);
	if(K&1)return puts("0"),0;
	K>>=1,fac[0]=inv[0]=1;
	for(int i=1;i<=K;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[K]=qpow(fac[K],mod-2);
	for(int i=K-1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=0;i<=K*2;++i)
		for(int j=*C[i]=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	sol(n1,f),sol(n2,g);
	int ans=0;
	for(int i=0;i<=K;++i)
		ans=(ans+1ll*f[i]*g[K-i]%mod*C[2*K][i*2])%mod;
	printf("%d",ans);
}
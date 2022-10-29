#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=1e9+7;
typedef unsigned long long ull;
int sz[101000],dp[101000][210][4],n,K,fac[210],inv[210];
int f[210][4],g[210][4];
ull tmp[4];
vector<int>G[maxn];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int C(int x,int y){
	if(x<y||y<0)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void dfs(int u,int fa){
	sz[u]=1;
	for(auto v:G[u])if(v!=fa)
		dfs(v,u),sz[u]+=sz[v];
	memset(f,0,sizeof(f));
	f[0][1]=1,f[0][0]=1;
	int s=0;
	for(auto v:G[u])if(v!=fa){
		memset(g,0,sizeof(g));
		for(int j=0;j<=s&&j<=K;++j)
			for(int k=0;k<=sz[v]&&j+k<=K;++k){
				int* A=f[j],*B=dp[v][k],*C=g[j+k];
				for(int a=0;a<4;++a)if(A[a])
					for(int b=0;b<4;++b)if(B[b]){
						int z=(a&1)|(b&1);
						int f=((a&2)&&(b&1)==0)||((a&1)==0&&(b&2));
						tmp[z|(f<<1)]=(tmp[z|(f<<1)]+1ll*A[a]*B[b]);
					}
				for(int a=0;a<4;++a)C[a]=(C[a]+tmp[a])%mod,tmp[a]=0;
			}
		for(int j=0;j<=K;++j)
			for(int k=0;k<4;++k)
				f[j][k]=g[j][k];
		s+=sz[v];
	}
	memset(g,0,sizeof(g));
	for(int i=0;i<=K;++i)
		for(int j=0;j<4;++j){
			if(fa!=0&&(j&1))g[i+1][j|2]=(g[i+1][j|2]+f[i][j])%mod;
			g[i][j]=(g[i][j]+f[i][j])%mod;
		}
	for(int i=0;i<=K;++i)
		for(int j=0;j<4;++j)
			dp[u][i][j]=g[i][j];//,printf("{(%d,%d,%d)=%d}\n",u,i,j,g[i][j]);
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	fac[0]=inv[0]=1;
	for(int i=1;i<=K;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[K]=qpow(fac[K],mod-2);
	for(int i=K-1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=K;++i){
//		printf("[%d]",dp[1][i][0]+dp[1][i][1]);
		int sum=0;
		for(int j=0;j<=i;++j)
			sum=(sum+1ll*C(i,j)*(j&1?mod-1:1)%mod*qpow(i-j,K))%mod;
		ans=(ans+1ll*sum*(dp[1][i][0]+dp[1][i][1]))%mod;
	}
	printf("%d",ans);
}
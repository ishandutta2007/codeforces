#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=998244353;
int n,fac[maxn],inv[maxn],f[maxn],vs[maxn];
vector<int> G[maxn];
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
int dfs(int u){
	int lst=-1;
	for(auto v:G[u])if(!vs[v]){
		lst=v;
//		break;
	}
	if(lst==-1){
		return 1;
	}
	
	vs[u]=1,vs[lst]=1;
	int ans=1,lc=0,rc=0;
	for(auto v:G[u])if(!vs[v])ans=1ll*ans*dfs(v)%mod,lc++;
	for(auto v:G[lst])if(!vs[v])ans=1ll*ans*dfs(v)%mod,rc++;
	int zl=(1ll*fac[lc]*C(lc+2,2)%mod*fac[rc+1]+1ll*fac[rc]*C(rc+2,2)%mod*fac[lc+1]-1ll*fac[lc+1]*fac[rc+1]%mod+mod)%mod;
//	printf("{[%d,%d](%d,%d)%d}",lst,u,lc,rc,zl);
	ans=1ll*ans*zl%mod;
	return 2ll*ans%mod;
}
int main(){
	scanf("%d",&n);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	//for(int i=1;i<=n;++i)
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans=1;
	for(int i=1;i<=n;++i)ans=1ll*ans*fac[G[i].size()]%mod; 
	printf("%d",1ll*n*ans%mod);
}
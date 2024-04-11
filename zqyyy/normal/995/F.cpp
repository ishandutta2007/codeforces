#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uint64_t ull;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=3007,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,D,f[N][N];
vector<int>G[N];
void dfs(int x){
	for(int i=1;i<=n;i++)f[x][i]=1;
	for(int y:G[x]){
		dfs(y);
		for(int i=1;i<=n;i++)
			f[x][i]=1ll*f[x][i]*f[y][i]%mod;
	}
	for(int i=2;i<=n;i++)f[x][i]=(f[x][i]+f[x][i-1])%mod;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),D=read();
	for(int i=2;i<=n;i++)
		G[read()].push_back(i);
	n++,dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int fz=1,fm=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			fz=1ll*fz*(D+mod-j)%mod;
			fm=1ll*fm*(i+mod-j)%mod;
		}
		ans=(ans+1ll*fz*qpow(fm,mod-2)%mod*f[1][i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
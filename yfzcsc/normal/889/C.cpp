#include<bits/stdc++.h>
#define maxn 1001000
#define mod 1000000007
using namespace std;
int dp[maxn],n,k,fac[maxn],inv[maxn],f[maxn];
int main(){
	scanf("%d%d",&n,&k),fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod,inv[i]=(i==1?1:1ll*inv[mod%i]*(mod-mod/i)%mod);
	for(int i=1;i<=n;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
	for(int i=1;i<=k;++i)dp[i]=0;
	for(int i=k+1;i<=n;++i){
		dp[i]=1ll*fac[i-2]*(i-k-1+(f[i-1]-f[i-k-1]+mod))%mod;
		f[i]=(f[i-1]+1ll*dp[i]*inv[i-1])%mod;
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans=(ans+1ll*dp[i]*inv[i-1])%mod;
	printf("%d",1ll*ans*fac[n-1]%mod);
}
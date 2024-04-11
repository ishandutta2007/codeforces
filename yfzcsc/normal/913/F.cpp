#include<bits/stdc++.h>
#define mod 998244353
#define maxn 2010
using namespace std;
int dp[maxn],f[maxn],C[maxn][maxn],n,a,b,P,pw[maxn],fpw[maxn],fP;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&a,&b),pw[0]=fpw[0]=1;
	P=1ll*a*qpow(b,mod-2)%mod,fP=mod+1-P;
	for(int i=1;i<=n;++i)pw[i]=1ll*pw[i-1]*P%mod;
	for(int i=1;i<=n;++i)fpw[i]=1ll*fpw[i-1]*fP%mod;
	for(int i=0;i<=n;++i)
		for(int j=*C[i]=1;j<=i;++j)
			C[i][j]=(1ll*C[i-1][j]*pw[j]+1ll*C[i-1][j-1]*fpw[i-j])%mod;
	f[1]=1;
	for(int i=2;i<=n;++i){
		f[i]=1;
		for(int j=1;j<i;++j)
			f[i]=(f[i]-1ll*f[j]*C[i][j]%mod+mod)%mod;
//		printf("[%d]",f[i]*4ll%mod);
	}
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;++j)
			dp[i]=(dp[i]+1ll*f[j]*C[i][j]%mod*(j*(j-1)/2+j*(i-j)+dp[j]+dp[i-j]))%mod;
		dp[i]=(1ll*i*(i-1)/2*f[i]+dp[i])%mod*qpow(mod+1-f[i],mod-2)%mod;
//		printf("[%d]",dp[i]);
	}
	printf("%d",(dp[n]-n+mod)%mod);
}
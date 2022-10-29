#include<bits/stdc++.h>
#define maxn 210
using namespace std;
typedef long long ll;
int dp[maxn][maxn],ans,n,d,mod,g[maxn],C[maxn][maxn];
int main(){
	scanf("%d%d%d",&n,&d,&mod);
	g[1]=dp[1][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=*C[i]=1;j<=i;++j)
			C[i][j]=(1ll*C[i-1][j]+C[i-1][j-1])%mod;
	ans=0;
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;j++)
			for(int k=1;k<=d;++k)
				dp[i][k]=(dp[i][k]+1ll*dp[i-j][k-1]*g[j]%mod*C[i-2][j-1])%mod;
		for(int k=0;k<d;++k)g[i]=(1ll*g[i]+dp[i][k])%mod;
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<=d;++j)
			for(int k=0;j+k<=d;++k)if(k!=1)
				ans=(ans+1ll*dp[i+1][j]*dp[n-i][k])%mod;
	ans=2ll*n*(n-1)*ans%mod;
	printf("%d",ans);
}
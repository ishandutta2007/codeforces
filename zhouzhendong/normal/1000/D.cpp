#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005;
const int mod=998244353;
int n,a[N],dp[N],sum[N],C[N][N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<=n;i++)
		C[i][0]=C[i][i]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	memset(dp,0,sizeof dp);
	dp[0]=sum[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=i-1;j>0;j--){
			if (a[j]>0&&a[j]<=n)
				dp[i]=(dp[i]+1LL*sum[j-1]*C[i-j-1][a[j]-1]%mod)%mod;
		}
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=(ans+dp[i])%mod;
	printf("%d",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5,mod=1e9+7;
long long a[maxn],dp[maxn],sum[maxn],n;
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		for(int i=0;i<=n;++i)dp[i]=sum[i]=a[i]=0;
		cin>>n;
		for(int j=1;j<=n;++j)cin>>a[j],sum[j]=sum[j-1]+a[j];
		map<long long,long long>s;
		dp[0]=1;
		long long s1=0;
		for(int i=1;i<=n;++i)
		{
			dp[i]=s1;
			dp[i]-=s[sum[i-1]];
			dp[i]=(dp[i]+mod)%mod;
			if(sum[i-1]!=0)dp[i]+=dp[0];
			dp[i]%=mod;
			s[sum[i-1]]=(s[sum[i-1]]+dp[i])%mod;
			s1=(s1+dp[i])%mod;
		}
		printf("%lld\n",(s1+1)%mod);
	}
	return 0;
}
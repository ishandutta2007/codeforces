#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 510
using namespace std;
 
ll T,n,m,K,ans=INF,dp[N][N],pos[N],num[N];
 
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	memset(dp,0x3f,sizeof(dp));
	ll i,j,k;
	scanf("%lld%lld%lld",&n,&m,&K);
	for(i=1; i<=n; i++) scanf("%lld",&pos[i]);pos[n+1]=m;
	for(i=1; i<=n; i++) scanf("%lld",&num[i]);
	dp[1][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			for(k=i+1;k<=n+1;k++)
			{
				Min(dp[k][j+k-i-1],dp[i][j]+(pos[k]-pos[i])*num[i]);
			}
		}
	}
	for(i=0;i<=K;i++) Min(ans,dp[n+1][i]);
	cout<<ans;
}
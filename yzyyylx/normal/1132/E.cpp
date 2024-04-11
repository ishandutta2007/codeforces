#include<bits/stdc++.h>
#define ll long long
#define n 8
#define MN 300000
using namespace std;

ll W,sum,ans,cnt[10],dp[400100];

inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
    memset(dp,-1,sizeof(dp));
    ll i,j,t;
    cin>>W;
    for(i=1;i<=n;i++)
    {
	scanf("%lld",&cnt[i]);
	sum+=cnt[i]*i;
    }
    if(sum<=W)
    {
	cout<<sum;
	return 0;
    }
    sum=0;
    for(i=1;i<=n;i++)
    {
	t=min(cnt[i]-1000,(W-sum-MN+100)/i);
	if(t<=0) continue;
	cnt[i]-=t;
	sum+=t*i;
    }
//    cout<<sum<<endl;
//    for(i=1;i<=n;i++) cout<<cnt[i]<<" ";puts("");
    dp[0]=0;
    for(i=1;i<=n;i++)
    {
	for(j=0;j<=MN;j++) if(dp[j]>=0) dp[j]=cnt[i];
	for(j=0;j+i<=MN;j++)
	{
	    if(dp[j]>0) Max(dp[j+i],dp[j]-1);
	}
    }
    for(i=0;i+sum<=W;i++)
    {
	if(dp[i]>=0) ans=max(ans,i+sum);
    }
    cout<<ans;
}
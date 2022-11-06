#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i;
ll a[150002],b[150002],ans;
ll eu(ll p,ll q)
{
	if(q==0)return p;
	return eu(q,p%q);
}
int main()
{
	scanf("%d",&n);
	scanf("%lld%lld",&a[1],&b[1]);
	ans=a[1]*b[1];
	for(i=2;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		ans=eu(ans,a[i]*b[i]);
		if(ans==1)
		{
			puts("-1");
			return 0;
		}
	}
	for(i=2;i<=min(1e8,sqrt(ans));i++)
	{
		if(ans%i==0)
		{
			printf("%d",i);
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ans%a[i]==0)
		{
			printf("%lld",a[i]);
			return 0;
		}
		if(ans%b[i]==0)
		{
			printf("%lld",b[i]);
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}
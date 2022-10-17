#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define LG 18
#define N 200100
#define M 1001000
using namespace std;

ll n,m,num[N],sum,ans,mx,pos,cnt[N],gg[N];

int main()
{
	ll i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
		mx=max(mx,num[i]);
		cnt[i]=m;
	}
	sort(num+1,num+n+1),pos=n;
	ans=sum*m;
	for(i=1;i<=m;i++) scanf("%lld",&gg[i]);
	sort(gg+1,gg+m+1);
	for(i=m;i>=1;i--)
	{
		ll t=gg[i];
		if(t<mx)
		{
			puts("-1");
			return 0;
		}
		if(t==num[pos]&&cnt[pos])
		{
			cnt[pos]--;
			continue;
		}
		for(;pos&&(cnt[pos]<=1);pos--);
		if(!pos)
		{
			puts("-1");
			return 0;
		}
		if(t>num[pos])
		{
			ans+=t-num[pos];
			cnt[pos]--;
		}
	}
	cout<<ans;
}
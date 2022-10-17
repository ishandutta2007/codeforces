#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7,P=1e9+7;

typedef long long ll;

int T;

int n;
ll a[N],cnt[61][2],c[61][61][2][2];

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<=60;i++)
			for(int j=0;j<2;j++)
				cnt[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			ll x=a[i];
			for(int t=60;t>=0;t--)
				cnt[t][(x>>t)&1]++;
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ll s1=0,s2=0;
			for(int j=0;j<=60;j++)
			{
				for(int t=0;t<2;t++)
					s1=(s1+(1ll<<j)%P*cnt[j][t]%P*(t&((a[i]>>j)&1))%P)%P,s2=(s2+(1ll<<j)%P*cnt[j][t]%P*(t|((a[i]>>j)&1))%P)%P;
			}
			ans=(ans+s1*s2%P)%P;
		}
		printf("%lld\n",ans);
	}
}
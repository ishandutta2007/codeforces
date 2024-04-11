#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

typedef long long ll;

ll fac[N],inv[N];

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

void pre(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%P;
	inv[n]=qpow(fac[n],P-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
}

ll C(ll n,ll m)
{
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

int a[N];

int main()
{
	pre(200000);
	int T,n,m,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int p=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			p=upper_bound(a+1,a+n+1,a[i]+k)-a;
			if(p-i>=m)
				(ans=(ans+C(p-i-1,m-1)))%=P;

		}
		printf("%d\n",ans);
	}
}
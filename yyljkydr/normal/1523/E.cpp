#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=1e9+7;

typedef long long ll;

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

int T;

int n,k;

ll fac[N],inv[N],f[N];

ll C(ll n,ll m)
{
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

int main()
{
	fac[0]=1;
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%P;
	inv[N-1]=qpow(fac[N-1],P-2);
	for(int i=N-2;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		f[n+1]=0;
		f[0]=1;
		for(int i=1;i<=n;i++)
			f[i]=C(n-i-1ll*(k-1)*(i-1)+i+1-1,i+1-1)*qpow(C(n,i),P-2)%P;
		ll ans=0;
		for(int i=0;i<=n;i++)
			ans=(ans+(f[i]-f[i+1])*(i+1)%P+P)%P;
		printf("%lld\n",ans);
	}
}
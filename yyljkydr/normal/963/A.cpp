#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7,P=1e9+9;

ll n,a,b,k;

ll w[N];

char s[N];

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
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	scanf("%s",s);
	for(int i=0;i<k;i++)
		w[i]=(s[i]=='+')?1:P-1;
	if(n<k)
	{
		ll now=qpow(a,n);
		ll det=b*qpow(a,P-2)%P;
		ll ans=0;
		for(int i=0;i<=n;i++)
			ans=(ans+now*w[i]%P)%P,now=now*det%P;
		printf("%lld",ans);
		return 0;
	}
	ll now=qpow(a,n);
	ll det=b*qpow(a,P-2)%P;
	ll ans=0;
	for(int i=0;i<k;i++)
		ans=(ans+now*w[i]%P)%P,now=now*det%P;
	ll bd=qpow(det,k);
	ll tms=(n+1)/k;
	ll fans=0;
	if(bd!=1)
		fans=ans*((qpow(bd,tms)-1+P)%P*(qpow((bd-1+P)%P,P-2))%P)%P;
	else
		fans=ans*tms%P;
	ll re=(n+1)%k;
	now=qpow(b,n);
	det=a*qpow(b,P-2)%P;
	for(int i=0;i<re;i++) 
		fans=(fans+now*w[(n-i)%k]%P)%P,now=now*det%P;
	printf("%lld",fans);
}
/*
12 1000000000 1000000000 11
+++++++++++
*/
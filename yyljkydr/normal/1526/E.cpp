#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=998244353;

typedef long long ll;

int n,k;

int rk[N],sa[N];

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

ll C(ll n,ll m)
{
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

int main()
{
	scanf("%d%d",&n,&k);
	int l=max(n,k);
	fac[0]=1;
	for(int i=1;i<=l;i++)
		fac[i]=fac[i-1]*i%P;
	inv[l]=qpow(fac[l],P-2);
	for(int i=l-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
	for(int i=1;i<=n;i++)
		scanf("%d",&sa[i]),rk[sa[i]]=i;
	int t=0;
	for(int i=1;i<n;i++)
		if(rk[sa[i]+1]>rk[sa[i+1]+1])
			t++;
	// printf("%d\n",t);
	//at least t 
	// k-=t+1;
	// if(k<0)
	// {
	// 	puts("0");
	// 	return 0;
	// }
	//n - 1 - t positions, each can be 0 or 1, sum not exceed k
	ll ans=0;
	for(int i=0;i<=k-(t+1);i++)
		ans=(ans+C(n-1-t,i)*C(k,i+t+1)%P)%P;
	printf("%lld\n",ans);
}
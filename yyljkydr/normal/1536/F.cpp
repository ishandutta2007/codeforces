#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7,P=1e9+7;

int T,n;

int fac[N],inv[N];

int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int C(int n,int m)
{
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

signed main()
{
	scanf("%lld",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%P;
	inv[n]=qpow(fac[n],P-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
	int ans=0;
	for(int x=1;x<=n/2;x++)
	{
		ans=(ans+2*(C(2*x,n-2*x)%P+C(2*x-1,n-2-(2*x-1))%P)*fac[x*2]%P)%P;
	}
	printf("%lld\n",ans);
}
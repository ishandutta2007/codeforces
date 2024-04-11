#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7,P=1e9+7;

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

int n,a[N],fac[N],inv[N];

int src,snk;

map<int,int>cnt;

int C(int n,int m)
{
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
	int s=0;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),s+=a[i],cnt[a[i]]++;
	if(s%n)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(a[i]*n<s)
			snk++;
		else if(a[i]*n>s)
			src++;
	int ans=1;
	if(snk<=1||src<=1)
	{
		ans=fac[n];
		for(auto [x,y]:cnt)
			ans=ans*inv[y]%P;
		printf("%lld\n",ans);
		return 0;
	}
	ans=fac[snk]*fac[src]%P*fac[n-snk-src]%P;
	for(auto [x,y]:cnt)
		ans=ans*inv[y]%P;
	int eq=n-snk-src;
	ans=ans*C(eq+snk+src,eq)%P;
	ans=ans*2%P;
	printf("%lld\n",ans);
}
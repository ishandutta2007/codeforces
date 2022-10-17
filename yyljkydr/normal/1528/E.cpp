#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7,P=998244353,iv2=(P+1)/2,iv3=(P+1)/3;

int f[N],g[N],h[N];

int n;

int C(int n,int m)
{
	if(m==2)
		return n*(n-1)%P*iv2%P;
	else
		return n*(n-1)%P*(n-2)%P*iv2%P*iv3%P;
}

int calc(int n)
{
	if(n==0)
		return 0;
	return (C(f[n-1],2)+f[n-1]+C(f[n-1],3)+f[n-1]+f[n-1]*(f[n-1]-1))%P;
}

signed main()
{
	scanf("%lld",&n);
	f[0]=h[0]=g[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=(1+f[i-1]+f[i-1]*(f[i-1]-1)%P*iv2%P+f[i-1])%P;
		g[i]=(f[i]-f[i-1]+P)%P;
		h[i]=(g[i]-g[i-1]+P)%P;
	}
	int ans=0;
	ans=2*(calc(n)-calc(n-1)+P)%P;
	for(int i=0;i<n;i++)
		ans=(ans+h[i]*g[n-i-1])%P;
	printf("%lld\n",ans);
}
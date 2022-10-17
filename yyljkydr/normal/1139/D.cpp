#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7,P=1e9+7;

int n,mu[N],p[N],ptot,vis[N];

void pre(int n)
{
	mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
			mu[i]=-1,p[++ptot]=i;
		for(int j=1;j<=ptot&&i*p[j]<=n;j++)
		{
			mu[i*p[j]]=-mu[i];
			vis[i*p[j]]=1;
			if(i%p[j]==0)
			{
				mu[i*p[j]]=0;
				break;
			}
		}
	}
}

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

signed main()
{
	scanf("%lld",&n);
	pre(n);
	int ans=0;
	for(int i=2;i<=n;i++)
		ans=(ans+mu[i]*(n*qpow(n-n/i,P-2)%P-1))%P;
	printf("%lld\n",(P-ans+1)%P);
}
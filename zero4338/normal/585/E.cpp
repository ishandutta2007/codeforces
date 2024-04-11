#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e5+5;
const int maxm=1e7+5;
const int mod=1e9+7;
int n,mx;
int ans;
int sum[maxn],fac[maxn],inv[maxn];
void prework()
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
namespace Euler_Sieve
{
	int mu[maxm],p[maxm],cnt;bool vis[maxm];
	void getmu()
	{
		mu[1]=1;
		for(int i=2;i<=mx;i++)
		{
			if(!vis[i])mu[i]=-1,p[++cnt]=i;
			for(int j=1;j<=cnt&&p[j]*i<=mx;j++)
			{
				vis[i*p[j]]=1;
				if(i%p[j]==0)continue;
				mu[i*p[j]]=-mu[i];
			}
		}
	}
}
namespace Dirichlet
{
	int num[maxm];
	void calc()
	{
		for(int i=1;i<=Euler_Sieve::cnt;i++)
		{
			int &now=Euler_Sieve::p[i];
			for(int j=mx/now;j>=1;j--)num[j]+=num[j*now];
		}
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read();mx=max(a,mx);
		Dirichlet::num[a]++;
	}
	Euler_Sieve::getmu();
	Dirichlet::calc();
	prework();
	for(int i=1;i<=mx;i++)
	{
		if(!Euler_Sieve::mu[i])continue;
		for(int j=1;j<=Dirichlet::num[i];j++)
		{
			if(Euler_Sieve::mu[i]==1)sum[j]=(sum[j]+C(Dirichlet::num[i],j))%mod;
			else sum[j]=(sum[j]-C(Dirichlet::num[i],j)+mod)%mod;
		}
	}
	for(int i=2;i<=n;i++)ans=((ll)ans+(ll)i*sum[i]%mod-(ll)(n-i+1)*sum[i-1]%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}
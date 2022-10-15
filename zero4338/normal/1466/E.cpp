#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll read()
{
	ll ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=5e5+5;
const int mod=1e9+7;
const int maxl=61;
int T;
int n;
int ans;
int cnt[maxl];
ll x[maxn];
int pow2[maxl];
int main()
{
	pow2[0]=1;
	for(int i=1;i<maxl;i++)pow2[i]=pow2[i-1]*2%mod;
	T=read();
	while(T--)
	{
		memset(cnt,0,sizeof cnt);
		n=read();
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
			for(int j=0;j<maxl;j++)if((x[i]>>j)&1)cnt[j]++;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int sa=0,so=0;
			for(int j=0;j<maxl;j++)
			{
				if((x[i]>>j)&1)
				{
					so=(so+(ll)n*pow2[j]%mod)%mod;
					sa=(sa+(ll)cnt[j]*pow2[j]%mod)%mod;
				}
				else so=(so+(ll)cnt[j]*pow2[j]%mod)%mod;
			}
			ans=(ans+(ll)sa*so%mod)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
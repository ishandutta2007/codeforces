#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define int long long
#define ll long long
#define ull unsigned long long
using namespace std;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
const int maxn=5e5+5;
int a[maxn],n;
int gcd,lcm,cnt,maxbase,maxv;
bool ok[maxn];
inline void prime()
{
	for(int i=2;i<=maxv;++i)
	{
		if(ok[i])
		{
			for(int j=i;i*j<=maxv;++j)
			{
				ok[i*j]=false;
			}
		}
	}
}
inline int count(int x,int base)
{
	int cnt=0;
	while(x%base==0&&x!=0)
	{
		cnt++;
		x/=base;
	}
	return cnt;
}
inline int quick_pow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret*=x;
		x*=x,k>>=1;
	}
	return ret;
} 
signed main()
{
	n=getint();
	for(int i=1;i<=n;++i)
	{
		a[i]=getint();
		if(i==1)gcd=a[i];
		else gcd=__gcd(a[i],gcd);
	}
	lcm=gcd;
	for(int i=1;i<=n;++i)a[i]/=gcd,maxv=max(maxv,a[i]);
	for(int i=2;i<=maxv;++i)ok[i]=1;
	prime();
	for(int i=1;i<=maxv;++i)
	{
		if(ok[i])
		{
			cnt=0,maxbase=1000000;
			for(int j=1;j<=n;++j)
			{
				int ti=count(a[j],i);
				if(ti>0)
				{
					maxbase=min(maxbase,ti);
					cnt++;
				}
				if(j-cnt>=2)break;
			}
			if(cnt==n-1)
			{
				for(int j=1;j<=maxbase;++j)lcm*=i;
			}
		}
	}
	printf("%lld\n",lcm);
	return 0;
}
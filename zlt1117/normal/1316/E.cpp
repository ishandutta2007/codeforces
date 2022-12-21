#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
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
inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}
const int maxn=1e5+5;
int n,p,k;
ll dp[2][(1<<7)+1];///iis 
struct node
{
	int a,w[7];
	inline bool operator<(const node &b)const
	{
		return a>b.a;
	}
}s[maxn];
int cnt[(1<<7)+1];
inline int count(int x)
{
	int ret=0;
	while(x)
	{
		ret+=x&1;
		x>>=1;
	}
	return ret;
}
int main()
{
	n=getint(),p=getint(),k=getint();
	for(int i=1;i<=n;++i)s[i].a=getint();
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<p;++j)s[i].w[j]=getint();
	}
	sort(s+1,s+n+1);
	for(int i=0;i<(1<<p);++i)cnt[i]=count(i);
	int now=0,last=0;
	memset(dp,0xcf,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		now=now^1,last=now^1;
		memset(dp[now],0xcf,sizeof(dp[now]));
		for(int j=0;j<(1<<p);++j)
		{
			for(int t=0;t<p;++t)
			{
				if((j>>t)&1)
				{
					dp[now][j]=max(dp[now][j],dp[last][j^(1<<t)]+s[i].w[t]);
				}
			}
			dp[now][j]=max(dp[now][j],dp[last][j]);
			if(i-cnt[j]>k)continue;
			else dp[now][j]=max(dp[now][j],dp[last][j]+s[i].a);
		}
	}
	printf("%lld\n",dp[now][(1<<p)-1]);
	return 0;
}
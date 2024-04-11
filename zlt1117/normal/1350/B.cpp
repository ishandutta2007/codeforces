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
const int maxn=1e5+5;
int T;
int n,s[maxn],dp[maxn];
inline int max(int a,int b){return a<b?b:a;}
int main()
{
	T=getint();
	while(T--)
	{
		int ans=0;
		n=getint();
		for(int i=1;i<=n;++i)s[i]=getint(),dp[i]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=2;i*j<=n;++j)
			{
				if(s[i*j]>s[i])dp[i*j]=max(dp[i*j],dp[i]+1);
			}
			ans=max(dp[i],ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
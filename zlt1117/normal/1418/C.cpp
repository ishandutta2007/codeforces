#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int T,n,a[maxn];
int dp[maxn][2],now,last;
int main()
{
	T=getint();
	while(T--)
	{
		n=getint();
		FOR(i,1,n)a[i]=getint();
		FOR(i,1,n+2)dp[i][0]=dp[i][1]=0x3f3f3f3f;
		dp[0][0]=0;///0 is me; 1 is my friend
		dp[0][1]=0x3f3f3f3f;
		FOR(i,0,n)
		{
			dp[i+2][1]=min(dp[i+2][1],dp[i][0]+a[i+1]+a[i+2]);
			dp[i+1][1]=min(dp[i+1][1],dp[i][0]+a[i+1]);
			dp[i+2][0]=min(dp[i+2][0],dp[i][1]);
			dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
	}
	return 0;
}
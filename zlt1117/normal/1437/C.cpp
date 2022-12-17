//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=405;
int T,n,t[maxn];
int dp[maxn][maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)t[i]=gi();
	sort(t+1,t+n+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	int ans=1e9;
	FOR(i,1,n)
	{
		FOR(j,0,2*n)
		{
			FOR(k,j+1,2*n)
			{
				dp[i][k]=min(dp[i][k],dp[i-1][j]+abs(k-t[i]));
			}
			if(i==n)ans=min(ans,dp[n][j]);
		}
	}
	printf("%d\n",ans);
}
inline void solve()
{

}
int main()
{
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}///
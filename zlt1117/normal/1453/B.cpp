//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
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
const int maxn=2e5+5;
int T,n,a[maxn];
ll dp[maxn][2];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	FOR(i,2,n)dp[i][0]=dp[i][1]=1e18;
	dp[2][1]=0;
	FOR(i,2,n)
	{
		dp[i][0]=dp[i-1][0]+abs(a[i]-a[i-1]);
		dp[i][1]=min(dp[i][1],dp[i-1][1]+abs(a[i]-a[i-1]));
		dp[i+1][1]=dp[i-1][0]+abs(a[i+1]-a[i-1]);
	}
	printf("%lld\n",min(min(dp[n][0],dp[n-1][0]),dp[n][1]));
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
}
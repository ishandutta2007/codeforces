#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
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
const int maxn=1e5+5,inf=1e9;
ll typ,x,y;
ll n,m;
ll dp[maxn];
inline void init()
{

}
inline void input()
{
	scanf("%lld%lld",&n,&m);
	FOR(i,1,m)dp[i]=inf;
}
int times[maxn];
inline void solve()
{
	FOR(i,1,n)
	{
		scanf("%lld%lld%lld",&typ,&x,&y);
		FOR(j,0,m)times[j]=0;
		FOR(j,0,m)
		{
			if(dp[j]==inf)continue;
			if(typ==1)
			{
				double now1=(double)x/100000.0;
				ll now=ceil(now1-1e-9);
				if(j+now<=m&&dp[j+now]==inf&&times[j]+1<=y)dp[j+now]=i,times[j+now]=times[j]+1;
			}
			else
			{
				ll now=ceil((double)j*x/100000.0-1e-9);
				if(now<=m&&dp[now]==inf&&times[j]+1<=y)dp[now]=i,times[now]=times[j]+1;
			}
		}
	}
	FOR(i,1,m)printf("%lld ",dp[i]==inf?-1:dp[i]);
	printf("\n");
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
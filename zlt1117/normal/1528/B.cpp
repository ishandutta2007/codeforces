#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e6+5,mod=998244353;
int n,dp[maxn];
bool vis[maxn];
vector<int>p;
int g[maxn],gcnt[maxn];
inline void init()
{
	vis[0]=vis[1]=1;
	FOR(i,2,maxn-1)
	{
		if(!vis[i])
		{
			p.pb(i);
			g[i]=2,gcnt[i]=2;
		}
		for(int x:p)
		{
			if(1ll*x*i>=maxn)break;
			if(i%x)vis[i*x]=1,gcnt[i*x]=2,g[i*x]=2*g[i];
			else
			{
				vis[i*x]=1;
				gcnt[i*x]=gcnt[i]+1;
				g[i*x]=g[i]/gcnt[i]*gcnt[i*x];
			}
		}
	}
}
inline void input()
{
	n=gi();dp[1]=1;
}
inline void solve()
{
	int s=1;
	FOR(i,2,n)
	{
		dp[i]=(s+g[i])%mod;
		s=(s+dp[i])%mod;
	}
	printf("%d\n",dp[n]);
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
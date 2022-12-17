#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int> 
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=5005;
int n,tag[maxn];
ll dp[maxn],s[maxn]; 
inline void init()
{
	
}
inline void input()
{
	n=gi();
	FOR(i,1,n)tag[i]=gi();
	FOR(i,1,n)s[i]=gi();
	FOR(i,1,n)dp[i]=0;
}
inline void solve()
{
	FOR(b,1,n)for(int a=b-1;a>=1;--a)
	{
		ll xx=dp[a],yy=dp[b];
		if(tag[a]==tag[b])continue;
		dp[a]=max(dp[a],yy+abs(s[a]-s[b]));
		dp[b]=max(dp[b],xx+abs(s[a]-s[b]));
	}
	ll ans=0;
	FOR(i,1,n)ans=max(ans,dp[i]);
	printf("%lld\n",ans);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
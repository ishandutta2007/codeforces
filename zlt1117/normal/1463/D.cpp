#pragma GCC optimize(4)
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
const int maxn=4e5+5;
int n,a[maxn],pre[maxn],suf[maxn];
bool vis[maxn];
int cnt[maxn],ans;
inline void init()
{
	FOR(i,0,2*n+2)a[i]=pre[i]=suf[i]=cnt[i]=0,vis[i]=false;
}
inline void input()
{
	n=gi();ans=0;
	FOR(i,1,n)a[i]=gi(),vis[a[i]]=1;
}
inline void solve()
{
	FOR(i,1,2*n)pre[i]=pre[i-1]+(!vis[i]);
	for(int i=2*n;i>=0;--i)suf[i]=suf[i+1]+(!vis[i]);
	pre[2*n+1]=pre[2*n];
	int now=1e9;
	a[n+1]=2*n+1;
	FOR(i,0,n)
	{
		if(suf[a[i]]<=now)now=suf[a[i]];
		if(i!=0)now--;
		if(now>=0)cnt[i]++;
	}
	now=1e9;
	for(int i=n+1;i>=1;--i)
	{
		if(pre[a[i]]<=now)now=pre[a[i]];
		if(i!=n+1)now--;
		if(now>=0)cnt[i-1]++;
	}
	FOR(i,0,n)ans+=(cnt[i]==2);
	printf("%d\n",ans);
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
}///
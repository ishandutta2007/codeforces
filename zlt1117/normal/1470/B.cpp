//#pragma GCC optimize(4)
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
const int maxn=3e5+5;
int n;
int a[maxn];
inline void calc(int &x)
{
	int ret=x,xx=x;x=1;
	for(int i=2;1LL*i*i<=xx;++i)
	{
		if(ret%i==0)
		{
			int cnt=0;
			while(ret%i==0)cnt++,ret/=i;
			if(cnt&1)x*=i;
		}
	}
	x*=ret;
}
map<int,int>mp;
inline void init()
{
	mp.clear();
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),calc(a[i]),mp[a[i]]++;
}
inline void solve()
{
	int counter=mp[1];
	int q=gi();
	int ans=0;
	for(auto x:mp)ans=max(ans,x.second);
	for(auto x:mp)if(x.second%2==0&&x.first!=1)counter+=x.second;
	counter=max(counter,ans);
	while(q--)
	{
		ll x;
		scanf("%lld",&x);
		if(x==0)printf("%d\n",ans);
		else printf("%d\n",counter);
	}
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
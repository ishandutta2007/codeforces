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
#define int ll
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
const int maxn=5e5+5,mod=1e9+7;
ll a[maxn];
ll cnt[62],n;
inline void init()
{
	memset(cnt,0,sizeof(cnt));
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)
	{
		FOR(j,0,60)
		{
			if(a[i]>>j&1)cnt[j]++;
		}
	}
}
inline void solve()
{
	ll ans=0;
	FOR(i,1,n)
	{
		ll ans1=0,ans2=0;
		FOR(j,0,60)
		{
			if(a[i]>>j&1)
			{
				ans1+=cnt[j]*((1LL<<j)%mod)%mod;
				ans2+=n*((1LL<<j)%mod)%mod;
				ans2%=mod;
				ans1%=mod;
			}
			else 
			{
				ans2+=cnt[j]*((1LL<<j)%mod)%mod;
				ans2%=mod;
			}
		}
		ans1%=mod,ans2%=mod;
		ans+=ans1*ans2%mod;
		ans%=mod;
	}
	printf("%lld\n",ans);
}
signed main()
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
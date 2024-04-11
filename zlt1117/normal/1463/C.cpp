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
const int maxn=1e5+5;
int n;
ll t[maxn],x[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)t[i]=gi(),x[i]=gi();
}
inline void solve()
{
	int now=0,tim=0;
	int ed=1,ans=0;
	t[n+1]=2e18;
	while(ed<=n)
	{
		int temp=t[ed],temp1=x[ed];
		tim=t[ed]+abs(now-x[ed]);
		if(tim>=t[ed]&&tim<=t[ed+1])ans++;
		ed++;
		while(ed<=n&&t[ed]<tim)
		{
			if(now<=temp1)
			{
				if(x[ed]>=now&&x[ed]<=temp1)
				{
					int now1=abs(now-x[ed]);
					if(now1+temp>=t[ed]&&now1+temp<=t[ed+1])ans++;
				}
			}
			else
			{
				if(x[ed]>=temp1&&x[ed]<=now)
				{
					int now1=abs(now-x[ed]);
					if(now1+temp>=t[ed]&&now1+temp<=t[ed+1])ans++;
				}
			}
			ed++;
		}
		now=temp1;
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
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
#define int ll
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
int n,m,x,y;
int fa[maxn];
vector<int>vec;
int cnt;
bool vis[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)fa[i]=i;
}
inline int get(int x)
{
	if(x==fa[x])return x;
	else return fa[x]=get(fa[x]);
}
inline void solve()
{
	FOR(i,1,n)
	{
		int k=gi();
		if(k==1)
		{
			x=gi();
			x=get(x);
			if(x==0)continue;
			fa[x]=0;
			vec.pb(i);
			vis[x]=1;
		}
		else
		{
			x=gi(),y=gi();
			x=get(x),y=get(y);
			if(x==0&&y==0)continue;
			if(x==0)swap(x,y);
			if(y==0)
			{
				vec.pb(i);
				vis[x]=1;
				fa[x]=0;
			}
			else
			{
				if(x==y)continue;
				if(x>y)swap(x,y);
				vec.pb(i);
				vis[x]=1;
				fa[x]=y;
			}
		}
	}
	FOR(i,1,m)cnt+=vis[i];
	ll ans=1;
	FOR(i,1,cnt)ans=ans*2%mod;
	printf("%lld %lld\n",ans,sz(vec));
	for(auto x:vec)printf("%lld ",x);
	printf("\n");
}
signed main()
{
//	int T=gi();
//	while(T--)
//	{
		init();
		input();
		solve();

//	}
	return 0;
}
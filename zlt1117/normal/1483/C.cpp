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
const int maxn=3e5+5;
const ll inf=1e18;
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=2e6+5;
	ll maxv[maxn],tag[maxn],now[maxn];
	inline void pushup(int u)
	{
		now[u]=max(now[ls],now[rs]);
		maxv[u]=max(maxv[ls],maxv[rs]);
	}
	inline void pushr(int u,ll v)
	{
		tag[u]=v;
		now[u]=maxv[u]+v;
	}
	inline void pushdown(int u)
	{
		if(tag[u]!=-inf)
		{
			pushr(ls,tag[u]);
			pushr(rs,tag[u]);
			tag[u]=-inf;
		}
	}
	inline void build(int u,int l,int r)
	{
		tag[u]=-inf;
		if(l==r)return now[u]=maxv[u]=-inf,void();
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(u);
	}
	inline void update(int u,int l,int r,int x,ll v)
	{
		if(l==r)return now[u]=maxv[u]=v,void();
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline void update2(int u,int l,int r,int x,int y,ll v)
	{
		if(x<=l&&y>=r)return pushr(u,v);
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)update2(ls,l,mid,x,y,v);
		if(y>mid)update2(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	#undef ls 
	#undef rs
}tree;
int h[maxn],a[maxn],pos[maxn],st[maxn][20],Log[maxn],n;
ll dp[maxn];
inline void init()
{
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
}
inline int compare(int x,int y){return h[x]<h[y]?x:y;}
inline int query(int x,int y)
{
	if(x>y)swap(x,y);
	int l=Log[y-x+1];
	return compare(st[x][l],st[y-(1<<l)+1][l]);
}
inline void input()
{
	n=gi();
	FOR(i,1,n)h[i]=gi();
	FOR(i,1,n)a[i]=gi(),st[i][0]=i;
	FOR(i,1,Log[n])for(int j=1;j<=n-(1<<i)+1;++j)st[j][i]=compare(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	FOR(i,1,n)
	{
		pos[i]=0;
		int l=0,r=i-1,now=-1;
		if(h[query(1,i)]>=h[i]){pos[i]=0;continue;}
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(h[query(mid,r)]<h[i])now=mid,l=mid+1;
			else r=mid-1;
		}
		pos[i]=now;
	}
}
inline void solve()
{
	tree.build(1,0,n);
	tree.update(1,0,n,0,0);
	FOR(i,1,n)
	{
		int l=pos[i],r=i-1;
		if(l<=r)tree.update2(1,0,n,l,r,a[i]);
		dp[i]=tree.now[1];
		tree.update(1,0,n,i,dp[i]);
	}
	printf("%lld\n",dp[n]);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
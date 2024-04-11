//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=2e5+5;
int val[maxn],n,m;
struct node
{
	int l,r,lp,rp;
	ll ans;
};
inline node merge(node a,node b)
{
	node c={};c.l=a.l,c.r=b.r;
	if(a.lp==a.r)
	{
		if(val[a.r]<=val[a.r+1])c.lp=b.lp;
		else c.lp=a.lp;
	}
	else c.lp=a.lp;
	if(b.rp==b.l)
	{
		if(val[b.l-1]<=val[b.l])c.rp=a.rp;
		else c.rp=b.rp;
	}
	else c.rp=b.rp;
	c.ans=(a.ans+b.ans+(val[a.r]<=val[b.l]?1ll*(a.r-a.rp+1)*(b.lp-b.l+1):0));
	return c;
}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=8e5+5;
	node a[maxn];
	inline void pushup(int u)
	{
		a[u]=merge(a[ls],a[rs]);
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return a[u]={l,r,l,r,1},void();
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(u);
	}
	inline void update(int u,int l,int r,int x)
	{
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x);
		else update(rs,mid+1,r,x);
		pushup(u);
	}
	inline node query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return a[u];
		int mid=(l+r)>>1;
		if(y<=mid)return query(ls,l,mid,x,y);
		if(x>mid)return query(rs,mid+1,r,x,y);
		return merge(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
	}
}tree;
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)val[i]=gi();
}
inline void solve()
{
	tree.build(1,1,n);
	FOR(i,1,m)
	{
		int t=gi();
		if(t==1)
		{
			int x=gi(),y=gi();
			val[x]=y;
			tree.update(1,1,n,x);
		}
		else
		{
			int l=gi(),r=gi();
			printf("%lld\n",tree.query(1,1,n,l,r).ans);
		}
	}
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
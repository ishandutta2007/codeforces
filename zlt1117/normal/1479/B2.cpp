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
const int maxn=1e5+5;
int a[maxn],n,las[maxn],dp[maxn],pos[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
struct segmentree
{
	static const int maxn=4e5+5;
	#define ls u<<1
	#define rs u<<1|1
	int tag[maxn],minv[maxn];
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			minv[ls]+=tag[u];
			minv[rs]+=tag[u];
			tag[ls]+=tag[u],tag[rs]+=tag[u];
			tag[u]=0;
		}
	}
	inline void pushup(int u)
	{
		minv[u]=min(minv[ls],minv[rs]);
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)return tag[u]+=v,minv[u]+=v,void();
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return minv[u];
		int mid=(l+r)>>1;
		pushdown(u);
		int ret=1e9;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret=min(ret,query(rs,mid+1,r,x,y));
		return ret;
	}
}tree;
inline void solve()
{
	FOR(i,1,n)
	{
		if(las[a[i]])pos[i]=las[a[i]];
		las[a[i]]=i;
	}
	tree.update(1,0,n,0,0,1);
	tree.update(1,0,n,1,n,100000);
	FOR(i,2,n)
	{
		///dp[i-1]
		int x=tree.query(1,0,n,0,i-2)+1;
		if(pos[i])x=min(x,tree.query(1,0,n,pos[i],pos[i]));
		tree.update(1,0,n,i-1,i-1,x-100000);
		if(a[i]!=a[i-1])tree.update(1,0,n,0,i-2,1);
	}
	printf("%d\n",tree.query(1,0,n,0,n-1));
}
int main()
{
	int T=1;
//	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
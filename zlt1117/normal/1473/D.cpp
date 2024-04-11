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
const int maxn=2e5+5;
int n,q;
char s[maxn];
int pre[maxn];
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=8e5+5;
	int maxv[maxn],minv[maxn];
	inline void clear()
	{
		FOR(i,1,4*n)maxv[i]=minv[i]=0;
	}
	inline void pushup(int u)
	{
		maxv[u]=max(maxv[ls],maxv[rs]);
		minv[u]=min(minv[ls],minv[rs]);
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return maxv[u]=minv[u]=pre[l],void();
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(u);
	}
	inline int query_max(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return maxv[u];
		int mid=(l+r)>>1;
		int val=-1e9;
		if(x<=mid)val=query_max(ls,l,mid,x,y);
		if(y>mid)val=max(val,query_max(rs,mid+1,r,x,y));
		return val;
	}
	inline int query_min(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return minv[u];
		int mid=(l+r)>>1;
		int val=1e9;
		if(x<=mid)val=query_min(ls,l,mid,x,y);
		if(y>mid)val=min(val,query_min(rs,mid+1,r,x,y));
		return val;
	}
}tree;
inline void init()
{
	tree.clear();
	FOR(i,1,n)pre[i]=s[i]=0;
}
inline void input()
{
	n=gi(),q=gi();
	scanf("%s",s+1);
	FOR(i,1,n)
	{
		if(s[i]=='+')pre[i]=pre[i-1]+1;
		else pre[i]=pre[i-1]-1;
	}
	tree.build(1,1,n);
}
inline void solve()
{
	while(q--)
	{
		int l=gi(),r=gi(),minv=0,maxv=0;
		if(l>1)minv=min(minv,tree.query_min(1,1,n,1,l-1)),maxv=max(maxv,tree.query_max(1,1,n,1,l-1));
		if(r<n)minv=min(minv,tree.query_min(1,1,n,r+1,n)-pre[r]+pre[l-1]),maxv=max(maxv,tree.query_max(1,1,n,r+1,n)-pre[r]+pre[l-1]);
		printf("%d\n",maxv-minv+1);
	}
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
/*
2
8 1
-+--+--+
1 1
*/
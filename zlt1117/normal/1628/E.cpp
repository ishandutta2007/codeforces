#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
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
inline void chkmax(int &x,int y){if(x<y)x=y;}
inline void chkmin(int &x,int y){if(x>y)x=y;}
const int maxn=6e5+5;
int fa[maxn][20];
vector<int>e[maxn];
int w[maxn],n,m,Log[maxn],dep[maxn];
inline int LCA(int u,int v)
{
	if(u==0||v==0)return max(u,v);
	if(dep[u]<dep[v])swap(u,v);
	for(int i=Log[dep[u]];i>=0;--i)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=Log[dep[u]];i>=0;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=1.2e6+5;
	int lca[maxn],tag[maxn],sta[maxn];
	inline void pushup(int u)
	{
		lca[u]=max(lca[ls],lca[rs]);
		if(lca[ls]&&lca[rs])lca[u]=LCA(lca[ls],lca[rs]);
	}
	inline void pushdown(int u)
	{
		if(tag[u])
		{
			tag[ls]=tag[rs]=tag[u];
			if(tag[u]==1)lca[ls]=sta[ls],lca[rs]=sta[rs];
			else lca[ls]=lca[rs]=0;
			tag[u]=0;
		}
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return sta[u]=l,void();
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		sta[u]=LCA(sta[ls],sta[rs]);
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)
		{
			if(v==1)lca[u]=sta[u];
			else lca[u]=0;
			tag[u]=v;
			return ;
		}
		int mid=(l+r)>>1;
		pushdown(u);
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline int query(){return lca[1];}
}tree;
struct DSU
{
	int fa[maxn];
	inline int get(int x)
	{
		if(x==fa[x])return x;
		return fa[x]=get(fa[x]);
	}
	inline void init(int n)
	{
		FOR(i,1,n)fa[i]=i;
	}
	inline bool test(int u,int v){return get(u)==get(v);}
	inline void merge(int u,int v){fa[get(u)]=get(v);}
}dsu;
struct edg{int u,v,w;inline bool operator < (const edg &b)const{return w<b.w;};}a[maxn];
inline void init()
{

}
int N;
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n-1)a[i].u=gi(),a[i].v=gi(),a[i].w=gi();
	sort(a+1,a+n);N=n;
	FOR(i,1,n)w[i]=-1;
	dsu.init(2*n);
	FOR(i,1,N-1)
	{
		int u=dsu.get(a[i].u),v=dsu.get(a[i].v);
		fa[u][0]=++n,fa[v][0]=n;w[n]=a[i].w;
		dsu.fa[u]=n,dsu.fa[v]=n;
	}
	FOR(i,2,n)Log[i]=Log[i>>1]+1;
	for(int i=n;i>=1;--i)
	{
		dep[i]=dep[fa[i][0]]+1;
		FOR(j,1,Log[dep[i]])fa[i][j]=fa[fa[i][j-1]][j-1];
	}
}
inline void solve()
{
	n=N;
	tree.build(1,1,n);
	FOR(i,1,m)
	{
		int typ=gi();
		if(typ==1)
		{
			int l=gi(),r=gi();
			tree.update(1,1,n,l,r,1);
		}
		else if(typ==2)
		{
			int l=gi(),r=gi();
			tree.update(1,1,n,l,r,-1);
		}
		else
		{
			int x=gi(),u=tree.query();
			if(u==0)puts("-1");
			else printf("%d\n",w[LCA(x,u)]);
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
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=5e5+5;
int u[maxn],v[maxn],n,m,k,q;
struct DSU
{
	static const int maxn=1e6+5;
	int fa[maxn],siz[maxn];
	stack<pair<int,int> >stk;
	inline int get(int x){if(x==fa[x])return x;return get(fa[x]);}
	inline void init(){FOR(i,1,n*2)fa[i]=i,siz[i]=1;}
	inline void merge(int x,int y)
	{
		x=get(x),y=get(y);
		if(siz[x]>siz[y])swap(x,y);
		if(x==y)return ;
		fa[x]=y,siz[y]+=siz[x];
		stk.push({x,y});
	}
}dsu[51];
int e[maxn],c[maxn];
int nxt[maxn],temp[maxn];
bool ans[maxn];
struct segmentree
{
	static const int maxn=1e6+5;
	vector<pair<int,pair<int,int>>>now[maxn];
	int val[maxn],col[maxn],ls[maxn],rs[maxn],tot;
	inline void build(int &u,int l,int r)
	{
		u=++tot;
		if(l==r)return val[u]=e[l],col[u]=c[l],void();
		int mid=(l+r)>>1;
		build(ls[u],l,mid),build(rs[u],mid+1,r);
	}
	inline void update(int u,int l,int r,int x,int y,pair<int,pair<int,int>>v)
	{
		if(x<=l&&y>=r)return now[u].pb(v),void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls[u],l,mid,x,y,v);
		if(y>mid)update(rs[u],mid+1,r,x,y,v);
	}
	inline void dfs(int u,int l,int r)
	{
		int size[k+1];memset(size,0,sizeof(size));
		FOR(i,1,k)size[i]=dsu[i].stk.size();
		for(auto x:now[u])
		{
			int c=x.first,u=x.second.first,v=x.second.second;
			dsu[c].merge(u+n,v),dsu[c].merge(u,v+n);
		}
		if(l==r)
		{
			int x=::u[val[u]],y=::v[val[u]],color=col[u];
			if(dsu[color].get(x)==dsu[color].get(y))
			{
				if(c[val[u]]!=0&&l<nxt[l])update(1,1,q,l+1,nxt[l],{c[val[u]],{x,y}});
				ans[l]=0;
			}
			else
			{
				c[val[u]]=col[u];
				if(l<nxt[l])update(1,1,q,l+1,nxt[l],{c[val[u]],{x,y}});
				ans[l]=1;
			}
		}
		else
		{
			int mid=(l+r)>>1;
			dfs(ls[u],l,mid);
			dfs(rs[u],mid+1,r);
		}
		FOR(i,1,k)
		{
			while(sz(dsu[i].stk)>size[i])
			{
				int x=dsu[i].stk.top().first;
				int y=dsu[i].stk.top().second;
				dsu[i].fa[x]=x,dsu[i].siz[y]-=dsu[i].siz[x];
				dsu[i].stk.pop();
			}
		}
	}
}tree;
inline void input()
{
	n=gi(),m=gi(),k=gi(),q=gi();
	FOR(i,1,k)dsu[i].init();
	FOR(i,1,m)u[i]=gi(),v[i]=gi();
	FOR(i,1,q)e[i]=gi(),c[i]=gi();
	FOR(i,1,m)temp[i]=q;
	for(int i=q;i>=1;--i)
	{
		nxt[i]=temp[e[i]];
		temp[e[i]]=i;
	}
}
int root;
inline void solve()
{
	tree.build(root,1,q);
	memset(c,0,sizeof(c));
	tree.dfs(1,1,q);
	FOR(i,1,q)ans[i]?puts("YES"):puts("NO");
}
int main()
{
// 	freopen("graph.in","r",stdin);
// 	freopen("graph.out","w",stdout);
	input();
	solve();
	return 0;
}
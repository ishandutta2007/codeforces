#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define PII pair<int,int>
#define iter set<int>::iterator 
#define gc getchar()//((p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++))
#define pb push_back
#define sz(x) (int)(x.size())
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=2e5+5,inf=1e9;
int n,m,q,w[maxn];
vector<int>e[maxn];
int bel[maxn];
vector<int>temp[maxn];///newedges
int dfn[maxn],low[maxn],nowc,N;
///2times memory
namespace Tarjan
{
	stack<int>stk;
	inline void tarjan(int u)
	{
		stk.push(u);
		dfn[u]=low[u]=++nowc;
		FOR(i,0,sz(e[u])-1)
		{
			int v=e[u][i];
			if(!dfn[v])
			{
				tarjan(v);
				low[u]=min(low[u],low[v]);
				if(low[v]>=dfn[u])
				{
					//cerr<<u<<' '<<v<<endl;
					++n;
					temp[n].pb(u);
					temp[u].pb(n);
					while(!stk.empty())
					{
						int x=stk.top();
						temp[n].pb(x);temp[x].pb(n);
						//if(x==5)cerr<<n<<endl;
						stk.pop();
						if(x==v)break;
					}
				}
			}
			else low[u]=min(low[u],dfn[v]);
		}	
	}
	inline void work()
	{
		FOR(i,1,N)if(!dfn[i])tarjan(i);
	}
}
///HLD
int fa[maxn],son[maxn],tp[maxn],siz[maxn],tot,rk[maxn],dep[maxn];
multiset<int>s[maxn];
///erase(s.find(...))
inline void dfs(int u)
{
	dep[u]=dep[fa[u]]+1;
	if(u<=N)s[fa[u]].insert(w[u]);
	siz[u]=1;
	FOR(i,0,sz(e[u])-1)
	{
		int v=e[u][i];
		if(v==fa[u])continue;
		fa[v]=u,dfs(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
inline void dfs2(int u,int topf)
{
	dfn[u]=++tot,tp[u]=topf;rk[tot]=u;
	if(son[u])dfs2(son[u],topf);
	FOR(i,0,sz(e[u])-1)
	{
		int v=e[u][i];
		if(v==son[u]||v==fa[u])continue;
		dfs2(v,v);
	}
	low[u]=tot;
}
struct segmentree
{
	static const int maxn=8e5+5;
	#define ls u<<1
	#define rs u<<1|1
	int minv[maxn];
	inline void pushup(int u)
	{
		minv[u]=min(minv[ls],minv[rs]);
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return minv[u]=w[rk[l]],void();
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r)return minv[u]=v,void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return minv[u];
		int ret=inf,mid=(l+r)>>1;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret=min(ret,query(rs,mid+1,r,x,y));
		return ret;
	}
	#undef ls
	#undef rs
}tree;
inline int query(int x,int y)
{
	int ret=inf;
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]])swap(x,y);
		ret=min(ret,tree.query(1,1,n,dfn[tp[x]],dfn[x]));
		x=fa[tp[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ret=min(ret,tree.query(1,1,n,dfn[x],dfn[y]));
	if(x>N)ret=min(ret,w[fa[x]]);
	//cerr<<x<<' '<<y<<endl;
	return ret;
}
///HLD
inline void input()
{
	N=n=gi(),m=gi(),q=gi();
	FOR(i,1,n)w[i]=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline void solve()
{
	Tarjan::work();//cerr<<low[5]<<endl;
	//FOR(i,1,N)cerr<<dfn[i]<<' '<<low[i]<<endl;
	FOR(i,1,n)swap(temp[i],e[i]),temp[i].clear();
	memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));
	dfs(1);dfs2(1,1);
	FOR(i,N+1,n)w[i]=*s[i].begin();
	tree.build(1,1,n);

	//FOR(i,1,n)FOR(j,0,sz(e[i])-1)if(e[i][j]>i)cerr<<i<<' '<<e[i][j]<<endl;

	while(q--)
	{
		char ss[2];int x,y;
		scanf("%s",ss);x=gi(),y=gi();
		if(ss[0]=='C')
		{
			tree.update(1,1,n,dfn[x],y);
			s[fa[x]].erase(s[fa[x]].find(w[x]));
			s[fa[x]].insert(w[x]=y);
			w[fa[x]]=*s[fa[x]].begin();
			if(fa[x])tree.update(1,1,n,dfn[fa[x]],w[fa[x]]);
		}
		else
		{
			printf("%d\n",query(x,y));
			//cerr<<1<<endl;
		}
	}
}
int main()
{
//	freopen("tourist.in","r",stdin);
//	freopen("tourist.out","w",stdout);
	input();
	solve();
	return 0;
}
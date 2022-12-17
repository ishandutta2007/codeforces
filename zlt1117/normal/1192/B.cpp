#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define pb push_back
#define rd (rand()<<16^rand())
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline ll gi()
{
	ll x=0,f=1;char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=1e5+5;
const ll inf=1e18;
int n,q,a,b;
ll W;
int u[maxn],v[maxn];
vector<pair<int,ll> >e[maxn];
ll dep[maxn],w[maxn];
struct Matrix
{
	ll a[3][3];
	inline void clear(){memset(a,0xcf,sizeof(a));}
	inline Matrix operator * (const Matrix &b)const
	{
		Matrix c;c.clear();
		FOR(k,0,2)FOR(i,0,2)FOR(j,0,2)c.a[i][j]=max(c.a[i][j],a[i][k]+b.a[k][j]);
		return c;
	}
};
///HLD
int dfn[maxn],tot,son[maxn];
ll f[maxn][2];
int fa[maxn],tp[maxn],bot[maxn],siz[maxn],rk[maxn];
inline void dfs(int u)
{
	dep[u]=dep[fa[u]]+1;
	siz[u]=1;f[u][0]=f[u][1]=0;
	for(auto x:e[u])
	{
		int v=x.first;ll w=x.second;
		if(v==fa[u])continue;
		fa[v]=u,dfs(v),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
		f[u][1]=max(f[u][1],max(f[v][1],f[u][0]+f[v][0]+w));
		f[u][0]=max(f[u][0],f[v][0]+w);
	}
	f[u][1]=max(f[u][1],f[u][0]);
}
Matrix now[maxn];
multiset<ll>s[maxn],s2[maxn]; 
ll val[maxn];
inline void work(int u)
{
	memset(now[u].a,0,sizeof(now[u].a));
	if(!son[u])return now[u].a[0][0]=val[u],void();///special
	now[u].a[0][0]=val[u];
	now[u].a[0][1]=now[u].a[2][0]=now[u].a[2][1]=-inf;
	if(!s[u].empty())now[u].a[0][2]=*(--s[u].end());
	now[u].a[1][0]=now[u].a[0][2],now[u].a[0][2]+=val[u];
	if(!s2[u].empty())now[u].a[1][2]=*(--s2[u].end());
	now[u].a[1][2]=max(now[u].a[1][2],now[u].a[1][0]);
	if(s[u].size()>=2)now[u].a[1][2]=max(now[u].a[1][2],*(--s[u].end())+(*(--(--s[u].end()))));
}
inline void dfs2(int u,int topf)
{
	s[u].clear();
	dfn[u]=++tot,rk[tot]=u;tp[u]=topf;
	if(son[u])dfs2(son[u],topf),bot[u]=bot[son[u]];
	else bot[u]=u;
	///g expect the heavy son
	for(auto x:e[u])
	{
		int v=x.first;ll w=val[v];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
		s[u].insert(f[v][0]+w);s2[u].insert(f[v][1]);
	}
	work(u);
}
///HLD 
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=4e5+5;
	Matrix sum[maxn];
	inline void pushup(int u)
	{
		sum[u]=sum[ls]*sum[rs];
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return sum[u]=now[rk[l]],void();
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	inline void update(int u,int l,int r,int x)
	{
		if(l==r)return sum[u]=now[rk[l]],void();
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x);
		else update(rs,mid+1,r,x);
		pushup(u);
	}
	inline Matrix query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		int mid=(l+r)>>1;
		if(y<=mid)return query(ls,l,mid,x,y);
		if(x>mid)return query(rs,mid+1,r,x,y);
		return query(ls,l,mid,x,y)*query(rs,mid+1,r,x,y);
	}
}tree;
inline void update(int v,ll w)
{
	now[v].a[0][0]+=w,now[v].a[0][2]+=w;
	while(v)
	{
		Matrix temp=tree.query(1,1,n,dfn[tp[v]],dfn[bot[v]]);
		tree.update(1,1,n,dfn[v]);
		if(tp[v]!=1)
		{
			int u=v;
			Matrix temp2=tree.query(1,1,n,dfn[tp[u]],dfn[bot[u]]);
			s[fa[tp[u]]].erase(s[fa[tp[u]]].find(temp.a[0][0]));
			s[fa[tp[u]]].insert(temp2.a[0][0]);
			s2[fa[tp[u]]].erase(s2[fa[tp[u]]].find(temp.a[1][0]));
			s2[fa[tp[u]]].insert(temp2.a[1][0]);
			work(fa[tp[u]]);
		}
		v=fa[tp[v]];
	}
}
inline void init()
{

}
inline void input()
{
	n=gi(),q=gi(),W=gi();
	FOR(i,1,n-1)
	{
		u[i]=gi(),v[i]=gi(),w[i]=gi();
		e[u[i]].pb({v[i],w[i]});e[v[i]].pb({u[i],w[i]});
	}
}
inline void solve()
{
	dfs(1);
	FOR(i,1,n-1)if(dep[u[i]]>dep[v[i]])swap(u[i],v[i]);
	FOR(i,1,n-1)val[v[i]]=w[i];
	dfs2(1,1);
	tree.build(1,1,n);
	ll ans=0;
	FOR(i,1,q)
	{
		int d=gi();ll value=gi();
		d=(d+ans)%(n-1)+1,value=(value+ans)%W;
		update(v[d],value-val[v[d]]);
		val[v[d]]=value;
		ans=tree.query(1,1,n,dfn[1],dfn[bot[1]]).a[1][0];
		printf("%lld\n",ans);
	}
}
int main()
{
//	freopen("diameter.in","r",stdin);
//	freopen("diameter.out","w",stdout);
	init();
	input();
	solve();
	return 0;
}
/*
6 0 10000
5 6 1630
1 2 1630
2 3 853
1 4 760
4 5 1076
*/
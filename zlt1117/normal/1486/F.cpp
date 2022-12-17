#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int>
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=6e5+5;
int dfn[maxn],st[maxn][20],tot,tim,fa[maxn][20],Log[maxn],dep[maxn],fir[maxn],n,m,siz[maxn];
vector<int>e[maxn];
struct Path
{
	int u,v,a,b,lca;
	inline bool operator < (const Path &x)const{return a==x.a?b<x.b:a<x.a;}
}a[maxn];
inline void dfs(int u,int f)
{
	siz[u]=1;
	dfn[u]=++tim;st[++tot][0]=u;fir[u]=tot;
	FOR(i,1,Log[dep[u]])fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u])
	{
		if(v==f)continue;
		fa[v][0]=u,dep[v]=dep[u]+1;
		dfs(v,u);
		st[++tot][0]=u,siz[u]+=siz[v];
	}
}
inline int compare(int x,int y){return dep[x]<dep[y]?x:y;}
inline void prepare()
{
	FOR(i,1,Log[tot])
		FOR(j,1,tot-(1<<i)+1)
			st[j][i]=compare(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
inline int LCA(int x,int y)
{
	x=fir[x],y=fir[y];
	if(x>y)swap(x,y);
	int l=Log[y-x+1]; 
	return compare(st[x][l],st[y-(1<<l)+1][l]);
}
inline int Kth(int x,int k)
{
	for(int i=Log[dep[x]];i>=0;--i)
	{
		if(k>=dep[x]-dep[fa[x][i]])
		{
			k-=dep[x]-dep[fa[x][i]];
			x=fa[x][i];
		}
	}
	return x;
}
struct BIT
{
	int c[maxn];
	inline void update(int x,int v)
	{
		while(x<=n)c[x]+=v,x+=x&-x; 
	}
	inline int query(int x)
	{
		int ret=0;
		while(x)ret+=c[x],x-=x&-x;
		return ret;
	}
}tree;
vector<int>ed[maxn];
int temp[maxn];
ll ans;
inline void init()
{
	FOR(i,2,maxn-1)Log[i]=Log[i>>1]+1;
}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1,0);
	prepare();
}
vector<Path>p[maxn];
int cnt[maxn];
inline void count(int u)
{
	///lca are same
	sort(p[u].begin(),p[u].end());
	vector<Path>temp;int last=-1,cntt=0;
	for(auto x:p[u])
	{
		if(last!=x.a)
		{
			for(auto y:temp)if(y.b!=-1)cnt[y.b]++;
			last=x.a;
			cntt+=sz(temp);
			temp.clear();
		}
		if(x.a==-1)
		{
			ans+=cntt;
			if(x.b!=-1)ans-=cnt[x.b],cnt[x.b]++;
			cntt++;
			continue;
		}
		ans+=cntt;
		if(x.b!=-1)ans-=cnt[x.b];
		if(x.a!=-1)ans-=cnt[x.a];
		temp.pb(x);
	}
	for(auto x:p[u]){if(x.b!=-1)cnt[x.b]=0;if(x.a!=-1)cnt[x.a]=0;}
	///lca are different 
	int now=tree.query(dfn[u]+siz[u]-1)-tree.query(dfn[u]-1);
	for(auto x:p[u])
	{
		ans+=now;
		if(x.a!=-1)ans-=tree.query(dfn[x.a]+siz[x.a]-1)-tree.query(dfn[x.a]-1);
		if(x.b!=-1)ans-=tree.query(dfn[x.b]+siz[x.b]-1)-tree.query(dfn[x.b]-1);
	}
}
inline void dfs2(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)continue;
		dfs2(v,u);
	}
	for(auto x:ed[u])
	{
		tree.update(dfn[x],-1);
	}
	tree.update(dfn[u],temp[u]);
	count(u);
	//cerr<<u<<' '<<ans<<endl;
}
inline void solve()
{
	m=gi();
	FOR(i,1,m)
	{
		a[i].u=gi(),a[i].v=gi();
		if(a[i].u==a[i].v)a[i].a=a[i].b=-1,a[i].lca=a[i].u;
		else
		{
			a[i].lca=LCA(a[i].u,a[i].v);
			if(dfn[a[i].u]>dfn[a[i].v])swap(a[i].u,a[i].v);
			if(a[i].u==a[i].lca)a[i].a=-1,a[i].b=Kth(a[i].v,dep[a[i].v]-dep[a[i].lca]-1),ed[a[i].lca].pb(a[i].v),temp[a[i].v]++;
			else
			{
				a[i].a=Kth(a[i].u,dep[a[i].u]-dep[a[i].lca]-1);
				a[i].b=Kth(a[i].v,dep[a[i].v]-dep[a[i].lca]-1);
				ed[a[i].lca].pb(a[i].u),ed[a[i].lca].pb(a[i].v);
				temp[a[i].u]++,temp[a[i].v]++;
			}
			if(a[i].a>a[i].b)swap(a[i].a,a[i].b),swap(a[i].u,a[i].v);
		}
		p[a[i].lca].pb(a[i]);
	}
	dfs2(1,0);
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}
/*
6
1 2
2 6
6 3
3 4
3 5
4
1 5
2 4 
3 4
4 6
*/
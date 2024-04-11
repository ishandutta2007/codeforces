#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
#define x first
#define y second
#define mp std::make_pair
#define pb push_back
#define N 250005
using std::vector;
using std::priority_queue;
using std::pair;
int n, m, s, dfn[N], id[N], fa[N], pa[N], val[N], semi[N], idom[N], cnt[N], top;
pair<int, int> vl[N];
struct graph{
	#define M 600005
	int head[M], to[M], nxt[M], top;
	inline void add(int a, int b) { nxt[++top]=head[a], to[top]=b, head[a]=top; }
}e, g, rq;
vector<pair<int, int> > to[N];
ll dis[N];
struct node{
	int id;
	ll dis;
	bool operator <(const node &a) const { return dis>a.dis; }
};
priority_queue<node> q;
void dij(void)
{
	std::fill(dis+1, dis+n+1, 0x3f3f3f3f3f3f3f);
	dis[s]=0;
	q.push(node{s, 0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int u=t.id;
		if(dis[u]!=t.dis) continue;
		for(auto x:to[u])
		{
			int v=x.x, w=x.y;
			if(dis[v]>dis[u]+w) dis[v]=dis[u]+w, q.push(node{v, dis[v]});
		}
	}
	for(int x=1; x<=n; ++x) for(auto t:to[x])
	{
		int y=t.x; 
		if(dis[x]+t.y!=dis[y]) continue;
		e.add(x, y), g.add(y, x);
	}
}
void dfs(int u, int fa)
{
	id[++top]=u, dfn[u]=top;
	pa[u]=fa;
	
	for(int i=e.head[u]; i; i=e.nxt[i])
	{
		int v=e.to[i];
		if(!dfn[v]) dfs(v, u);
	}
}
inline int findfa(int x)
{
	if(x==fa[x]) return x;
	int t=fa[x];
	fa[x]=findfa(fa[x]), vl[x]=std::min(vl[x], vl[t]);
	return fa[x];
}
inline void merge(int x, int y)
{
	fa[x]=y, vl[x]=std::min(vl[x], vl[y]);
}
void insert(int u)
{
	val[u]=dfn[u];
	for(int i=g.head[u]; i; i=g.nxt[i])
	{
		int v=g.to[i];
		if(dfn[v]<dfn[u]) val[u]=std::min(dfn[v], val[u]);
		else findfa(v), val[u]=std::min(val[u], vl[v].x);
	}
	vl[u]=mp(val[u], u);
	semi[u]=id[val[u]];
	rq.add(semi[u], u);
	for(int i=rq.head[u]; i; i=rq.nxt[i])
	{
		int v=rq.to[i];
		findfa(v);
		idom[v]=vl[v].y;
	}
	
	for(int i=e.head[u]; i; i=e.nxt[i])
	{
		int v=e.to[i];
		if(pa[v]==u) merge(v, u);
	}
}
void build(void)
{
	for(int i=1; i<=n; ++i)
	{
		int u=id[i], t=idom[u];
		idom[u]=(semi[u]==semi[t])?semi[u]:idom[t];
	}
	for(int i=n; i; --i)
	{
		int u=id[i];
		++cnt[u];
		if(u!=s) cnt[idom[u]]+=cnt[u];
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &s);
	for(int i=1, x, y, z; i<=m; ++i) scanf("%d%d%d", &x, &y, &z), to[x].pb(mp(y, z)), to[y].pb(mp(x, z));
	for(int i=1; i<=n; ++i) fa[i]=i;
	dij();
	dfs(s, 0);
	for(int i=top; i; --i) insert(id[i]);
	build();
	int ans=0;
	for(int i=1; i<=n; ++i) if(i!=s) ans=std::max(cnt[i], ans);
	printf("%d\n", ans);
	return 0;
}
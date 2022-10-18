#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#define pb push_back
using std::queue;
using std::set;
using std::vector;
const int N=600005;
int T, n, m, x[N], y[N], pos[N];
vector<int> e[N], g[N], re[N];
int stk[N], dfn[N], low[N], cnt, top;
int cur[N], tp, ok;
int pid[N], rp;
void solve(void)
{
	static int rid[N], id[N], eid[N], ch[N][2], vis[N], rtp, m;
	static int stk[N][4], top;
	static set<int> st[N];
	top=rtp=m=0;
	// puts("slv");
	// for(int i=1; i<=tp; ++i) if(cur[i]<=n) printf("%d ", cur[i]);
	// puts("");
	// for(int i=1; i<=tp; ++i) if(cur[i]>n) printf("%d ", cur[i]-n);
	// puts("");
	for(int i=1; i<=tp; ++i) if(cur[i]<=n) rid[cur[i]]=++rtp, id[rtp]=cur[i];
	else eid[++m]=cur[i]-n;
	if(rtp==1)
	{
		int u=id[1], v=(cur[1]^cur[2]^u)-n;
		re[u].pb(x[v]^y[v]^u);
		// printf("pb %d %d %d\n", x[v], y[v], x[v]^y[v]^u);
		return;
	}
	int n=rtp;
	for(int i=1; i<=n; ++i) ch[i][0]=ch[i][1]=vis[i]=0, st[i].clear(), g[i].clear();
	for(int i=1; i<=m; ++i)
	{
		int v=eid[i];
		// printf("add %d %d %d %d\n", x[v], y[v], rid[x[v]], rid[y[v]]);
		g[rid[x[v]]].pb(rid[y[v]]), g[rid[y[v]]].pb(rid[x[v]]);
	}
	for(int i=1; i<=n; ++i) for(int x:g[i]) st[i].insert(x);
	queue<int> q;
	for(int i=1; i<=n; ++i) if(st[i].size()==2) q.push(i);
	int rem=n;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		--rem;
		vis[u]=1;
		// printf("in %d\n", id[u]);
		int a=0, b=0;
		for(int v:st[u]) (a?b:a)=v;
		// printf("ab %d %d %d %d %d\n", id[u], id[a], id[b], st[a].size(), st[b].size());
		if(!a) continue;
		if(rem==2&&b)
		{
			if(!st[a].count(b)) { ok=0; return; }
			vis[a]=vis[b]=1;
			ch[u][0]=a, ch[u][1]=b;
			ch[a][0]=u, ch[a][1]=b;
			ch[b][0]=a, ch[b][1]=u;
			break;
		}
		stk[++top][0]=u, stk[top][1]=a, stk[top][2]=b;
		st[a].erase(u);
		if(b)
		{
			st[b].erase(u);
			if(a!=b) st[a].insert(b), st[b].insert(a);
		}
		if(st[a].size()<=2) q.push(a);
		if(b&&st[b].size()<=2) q.push(b);
	}
	// for(int i=1; i<=n; ++i) printf("%d %d %d\n", id[i], id[ch[i][0]], id[ch[i][1]]);
	while(top)
	{
		int u=stk[top][0], a=stk[top][1], b=stk[top][2];
		--top;
		// printf("in %d %d %d\n", id[u], id[a], id[b]);
		if(b)
		{
			if(ch[a][0]!=b&&ch[a][1]!=b) { ok=0; return; }
			if(ch[b][0]!=a&&ch[b][1]!=a) { ok=0; return; }
			ch[a][ch[a][1]==b]=u, ch[b][ch[b][1]==a]=u;
		}
		else ch[a][ch[a][0]>0]=u;
		ch[u][0]=a, ch[u][1]=b;
	}
	// for(int i=1; i<=n; ++i) printf("%d %d %d\n", id[i], id[ch[i][0]], id[ch[i][1]]);
	for(int i=1; i<=n; ++i) if(!vis[i]) { ok=0; return; }
	static int pid[N];
	tp=0;
	int x=1;
	while(vis[x])
	{
		pid[++tp]=x;
		pos[x]=tp;
		vis[x]=0;
		// printf("in %d", x);
		x=vis[ch[x][0]]?ch[x][0]:ch[x][1];
	}
	// for(int i=1; i<=n; ++i) printf("%d ", pid[i]);
	// puts("");
	for(int i=1; i<=n; ++i) if(vis[i]) { ok=0; return; }
	for(int i=1; i<=n; ++i)
	{
		rp=pos[i];
		std::sort(g[i].begin(), g[i].end(), [] (int x, int y) { return (pos[x]<rp)!=(pos[y]<rp)?(pos[x]<rp)>(pos[y]<rp):pos[x]>pos[y]; } );
		// for(int x:g[i]) printf("x %d %d\n", x, id[x]);
		for(int x:g[i]) re[id[i]].pb(id[x]);
	}
}
void tarjan(int u, int fa)
{
	if(!ok) return;
	low[u]=dfn[u]=++cnt;
	stk[++top]=u;
	for(int v:e[u]) if(v!=fa)
	{
		if(!dfn[v])
		{
			tarjan(v, u);
			low[u]=std::min(low[v], low[u]);
			if(low[v]>=dfn[u])
			{
				stk[top+1]=0;
				tp=0;
				while(stk[top+1]!=v) cur[++tp]=stk[top--];
				cur[++tp]=u;
				solve();
			}
		}
		else low[u]=std::min(low[u], dfn[v]);
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		cnt=top=0;
		for(int i=1; i<=n+m; ++i) e[i].clear(), g[i].clear(), re[i].clear(), dfn[i]=low[i]=0;
		for(int i=1; i<=m; ++i)
		{
			scanf("%d%d", x+i, y+i);
			++x[i], ++y[i];
			// printf("%d %d\n", x[i], y[i]);
			e[x[i]].pb(i+n), e[i+n].pb(x[i]);
			e[y[i]].pb(i+n), e[i+n].pb(y[i]);
		}
		ok=1;
		for(int i=1; i<=n; ++i) if(!dfn[i]) tarjan(i, 0);
		if(!ok) { puts("NO"); continue; }
		puts("YES");
		for(int i=1; i<=n; ++i, puts("")) for(int x:re[i]) printf("%d ", x-1);
	}
	return 0;
}
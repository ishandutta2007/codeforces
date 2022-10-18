#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
#define pb push_back
#define N 40005
using std::vector;
using std::queue;
namespace FLOW{
	int S, T, head[N], iter[N], dis[N], top=1;
	struct edge{
		int to, fl, nxt;
	}e[N<<3];
	inline void adde(int a, int b, int fl)
	{ e[++top]=edge{b, fl, head[a]}, head[a]=top; }
	inline void add(int a, int b, int fl)
	{
		adde(a, b, fl), adde(b, a, 0);
	}
	queue<int> q;
	inline void bfs(int n)
	{
		std::fill(dis+1, dis+n+1, -1);
		dis[S]=0;
		q.push(S);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=head[u]; i; i=e[i].nxt) if(e[i].fl)
			{
				int v=e[i].to;
				if(dis[v]==-1) dis[v]=dis[u]+1, q.push(v);
			}
		}
	}
	int dfs(int u, int fl)
	{
		if(u==T) return fl;
		int ret=0;
		for(int &i=iter[u]; i; i=e[i].nxt) if(e[i].fl)
		{
			int v=e[i].to;
			if(dis[v]!=dis[u]+1) continue;
			int s=dfs(v, std::min(fl, e[i].fl));
			e[i].fl-=s, fl-=s, e[i^1].fl+=s, ret+=s;
			if(!fl) break;
		}
		return ret;
	}
	inline int dinic(int n, int s, int t)
	{
		S=s, T=t;
		int ans=0;
		while(1)
		{
			bfs(n);
			if(dis[t]==-1) break;
			memcpy(iter, head, sizeof(int)*(n+1));
			ans+=dfs(s, INF);
		}
		return ans;
	}
}
using FLOW::add;
using FLOW::dinic;
int n, a[N], is[N], pr[N], s, t, top;
vector<int> e[N];
inline void init(int n)
{
	for(int i=2; i<=n; ++i)
	{
		if(!is[i]) pr[++top]=i;
		for(int j=1; j<=top&&pr[j]*i<=n; ++j)
		{
			is[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
}
int ans, vis[N], tot[N], ok;
void dfs(int u)
{
	vis[u]=1;
	++tot[ans];
	if(ok) printf("%d ", u);
	for(int v:e[u]) if(!vis[v]) dfs(v);
}
int main()
{
	scanf("%d", &n);
	s=n+1, t=n+2;
	int cnt=0;
	for(int i=1; i<=n; ++i) scanf("%d", a+i), ((a[i]&1)?add(s, i, 2), ++cnt:(add(i, t, 2), 0));
	init(20000);
	for(int i=1; i<=n; ++i) if(a[i]&1)
		for(int j=1; j<=n; ++j) if(!is[a[i]+a[j]])
			add(i, j, 1);
	if(cnt*2!=n||dinic(t, s, t)!=n) return puts("Impossible"), 0;
	for(int u=1; u<=n; ++u) if(a[u]&1)
	{
		for(int i=FLOW::head[u]; i; i=FLOW::e[i].nxt) if(!FLOW::e[i].fl)
		{
			int v=FLOW::e[i].to;
			if(v!=s) e[u].pb(v), e[v].pb(u);
		}
	}
	for(int i=1; i<=n; ++i) if(!vis[i]) ++ans, dfs(i);
	ok=1;
	std::fill(vis+1, vis+n+1, 0);
	printf("%d\n", ans);
	ans=0;
	for(int i=1; i<=n; ++i) if(!vis[i]) printf("%d ", tot[++ans]), dfs(i), puts("");
	return 0;
}
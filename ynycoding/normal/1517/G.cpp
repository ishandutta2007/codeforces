#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
using std::queue;
const int N=2005;
namespace FLOW{
	const int M=20005;
	int S, T, head[N], iter[N], dis[N], top=1;
	struct edge{
		int to;
		ll fl;
		int nxt;
	}e[M];
	queue<int> q;
	inline void adde(int a, int b, ll fl)
	{
		e[++top]=edge{b, fl, head[a]};
		head[a]=top;
	}
	inline void add(int a, int b, ll fl)
	{
		adde(a, b, fl), adde(b, a, 0);
	}
	void bfs(int n)
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
	ll dfs(int u, ll fl)
	{
		if(u==T) return fl;
		ll ret=0;
		for(int &i=iter[u]; i; i=e[i].nxt) if(e[i].fl)
		{
			int v=e[i].to;
			if(dis[v]!=dis[u]+1) continue;
			ll s=dfs(v, std::min(fl, 1ll*e[i].fl));
			fl-=s, e[i].fl-=s, ret+=s, e[i^1].fl+=s;
			if(!fl) break;
		}
		return ret;
	}
	ll dinic(int n, int s, int t)
	{
		S=s, T=t;
		ll ret=0;
		while(1)
		{
			bfs(n);
			if(dis[t]==-1) break;
			memcpy(iter, head, sizeof(int)*(n+1));
			ret+=dfs(s, 0x3f3f3f3f3f3f3f3f);
		}
		return ret;
	}
}
using FLOW::add;
using FLOW::dinic;
using FLOW::e;
using FLOW::dis;
int n, x[N], y[N], w[N], s, t;
ll ans;
inline int gtp(int id)
{
	int a=abs(x[id])&1^1, b=abs(y[id])&1;
	if(a&&b) return 2;
	if(a) return 1;
	if(b) return 3;
	return 0;
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d%d", x+i, y+i, w+i), ans+=w[i];
	s=2*n+1, t=2*n+2;
	for(int i=1; i<=n; ++i)
	{
		if(gtp(i)==0) add(s, i, 0x3f3f3f3f3f3f3f3f);
		if(gtp(i)==3) add(i+n, t, 0x3f3f3f3f3f3f3f3f);
		add(i, i+n, w[i]);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j)
		if(abs(x[i]-x[j])<=1&&abs(y[i]-y[j])<=1&&gtp(i)+1==gtp(j))
			add(i+n, j, 0x3f3f3f3f3f3f3f3f);
	ans-=dinic(t, s, t);
	printf("%lld\n", ans);
	return 0;
}
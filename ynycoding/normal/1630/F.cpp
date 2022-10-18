#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define INF 0x3f3f3f3f
using std::vector;
using std::queue;
const int N=300005, M=3600005;
namespace FLOW{
	int S, T, head[N], iter[N], dis[M], top=1;
	struct edge{
		int to, fl, nxt;
	}e[M];
	queue<int> q;
	inline void adde(int a, int b, int fl)
	{
		e[++top]=edge{b, fl, head[a]};
		head[a]=top;
	}
	inline void add(int a, int b, int fl)
	{
		adde(a, b, fl), adde(b, a, 0);
	}
	void bfs(int n)
	{
		while(!q.empty()) q.pop();
		std::fill(dis+1, dis+n+1, -1);
		dis[S]=0;
		q.push(S);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(u==T) return;
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
			fl-=s, e[i].fl-=s, ret+=s, e[i^1].fl+=s;
			if(!fl) break;
		}
		return ret;
	}
	int n;
	int dinic(int nn, int s, int t)
	{
		n=nn;
		S=s, T=t;
		int ret=0;
		while(1)
		{
			bfs(n);
			if(dis[t]==-1) break;
			memcpy(iter, head, sizeof(int)*(n+1));
			ret+=dfs(s, 0x3f3f3f3f);
		}
		return ret;
	}
	inline void clr(void)
	{
		std::fill(head, head+n+1, 0);
		top=1;
	}
}
using FLOW::add;
using FLOW::dinic;
using FLOW::e;
using FLOW::dis;
using FLOW::clr;
int T, n, a[N], id[N], col[N];
vector<int> fac[N];
int main()
{
	n=50000;
	for(int i=1; i<=n; ++i) for(int j=2*i; j<=n; j+=i) fac[j].pb(i);
	scanf("%d", &T);
	while(T--)
	{
		clr();
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), col[a[i]]=0, id[a[i]]=i;
		std::sort(a+1, a+n+1);
		int s=4*n+1, t=s+1;
		int ls=0, inf=0x3f3f3f3f;
		for(int i=n; i; --i)
		{
			int x=a[i], u=id[x];
			add(s, u, ls+1), add(u, u+n, ls), add(u+n, u+2*n, ls+1), add(u+2*n, u+3*n, ls), add(u+3*n, t, ls+1);
			for(int y:fac[x]) if(id[y])
			{
				int v=id[y];
				add(u, v+n, inf);
				add(u+2*n, v+3*n, inf);
			}
		}
		int fl=dinic(t, s, t);
		printf("%d\n", fl-n*ls);
		for(int i=1; i<=n; ++i) id[a[i]]=0;
	}
	return 0;
}
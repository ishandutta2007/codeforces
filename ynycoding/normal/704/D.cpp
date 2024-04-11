#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
#define N 200005
using std::queue;
namespace FLOW{
	int S, T, head[N], iter[N], dis[N], top=1;
	struct edge{
		int to, fl, nxt;
	}e[N*5];
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
			ans+=dfs(s, 0x3f3f3f3f);
		}
		return ans;
	}
}
using FLOW::e;
using FLOW::add;
using FLOW::dinic;
using FLOW::head;
using FLOW::top;
int n, m, r, b, x[N], y[N], lsx[N], lsy[N], cnx[N], cny[N], dx[N], dy[N], fs, ft, s, t, S, T;
ll ans;
int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &r, &b);
	s=2*n+1, t=2*n+2, S=2*n+3, T=2*n+4;
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i), lsx[i]=x[i], lsy[i]=y[i];
	std::sort(lsx+1, lsx+n+1);
	std::sort(lsy+1, lsy+n+1);
	for(int i=1; i<=n; ++i) x[i]=std::lower_bound(lsx+1, lsx+n+1, x[i])-lsx;
	for(int i=1; i<=n; ++i) y[i]=std::lower_bound(lsy+1, lsy+n+1, y[i])-lsy;
	for(int i=1; i<=n; ++i) ++cnx[x[i]], ++cny[y[i]];
	for(int i=1; i<=n; ++i) dx[i]=cnx[i], dy[i]=cny[i];
	for(int i=1, t, l, d; i<=m; ++i)
	{
		scanf("%d%d%d", &t, &l, &d);
		if(t==1)
		{
			int tl=std::lower_bound(lsx+1, lsx+n+1, l)-lsx;
			if(lsx[tl]!=l) continue;
			dx[tl]=std::min(dx[tl], d);
		}
		else
		{
			int tl=std::lower_bound(lsy+1, lsy+n+1, l)-lsy;
			if(lsy[tl]!=l) continue;
			dy[tl]=std::min(dy[tl], d);
		}
	}
	ans=1ll*n*r;
	for(int i=1; i<=n; ++i)
		add(x[i], y[i]+n, 1);
	for(int i=1; i<=n; ++i)
	{
		if(!dx[i]&&(cnx[i]&1)) return puts("-1"), 0;
		if(!dy[i]&&(cny[i]&1)) return puts("-1"), 0;
		add(s, i, dx[i]-((dx[i]^cnx[i])&1));
		add(i+n, t, dy[i]-((dy[i]^cny[i])&1));
		add(S, i, (cnx[i]-dx[i]+1)>>1);
		fs+=(cnx[i]-dx[i]+1)>>1;
		add(i+n, T, (cny[i]-dy[i]+1)>>1);
		ft+=(cny[i]-dy[i]+1)>>1;
	}
	add(s, T, fs);
	add(S, t, ft);
	add(t, s, 0x3f3f3f3f);
	dinic(T, S, T);
	for(int i=head[S]; i; i=e[i].nxt) if(e[i].fl) return puts("-1"), 0;
	int cur=e[top].fl;
	e[top].fl=e[top^1].fl=0;
	if(r>b) ans-=1ll*(r-b)*(cur+dinic(T, s, t));
	else ans+=1ll*(b-r)*(cur-dinic(T, t, s));
	printf("%lld\n", ans);
	for(int i=1; i<=n; ++i) if(!e[i<<1].fl) putchar('b');
	else putchar('r');
	return 0;
}
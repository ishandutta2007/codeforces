#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
using std::queue;
using std::vector;
const int N=600005;
namespace FLOW{
	const int M=3000005;
	struct edge{
		int to, nxt, fl;
	}e[M];
	int S, T, n, head[N], dis[N], iter[N], top=1;
	inline void adde(int x, int y, int fl) { e[++top]=edge{y, head[x], fl}, head[x]=top; }
	inline void add(int x, int y, int fl)
	{
		adde(x, y, fl);
		adde(y, x, 0);
	}
	queue<int> q;
	void bfs(void)
	{
		std::fill(dis+1, dis+n+1, -1);
		while(!q.empty()) q.pop();
		dis[S]=0;
		q.push(S);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=head[u]; i; i=e[i].nxt) if(e[i].fl)
			{
				int v=e[i].to;
				if(dis[v]==-1)
				{
					dis[v]=dis[u]+1;
					if(v==T) return;
					q.push(v);
				}
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
			e[i].fl-=s, e[i^1].fl+=s, fl-=s, ret+=s;
			if(!fl) break;
		}
		return ret;
	}
	int dinic(int s, int t, int nn)
	{
		n=nn;
		S=s, T=t;
		int ret=0;
		while(1)
		{
			bfs();
			if(dis[t]==-1) break;
			std::copy(head, head+n+1, iter);
			ret+=dfs(s, 0x3f3f3f3f);
		}
		return ret;
	}
}
using FLOW::add;
using FLOW::dinic;
int n, m, dep[N], pa[N], w[N], lsh[N], ok[N], rok[N], tot, top, ans, s, t;
vector<int> e[N], ew[N], id[N];
void dfs(int u, int fa, int rw)
{
	dep[u]=dep[fa]+1;
	pa[u]=fa, w[u]=rw;
	for(int i=0, ok=0; i<e[u].size(); ++i)
	{
		int v=e[u][i], c=std::lower_bound(lsh+1, lsh+top+1, ew[u][i])-lsh;
		if(v==fa&&!ok&&c==rw) { ok=1; continue; }
		if(dep[v])
		{
			if(dep[v]>dep[u]) continue;
			++tot;
			int x=u;
			while(x!=v) id[tot].pb(w[x]), ::ok[x]=0, x=pa[x];
			id[tot].pb(c);
		}
		else dfs(v, u, c);
	}
	if(ok[u]) rok[rw]=1;
}
namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[15];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;
int main()
{
	scanf("%d%d", &n, &m);
	std::fill(ok+1, ok+n+1, 1);
	for(int i=1, x, y, c; i<=m; ++i)
	{
		scan(x), scan(y), scan(c), e[x].pb(y), ew[x].pb(c), e[y].pb(x), ew[y].pb(c);
		lsh[i]=c;
	}
	std::sort(lsh+1, lsh+m+1);
	top=std::unique(lsh+1, lsh+m+1)-lsh-1;
	for(int i=1; i<=n; ++i) if(!dep[i]) dfs(i, 0, 0);
	for(int i=1; i<=top; ++i) ans+=rok[i];
	s=top+tot+1, t=top+tot+2;
	for(int i=1; i<=top; ++i) if(!rok[i]) add(s, i, 1);
	for(int i=1; i<=tot; ++i)
	{
		add(top+i, t, id[i].size()-1);
		for(int x:id[i]) if(!rok[x]) add(x, top+i, 1);
	}
	printf("%d\n", ans+dinic(s, t, t));
	return 0;
}
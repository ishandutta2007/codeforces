#include <cstdio>
#include <queue>
#include <algorithm>
using std::queue;
const int N=205;
namespace FLOW{
	const int M=N*N*32;
	struct edge{
		int nxt, to, fl;
	}e[M];
	int S, T, n, dis[M], head[M], iter[M], top=1;
	queue<int> q;
	inline void adde(int x, int y, int f)
	{
		e[++top]=edge{head[x], y, f};
		head[x]=top;
	}
	inline void add(int x, int y, int f)
	{
		adde(x, y, f);
		adde(y, x, 0);
	}
	void bfs(void)
	{
		std::fill(dis+1, dis+n+1, -1);
		q.push(S);
		dis[S]=0;
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
	int dinic(int nn, int s, int t)
	{
		n=nn, S=s, T=t;
		int ret=0;
		while(1)
		{
			bfs();
			if(dis[T]==-1) break;
			std::copy(head+1, head+n+1, iter+1);
			ret+=dfs(S, 0x3f3f3f3f);
		}
		return ret;
	}
}
using FLOW::add;
using FLOW::dinic;
int n, m, nm, S, T, cnt;
char s[N][N];
inline int gid(int x, int y) { return (x-1)*(m+1)+y; }
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", s[i]+1);
		for(int j=1; j<=m; ++j) cnt+=s[i][j]=='#';
	}
	nm=(n+1)*(m+1);
	S=2*(n+1)*(m+1)+1, T=S+1;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			if(s[i][j-1]=='#'&&s[i-1][j]=='#'&&s[i][j]=='#') add(gid(i-1, j), nm+gid(i, j-1), 1);
			if(s[i][j+1]=='#'&&s[i-1][j]=='#'&&s[i][j]=='#') add(gid(i-1, j), nm+gid(i, j), 1);
			if(s[i][j-1]=='#'&&s[i+1][j]=='#'&&s[i][j]=='#') add(gid(i, j), nm+gid(i, j-1), 1);
			if(s[i][j+1]=='#'&&s[i+1][j]=='#'&&s[i][j]=='#') add(gid(i, j), nm+gid(i, j), 1);
			if(s[i][j]=='#'&&s[i][j+1]=='#') add(nm+gid(i, j), T, 1), --cnt;
			if(s[i][j]=='#'&&s[i+1][j]=='#') add(S, gid(i, j), 1), --cnt;
		}
	}
	printf("%d\n", cnt+dinic(T, S, T));
	return 0;
}
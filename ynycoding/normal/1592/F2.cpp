#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using std::queue;
const int N=505;
namespace FLOW{
	const int M=N*N*8;
	int S, T, head[M], iter[M], dis[M], top=1;
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
	int dinic(int n, int s, int t)
	{
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
}
using FLOW::add;
using FLOW::dinic;
using FLOW::e;
using FLOW::dis;
int cnt;
int n, m, nm, s, t, a[N][N];
char S[N];
inline int gid(int x, int y) { return (x-1)*m+y; }
int main()
{
	scanf("%d%d", &n, &m);
	s=n+m+1, t=s+1;
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", S+1);
		for(int j=1; j<=m; ++j) a[n-i+1][m-j+1]=S[j]=='B';
	}
	for(int i=n; i; --i) for(int j=m; j; --j)
	{
		a[i][j]^=a[i-1][j]^a[i][j-1]^a[i-1][j-1];
	}
//	for(int i=1; i<=n; ++i, puts("")) for(int j=1; j<=m; ++j) printf("%d ", a[i][j]);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cnt+=a[i][j];
	for(int i=2; i<=n; ++i) for(int j=2; j<=m; ++j) if(a[i][1]&&a[i][j]&&a[1][j])
	{
		add(i, j+n, 1);
	}
	for(int i=1; i<=n; ++i) if(a[i][1]) add(s, i, 1);
	for(int i=1; i<=m; ++i) if(a[1][i]) add(i+n, t, 1);
	int fl=dinic(t, s, t);
//	printf("cnt %d\n", cnt);
//	printf("%d\n", fl);
	printf("%d\n", cnt-fl+(fl?a[1][1]?-(fl&1):(fl&1):0));
	return 0;
}
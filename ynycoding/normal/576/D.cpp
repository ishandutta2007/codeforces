#include <cstdio>
#include <queue>
#include <bitset>
#include <cstring>
#include <algorithm>
#define N 156
using std::bitset;
using std::queue;
int n, m, a[N], b[N], d[N], id[N], dis[N], ans=0x3f3f3f3f;
bool tr[N][N], g[N][N], ret[N][N], cur[N], tmp[N];
bitset<N> rw[N], cl[N];
inline void mul(bool a[][N], bool b[][N], bool c[][N])
{
	for(int i=1; i<=n; ++i)
	{
		rw[i].reset(), cl[i].reset();
		for(int j=1; j<=n; ++j) rw[i][j]=a[i][j], cl[i][j]=b[j][i];
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) c[i][j]=(rw[i]&cl[j]).any();
}
inline void qp(int p)
{
	memcpy(tr, g, sizeof(g));
	memset(ret, 0, sizeof(ret));
	for(int i=1; i<=n; ++i) ret[i][i]=1;
	while(p)
	{
		if(p&1) mul(ret, tr, ret);
		p>>=1;
		mul(tr, tr, tr);
	}
}
queue<int> q;
inline void bfs(void)
{
	std::fill(dis+1, dis+n+1, -1);
	for(int i=1; i<=n; ++i) if(cur[i]) dis[i]=0, q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v=1; v<=n; ++v) if(g[u][v]&&dis[v]==-1) dis[v]=dis[u]+1, q.push(v);
	}
}
bool cmp(int x, int y) { return d[x]<d[y]; }
int main()
{
	scanf("%d%d", &n, &m);
	cur[1]=1;
	for(int i=1; i<=m; ++i) scanf("%d%d%d", a+i, b+i, d+i), id[i]=i;
	std::sort(id+1, id+m+1, cmp);
	for(int i=1, pr=0; i<=m; ++i)
	{
		int u=id[i];
		qp(d[u]-pr);
		memset(tmp, 0, sizeof(tmp));
		for(int i=1; i<=n; ++i) if(cur[i]) for(int j=1; j<=n; ++j) tmp[j]|=ret[i][j];
		memcpy(cur, tmp, sizeof(tmp));
		g[a[u]][b[u]]=1;
		bfs();
		if(dis[n]!=-1) ans=std::min(d[u]+dis[n], ans);
		pr=d[u];
	}
	if(ans==0x3f3f3f3f) puts("Impossible");
	else printf("%d\n", ans);
	return 0;
}
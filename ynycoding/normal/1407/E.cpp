#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
#define INF 0x3f3f3f3f
const int N=500005;
using std::vector;
using std::queue;
int n, m, col[N], dis[N], vis[N];
vector<int> e0[N], e1[N];
queue<int> q;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, x, y, t; i<=m; ++i)
	{
		scanf("%d%d%d", &x, &y, &t);
		if(x==n) continue;
		(t?e1:e0)[y].pb(x);
	}
	std::fill(vis+1, vis+n, 3);
	std::fill(dis+1, dis+n, INF);
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:e0[u]) if(vis[v]&1)
		{
			vis[v]&=2;
			if(!vis[v]) dis[v]=dis[u]+1, q.push(v);
			else col[v]=1;
		}
		for(int v:e1[u]) if(vis[v]&2)
		{
			vis[v]&=1;
			if(!vis[v]) dis[v]=dis[u]+1, q.push(v);
		}
	}
	printf("%d\n", dis[1]>=INF?-1:dis[1]);
	for(int i=1; i<=n; ++i) putchar('0'+col[i]);
	return 0;
}
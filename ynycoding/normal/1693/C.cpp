#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
using std::vector;
using std::priority_queue;
using std::pair;
const int N=200005;

int n, m, f[N], deg[N];
vector<int> e[N];
priority_queue<pair<int, int> > q;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, x, y; i<=m; ++i)
	{
		scanf("%d%d", &x, &y);
		if(x!=n) e[y].pb(x), ++deg[x];
	}
	std::fill(f+1, f+n+1, 0x3f3f3f3f);
	q.push({0, n});
	f[n]=0;
	while(!q.empty())
	{
		auto [d, u]=q.top();
		q.pop();
		d=-d;
		if(d!=f[u]) continue;
		for(int v:e[u]) if(v!=n)
		{
			--deg[v];
			if(d+deg[v]+1<f[v])
			{
				f[v]=d+deg[v]+1;
				q.push({-f[v], v});
			}
		}
	}
	printf("%d\n", f[1]);
	return 0;
}
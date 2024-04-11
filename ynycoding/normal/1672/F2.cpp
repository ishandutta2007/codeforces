#include <cstdio>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>
#define pb push_back
using std::vector;
using std::queue;
const int N=200005;
int T, n, a[N], b[N], p[N], cnt[N], id;
int vis[N], tim[N], t, deg[N];
queue<int> q;
vector<int> e[N], g[N];
inline void add(int x, int y) { g[x].pb(y), ++deg[y]; }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		id=0;
		while(!q.empty()) q.pop();
		for(int i=1; i<=n; ++i) deg[i]=cnt[i]=0, g[i].clear(), e[i].clear();
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", a+i);
			++cnt[a[i]];
			if(cnt[a[i]]>cnt[id]) id=a[i];
			e[a[i]].pb(i);
		}
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", b+i);
			p[i]=e[b[i]].back();
			e[b[i]].pop_back();
		}
		std::fill(vis+1, vis+n+1, 0);
		for(int i=1; i<=n; ++i) if(b[p[i]]!=id) add(b[i], b[p[i]]);
		if(deg[id]) goto out;
		q.push(id);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			vis[u]=1;
			for(int v:g[u]) if(!(--deg[v])) q.push(v);
		}
		for(int i=1; i<=n; ++i) if(!vis[b[i]]) goto out;
		puts("AC");
		if(0)
		{
			out:;
			puts("WA");
		}
	}
	return 0;
}
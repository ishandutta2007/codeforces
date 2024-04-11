#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define pb push_back
#define mp std::make_pair
using std::vector;
using std::set;
using std::pair;
using std::queue;
const int N=500005;
int T, n, m, p[N], q[N], vis[N], deg[N], cnt;
set<pair<int, int> >st;
set<int> res;
queue<int> que;
vector<int> e[N];
inline void add(int x, int y)
{
	e[x].pb(y);
	e[y].pb(x);
//	printf("add %d %d\n", x, y);
	++deg[x], ++deg[y];
}
void dfs(int u)
{
	res.erase(u);
	que.push(u);
	vector<int> tmp;
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u]=1;
//		printf("in %d\n", u);
		for(int v:res) if(!st.count(mp(u, v)))
			add(u, v), tmp.pb(v), que.push(v);
		for(int v:tmp) res.erase(v);
		tmp.clear();
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		st.clear();
		res.clear();
		for(int i=1; i<=n; ++i) e[i].clear(), deg[i]=0;
		for(int i=1, x, y; i<=m; ++i)
		{
			scanf("%d%d", &x, &y);
			st.insert(mp(x, y));
			st.insert(mp(y, x));
		}
		for(int i=1; i<=n; ++i) res.insert(i);
		std::fill(vis+1, vis+n+1, 0);
		std::fill(deg+1, deg+n+1, 0);
		for(int i=1; i<=n; ++i) if(!vis[i])
			dfs(i);
		cnt=0;
//		for(int i=1; i<=n; ++i) printf("%d ", deg[i]);
//		puts("");
		for(int i=1; i<=n; ++i) if(deg[i]==1) que.push(i);
		std::fill(vis+1, vis+n+1, 0);
		while(!que.empty())
		{
			int u=que.front();
			que.pop();
			if(vis[u]) continue;
			for(int v:e[u]) if(!vis[v])
			{
				u=v;
				break;
			}
//			printf("now %d\n", u);
			vis[u]=1;
			p[u]=++cnt;
			int tot=0;
			for(int v:e[u]) if(deg[v]==1)
			{
				p[v]=cnt+(++tot);
			}
			q[u]=cnt+tot;
			--cnt;
			for(int v:e[u]) if(deg[v]==1)
			{
				vis[v]=1;
				q[v]=++cnt;
			}
			++cnt;
			for(int v:e[u]) if((--deg[v])==1)
				que.push(v);
		}
		for(int i=1; i<=n; ++i) if(!vis[i]) p[i]=q[i]=++cnt;
		for(int i=1; i<=n; ++i) printf("%d ", p[i]);
		puts("");
		for(int i=1; i<=n; ++i) printf("%d ", q[i]);
		puts("");
	}
	return 0;
}
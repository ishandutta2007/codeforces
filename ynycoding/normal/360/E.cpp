#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::vector;
using std::priority_queue;
const int N=100005;
int n, m, k, l[N], r[N], ok[N];
int s1, s2, t, vis[N];
ll dis[N], dis1[N];
vector<int> e[N], w1[N], w2[N], id[N];
struct node{
	int id;
	ll dis;
	bool operator <(const node &a) const { return dis>a.dis; }
};
priority_queue<node> q;
void dij(int n, int s, const vector<int> *w, ll *dis)
{
	std::fill(dis+1, dis+n+1, 0x3f3f3f3f3f3f3f3f);
	dis[s]=0;
	q.push(node{s, 0});
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		int u=tmp.id;
		if(dis[u]!=tmp.dis) continue;
		for(int i=0; i<e[u].size(); ++i)
		{
			int v=e[u][i], c=w[u][i];
			if(dis[v]>dis[u]+c)
			{
				dis[v]=dis[u]+c;
				q.push(node{v, dis[v]});
			}
		}
	}
}
int ad;
bool dfs(int u)
{
	if(dis[u]>=dis1[u]+ad) return 0;
	vis[u]=1;
	if(u==t) return 1;
	for(int i=0; i<e[u].size(); ++i)
	{
		int v=e[u][i];
		if(vis[v]) continue;
		if(dfs(v)) { ok[id[u][i]]=1; return 1; }
	}
	return 0;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d", &s1, &s2, &t);
	for(int i=1, x, y, a, b; i<=m; ++i)
	{
		scanf("%d%d%d", &x, &y, &a);
		b=a;
		l[i]=a, r[i]=b;
		e[x].pb(y), w1[x].pb(a), w2[x].pb(b), id[x].pb(i);
	}
	for(int i=m+1, x, y, a, b; i<=m+k; ++i)
	{
		scanf("%d%d%d%d", &x, &y, &a, &b);
		l[i]=a, r[i]=b;
		e[x].pb(y), w1[x].pb(a), w2[x].pb(b), id[x].pb(i);
	}
	dij(n, s1, w1, dis);
	dij(n, s2, w2, dis1);
//	for(int i=1; i<=n; ++i) printf("dis %d %lld %lld\n", i, dis[i], dis1[i]);
	if(!dfs(s1))
	{
		ad=1;
		std::fill(vis+1, vis+n+1, 0);
		if(!dfs(s1)) return puts("LOSE"), 0;
	}
	puts(ad?"DRAW":"WIN");
	for(int i=m+1; i<=m+k; ++i) printf("%d ", ok[i]?l[i]:r[i]);
	return 0;
}
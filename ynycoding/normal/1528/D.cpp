#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#define INF 0x3f3f3f3f
#define mp std::make_tuple
#define pb push_back
using std::vector;
using std::tuple;
using std::queue;
const int N=605;
int n, m, dis[N], in[N];
vector<tuple<int, int> > e[N];
queue<int> q;
void dij(int s)
{
	std::fill(dis, dis+n, INF);
	std::fill(in, in+n, 0);
//	dis[s]=0;
	int mn=INF;
	for(auto [v, c]:e[s]) if(c>=0)
		dis[v]=c, q.push(v), in[v]=1, mn=std::min(mn, c);
//	dis[s]=0;
//	q.push(mp(s, 0));
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int d=dis[u];
		in[u]=0;
		if(d>mn+n) continue;
		for(auto [v, c]:e[u])
		{
			v=c>=0?(v+d)%n:v;
			if(c<0) c=-c;
			if(dis[v]>d+c)
			{
				dis[v]=d+c;
				if(!in[v]) q.push(v), in[v]=1;
			}
		}
	}
	dis[s]=0;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i) e[i].pb(mp((i+1)%n, -1));
	for(int i=1, a, b, c; i<=m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		e[a].pb(mp(b, c));
	}
	for(int i=0; i<n; ++i, puts(""))
	{
		dij(i);
		for(int j=0; j<n; ++j) printf("%d ", dis[j]);
	}
	return 0;
}
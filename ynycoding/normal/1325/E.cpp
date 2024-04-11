#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
#define N 1000005
using std::max;
using std::vector;
using std::queue;
int n, a[N], dis[N], x[N], y[N], ans=0x3f3f3f3f, nd[N<<1], tp, lim;
vector<int> e[N];
inline void pr(int id)
{
	for(int i=2; i*i<=a[id]; ++i) while(a[id]%(i*i)==0) a[id]/=(i*i);
	for(int i=2; i*i<=a[id]; ++i) if(a[id]%i==0)
	{ x[id]=i, y[id]=a[id]/i, nd[++tp]=i, nd[++tp]=a[id]/i; return; }
	x[id]=1, y[id]=a[id];
}
queue<int> q;
inline int bfs(int s)
{
	int ret=0x3f3f3f3f;
	while(!q.empty()) q.pop();
	for(int i=1; i<=tp; ++i) dis[nd[i]]=-2;
	dis[s]=0, q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:e[u])
		{
			if(dis[v]==dis[u]-1) continue;
			if(dis[v]!=-2) ret=std::min(ret, dis[u]+dis[v]+1);
			else dis[v]=dis[u]+1, q.push(v);
		}
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	nd[++tp]=1;
	for(int i=1; i<=n; ++i) scanf("%d", a+i), pr(i), e[x[i]].pb(y[i]), e[y[i]].pb(x[i]), lim=max(lim, a[i]), nd[++tp]=x[i], nd[++tp]=y[i];
	std::sort(nd+1, nd+tp+1);
	tp=std::unique(nd+1, nd+tp+1)-nd-1;
	for(int i=1; i<=tp&&nd[i]*nd[i]<=lim; ++i) ans=std::min(ans, bfs(nd[i]));
	printf("%d\n", ans==0x3f3f3f3f?-1:ans);
	return 0;
}
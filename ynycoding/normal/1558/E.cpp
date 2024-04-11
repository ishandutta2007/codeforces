#include <cstdio>
#include <bitset>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define x first
#define y second
#define mp std::make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
using std::bitset;
using std::pair;
using std::vector;
using std::priority_queue;
const int N=1005;
int T, n, m, a[N], b[N], lim, id[N][2];
ll dis[N][2], tot, tota;
ull st[N][2][20];
priority_queue<pair<ll, int> > q;
vector<int> e[N], eid[N];
inline void set(ull *s, int x) { s[x>>6]|=1ull<<(x&63); }
inline int test(ull *s, int x) { return (s[x>>6]>>(x&63))&1; }
void dij(int s, ll k)
{
	for(int i=1; i<=n; ++i)
	{
		dis[i][0]=dis[i][1]=0;
		id[i][0]=id[i][1]=0;
		std::fill(st[i][0], st[i][0]+lim+1, 0);
		std::fill(st[i][1], st[i][1]+lim+1, 0);
	}
	dis[s][0]=k;
	set(st[s][0], s);
	q.push(mp(k, s<<1));
//	puts("fa");
	while(!q.empty())
	{
		auto tmp=q.top();
		q.pop();
		int u=tmp.y>>1, t=tmp.y&1;
		if(dis[u][t]!=tmp.x) continue;
//		printf("now %d %d %lld\n", u, t, dis[u][t]);
		for(int i=0; i<e[u].size(); ++i) if(eid[u][i]!=id[u][t])
		{
			int v=e[u][i], x=eid[u][i];
			if(!test(st[u][t], v)&&a[v]>=dis[u][t]) continue;
			if(dis[v][0]<dis[u][t]+(test(st[u][t], v)?0:b[v]))
			{
				if(id[v][0]!=x)
				{
					id[v][1]=id[v][0];
					dis[v][1]=dis[v][0];
					memcpy(st[v][1], st[v][0], sizeof(ull)*(lim+1));
				}
				id[v][0]=x;
				dis[v][0]=dis[u][t]+(test(st[u][t], v)?0:b[v]);
				memcpy(st[v][0], st[u][t], sizeof(ull)*(lim+1));
				set(st[v][0], v);
				q.push(mp(dis[v][0], v<<1));
			}
			else if(id[v][0]!=x&&dis[v][1]<dis[u][t]+(test(st[u][t], v)?0:b[v]))
			{
				id[v][1]=x;
				dis[v][1]=dis[u][t]+(test(st[u][t], v)?0:b[v]);
				memcpy(st[v][1], st[u][t], sizeof(ull)*(lim+1));
				set(st[v][1], v);
				q.push(mp(dis[v][1], v<<1|1));
			}
		}
	}
}
bool chk(ll k)
{
	dij(1, k);
	for(int i=1; i<=n; ++i) if(dis[i][0]==tot+k)
		return 1;
	return 0;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		for(int i=1; i<=n; ++i) e[i].clear(), eid[i].clear();
		scanf("%d%d", &n, &m);
		lim=(n+63)>>6;
//		printf("lim %d\n", lim);
		tot=tota=0;
		for(int i=2; i<=n; ++i) scanf("%d", a+i), tota+=a[i];
		for(int i=2; i<=n; ++i) scanf("%d", b+i), tot+=b[i];
		for(int i=1, x, y; i<=m; ++i)
		{
			scanf("%d%d", &x, &y);
			e[x].pb(y), e[y].pb(x);
			eid[x].pb(i), eid[y].pb(i);
		}
		ll l=0, r=tota+1;
//		if(chk(15)) puts("ok");
//		exit(114);
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(chk(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n", l);
	}
	return 0;
}
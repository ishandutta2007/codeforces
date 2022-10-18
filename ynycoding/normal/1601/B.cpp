#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define x first
#define y second
#define pb push_back
using std::pair;
using std::vector;
const int N=2000005;
int n, a[N], b[N], mx;
vector<pair<int, int> > e[N];
inline void add(int x, int y, int c)
{
//	printf("add %d %d %d\n", x, y, c);
	e[x].pb({y, c});
}
namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	void build(int id, int l, int r)
	{
		mx=std::max(mx, id);
		if(l==r) { add(id+2*(n+1), l+n+1, 0); return; }
		int mid=(l+r)>>1;
		build(lid, l, mid), build(rid, mid+1, r);
		add(id+2*(n+1), lid+2*(n+1), 0);
		add(id+2*(n+1), rid+2*(n+1), 0);
	}
	void add(int id, int l, int r, int l1, int r1, int v, int w)
	{
		if(l1<=l&&r<=r1) { ::add(v, id+2*(n+1), w); return; }
		int mid=(l+r)>>1;
		if(l1<=mid) add(lid, l, mid, l1, r1, v, w);
		if(r1>mid) add(rid, mid+1, r, l1, r1, v, w);
	}
	#undef lid
	#undef rid
}
using namespace SGT;
int dis[N], pr[N], d[N], top, in[N];
void dij(int s, int n)
{
	static int q[N<<5], *ql, *qr;
	ql=q+(N<<4), qr=ql-1;
	std::fill(dis, dis+n+1, 0x3f3f3f3f);
	dis[s]=0;
	in[s]=1;
	*(++qr)=s;
	int tcnt;
	while(ql<=qr)
	{
		int u=*(ql++);
//		if(in[u]) exit(114);
//		in[u]=1;
//		if((++tcnt)%100000==0) printf("fa %d %d\n", u, dis[u]);
		for(auto [v, w]:e[u])
		{
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pr[v]=u;
				if(!w) *(--ql)=v;
				else *(++qr)=v;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) scanf("%d", b+i);
	build(1, 0, n);
	add(n+1, 0, 0);
	for(int i=1; i<=n; ++i)
	{
//		printf("add %d %d\n", i-a[i], i);
		add(1, 0, n, i-a[i], i, i, 1);
		add(i+n+1, i+b[i], 0);
	}
	dij(n, 2*(n+1)+mx);
	if(dis[0]==0x3f3f3f3f) return puts("-1"), 0;
	int s=0;
	while(s!=n)
	{
		if(s<=2*n+2&&s>n) d[++top]=s;
		s=pr[s];
	}
	printf("%d\n", top);
	while(top) printf("%d ", d[top]-n-1), --top;
	return 0;
}
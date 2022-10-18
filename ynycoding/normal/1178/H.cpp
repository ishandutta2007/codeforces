#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define ll long long
#define N 62005
using std::queue;
namespace FLOW{
	int S, T, head[N], iter[N], dis[N], in[N], top=1;
	struct edge{
		int to, fl, c, nxt;
	}e[N<<2];
	inline void adde(int x, int y, int fl, int c)
	{ e[++top]=edge{y, fl, c, head[x]}, head[x]=top; }
	inline void add(int x, int y, int fl, int c)
	{
		adde(x, y, fl, c);
		adde(y, x, 0, -c);
	}
	int q[N<<1], *ql, *qr;
	void spfa(int n)
	{
		std::fill(dis+1, dis+n+1, 0x3f3f3f3f);
		ql=q+N, qr=ql-1;
		dis[S]=0, *++qr=S, in[S]=1;
		while(ql<=qr)
		{
			int u=*ql;
			in[u]=0;
			++ql;
			for(int i=head[u]; i; i=e[i].nxt) if(e[i].fl)
			{
				int v=e[i].to;
				if(dis[v]>dis[u]+e[i].c)
				{
					dis[v]=dis[u]+e[i].c;
					if(!in[v]) in[v]=1, (e[i].c?*++qr=v:*--ql=v);
				}
			}
		}
	}
	int ans, rfl;
	int dfs(int u, int fl, int c)
	{
		if(u==T) { ans+=fl*c; return fl; }
		in[u]=1;
		int ret=0;
		for(int &i=iter[u]; i; i=e[i].nxt) if(e[i].fl)
		{
			int v=e[i].to;
			if(dis[v]!=dis[u]+e[i].c||in[v]) continue;
			int s=dfs(v, std::min(fl, e[i].fl), c+e[i].c);
			fl-=s, e[i].fl-=s, e[i^1].fl+=s, ret+=s;
			if(!fl) break;
		}
		in[u]=0;
		return ret;
	}
	void dinic(int s, int t, int n)
	{
		S=s, T=t;
		while(1)
		{
			spfa(n);
			if(dis[t]==0x3f3f3f3f) break;
			memcpy(iter, head, sizeof(int)*(n+1));
			rfl+=dfs(s, 0x3f3f3f3f, 0);
		}
	}
}
using namespace FLOW;
int n, a[N], b[N], id[N], id1[N], pos[N], c;
bool cmp(int x, int y) { return b[x]==b[y]?x>y:b[x]<b[y]; }
inline ll calc(int x) { return 1ll*a[x]*c+b[x]; }
bool cmp1(int x, int y) { return calc(x)==calc(y)?x>y:calc(x)<calc(y); }
bool cmp2(int x, int y) { return calc(pos[x])==calc(pos[y])?x>y:calc(pos[x])<calc(pos[y]); }
bool check(int t)
{
	c=t;
	std::sort(id1+1, id1+2*n+1, cmp1);
	for(int i=1, cur=0; i<=2*n; ++i)
	{
		if(calc(cur)<calc(id[i])) cur=id[i];
		pos[id[i]]=cur;
	}
	for(int i=n+1; i<=2*n; ++i) pos[i]=i;
	std::sort(id1+1, id1+2*n+1, cmp2);
	for(int i=1, cur=0; i<=2*n; ++i)
	{
		if(id1[i]>n) ++cur;
		else --cur;
		if(cur<0) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=2*n; ++i) scanf("%d%d", a+i, b+i), id[i]=i, id1[i]=i;
	std::sort(id+1, id+2*n+1, cmp);
	int l=0, r=0x3f3f3f3f;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(r==0x3f3f3f3f) return puts("-1"), 0;
	c=l;
	std::sort(id1+1, id1+2*n+1, cmp1);
	int m=2*n, s=8*n+1, t=s+1;
	for(int i=2; i<=2*n; ++i) add(id[i]+m, id[i-1]+m, n, 0), add(id1[i]+2*m, id1[i-1]+2*m, n, 0);
	for(int i=1; i<2*n; ++i) if(b[id[i]]==b[id[i+1]]) add(id[i]+m, id[i+1]+m, n, 0);
	for(int i=1; i<2*n; ++i) if(calc(id1[i])==calc(id1[i+1])) add(id1[i]+2*m, id1[i+1]+2*m, n, 0);
	for(int i=1; i<=2*n; ++i)
	{
		if(i<=n) add(s, i, 1, 0);
		else add(i, i+3*m, 1, 0), add(i+2*m, i+3*m, 1, 0), add(i+3*m, t, 1, 0);
		add(i+m, i, n, 0);
		add(i, i+m, n, 1);
		add(i, i+2*m, n, 1);
	}
	dinic(s, t, t);
	printf("%d %d\n", l, ans);
	return 0;
}
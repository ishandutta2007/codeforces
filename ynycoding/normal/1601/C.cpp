#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
using std::vector;
const int N=2000005;
int n, m, a[N], b[N], lsh[N], top;
int sum[N], mn[N];
ll ans;
vector<int> e[N];
inline void add(int p) { while(p<=top) ++sum[p], p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int sum[N<<2], mx[N<<2];
	inline void upt(int id)
	{
		mx[id]=std::min(mx[lid], sum[lid]+mx[rid]);
		sum[id]=sum[lid]+sum[rid];
	}
	void build(int id, int l, int r)
	{
		if(l==r) { mx[id]=sum[id]=-(l!=0); return; }
		int mid=(l+r)>>1;
		build(lid, l, mid), build(rid, mid+1, r);
		upt(id);
	}
	void add(int id, int l, int r, int p, int v)
	{
		if(l==r) { mx[id]=sum[id]=v; return; }
		int mid=(l+r)>>1;
		if(p<=mid) add(lid, l, mid, p, v);
		else add(rid, mid+1, r, p, v);
		upt(id);
	}
}
using namespace SGT;
inline int gid(int x) { return std::lower_bound(lsh+1, lsh+top+1, x)-lsh; }
int T;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		ans=top=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i), lsh[++top]=a[i];
		for(int i=1; i<=m; ++i) scanf("%d", b+i), lsh[++top]=b[i];
		std::sort(lsh+1, lsh+top+1);
		std::fill(::sum+1, ::sum+top+1, 0);
		for(int i=1; i<=top+1; ++i) e[i].clear();
		for(int i=1; i<=n; ++i)
		{
			int x=gid(a[i]);
			add(x);
			ans+=i-ask(x);
			e[x].pb(i);
		}
//		printf("ans %lld\n", ans);
		build(1, 0, n);
		for(int i=top; i; --i)
		{
			for(int x:e[i]) add(1, 0, n, x, 0);
			for(int x:e[i+1]) add(1, 0, n, x, 1);
			mn[i]=ask(i-1)+mx[1];
//			printf("ask %d %d\n", ask(i-1), mx[1]);
//			printf("now %d %d\n", lsh[i], mn[i]);
		}
		for(int i=1; i<=m; ++i) ans+=mn[gid(b[i])];//, printf("id %d\n", gid(b[i]));
		printf("%lld\n", ans);
	}
	return 0;
}
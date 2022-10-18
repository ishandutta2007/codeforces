#include <cstdio>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using std::min;
using std::max;
const int N=200005;
int n, q;
int sum[N];
ll sum1[N];
inline void add(int p, int v) { while(p<=n) sum[p]+=v, p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
inline void add1(int p, int v) { while(p<=n) sum1[p]+=v, p+=p&(-p); }
inline ll ask1(int p) { ll ret=0; while(p) ret+=sum1[p], p-=p&(-p); return ret; }
inline void radd(int l, int r, int v)
{
	add(l, v), add1(l, 1ll*l*v);
	add(r+1, -v), add1(r+1, -1ll*(r+1)*v);
}
inline ll rask(int p)
{
	return 1ll*(p+1)*ask(p)-ask1(p);
}
namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int mx[N<<2], mx1[N<<2], cnt[N<<2], tag[N<<2];
	inline void pushdown(int id)
	{
		mx[lid]=min(mx[lid], tag[id]);
		tag[lid]=min(tag[lid], tag[id]);
		mx[rid]=min(mx[rid], tag[id]);
		tag[rid]=min(tag[rid], tag[id]);
		tag[id]=INF;
	}
	inline void upt(int id)
	{
		mx1[id]=0;
		mx[id]=max(mx[lid], mx[rid]);
		cnt[id]=(mx[lid]==mx[id]?cnt[lid]:0)+(mx[rid]==mx[id]?cnt[rid]:0);
		mx1[id]=max((mx[lid]==mx[id]?mx1[lid]:mx[lid]), (mx[rid]==mx[id]?mx1[rid]:mx[rid]));
	}
	void build(int id, int l, int r)
	{
		tag[id]=INF;
		if(l==r)
		{
			mx[id]=l;
			cnt[id]=1;
			return;
		}
		int mid=(l+r)>>1;
		build(lid, l, mid), build(rid, mid+1, r);
		upt(id);
	}
	void addp(int id, int l, int r, int p, int v)
	{
		if(l==r)
		{
			radd(l+1, mx[id], -1);
			mx[id]=v;
			radd(l+1, v, 1);
			return;
		}
		int mid=(l+r)>>1;
		pushdown(id);
		if(p<=mid) addp(lid, l, mid, p, v);
		else addp(rid, mid+1, r, p, v);
		upt(id);
	}
	void add(int id, int l, int r, int p)
	{
		if(mx[id]<=p) return;
		if(r<=p)
		{
			if(mx1[id]<p)
			{
				radd(p+1, mx[id], -cnt[id]);
				tag[id]=p;
				mx[id]=p;
				return;
			}
		}
		pushdown(id);
		int mid=(l+r)>>1;
		add(lid, l, mid, p);
		if(p>mid) add(rid, mid+1, r, p);
		upt(id);	
	}
}
using namespace SGT;
int main()
{
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	for(int i=1, tp, x, y; i<=q; ++i)
	{
		scanf("%d%d%d", &tp, &x, &y);
		if(tp==1)
		{
			if(x-1) add(1, 1, n, x-1);
			addp(1, 1, n, x, y);
		}
		else printf("%lld\n", rask(y)-rask(x-1)+y-x+1);
	}
	return 0;
}
#include <cstdio>
#include <algorithm>
#define ll long long
const int N=100005;
int n, m, q;
ll a[N], b[N], cans;
inline ll calc(int x) { return 1ll*x*(x+1)/2; }
int pos;
ll ret;
namespace SGT{
	#define ls (u<<1)
	#define rs (u<<1|1)
	ll sum[N<<2], mn[N<<2], tag[N<<2];
	inline void upt(int u)
	{
		sum[u]=sum[ls]+sum[rs];
	}
	inline void addp(int u, int l, int r, ll v)
	{
		tag[u]+=v;
		mn[u]+=v;
		sum[u]+=(r-l+1)*v;
	}
	inline void pushdown(int u, int l, int r)
	{
		int mid=(l+r)>>1;
		if(tag[u])
		{
			addp(ls, l, mid, tag[u]);
			addp(rs, mid+1, r, tag[u]);
			tag[u]=0;
		}
	}
	void build(int u, int l, int r)
	{
		mn[u]=a[l];
		if(l==r) { sum[u]=a[l]; return; }
		int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r);
		upt(u);
	}
	void ask(int u, int l, int r, ll v)
	{
		if(l==r)
		{
			if(v>mn[u]) ret+=mn[u], pos=l;
			return;
		}
		int mid=(l+r)>>1;
		pushdown(u, l, r);
		if(mn[rs]>=v) ask(ls, l, mid, v);
		else ret+=sum[ls], ask(rs, mid+1, r, v);
	}
	void add(int u, int l, int r, int l1, int r1, ll v)
	{
		if(l1<=l&&r<=r1) { addp(u, l, r, v); return; }
		int mid=(l+r)>>1;
		pushdown(u, l, r);
		if(l1<=mid) add(ls, l, mid, l1, r1, v);
		if(r1>mid) add(rs, mid+1, r, l1, r1, v);
		upt(u);
	}
}
using namespace SGT;
int main()
{
	scanf("%d%d%d", &m, &n, &q);
	for(int i=0; i<m; ++i) scanf("%lld", b+i);
	for(int i=0; i<n; ++i) scanf("%lld", a+i), cans+=a[i];
	--n, --m;
	for(int i=n; i; --i) a[i]-=a[i-1];
	for(int i=m; i; --i) b[i]-=b[i-1];
	build(1, 1, n);
	for(int i=1, tp, k, d; i<=q; ++i)
	{
		scanf("%d%d%d", &tp, &k, &d);
		if(tp==2)
		{
			add(1, 1, n, std::max(1, n-k+1), n, d);
			int l=std::min(k, n);
			cans+=calc(l)*d;
			if(n-k+1==0) a[0]+=d, cans+=1ll*d*(n+1);
		}
		else
		{
			for(int i=m-k+1; i<=m; ++i) b[i]+=d;
		}
		ll cs=a[0]+b[0], ans=cans+b[0]*(n+1);
		for(int i=1; i<=m; ++i)
		{
			pos=ret=0;
			ask(1, 1, n, b[i]);
			ans+=ret+cs+b[i]*(n-pos+1);
			cs+=b[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
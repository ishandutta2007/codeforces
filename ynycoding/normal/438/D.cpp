#include <cstdio>
#include <algorithm>
#define ll long long
#define N 100005
int n, m, a[N];
#define lid (id<<1)
#define rid (id<<1|1)
int mx[N<<2], mn[N<<2], tagv[N<<2];
ll sum[N<<2];
inline void gval(int id, int v, int len)
{
	mx[id]=v, mn[id]=v, tagv[id]=v, sum[id]=1ll*len*v;
}
inline void upt(int id)
{
	mn[id]=std::min(mn[lid], mn[rid]), mx[id]=std::max(mx[lid], mx[rid]), sum[id]=sum[lid]+sum[rid];
}
inline void pushdown(int id, int l, int r)
{
	int mid=(l+r)>>1;
	if(tagv[id])
	{
		gval(lid, tagv[id], mid-l+1), gval(rid, tagv[id], r-mid);
		tagv[id]=0;
	}
}
void build(int id, int l, int r)
{
	if(l==r)
	{
		mx[id]=mn[id]=sum[id]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lid, l, mid), build(rid, mid+1, r);
	upt(id);
}
void cov(int id, int l, int r, int l1, int r1, int v)
{
	if(l1<=l&&r<=r1) { gval(id, v, 1); return; }
	pushdown(id, l, r);
	int mid=(l+r)>>1;
	if(r1<=mid) cov(lid, l,  mid, l1, r1, v);
	else if(l1>mid) cov(rid, mid+1, r, l1, r1, v);
	else cov(lid, l, mid, l1, r1, v), cov(rid, mid+1, r, l1, r1, v);
	upt(id);
}
void perf(int id, int l, int r, int l1, int r1, int v)
{
	if(l1<=l&&r<=r1&&mx[id]<v) return;
	if(l==r) { gval(id, mx[id]%v, 1); return; }
	pushdown(id, l, r);
	int mid=(l+r)>>1;
	if(r1<=mid) perf(lid, l,  mid, l1, r1, v);
	else if(l1>mid) perf(rid, mid+1, r, l1, r1, v);
	else perf(lid, l, mid, l1, r1, v), perf(rid, mid+1, r, l1, r1, v);
	upt(id);
}
ll ask(int id, int l, int r, int l1, int r1)
{
	if(l1<=l&&r<=r1) return sum[id];
	pushdown(id, l, r);
	int mid=(l+r)>>1;
	if(r1<=mid) return ask(lid, l, mid, l1, r1);
	if(l1>mid) return ask(rid, mid+1, r, l1, r1);
	return ask(lid, l, mid, l1, r1)+ask(rid, mid+1, r, l1, r1);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	build(1, 1, n);
	for(int i=1, t, l, r, x; i<=m; ++i)
	{
		scanf("%d%d%d", &t, &l, &r);
		if(t==2) scanf("%d", &x), perf(1, 1, n, l, r, x);
		if(t==3) cov(1, 1, n, l, l, r);
		if(t==1) printf("%lld\n", ask(1, 1, n, l, r));
	}
	return 0;
}
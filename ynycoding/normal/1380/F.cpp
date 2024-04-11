#include <cstdio>
#include <algorithm>
#define MOD 998244353
#define N 500005
int n, m, a[N];
char c[N];
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int gn1(int x) { return a[x]+1; }
inline int gn2(int x) { return (x<n&&a[x]==1)?9-a[x+1]:0; }
namespace sgt{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int f[N<<2][4]; //0 [] 1 [) 2 (] 3 ()
	void merge(int *a, int *b, int *c, int t)
	{
		c[0]=mval(1ll*a[0]*b[0]%MOD+1ll*a[1]*b[2]%MOD*t%MOD);
		c[1]=mval(1ll*a[0]*b[1]%MOD+1ll*a[1]*b[3]%MOD*t%MOD);
		c[2]=mval(1ll*a[2]*b[0]%MOD+1ll*a[3]*b[2]%MOD*t%MOD);
		c[3]=mval(1ll*a[2]*b[1]%MOD+1ll*a[3]*b[3]%MOD*t%MOD);
	}
	void update(int id, int mid) { merge(f[lid], f[rid], f[id], gn2(mid)); }
	void build(int id, int l, int r)
	{
		if(l==r) { f[id][0]=gn1(l), f[id][1]=f[id][2]=1; return; }
		int mid=(l+r)>>1;
		build(lid, l, mid), build(rid, mid+1, r);
		update(id, mid);
	}
	void modify(int id, int l, int r, int p, int x)
	{
		if(l==r) { a[l]=x, f[id][0]=gn1(l), f[id][1]=f[id][2]=1; return; }
		int mid=(l+r)>>1;
		if(p>mid) modify(rid, mid+1, r, p, x);
		else modify(lid, l, mid, p, x);
		update(id, mid);
	}
}
using namespace sgt;
int main()
{
	scanf("%d%d%s", &n, &m, c+1);
	for(int i=1; i<=n; ++i) a[i]=c[i]-'0';
	build(1, 1, n);
	for(int i=1, x, d; i<=m; ++i)
	{
		scanf("%d%d", &x, &d);
		modify(1, 1, n, x, d);
		printf("%d\n", f[1][0]);
	}
	return 0;
}
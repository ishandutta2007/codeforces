#include <cstdio>
#include <algorithm>
#define ld double
using std::pair;
const int N=200005;
int x, y;
struct mat{
	ld v[3][3];
	mat operator +(const mat &x)
	{
		mat ret;
		for(int i=0; i<3; ++i) for(int j=0; j<3; ++j)
		{
			ret.v[i][j]=std::max({v[i][0]+x.v[0][j], v[i][1]+x.v[1][j], v[i][2]+x.v[2][j]});
		}
		return ret;
	}
	inline void set(int c)
	{
		for(int i=0; i<3; ++i) std::fill(v[i], v[i]+3, -1e9);
		v[0][0]=v[1][0]=v[2][0]=0;
		v[0][1]=v[1][1]=(ld)c/(x+y);
		v[0][2]=(ld)c/y;
	}
};
mat ret;
int a[N];
namespace SGT{
	#define ls (u<<1)
	#define rs (u<<1|1)
	mat sum[N<<2];
	inline void upt(int u)
	{
		sum[u]=sum[ls]+sum[rs];
	}
	void build(int u, int l, int r)
	{
		if(l==r)
		{
			sum[u].set(a[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r);
		upt(u);
	}
	void add(int u, int l, int r, int p, int x)
	{
		if(l==r)
		{
			sum[u].set(x);
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid) add(ls, l, mid, p, x);
		else add(rs, mid+1, r, p, x);
		upt(u);
	}
	void ask(int u, int l, int r, int l1, int r1)
	{
		if(l1<=l&&r<=r1)
		{
			ret=ret+sum[u];
			return;
		}
		int mid=(l+r)>>1;
		if(l1<=mid) ask(ls, l, mid, l1, r1);
		if(r1>mid) ask(rs, mid+1, r, l1, r1);
	}
}
using namespace SGT;
int n, q;
int main()
{
	scanf("%d%d", &n, &q);
	scanf("%d%d", &x, &y);
	if(x>y) std::swap(x, y);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	build(1, 1, n);
	for(int i=1, tp, x, y; i<=q; ++i)
	{
		scanf("%d%d%d", &tp, &x, &y);
		if(tp==1) add(1, 1, n, x, y);
		else
		{
			ret.v[0][0]=ret.v[0][1]=ret.v[0][2]=0;
			ask(1, 1, n, x, y);
			printf("%.10lf\n", std::max({ret.v[0][0], ret.v[0][1], ret.v[0][2]}));
		}
	}
	return 0;
}
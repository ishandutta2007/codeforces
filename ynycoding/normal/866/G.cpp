#include <cstdio>
#include <vector>
#include <algorithm>
#define N 105
#define ll long long
using std::vector;
typedef vector<int> poly;
const int MOD=1000000007;
int n, m, a[N], b[N], mx;
ll k;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=mval(MOD+x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
poly add(const poly &a, const poly &b)
{
	poly ret(std::max(a.size(), b.size()));
	for(int i=0; i<ret.size(); ++i) ret[i]=mval((i>=a.size()?0:a[i])+(i>=b.size()?0:b[i]));
	return ret;
}
poly mul(const poly &a, const poly &b)
{
	poly ret(a.size()+b.size()-1);
	for(int i=0; i<a.size(); ++i) for(int j=0; j<b.size(); ++j)
		inc(ret[i+j], 1ll*a[i]*b[j]%MOD);
	return ret;
}
poly mod(poly a, const poly &b)
{
	if(a.size()<b.size()) return a;
	int iv=qpow(b[b.size()-1], MOD-2);
	for(int i=a.size()-1; i>=b.size()-1; --i)
	{
		int ml=1ll*a[i]*iv%MOD;
		for(int x=i, y=b.size()-1; ~y; --x, --y) dec(a[x], 1ll*b[y]*ml%MOD);
	}
	a.resize(b.size()-1);
	return a;
}
poly qp(poly x, poly m, ll p)
{
	poly ret(1);
	ret[0]=1;
	while(p)
	{
		if(p&1) ret=mul(ret, x), ret=mod(ret, m);
		p>>=1;
		x=mul(x, x), x=mod(x, m);
	}
	return ret;
}
poly f, g, h;
int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=m; ++i) scanf("%d", b+i), mx=std::max(mx, b[i]);
	f.resize(mx+1);
	for(int i=1; i<=m; ++i) dec(f[b[i]], 1);
	std::reverse(f.begin(), f.end());
	inc(f[mx], 1);
	poly t(2);
	t[1]=1;
	for(int i=1; i<=n; ++i)
	{
		g=add(g, qp(t, f, a[i]));
	}
	h=qp(g, f, k);
	t.clear();
	t.resize(mx);
	t[mx-1]=1;
	h=mul(h, t);
	h=mod(h, f);
	printf("%d\n", h[mx-1]);
	return 0;
}
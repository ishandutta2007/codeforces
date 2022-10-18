#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
using std::vector;
typedef vector<int> poly;
const int N=800005, MOD=998244353, iv2=MOD/2+1;

inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

namespace Poly{
	namespace Poly_Basic{
		inline void print(const poly &a) { for(int x:a) printf("%d ", x); puts(""); }
		inline poly to_poly(int *a, int n) { poly ret; ret.resize(n); memcpy((int*)&ret[0], a, sizeof(int)*n); return ret; }
		inline poly slice(const poly &a, int s, int t)
		{ poly ret(t-s); memcpy((int*)&ret[0], (int*)&a[s], sizeof(int)*(t-s)); return ret; }
		inline poly add(const poly &a, const poly &b)
		{
			poly ret(std::max(a.size(), b.size()));
			for(int i=0; i<ret.size(); ++i) ret[i]=mval((i<a.size()?a[i]:0)+(i<b.size()?b[i]:0));
			return ret;
		}
		inline void add_to(poly &a, const poly &b)
		{
			if(a.size()<b.size()) a.resize(b.size());
			for(int i=0; i<b.size(); ++i) inc(a[i], b[i]);
		}
		inline poly neg(poly a)
		{
			for(int i=0; i<a.size(); ++i) a[i]=MOD-a[i];
			return a;
		}
		inline poly mul(poly a, int x)
		{
			for(int i=0; i<a.size(); ++i) a[i]=1ll*a[i]*x%MOD;
			return a;
		}
		inline void mul_val(poly &a, int x)
		{
			for(int i=0; i<a.size(); ++i) a[i]=1ll*a[i]*x%MOD;
		}
	}
	using namespace Poly_Basic;
	namespace NTT{
		const int g=3;
		int A[N], B[N], C[N], rev[N], wn[N], up=1;
		inline int glim(int n)
		{
			int l=0;
			while(n) n>>=1, ++l;
			return l;
		}
		inline void init(int l)
		{
			for(int i=1; i<(1<<l); ++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
			for(int i=up; i<(1<<l); i<<=1)
			{
				wn[i]=1;
				int mw=qpow(g, (MOD-1)/(i<<1));
				for(int j=1; j<i; ++j) wn[i+j]=1ll*wn[i+j-1]*mw%MOD;
			}
			if((1<<l)>up) up=(1<<l);
		}
		inline void ntt(int *f, int n, int mod)
		{
			for(int i=0; i<n; ++i) if(i<rev[i]) std::swap(f[i], f[rev[i]]);
			for(int len=2; len<=n; len<<=1)
			{
				int c=len>>1;
				for(int i=0; i<n; i+=len) for(int j=i; j<i+c; ++j)
				{
					int x=f[j], y=1ll*f[j+c]*wn[c+j-i]%MOD;
					f[j]=mval(x+y), f[j+c]=mval(MOD+x-y);
				}
			}
			if(mod)
			{
				std::reverse(f+1, f+n);
				int iv=qpow(n, MOD-2);
				for(int i=0; i<n; ++i) f[i]=1ll*f[i]*iv%MOD;
			}
		}
		template <class _T, class _T1, class _T2> inline void mul(const _T &a, const _T1 &b, _T2 &c, int n, int m)
		{
			int l=glim(n+m);
			init(l);
			memcpy(A, (int*)&a[0], sizeof(int)*(n+1));
			memcpy(B, (int*)&b[0], sizeof(int)*(m+1));
			std::fill(A+n+1, A+(1<<l)+1, 0);
			std::fill(B+m+1, B+(1<<l)+1, 0);
			ntt(A, (1<<l), 0), ntt(B, (1<<l), 0);
			for(int i=0; i<(1<<l); ++i) C[i]=1ll*A[i]*B[i]%MOD;
			ntt(C, (1<<l), 1);
			memcpy((int*)&c[0], C, sizeof(int)*(n+m+1));
		}
		inline poly mul(const poly &a, const poly &b)
		{
			if(!a.size()||!b.size()) return poly(0);
			poly ret(a.size()+b.size()-1);
			mul(a, b, ret, a.size()-1, b.size()-1);
			return ret;
		}
	}
	using NTT::init;
	using NTT::ntt;
	using NTT::glim;
	using NTT::mul;
}
using namespace Poly;

int n, k, inv[N], fac[N], a[N], val[N], sz[N], ans, tp;
int f[N], s[N];
vector<int> e[N];
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
poly g[N<<2], h[N<<2];
#define lid (id<<1)
#define rid (id<<1|1)
void solve(int id, int l, int r)
{
	if(l>r) { g[id]=poly{1}, h[id].clear(); return; }
	if(l==r)
	{
		g[id]=poly{1, a[l]};
		h[id]=poly{val[l]};
		return;
	}
	int mid=(l+r)>>1;
	solve(lid, l, mid);
	solve(rid, mid+1, r);
	g[id]=mul(g[lid], g[rid]);
	h[id]=add(mul(g[lid], h[rid]), mul(h[lid], g[rid]));
}
void dfs(int u, int fa)
{
	for(int v:e[u]) if(v!=fa)
		dfs(v, u);
	tp=0;
	sz[u]=1;
	for(int v:e[u]) if(v!=fa)
	{
		inc(ans, 1ll*s[u]*s[v]%MOD);
		inc(s[u], s[v]);
		sz[u]+=sz[v];
		a[++tp]=sz[v];
		val[tp]=s[v];
	}
	int res=0;
	poly &g=::g[1], &h=::h[1];
	solve(1, 1, tp);
	h.pb(0);
	for(int i=tp-1; ~i; --i) inc(h[i+1], 1ll*h[i]*(n-sz[u])%MOD);
	for(int i=0; i<=std::min(tp, k); ++i) inc(f[u], 1ll*fac[i]%MOD*C(k, i)%MOD*g[i]%MOD);
	inc(s[u], f[u]);
	for(int i=0; i<=std::min(tp, k); ++i) inc(res, 1ll*fac[i]%MOD*C(k, i)%MOD*h[i]%MOD);
	inc(ans, res);
}
int main()
{
	scanf("%d%d", &n, &k);
	if(k==1) return printf("%lld\n", 1ll*n*(n-1)/2%MOD), 0;
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=std::max(n, k); ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1; i<=std::max(n, k); ++i) inv[i]=1ll*inv[i-1]*inv[i]%MOD, fac[i]=1ll*fac[i-1]*i%MOD;
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
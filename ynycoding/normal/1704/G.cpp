#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
const int N=800005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

namespace Poly{
	const int g=3;
	int rev[N];
	int F[N], G[N], wn[N];
	inline int glim(int n)
	{
		int l=0;
		while(n) n>>=1, ++l;
		return l;
	}
	inline void init(int l)
	{
		int n=1<<l;
		for(int i=1; i<n; ++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=1; i<n; i<<=1)
		{
			wn[i]=1;
			int ml=qpow(g, (MOD-1)/(i*2));
			for(int j=1; j<i; ++j) wn[i+j]=1ll*wn[i+j-1]*ml%MOD;
		}
	}
	void NTT(int *f, int l, int mod)
	{
		int n=1<<l;
		for(int i=1; i<n; ++i) if(rev[i]<i) std::swap(f[rev[i]], f[i]);
		for(int len=2; len<=n; len<<=1)
		{
			int mid=len>>1;
			for(int i=0; i<n; i+=len) for(int j=i; j<i+mid; ++j)
			{
				int x=f[j], y=1ll*f[j+mid]*wn[j-i+mid]%MOD;
				f[j]=mval(x+y), f[j+mid]=fix(x-y);
			}
		}
		if(mod)
		{
			std::reverse(f+1, f+n);
			int iv=qpow(n, MOD-2);
			for(int i=0; i<n; ++i) f[i]=1ll*f[i]*iv%MOD;
		}
	}
	void mul(int *A, int *B, int *C, int n, int m)
	{
		int l=glim(n+m);
		init(l);
		std::fill(F, F+(1<<l), 0);
		std::fill(G, G+(1<<l), 0);
		std::copy(A, A+n+1, F);
		std::copy(B, B+m+1, G);
		NTT(F, l, 0), NTT(G, l, 0);
		for(int i=0; i<(1<<l); ++i) F[i]=1ll*F[i]*G[i]%MOD;
		NTT(F, l, 1);
		std::copy(F, F+n+m+1, C);
	}
}
using Poly::mul;
int T, n, m, b[N], tot;
ll a[N];
int f[N], g[N], sum[N], h[N], ban[N], rf[N], rg[N];
int is[N];
inline ll calc(int x) { return 1ll*x*(x+1)/2; }
inline bool cons(int p, int dt, ll val, int typ=0)
{
	// printf("val %d\n", val);
	int c=(p+1)/2;
	// printf("c %d\n", c);
	int x=(dt+c)/2, y=x-dt;
	ll l=calc(y-1)*2+y-(calc((p-1)/2)-calc((p-1)/2-x))*2;
	// printf("xy %d %d\n", x, y);
	c=p/2+1;
	x=(dt+c)/2, y=x-dt;
	ll r=(calc(p/2-1)-calc(p/2-1-y))*2+y-calc(x-1)*2;
	// printf("lr %lld %lld\n", l, r);
	// printf("xy %d %d\n", x, y);
	if(val<l||val>r) return 0;
	if(!typ) return 1;
	// printf("cons %d %d %lld\n", p, dt, val);
	std::fill(is, is+p+1, 0);
	for(int i=0; i<2*x; i+=2) is[i]=1;
	for(int i=0; i<y; ++i) is[p-1-(p&1)-i*2]=1;
	int t=2*x-2;
	val=r-val;
	// printf("r %d\n", r);
	for(int i=(p-1)/2*2; i>0&&t>=0; i-=2) if(!is[i])
	{
		if(val>=(i-t)) is[t]=0, is[i]=1, val-=(i-t), t-=2;
	}
	// printf("res %d\n", val);
	t=p-1-(p&1)-(y-1)*2;
	// printf("t %d\n", t);
	for(int i=1; i<p&&t<p; i+=2) if(!is[i])
	{
		// printf("t %d %d\n", i, t);
		if(val>=(t-i)) is[t]=0, is[i]=1, val-=(t-i), t+=2;
	}
	// for(int i=0; i<p; ++i) printf("%d ", is[i]);
	// puts("");
	// for(int i=0; i<=p; ++i) printf("%d ", is[i]);
	// puts("");
	if(val)
	{
		for(int i=1; i<p; i+=2) if(is[i]&&is[i-1])
		{
			is[i]=is[i-1]=0;
			--val;
			break;
		}
	}
	if(val)
	{
		for(int i=2; i<p; i+=2) if(!is[i]&&!is[i-1])
		{
			is[i]=is[i-1]=1;
			--val;
			break;
		}
	}
	// printf("res %d\n", val);
	// for(int i=0; i<p; ++i) printf("%d ", is[i]);
	// puts("");
	return 1;
}
int rok[N];
inline void work(int i)
{
	for(int j=1; j+i-1<=m; ++j) (j&1)?b[i+j-1]+=j:b[i+j-1]-=j;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &m);
		for(int i=1; i<=m; ++i) scanf("%d", b+i);
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%lld", a+i);
		tot=0;
		for(int i=1; i<=n-2; ++i)
		{
			if(std::abs(a[i+1]*2+a[i]+a[i+2])>2e6) { puts("-1"); goto out; }
			rf[i]=(a[i+1]*2+a[i]+a[i+2])*2-1;
			f[i]=fix(rf[i]);
			inc(tot, 1ll*f[i]*f[i]%MOD);
		}
		for(int i=1; i<=m-2; ++i)
		{
			rg[i]=(b[i+1]*2+b[i]+b[i+2])*2;
			g[i]=fix(rg[i]%MOD);
			sum[i]=(sum[i-1]+1ll*g[i]*g[i])%MOD;
		}
		f[0]=0;
		// for(int i=1; i<m-1; ++i) printf("%d ", rg[i]);
		// puts("");
		// for(int i=1; i<n-1; ++i) printf("%d ", rf[i]);
		// puts("");
		std::reverse(f, f+n-1);
		std::reverse(rf, rf+n-1);
		mul(f, g, h, n-2, m-2);
		for(int i=1; i+n-1<=m; ++i)
		{
			int p=i+n-3;
			if((1ll*tot+sum[p]+3ll*MOD-sum[p-(n-2)]-2*h[p])%MOD==n-2)
			{
				// printf("ok %d\n", i);
				ll dt=a[1]+a[2]-b[i]-b[i+1];
				if(dt>i/2+1||dt<-((i+1)/2)) continue;
				if(!cons(i+1, dt, a[1]-b[i], 0)) continue;
				cons(i+1, dt, a[1]-b[i], 1);
				std::fill(rok, rok+m+1, 0);
				int k=0;
				for(int j=0; j<=i+1; ++j) rok[i-j+1]=is[j];
				for(int j=i; j<=p; ++j) rok[j+2]=rg[j]<rf[p-j];
				for(int i=1; i<=m; ++i) k+=rok[i];
				// printf("i %d\n", i);
				printf("%d\n", k);
				for(int i=1; i<=m; ++i) if(rok[i]) printf("%d ", i);//, work(i);
				puts("");
				// for(int i=1; i<=m; ++i) printf("%d ", b[i]);
				// puts("");
				// for(int j=1; j<=n; ++j) if(a[j]!=b[i+j-1]) { printf("WA %d\n", _tt); exit(114); }
				goto out;
			}
		}
		// printf("WA %d\n", _tt);
		// exit(114);
		puts("-1");
		out:;
	}
	return 0;
}
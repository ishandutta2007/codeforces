#include <cstdio>
#include <vector>
#include <algorithm>
#define ull unsigned long long
#define pb push_back
using std::vector;
typedef vector<int> poly;
const int N=800005, MOD=998244353, iv2=MOD/2+1;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

namespace Poly{
	const int g=3;
	int rev[N], wn[N], tp=1;
	inline int glim(int n)
	{
		int l=0;
		while((1<<l)<=n) ++l;
		return l;
	}
	inline void init(int l)
	{
		int n=1<<l;
		for(int i=0; i<n; ++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=tp; i<=n; i<<=1, tp=i)
		{
			wn[i]=1;
			int mul=qpow(g, (MOD-1)/(i<<1));
			for(int j=1; j<i; ++j) wn[i+j]=1ll*wn[i+j-1]*mul%MOD;
		}
	}
	inline void NTT(int *f, int l, int tp)
	{
		int n=1<<l;
		for(int i=0; i<n; ++i) if(i<rev[i]) std::swap(f[i], f[rev[i]]);
		for(int len=2; len<=n; len<<=1)
		{
			int mid=len>>1;
			for(int i=0; i<n; i+=len) for(int j=i; j<i+mid; ++j)
			{
				int x=f[j], y=1ll*wn[j+mid-i]*f[j+mid]%MOD;
				f[j]=mval(x+y), f[j+mid]=fix(x-y);
			}
		}
		if(tp)
		{
			int iv=qpow(n, MOD-2);
			std::reverse(f+1, f+n);
			for(int i=0; i<n; ++i) f[i]=1ll*f[i]*iv%MOD;
		}
	}
	poly mul(const poly &f, const poly &g)
	{
		static int A[N], B[N];
		int n=f.size()-1, m=g.size()-1, l=glim(n+m);
		init(l);
		std::fill(A, A+(1<<l), 0);
		std::fill(B, B+(1<<l), 0);
		std::copy(f.data(), f.data()+n+1, A);
		std::copy(g.data(), g.data()+m+1, B);
		NTT(A, l, 0), NTT(B, l, 0);
		for(int i=0; i<(1<<l); ++i) A[i]=1ll*A[i]*B[i]%MOD;
		NTT(A, l, 1);
		poly ret(n+m+1);
		std::copy(A, A+n+m+1, ret.data());
		return ret;
	}
}
using Poly::mul;
int n, m, a[N], is[N], pref[N], suf[N], cnt[N], ans;
void solve(int l, int r)
{
	if(l==r) return;
	int mid=(l+r)>>1, len=mid-l+1;
	poly lf(len), rt(len);
	for(int i=l; i<=mid; ++i) lf[i-l]=pref[i];
	for(int i=mid+1; i<=r; ++i) rt[i-mid-1]=suf[i];
	lf=mul(lf, rt);
	for(int i=(l+mid+1)&1; i<lf.size(); i+=2)
	{
		int p=(i+l+mid+1)>>1;
		inc(cnt[p], lf[i]);
	}
	solve(l, mid), solve(mid+1, r);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1, x; i<=m; ++i) scanf("%d", &x), is[x]=1;
	pref[0]=1;
	for(int i=1; i<=n; ++i) pref[i]=1ll*pref[i-1]*(is[i]+1)%MOD;
	suf[n+1]=1;
	for(int i=n; i; --i) suf[i]=1ll*suf[i+1]*(is[i]+1)%MOD;
	solve(1, n);
	for(int i=1; i<=n; ++i) inc(pref[i], pref[i-1]);
	for(int i=n; i; --i) inc(suf[i], suf[i+1]);
	for(int i=1; i<=n; ++i)
	{
		if(i*2<=n+1)
		{
			int len=i-1;
			inc(cnt[i], suf[i+len+1]);
		}
		else
		{
			int len=n-i;
			inc(cnt[i], pref[i-len-1]);
		}
		int len=std::max(n-i, i-1);
		dec(cnt[i], len+1);
		inc(ans, 1ll*cnt[i]*a[i]%MOD);
	}
	printf("%d\n", 1ll*ans*qpow(qpow(2, m)-1, MOD-2)%MOD);
	return 0;
}
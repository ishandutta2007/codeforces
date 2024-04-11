#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
typedef vector<int> poly;
const int N=205, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*p%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, k, inv[N];
inline void prt(const poly &a) { for(int x:a) printf("%d ", x); puts(""); }
poly mul(const poly &A, const poly &B)
{
	poly ret(std::min((int)(A.size()+B.size()-1), k+1));
	for(int i=0; i<A.size(); ++i) for(int j=0; j+i<=k&&j<B.size(); ++j)
		inc(ret[i+j], 1ll*A[i]*B[j]%MOD);
	return ret;
}
poly addv(const poly &A, int l, int v)
{
	poly ret(A.size());
	for(int i=0; i<A.size(); ++i)
	{
		for(int j=0, cur=1; j+i<A.size(); ++j, cur=1ll*v*cur%MOD*(l-i-j+1)%MOD*inv[j]%MOD)
		{
			inc(ret[i+j], 1ll*A[i]*cur%MOD);
		}
	}
//	printf("adv %d %d\n", l, v);
//	prt(A);
//	prt(ret);
	return ret;
}
poly solve(int len)
{
	if(len==1) { return poly{1, 0}; }
	int l=len>>1;
	poly t=solve(l);
	t=mul(t, addv(t, l, l));
	if(len&1)
	{
		t.pb(0);
		for(int i=t.size()-2; ~i; --i)
			inc(t[i+1], 1ll*t[i]*(len-1)%MOD);
		if(t.size()>k+1) t.pop_back();
	}
	return t;
}
int main()
{
	scanf("%d%d", &n, &k);
	inv[0]=inv[1]=1;
	for(int i=2; i<=k; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	poly t=solve(n);
//	prt(t);
	for(int i=1, cur0=0, cur1=1; i<=k; ++i)
	{
		if(t.size()>i) inc(cur0, t[i]);
		printf("%d ", cur0);
		std::swap(cur0, cur1);
	}
	return 0;
}
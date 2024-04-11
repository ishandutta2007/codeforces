#include <cstdio>
#include <algorithm>
#define ll long long
const int N=1005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, m, a[N], tot;
ll f1=1, f2=1, d, ca;
int main()
{
	scanf("%d", &m);
	if(m==1) return puts("0"), 0;
	for(int i=1; i<=m; ++i) scanf("%d", a+i), n+=a[i];
	std::sort(a+1, a+m+1);
	for(int i=0, j=1; i<n; ++i)
	{
		f1=f1*(2*n-i)%MOD, f2=f2*(n-i)%MOD;
		d=(d*(n-i)+f1)%MOD;
		ca=ca*(n-i)%MOD;
		while(j<=m&&a[j]==i+1) ca=mval(ca+d), ++j;
	}
	printf("%d\n", (d-ca+MOD)*qpow(f2, MOD-2)%MOD);
	return 0;
}
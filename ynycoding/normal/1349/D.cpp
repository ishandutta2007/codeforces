#include <cstdio>
#include <algorithm>
#define N 300005
const int MOD=998244353;
int n, a[N], f[N][2], x[N][3], tot, ivn, ivt;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void upt(int &x, int a) { x=mval(x+a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
inline int inv(int x) { return qpow(x, MOD-2); }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), tot+=a[i];
	ivn=inv(n-1), ivt=inv(tot);
	f[1][1]=1;
	for(int i=0; i<tot; ++i)
	{
		x[i][0]=1ll*ivt*i%MOD;
		x[i][1]=1ll*ivn*ivt%MOD*(tot-i)%MOD*(n-2)%MOD;
		x[i][2]=1ll*ivn*ivt%MOD*(tot-i)%MOD;
		if((1ll*x[i][0]+x[i][1]+x[i][2])%MOD!=1) puts("fa");
	}
	int t=inv(mval(MOD+1-x[0][1]));
	f[0][0]=t, f[0][1]=1ll*t*x[0][2]%MOD;
	for(int i=1; i<tot; ++i)
	{
		int t=mval(x[i][1]+1ll*f[i-1][1]*x[i][0]%MOD);
		t=inv(mval(MOD+1-t));
		f[i][1]=1ll*x[i][2]*t%MOD, f[i][0]=1ll*(1ll*x[i][0]*f[i-1][0]%MOD+1)*t%MOD;
	}
	for(int i=tot-2; ~i; --i) upt(f[i][0], 1ll*f[i][1]*f[i+1][0]%MOD);
	int ans=0;
	for(int i=1; i<=n; ++i) upt(ans, f[a[i]][0]);
	upt(ans, MOD-1ll*f[0][0]*(n-1)%MOD);
	printf("%d\n", 1ll*ans*inv(n)%MOD);
	return 0;
}
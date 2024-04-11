#include <cstdio>
#include <algorithm>
const int N=50005, K=25, MOD=998244353;
int n, m, cnt[N], dw[K][K], mul=1, ans;
int d[N][21];
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
		scanf("%d", d[j]+i);
	for(int i=0; i<=n; ++i)
	{
		dw[i][0]=1;
		for(int j=1; j<=i; ++j) dw[i][j]=1ll*dw[i][j-1]*(i-j+1)%MOD;
	}
	for(int i=1; i<=n; ++i) mul=1ll*mul*qpow(i, MOD-2)%MOD;
	for(int i=1; i<=m; ++i)
	{
		std::fill(cnt+1, cnt+n+2, 0);
		for(int j=1; j<=n; ++j) ++cnt[d[i][j]];
		int ret=mul;
		for(int j=1, pre=0; j<=n+1; ++j)
		{
			if(pre+cnt[j]>=j) { ret=0; break; }
			ret=1ll*ret*dw[j-pre-1][cnt[j]]%MOD;
			pre+=cnt[j];
		}
		ret=fix(1-ret);
		inc(ans, ret);
	}
	printf("%d\n", ans);
	return 0;
}
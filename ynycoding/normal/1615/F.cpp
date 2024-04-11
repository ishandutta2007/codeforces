#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=2005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int T, n, f[N][N<<1], g[N][N<<1], off;
char s[N], t[N];
void solve(int f[][N<<1], int tp)
{
	std::fill(f[0], f[0]+2*n+1, 0);
	f[0][off]=1;
	for(int i=1; i<=n; ++i)
	{
		std::fill(f[i], f[i]+2*n+1, 0);
		int x0=(s[i]=='?'||s[i]=='0'), y0=(t[i]=='?'||t[i]=='0');
		int x1=(s[i]=='?'||s[i]=='1'), y1=(t[i]=='?'||t[i]=='1');
		int c0=x0*y0+x1*y1, c1=x1*y0, cn1=x0*y1;
		int t0=0, t1=((i+tp)&1)?-1:1, tn1=((i+tp)&1)?1:-1;
		for(int j=-i; j<=i; ++j)
		{
			inc(f[i][j+t0+off], 1ll*f[i-1][j+off]*c0%MOD);
			(c1?inc(f[i][j+t1+off], f[i-1][j+off]), 0:0);
			(cn1?inc(f[i][j+tn1+off], f[i-1][j+off]), 0:0);
		}
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s%s", &n, s+1, t+1);
		off=n;
		solve(f, 0);
		std::reverse(s+1, s+n+1);
		std::reverse(t+1, t+n+1);
		solve(g, n+1);
		int ans=0;
		for(int i=1; i<n; ++i) for(int j=-i; j<=i; ++j)
			inc(ans, 1ll*f[i][j+off]*g[n-i][-j+off]%MOD*std::abs(j)%MOD);
		printf("%d\n", ans);
	}
	return 0;
}
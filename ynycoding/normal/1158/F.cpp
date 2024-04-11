#include <cstdio>
#include <algorithm>
const int N=3005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; x=1ll*x*x%MOD, p>>=1; } return ret; }


int n, c, a[N], ans[N], pw[N], f[N][N];
namespace SUB1{
	int mul[N][N], cur[N], tc, ml[N], iml[N];
	void solve(void)
	{
		for(int i=1; i<=n; ++i) ml[i]=fix(pw[i]-1), iml[i]=qpow(ml[i], MOD-2);
		iml[0]=1;
		for(int i=1; i<=n; ++i)
		{
			tc=0;
			std::fill(cur+1, cur+c+1, 0);
			cur[a[i]]=1, tc=1;
			for(int j=i-1, cm=1; j; --j)
			{
				tc+=!(cur[a[j]]++);
				if(a[j]!=a[i]) cm=1ll*cm*iml[cur[a[j]]-1]%MOD*ml[cur[a[j]]]%MOD;
				if(tc==c)
				{
					mul[j][i]=cm;
				}
			}
		}
		ans[0]=fix(pw[n]-1);
		f[0][0]=1;
		for(int i=1; i*c<=n; ++i)
		{
			for(int j=0; j<=n; ++j) if(f[i-1][j])
			{
				for(int k=j+c; k<=n; ++k)
				{
					inc(f[i][k], 1ll*mul[j+1][k]*f[i-1][j]%MOD);
				}
			}
			for(int j=1; j<=n; ++j) inc(ans[i], 1ll*f[i][j]*pw[n-j]%MOD);
		}
	}
}
namespace SUB2{
	const int C=12;
	int f[N][N], g[N][1<<C];
	void solve(void)
	{
		f[0][0]=1;
		ans[0]=fix(pw[n]-1);
		for(int i=1; i*c<=n; ++i)
		{
			std::fill(g[0], g[0]+(1<<c), 0);
			for(int j=0; j<=n; ++j)
			{
				if(j) std::copy(g[j-1], g[j-1]+(1<<c), g[j]);
				g[j][(1<<c)-1]=0;
				if(j) for(int s=0; s<(1<<c); ++s) inc(g[j][s|(1<<(a[j]-1))], g[j-1][s]);
				if(j) f[i][j]=g[j-1][((1<<c)-1)^(1<<(a[j]-1))];
				inc(g[j][0], f[i-1][j]);
				//printf("%d %d %d %d %d\n", i, j, f[i][j], g[j][((1<<c)-1)^1], g[j][((1<<c)-1)]);
				inc(ans[i], 1ll*f[i][j]*pw[n-j]%MOD);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &c);
	pw[0]=1;
	for(int i=1; i<=n; ++i) scanf("%d", a+i), pw[i]=2ll*pw[i-1]%MOD;
	if(c>10) SUB1::solve();
	else SUB2::solve();
	for(int i=0; i<=n; ++i) printf("%d\n", fix(ans[i]-ans[i+1]));
	return 0;
}
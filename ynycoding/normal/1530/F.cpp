#include <cstdio>
#include <algorithm>
const int N=25, MOD=31607;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=ret*x%MOD; x=x*x%MOD, p>>=1; } return ret; }
int n, a[N][N], iva[N][N], row[N], col[1<<21][21], cur[21], ans, iv=qpow(10000, MOD-2);
inline int calc(int s)
{
	int ret=1;
	for(int i=0; i<n; ++i)
	{
		if(s&(1<<i)) ret=ret*row[i]%MOD;
		else
		{
			if(s&(1<<n)) ret=ret*a[i][i]%MOD;
			if((i*2+1!=n||!(s&(1<<n)))&&(s&(1<<(n+1))))
				ret=ret*a[n-i-1][i]%MOD;
		}
	}
	std::copy(col[s&((1<<n)-1)], col[s&((1<<n)-1)]+n, cur);
	if(s&(1<<n)) for(int i=0; i<n; ++i)
	{
		if(!(s&(1<<i)))
			cur[i]=cur[i]*iva[i][i]%MOD;
	}
	if(s&(1<<(n+1))) for(int i=0; i<n; ++i)
	{
		if(!(s&(1<<(n-i-1)))&&!((s&(1<<n))&&2*i+1==n))
			cur[i]=cur[i]*iva[i][n-i-1]%MOD;
	}
	for(int i=0; i<n; ++i) ret=ret*(MOD+1-cur[i])%MOD;
	return ret;
}
int main()
{
	scanf("%d", &n);
	std::fill(row, row+n, 1);
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
		scanf("%d", a[i]+j), a[i][j]=a[i][j]*iv%MOD, row[j]=row[j]*a[i][j]%MOD, iva[i][j]=qpow(a[i][j], MOD-2);
	for(int i=0; i<n; ++i)
	{
		col[0][i]=1;
		for(int j=0; j<n; ++j) col[0][i]=col[0][i]*a[i][j]%MOD;
	}
	for(int s=1; s<(1<<n); ++s)
	{
		int x=__builtin_ctz(s);
		int t=s^(1<<x);
		if(x<n)
		{
			for(int i=0; i<n; ++i)
			{
				if(!((t&(1<<n))&&x==i)&&!((t&(1<<(n+1)))&&x==(n-i-1)))
					col[s][i]=col[t][i]*iva[i][x]%MOD;
				else col[s][i]=col[t][i];
			}
		}
	}
	for(int s=0; s<(1<<(n+2)); ++s)
		((__builtin_popcount(s)&1)?dec:inc)(ans, calc(s));
	printf("%d\n", fix(1-ans));
	return 0;
}
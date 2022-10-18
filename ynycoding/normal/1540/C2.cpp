#include <cstdio>
#include <algorithm>
const int N=205, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }

int n, q, c[N], b[N], f[N][N*N], lim[N], ans[N], prod=1, lw, up;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", c+i), up=std::max(up, c[i]), prod=1ll*prod*(c[i]+1)%MOD;
	for(int i=2; i<=n; ++i) scanf("%d", b+i), b[i]+=b[i-1], lw+=b[i]-c[i];
	lw-=c[1];
	lw=-((lw+n-1)/n);
	++lw;
	++up;
	for(int x=lw; x>lw-up; --x)
	{
		f[0][0]=1;
		int sum=0;
		for(int i=1; i<=n; ++i)
		{
			int l=-b[i]-x, r=l+c[i];
			lim[i]=std::max(0, lim[i-1]+l);
			if(sum+r<0) { goto out; }
			std::fill(f[i], f[i]+sum+r-lim[i]+1, 0);
			for(int j=std::max(lim[i-1], -r); j<=sum; ++j)
			{
				inc(f[i][std::max(0, j+l-lim[i])], f[i-1][j-lim[i-1]]);
				dec(f[i][j+r+1-lim[i]], f[i-1][j-lim[i-1]]);
			}
			sum+=r;
			for(int j=1; j<=sum-lim[i]+1; ++j) inc(f[i][j], f[i][j-1]);
		}
		for(int j=0; j<=sum-lim[n]; ++j) inc(ans[lw-x], f[n][j]);
		out:;
	}
	scanf("%d", &q);
	for(int i=1, x; i<=q; ++i)
	{
		scanf("%d", &x);
		printf("%d\n", (x>lw?0:x<=lw-up?prod:ans[lw-x]));
	}
	return 0;
}
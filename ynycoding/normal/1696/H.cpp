#include <cstdio>
#include <cstring>
#include <algorithm>
using std::abs;
const int N=605, MOD=1000000007, iv2=MOD/2+1;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, k, a[N], f[N][N][2], g[N][N], h[2][N], ans;
inline int sgn(int x) { return x<0; }
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	std::sort(a+1, a+n+1, [] (int x, int y) { return std::abs(x)>std::abs(y); } );
	if(k==1)
	{
		std::sort(a+1, a+n+1, [] (int x, int y) { return x>y; } );
		for(int i=1; i<=n; ++i) inc(ans, 1ll*(MOD+a[i])*qpow(2, n-i)%MOD);
		printf("%d\n", ans);
		return 0;
	}
	f[0][0][0]=1;
	for(int i=1; i<=n; ++i)
	{
		for(int s=0; s<std::min(i, k); ++s)
		{
			for(int t:{0, 1})
			{
				inc(f[i][s+1][t^sgn(a[i])], 1ll*iv2*f[i-1][s][t]%MOD*abs(a[i])%MOD);
				inc(f[i][s][t], 1ll*iv2*f[i-1][s][t]%MOD);
			}
		}
		inc(ans, f[i][k][0]);
		int cur=1ll*iv2*iv2%MOD;
		dec(ans, 1ll*f[i][k][1]*qpow(iv2, n-i)%MOD);
		memset(h, 0, sizeof(h));
		h[0][0]=1;
		for(int j=i+1, c=0, ct=0; j<=n; ++j)
		{
			if(sgn(a[i])^sgn(a[j]))
			{
				for(int s=0; s<=std::min(k-2, ct); ++s)
				{
					inc(h[c^1][s+1], 1ll*h[c][s]*abs(a[j])%MOD*iv2%MOD);
					inc(h[c^1][s], 1ll*h[c][s]*iv2%MOD);
					inc(g[i][j], 1ll*h[c][s]*f[i-1][k-2-s][sgn(a[j])?(s&1):0]%MOD*cur%MOD);
					h[c][s]=0;
				}
				c^=1;
				++ct;
				g[j][i]=g[i][j];
			}
			else cur=1ll*cur*iv2%MOD;
		}
	}
	if(k&1)
	{
		memset(h, 0, sizeof(h));
		h[0][0]=1;
		int c=0, tot=0;
		for(int i=1; i<=n; ++i) tot+=a[i]>=0;
		for(int i=n, ct=0; i; --i) if(a[i]<0)
		{
			memset(h[c^1], 0, sizeof(h[0]));
			for(int s=0; s<=std::min(ct, k-1); ++s)
			{
				inc(h[c^1][s+1], 1ll*h[c][s]*(-a[i])%MOD*iv2%MOD);
				inc(h[c^1][s], 1ll*h[c][s]*iv2%MOD);
			}
			++ct;
			c^=1;
			dec(ans, 1ll*fix(qpow(iv2, tot)-qpow(iv2, n-ct))*h[c][k]%MOD);
		}
		memset(h, 0, sizeof(h));
		h[0][0]=1;
		c=0;
		for(int i=1, ct=0; i<=n; ++i) if(a[i]<0)
		{
			memset(h[c^1], 0, sizeof(h[0]));
			for(int s=0; s<=std::min(ct, k-1); ++s)
			{
				inc(h[c^1][s+1], 1ll*h[c][s]*(-a[i])%MOD*iv2%MOD);
				inc(h[c^1][s], 1ll*h[c][s]*iv2%MOD);
			}
			int rct=0;
			for(int j=n; j>i; --j) if(a[j]>=0)
			{
				inc(ans, 1ll*qpow(iv2, tot-rct)*h[c][k-1]%MOD*iv2%MOD*a[j]%MOD);
				++rct;
			}
			++ct;
			c^=1;
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) if(g[i][j])
		{
			int v=g[i][j];
			for(int x=std::max(i, j)+1, t=std::max(i, j)+1; x<=n; ++x) if(sgn(a[i])==sgn(a[x]))
			{
				v=1ll*iv2*v%MOD;
				while(t<=n&&1ll*a[i]*a[x]-sgn(a[i])<1ll*abs(a[j])*abs(a[t]))
				{
					if(sgn(a[t])==sgn(a[j])) v=1ll*v*iv2%MOD;
					++t;
				}
				inc(ans, 1ll*v*abs(a[i])%MOD*abs(a[x])%MOD);
			}
		}
	}
	printf("%d\n", 1ll*ans*qpow(2, n)%MOD);
	return 0;
}
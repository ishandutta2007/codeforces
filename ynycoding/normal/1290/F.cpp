#include <cstdio>
#include <algorithm>
#define x first
#define y second
using std::pair;
const int N=6, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, m, x[N], y[N], f[32][21][21][21][21][2][2], sa, sb, sc, sd, ans;
inline void tr(int v, int a, int b, int c, int d, int s0, int s1, int val)
{
	for(int s=0; s<(1<<n); ++s)
	{
		int a0=a, b0=b, c0=c, d0=d;
		for(int i=0; i<n; ++i) if(s&(1<<i))
		{
			if(x[i]>=0) a0+=x[i];
			else b0-=x[i];
			if(y[i]>=0) c0+=y[i];
			else d0-=y[i];
		}
		if(((a0^b0)&1)||((c0^d0)&1)) continue;
		int x=(a0&1)==((m>>v)&1)?s0:(a0&1);
		int y=(c0&1)==((m>>v)&1)?s1:(c0&1);
		inc(f[v][a0>>1][b0>>1][c0>>1][d0>>1][x][y], val);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i)
	{
		scanf("%d%d", x+i, y+i);
		if(x[i]>=0) sa+=x[i];
		else sb-=x[i];
		if(y[i]>=0) sc+=y[i];
		else sd-=y[i];
	}
	tr(0, 0, 0, 0, 0, 0, 0, 1);
	int v;
	for(v=0; (1<<v)<=m; ++v)
	for(int a=0; a<=sa; ++a)
	for(int b=0; b<=sb; ++b)
	for(int c=0; c<=sc; ++c)
	for(int d=0; d<=sd; ++d)
	{
		{
			for(int x:{0, 1}) for(int y:{0, 1})
			{
				int val=f[v][a][b][c][d][x][y];
				if(val) tr(v+1, a, b, c, d, x, y, val);
			}
		}
	}
	for(int a=0; a<=sa; ++a) if(a<=(m>>v)) for(int c=0; c<=sc; ++c) if(c<=(m>>v))
	{
		for(int x=0; x<=(a<(m>>v)); ++x) for(int y=0; y<=(c<(m>>v)); ++y)
		{
			int val=f[v][a][a][c][c][x][y];
			inc(ans, f[v][a][a][c][c][x][y]);
		}
	}
	printf("%d\n", fix(ans-1));
	return 0;
}
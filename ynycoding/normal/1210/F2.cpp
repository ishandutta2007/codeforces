#include <cstdio>
#include <bitset>
#include <unordered_map>
#include <algorithm>
#define bc __builtin_popcount
using std::unordered_map;
using std::bitset;
const int N=10, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, p[N][N], g[N][1<<N], ans, iv=qpow(100, MOD-2), tot;
bitset<128> to, rto[N], cto[1<<N];
unordered_map<bitset<128>, int> f, f1;
int main()
{
	scanf("%d", &n);
	for(int i=0, x; i<n; ++i) for(int j=0; j<n; ++j) scanf("%d", &x), p[i][j]=1ll*iv*x%MOD;
	for(int i=0; i<n; ++i)
	{
		for(int s=0; s<(1<<n); ++s)
		{
			g[i][s]=1;
			for(int j=0; j<n; ++j) if(s&(1<<j)) g[i][s]=1ll*g[i][s]*p[i][j]%MOD;
			else g[i][s]=1ll*g[i][s]*fix(1-p[i][j])%MOD;
		}
	}
	to.set((1<<n)-1);
	f[to]=1;
	for(int i=0; i<n; ++i)
	{
		f1.clear();
		for(auto [bs, v]:f)
		{
			for(int i=0; i<n; ++i) rto[i].reset();
			for(int s=bs._Find_first(); s<(1<<n); s=bs._Find_next(s))
			{
				for(int j=0; j<n; ++j) if(s&(1<<j)) rto[j][s^(1<<j)]=1;
			}
			for(int s=1; s<(1<<n); ++s)
			{
				int x=__builtin_ctz(s);
				cto[s]=cto[s^(1<<x)]|rto[x];
				if(cto[s].any()) inc(f1[cto[s]], 1ll*v*g[i][s]%MOD);
			}
		}
		f.swap(f1);
	}
	for(auto [bs, v]:f) inc(ans, v);
	printf("%d\n", ans);
	return 0;
}
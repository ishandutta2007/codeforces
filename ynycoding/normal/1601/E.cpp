#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#define x first
#define y second
#define ll long long
#define pb push_back
using std::pair;
using std::vector;
const int N=300005;
int n, Q, k, l[N], r[N], a[N], len[N], fa[N];
ll sum[N], rans[N];
vector<int> e[N];
inline int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
inline void upt(int x) { sum[x]=1ll*a[x]*len[x]+(x+len[x]*k<=n?sum[x+len[x]*k]:0); }
inline void fix(int x, int v)
{
	a[x]=v;
	while(x+len[x]*k<=n&&v<=a[x+len[x]*k])
	{
		fa[x+len[x]*k]=x;
		len[x]+=len[x+len[x]*k];
	}
	upt(x);
}
int main()
{
	scanf("%d%d%d", &n, &Q, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=Q; ++i) scanf("%d%d", l+i, r+i), e[l[i]].pb(i);
	std::iota(fa, fa+n+1, 0);
	for(int i=n; i; --i)
	{
		for(int j=i+1; j<i+k&&a[j]>a[i]; ++j) fix(j, a[i]);
		len[i]=1;
		fix(i, a[i]);
		upt(i);
		for(int x:e[i])
		{
			int r=::r[x];
			r=(r-i)/k*k+k+i;
			if(r>n) { rans[x]=sum[i]; continue; }
			int fr=findfa(r);
			rans[x]=sum[i]-(fr+len[fr]*k<=n?sum[fr+len[fr]*k]:0)-1ll*a[fr]*(len[fr]-(r-fr)/k);
		}
	}
	for(int i=1; i<=Q; ++i) printf("%lld\n", rans[i]);
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define lid (id<<1)
#define rid (id<<1|1)
#define N 3005
int n, k, a[N][N], t[N];
ll s[N], f[N<<2][N];
inline void upt(ll v, int a, ll *f) { for(int i=k; i>=a; --i) f[i]=std::max(f[i], f[i-a]+v); }
void solve(int id, int l, int r)
{
	if(l==r) { for(int i=1; i<=t[l]; ++i) f[id][i]=f[id][i-1]+a[l][i]; return; }
	int mid=(l+r)>>1;
	solve(lid, l, mid), solve(rid, mid+1, r);
	for(int i=mid+1; i<=r; ++i) upt(s[i], t[i], f[lid]);
	for(int i=l; i<=mid; ++i) upt(s[i], t[i], f[rid]);
	for(int i=1; i<=k; ++i) f[id][i]=std::max(f[lid][i], f[rid][i]);
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", t+i);
		for(int j=1; j<=std::min(t[i], k); ++j) scanf("%d", a[i]+j), s[i]+=a[i][j];
		for(int j=k+1, x; j<=t[i]; ++j) scanf("%d", &x);
		t[i]=std::min(t[i], k);
	}
	solve(1, 1, n);
	printf("%lld\n", f[1][k]);
	return 0;
}
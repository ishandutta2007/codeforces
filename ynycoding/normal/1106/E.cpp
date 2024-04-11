#include <cstdio>
#include <vector>
#include <algorithm>
#define lid (id<<1)
#define rid (id<<1|1)
#define mp std::make_pair
#define x first	
#define y second
#define ll long long
#define MAXN 100005
using std::pair;
using std::min;
int n, k, m, s[MAXN], t[MAXN], w[MAXN], d[MAXN];
ll dp[MAXN][205];
pair<int, int> f[MAXN];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.x==b.x?a.y<b.y:a.x<b.x; }
struct node{
	int l, r, w, d;
}tr[MAXN<<2];
void build(int id, int l, int r)
{
	tr[id].l=l, tr[id].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lid, l, mid), build(rid, mid+1, r);
}
void update(int id, int l, int r, int w, int d)
{
	if(l==tr[id].l&&r==tr[id].r)
	{
		if(cmp(mp(tr[id].w, tr[id].d), mp(w, d))) tr[id].w=w, tr[id].d=d;
		return;
	}
	int mid=(tr[id].l+tr[id].r)>>1;
	if(l>mid) update(rid, l, r, w, d);
	else if(r<=mid) update(lid, l, r, w, d);
	else update(lid, l, mid, w, d), update(rid, mid+1, r, w, d);
}
pair<int, int> query(int id, int x)
{
	if(tr[id].l==tr[id].r) return mp(tr[id].w, tr[id].d);
	int mid=(tr[id].l+tr[id].r)>>1;
	pair<int, int> a=(x<=mid?query(lid, x):query(rid, x)), b=mp(tr[id].w, tr[id].d);
	return cmp(a, b)?b:a;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	build(1, 1, n);
	for(int i=1; i<=n+1; ++i) for(int j=0; j<=m; ++j) dp[i][j]=0x3f3f3f3f3f3f3f;
	for(int i=1; i<=k; ++i) scanf("%d%d%d%d", s+i, t+i, d+i, w+i), update(1, s[i], t[i], w[i], d[i]);
	for(int i=1; i<=n; ++i) f[i]=query(1, i);
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=m; ++j)
		{
			int w=f[i].x, d=f[i].y;
			dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]);
			if(!d) {dp[i+1][j]=min(dp[i+1][j], dp[i][j]); continue; }
			dp[min(d+1, n+1)][j]=min(dp[min(d+1, n+1)][j], dp[i][j]+w);
		}
	}
	printf("%lld", dp[n+1][m]);
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;

#define N 200019
#define int long long
int n, t, sz, a[N], ans[N], sum, cnt[1000086];

struct data
{
	int l, r, id;
} q[N];

void inc(int x)
{
	sum += (cnt[a[x]]++ << 1 | 1) * a[x];
}

void dec(int x)
{
	sum -= (--cnt[a[x]] << 1 | 1) * a[x];
}

signed main() 
{
	scanf("%lld%lld", &n, &t); sz = pow(n, 0.5);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 1; i <= t; i++) scanf("%lld%lld", &q[i].l, &q[i].r), q[i].id = i;
	sort(q + 1, q + t + 1, [](data a, data b){return (a.l / sz) ^ (b.l / sz) ? a.l < b.l : a.r < b.r;});
	int lp = 1, rp = 0;
	for (int i = 1; i <= t; i++) 
	{
		while (rp < q[i].r) inc(++rp);
		while (rp > q[i].r) dec(rp--);
		while (lp < q[i].l) dec(lp++);
		while (lp > q[i].l) inc(--lp);
		ans[q[i].id] = sum;
	}
	for (int i = 1; i <= t; i++) printf("%lld\n", *(ans + i));
}
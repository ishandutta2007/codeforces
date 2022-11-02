#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6;
int n, m, k, a[maxn + 3], b[maxn + 3], cnt1, cnt2, mx[maxn + 3];
int fa1[maxn + 3], fa2[maxn + 3], sz1[maxn + 3], sz2[maxn + 3];
char op[5], s[maxn + 3], t[maxn + 3];
ll ans[maxn + 3], sum[maxn + 3];

int find1(int x) {
	if (fa1[x] == x) return x;
	find1(fa1[x]);
	if (fa1[fa1[x]] != fa1[x]) sum[x] += sum[fa1[x]];
	return fa1[x] = fa1[fa1[x]];
}

int find2(int x) {
	if (fa2[x] == x) return x;
	find2(fa2[x]);
	if (fa2[fa2[x]] != fa2[x]) mx[x] = max(mx[x], mx[fa2[x]]);
	return fa2[x] = fa2[fa2[x]];
}

struct query {
	int t, x, y;
	char ch;
	friend bool operator < (const query &a, const query &b) {
		return a.t < b.t;
	}
} q[maxn + 3];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", op), s[i] = op[0];
		if (s[i] == 'U' || s[i] == 'M') scanf("%d %d", &a[i], &b[i]);
		else scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n + m; i++) fa1[i] = fa2[i] = i, sz1[i] = sz2[i] = 1;
	cnt1 = cnt2 = n;
	for (int i = 1; i <= m; i++) {
		if (s[i] == 'U') {
			int x = find1(a[i]), y = find1(b[i]);
			++cnt1, fa1[x] = fa1[y] = cnt1, sz1[cnt1] = sz1[x] + sz1[y];
			++k, q[k].ch = 'U', q[k].t = i, q[k].x = a[i], q[k].y = b[i];
		} else if (s[i] == 'M') {
			int x = find2(a[i]), y = find2(b[i]);
			++cnt2, fa2[x] = fa2[y] = cnt2, sz2[cnt2] += sz2[x] + sz2[y];
		} else if (s[i] == 'A') {
			int x = find1(a[i]);
			sum[x] += sz1[x];
			++k, q[k].ch = 'A', q[k].t = i, q[k].x = a[i];
		} else if (s[i] == 'Z') {
			int x = find2(a[i]);
			mx[x] = max(mx[x], i);
		} else {
			int x = find1(a[i]), y = find2(a[i]);
			ans[i] += sum[a[i]];
			if (x != a[i]) ans[i] += sum[x];
			int z = max(mx[a[i]], mx[y]);
			++k, q[k].ch = 'Q', q[k].t = z, q[k].x = a[i], q[k].y = i;
		}
	}
	sort(q + 1, q + k + 1);
	for (int i = 1; i <= n + k; i++) fa1[i] = i, sz1[i] = 1, sum[i] = 0;
	cnt1 = n;
	for (int i = 1; i <= k; i++) {
		if (q[i].ch == 'U') {
			int x = find1(q[i].x), y = find1(q[i].y);
			++cnt1, fa1[x] = fa1[y] = cnt1, sz1[cnt1] = sz1[x] + sz1[y];
		} else if (q[i].ch == 'A') {
			int x = find1(q[i].x);
			sum[x] += sz1[x];
		} else {
			int x = find1(q[i].x);
			ans[q[i].y] -= sum[q[i].x];
			if (x != q[i].x) ans[q[i].y] -= sum[x];
		}
	}
	for (int i = 1; i <= m; i++) if (s[i] == 'Q') printf("%lld\n", ans[i]);
	return 0;
}
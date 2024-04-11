#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], k[100005];
vector<int> b[100005];
int mn[400005], sum[400005];
inline void push_up(int p) {
	sum[p] = sum[p << 1] + sum[p << 1 | 1]; 
	mn[p] = min(mn[p << 1] + sum[p << 1 | 1], mn[p << 1 | 1]);
}
void build(int p, int l, int r) {
	if (l == r) {
		mn[p] = 0;
		sum[p] = (r == n + 1) ? 0 : 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	push_up(p); 
}
void modify(int p, int l, int r, int pos, int x) {
	if (l == r) {
		sum[p] += x;
		mn[p] = min(sum[p], 0);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= pos) {
		modify(p << 1, l, mid, pos, x);
	} else {
		modify(p << 1 | 1, mid + 1, r, pos, x);
	}
	push_up(p);
}
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	build(1, 1, n + 1);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &k[i]);
		b[i].resize(k[i]);
		long long s = 0;
		for (auto &x : b[i]) {
			scanf("%d", &x);
			s += x;
		}
		int pos = lower_bound(a + 1, a + n + 1, (s + k[i] - 1) / k[i]) - a;
		modify(1, 1, n + 1, pos, -1);
	}
	for (int i = 1; i <= m; ++i) {
		long long s = 0;
		for (auto x : b[i]) {
			s += x;
		}
		int pos = lower_bound(a + 1, a + n + 1, (s + k[i] - 1) / k[i]) - a;
		modify(1, 1, n + 1, pos, 1);
		for (auto x : b[i]) {
			long long s1 = s - x;
			int pos1 = lower_bound(a + 1, a + n + 1, (s1 + k[i] - 2) / (k[i] - 1)) - a;
			modify(1, 1, n + 1, pos1, -1);
			putchar(mn[1] >= 0 ? '1' : '0');
			modify(1, 1, n + 1, pos1, 1);
		}
		modify(1, 1, n + 1, pos, -1);
	}
	puts("");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
inline void add(int &x, int y) { 
	(x += y) >= P && (x -= P); 
}
const int N = 1e5 + 5, M = 355;
int n, k, dp[N], cnt[N], pre[N], last[N];
struct block {
	int l, r, tag, sum[M * 2];
	void update(int pos) {
		int v = dp[pos - 1];
		for (int i = cnt[pos] + M; i < M * 2; ++i)
			::add(sum[i], v);
	}
	void add(int l1, int r1, int x) {
		l1 = max(l1, l), r1 = min(r1, r);
		if (l1 > r1) return;
		if (l1 == l && r1 == r) {
			tag += x;
		} else {
			memset(sum, 0, sizeof sum);
			for (int i = l1; i <= r1; ++i)
				cnt[i] += x;
			for (int i = l; i <= r; ++i)
				::add(sum[cnt[i] + M], dp[i - 1]);
			for (int i = 1; i < M * 2; ++i)
				::add(sum[i], sum[i - 1]);
		}
	}
	inline int query() {
		int lim = min(M - 1, k - tag);
		return lim + M < 0 ? 0 : sum[lim + M];
	}
} b[M];
int main() {
	scanf("%d%d", &n, &k);
	int tot = 0;
	for (int l = 1, r; l <= n; l = r) {
		r = min(n + 1, l + 350);
		b[++tot].l = l, b[tot].r = r - 1;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int x; 
		scanf("%d", &x);
		int y = last[x];
		last[x] = i;
		pre[i] = y;
		int id = (i - 1) / 350 + 1;
		b[id].update(i);
		for (int j = 1; j <= tot; ++j)
			b[j].add(y + 1, i, 1);
		if (y) {
			int z = pre[y];
			for (int j = 1; j <= tot; ++j)
				b[j].add(z + 1, y, -1);
		}
		for (int j = 1; j <= tot; ++j)
			add(dp[i], b[j].query());
	}
	printf("%d\n", dp[n]);
}
#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
const int P = 1e9 + 7;
inline void add(int &x, int y) {
	(x += y) >= P && (x -= P);
}
inline void sub(int &x, int y) {
	(x -= y) < 0 && (x += P);
}
int n, m, a[200005];
pr f[200005], c[200005];
vector<int> pos[200005];
inline void modify(int p, const pr &x, bool rev = false) {
	if (rev) {
		p = m - p + 1;
	}
	for (; p <= m; p += p & -p) {
		add(c[p].first, x.first);
		add(c[p].second, x.second);
	}
}
inline pr query(int p, bool rev = false) {
	if (rev) {
		p = m - p + 1;
	}
	pr res = {0, 0};
	for (; p; p -= p & -p) {
		add(res.first, c[p].first);
		add(res.second, c[p].second);
	}
	return res;
}
inline void clear(int p, bool rev = false) {
	if (rev) {
		p = m - p + 1;
	}
	for (; p <= m; p += p & -p) {
		c[p] = {0, 0};
	}
}
inline void init() {
	memset(c + 1, 0, m * 8);
}
void solve() {
	scanf("%d", &n);
	vector<int> p;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		p.emplace_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin() + 1;
	}
	m = p.size();
	for (int i = 1; i <= m; ++i) {
		pos[i].clear();
	}
	for (int i = n; i; --i) {
		pos[a[i]].emplace_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		f[i] = query(a[i] - 1);
		add(f[i].first, 1);
		add(f[i].second, f[i].first);
		modify(a[i], f[i]);
		add(ans, f[i].second);
	}
	init();
	int mx = 0;
	for (int i = n; i; --i) {
		if (mx <= a[i]) {
			vector<int> v;
			for (int x = mx; x < a[i]; ++x) {
				for (auto p : pos[x]) {
					if (p <= i) {
						v.emplace_back(p);
					}
				}
			}
			mx = a[i];
			sort(v.begin(), v.end(), greater<int>());
			sub(ans, f[i].first);
			for (auto p : v) {
				pr res = query(a[p] + 1, true);
				add(res.first, 1);
				sub(ans, 1ll * res.first * f[p].first % P);
				modify(a[p], res, true);
			}
			for (auto p : v) {
				clear(a[p], true);
			}
		}
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
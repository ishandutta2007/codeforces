#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int rng(int l, int r) {
	return l + rnd() % (r - l + 1);
}
int query(int u, int v, int w) {
	cout << "? " << u << " " << v << " " << w << "\n";
	int x;
	cin >> x;
	return x;
}
int cnt[300000], id[300000];
int main() {
	int h;
	cin >> h;
	int n = (1 << h) - 1;
	int T = 420 + 2;
	while (T--) {
		int u, v, w;
		do {
			u = rng(1, n);
			v = rng(1, n);
			w = rng(1, n);
		} while (u == v || v == w || u == w);
		++cnt[query(u, v, w)];
	}
	iota(id + 1, id + n + 1, 1);
	sort(id + 1, id + n + 1, [&](int i, int j) {
		return cnt[i] > cnt[j];
	});
	int x = id[1], y = id[2];
	for (int i = 1; i <= n; ++i) {
		if (i == x || i == y) continue;
		if (query(x, y, i) == i) {
			cout << "! " << i << "\n";
			return 0;
		}
	}
	return 0;
}
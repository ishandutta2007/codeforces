#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054;

int n, l, r;
int c[N];
int a[N];

void work() {
	int i, s = 0, t = 0, pos = 0, neg = 0;
	cin >> n >> l >> r;
	for (i = 0; i < n; ++i) cin >> c[i];
	memset(a, 0, n << 2);
	for (i = 0; i < l; ++i) ++a[c[i] - 1];
	for (; i < n; ++i) --a[c[i] - 1];
	for (i = 0; i < n; ++i) s += a[i];
	if (s < 0) for (s = -s, i = 0; i < n; ++i) a[i] = -a[i];
	std::sort(a, a + n), assert(!(s & 1));

	s /= 2;
	for (i = 0; i < n; ++i) {
		if (a[i] > 0) t += a[i] / 2, pos += a[i];
		else neg -= a[i];
	}
	if (s <= t) cout << s + neg << '\n';
	else cout << pos - t << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}
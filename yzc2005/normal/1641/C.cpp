#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, c[N], sick[N], t[N], tim[N], l[N], r[N], mx[N][20], lg[N], x[N], sum[N];
set<int> rest;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		rest.insert(i);
	for (int i = 1; i <= q; ++i) {
		cin >> t[i];
		if (t[i] == 0) {
			cin >> l[i] >> r[i] >> x[i];
			if (x[i] == 0) {
				auto it = rest.lower_bound(l[i]);
				vector<int> v;
				while (it != rest.end() && *it <= r[i])
					v.emplace_back(*it), ++it;
				for (auto x : v)
					rest.erase(x), sick[x] = i;
			}
		} else {
			cin >> x[i];
		}
	}
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + !sick[i], mx[i][0] = sick[i];
	for (int k = 1; k < 20; ++k)
		for (int i = 1; i + (1 << k) - 1 <= n; ++i)
			mx[i][k] = max(mx[i][k - 1], mx[i + (1 << (k - 1))][k - 1]);
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i >> 1] + 1;
	auto query = [&](int l, int r) {
		int k = lg[r - l + 1];
		return max(mx[l][k], mx[r - (1 << k) + 1][k]);
	};
	memset(tim, 0x3f, sizeof tim);
	for (int i = 1; i <= q; ++i) {
		if (t[i] || !x[i]) continue;
		int tmp = sum[r[i]] - sum[l[i] - 1];
		assert(tmp);
		if (tmp > 1) continue;
		int val = query(l[i], r[i]);
		auto it = rest.lower_bound(l[i]);
		tim[*it] = min(tim[*it], max(val, i));
	}
	for (int i = 1; i <= q; ++i) {
		if (t[i] == 1) {
			int p = x[i];
			if (sick[p]) {
				if (sick[p] > i) puts("N/A");
				else puts("NO");
			} else {
				if (tim[p] > i) puts("N/A");
				else puts("YES");
			}
		}
	}
	return 0;
}
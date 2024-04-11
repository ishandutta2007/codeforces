#include <bits/stdc++.h>
using namespace std;
int n, d;
int par[1005], sz[1005];
int find(int x) {
	if (x == par[x]) {
		return x;
	}
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	par[x] = y;
	sz[y] += sz[x];
}
int main() {
	cin >> n >> d;
	iota(par + 1, par + n + 1, 1);
	fill(sz + 1, sz + n + 1, 1);
	for (int t = 1; t <= d; ++t) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
		int rest = t;
		vector<int> a;
		for (int i = 1; i <= n; ++i) {
			if (find(i) == i) {
				a.emplace_back(sz[i]);
				rest -= sz[i] - 1;
			}
		}
		sort(a.begin(), a.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i <= rest; ++i) {
			ans += a[i];
		}
		cout << ans - 1 << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, p[10005];
int query(int p) {
	cout << "? " << p << "\n";
	int x;
	cin >> x;
	return x;
}
void solve() {
	cin >> n;
	memset(p, 0, sizeof p);
	for (int i = 1; i <= n; ++i) {
		if (p[i]) {
			continue;
		}
		int x = query(i);
		vector<int> v = {x};
		while (true) {
			int y = query(i);
			if (y == x) {
				break;
			}
			v.emplace_back(y);
		}
		for (int j = 0; j < (int) v.size(); ++j) {
			p[v[j]] = v[(j + 1) % v.size()];
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i)
		cout << p[i] << " \n"[i == n];
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
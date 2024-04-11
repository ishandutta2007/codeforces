#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::vector <int> vector;
const int N = 108;

int n, m;
vector a[N], b[N];

void work() {
	int i, j, x, t; ll s = 0;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		a[i].resize(m), b[i].clear();
		for (j = 0; j < m; ++j) cin >> a[i][j];
		std::sort(a[i].begin(), a[i].end());
	}
	for (t = 0; t < m; ++t) {
		x = 0;
		for (i = 1; i < n; ++i) if (a[i][0] < a[x][0]) x = i;
		for (i = 0; i < n; ++i) {
			if (i == x) b[i].emplace_back(a[i].front()), a[i].erase(a[i].begin());
			else b[i].emplace_back(a[i].back()), a[i].pop_back();
		}
	}
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) cout << b[i][j] << (j == m - 1 ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}
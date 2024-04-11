#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	vector<vector<int>> c(n, vector<int>(m));
	vector<vector<pair<int, int>>> pos(100001);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> c[i][j], pos[c[i][j]].emplace_back(i, j);
	long long ans = 0;
	for (int x = 1; x <= 100000; ++x) {
		auto &v = pos[x];
		if ((int) v.size() <= 500) {
			for (int i = 0; i < (int) v.size(); ++i)
				for (int j = i + 1; j < (int) v.size(); ++j)
					ans += abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);					
		} else {
			long long c1 = 0, c2 = 0;
			for (int j = 0; j < m; ++j) {
				for (int i = 0; i < n; ++i)
					if (c[i][j] == x) ans += j * c2 - c1;
				for (int i = 0; i < n; ++i)
					if (c[i][j] == x) ++c2, c1 += j;
			}
			c1 = 0, c2 = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) 
					if (c[i][j] == x) ans += i * c2 - c1;
				for (int j = 0; j < m; ++j) 
					if (c[i][j] == x) ++c2, c1 += i;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

#include "bits/stdc++.h"
using namespace std;



int main() {
	int n, m; cin >> n >> m;
	vector < vector<vector<int>>>edges(m);
	for (int i = 0; i < m; ++i) {
		edges[i].resize(n);
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		c--;
		edges[c][a].push_back(b);
		edges[c][b].push_back(a);
	}
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		int ans = 0;
		for (int j = 0; j < m; ++j) {
			vector<int>ids;
			vector<bool>used(n,false);
			ids.push_back(u);
			used[u] = true;
			bool ok = false;
			while (!ids.empty()) {
				int atop = ids.back();
				ids.pop_back(); 
				for (auto k : edges[j][atop]) {
					if (k == v) {
						ok = true;
						break;
					}
					if (!used[k]) {
						used[k] = true;
						ids.push_back(k);
					}
				}
			}
			if (ok)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
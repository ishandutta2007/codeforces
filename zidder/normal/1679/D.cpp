#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, m;
	long long k;
	cin >> n >> m >> k;
	vector<vector<int> > g(n);
	vector<int> a(n);
	for (int &i:a) scanf("%d", &i);
	for (int i=0;i<m;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		g[u].push_back(v);
	}

	auto f = [&](int x) -> bool {
		vector<int> d(n, -1);
		vector<bool> visited(n, false);
		function<bool(int)> dfs = [&](int v) -> bool {
			int dist = 1;
			visited[v] = true;
			for (int u: g[v]) {
				if (a[u] > x) continue;
				if (visited[u] && d[u] == -1) return true;
				if (visited[u]) {
					dist = max(dist, 1 + d[u]);
				} else {
					if (dfs(u)) return true;
					dist = max(dist, 1 + d[u]);
				}
			}
			d[v] = dist;
			return false;
		};
		for (int i=0;i<n;++i){
			if (a[i] > x) continue;
			if (d[i] == -1) {
				if (dfs(i)) {
					return true;
				}
			}
			if (d[i] >= k) {
				return true;
			}
		}
		return false;
	};

	int l = 0, r = 1000000000;
	// (l, r]
	// r -> possible
	// l -> impossible
	if (!f(r)) {
		cout << -1 << endl;
		return;
	}
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (f(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <random>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<vector<int> > g(n);
	for (int i=1;i<n;++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> d(n, -1);
	function<void(int)> dfs = [&](int v) {
		for (int u: g[v]) {
			if (d[u] == -1) {
				d[u] = d[v] + 1;
				dfs(u);
			}
		}
	};

	d[0] = 0;
	dfs(0);
	int f1 = 0;
	for (int i=0;i<n;++i) if (d[f1] < d[i]) f1 = i;

	d = vector<int>(n, -1);
	d[f1] = 0;
	dfs(f1);

	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	set<pair<int, int> > s;
	for (int i=0;i<n;++i) if (d[i]) s.emplace(d[i], i);

	int f2 = s.rbegin()->second;
	if (d[f2] == n - 1) {
		cout << 1 << endl;
		return;
	}

	function<int(int, int)> dfs2 = [&](int v, int p) -> int {
		bool b = false;
		int c = 0;
		for (int u: g[v]) {
			if (u == p) continue;
			int c2 = dfs2(u, v);
			if (c2 == 0) {
				if (b) c++;
				else b = true;
			} else {
				c += c2;
			}
		}
		return c;
	};

	int ans = min(dfs2(f1, -1), dfs2(f2, -1));
	for (int i=0;i<30;++i)
		ans = min(ans, dfs2(rand() % n, -1));

	cout << ans + 1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
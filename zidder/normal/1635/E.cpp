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
	cin >> n >> m;
	vector<vector<int> > g(n), gd(n);
	vector<pair<int, pair<int, int> > > rels(m);
	for (int i=0;i<m;++i){
		int t;
		int x, y;
		scanf("%d%d%d", &t, &x, &y);
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
		rels[i] = {t, {x, y}};
	}

	vector<int> is_left(n, -1);
	bool ok = true;
	function<void(int, bool)> dfs = [&](int v, bool lft) {
		is_left[v] = lft;
		for (auto u: g[v]){
			if (!ok) break;
			if (is_left[u] == -1) dfs(u, !lft);
			else {
				if (is_left[u] == lft) {
					ok = false;
					break;
				}
			}
		}
	};

	for (int i=0;i<n;++i) {
		if (is_left[i] == -1) dfs(i, true);
	}
	if (!ok) {
		cout << "NO" << endl;
		return;
	}

	// y in gd[x] means x is more left than y
	for (auto p: rels) {
		int x = p.second.first;
		int y = p.second.second;
		// left is lefter than right
		if (p.first == 1) {
			if (is_left[x]) {
				gd[x].push_back(y);
			} else {
				gd[y].push_back(x);
			}
		} else {
			if (is_left[x]) {
				gd[y].push_back(x);
			} else {
				gd[x].push_back(y);
			}
		}
	}

	// top sort by gd
	vector<bool> visited(n, false);
	vector<int> ans;

	function<void(int)> dfs2 = [&](int v) {
		visited[v] = true;
		for (int u : gd[v]) {
			if (!visited[u])
				dfs2(u);
		}
		ans.push_back(v);
	};

	for (int i = 0; i < n; ++i) {
		if (!visited[i])
			dfs2(i);
	}
	reverse(ans.begin(), ans.end());

	vector<int> X(n);
	for (int i=0;i<n;++i) X[ans[i]] = i;
	for (auto p: rels) {
		int x = p.second.first;
		int y = p.second.second;
		// left is lefter than right
		if (p.first == 1) {
			if (is_left[x]) {
				if (X[x] >= X[y]) {
					ok = false;
					break;
				}
			} else {
				if (X[y] >= X[x]) {
					ok = false;
					break;
				}
			}
		} else {
			if (is_left[x]) {
				if (X[y] >= X[x]) {
					ok = false;
					break;
				}
			} else {
				if (X[x] >= X[y]) {
					ok = false;
					break;
				}
			}
		}
	}
	if (!ok) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i=0;i<n;++i) {
		if (is_left[i]) printf("L");
		else printf("R");
		printf(" %d\n", X[i]);
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
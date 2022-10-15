#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	int x, y;
	cin >> x >> y;
	x--;y--;
	vector<int> a(k);
	for (int &i: a) scanf("%d", &i);
	for (int &i: a) i--;
	vector<vector<int> > g(n);
	for (int i=1;i<n;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<bool> vis(n, false);
	function<vector<int>(int)> get_path = [&](int xx) ->vector<int>{
		if (xx == y) return {xx};
		vis[xx] = true;
		for (int u: g[xx]) {
			if (vis[u]) continue;
			auto res = get_path(u);
			if (!res.empty()){
				res.push_back(xx);
				return res;
			}
		}
		return {};
	};
	vector<int> pth = get_path(x);
	set<int> path;
	for (int i: pth) path.insert(i);
	vector<set<int> > g1(n);
	for (int i=0;i<n;++i){
		if (path.count(i)) {
			for (int j: g[i]) {
				if (path.count(j)) continue;
				g1[x].insert(j);
				g1[j].insert(x);
			}
		}
		else for (int j: g[i]) {
			if (path.count(j)) {
				g1[i].insert(x);
				g1[x].insert(i);
			} else {
				g1[i].insert(j);
				g1[j].insert(i);
			}
		}
	}

	vector<int> pr(n, -1);
	function<void(int, int)> dfs = [&](int v, int p){
		for (int j: g1[v]) {
			if (j == p) continue;
			pr[j] = v;
			dfs(j, v);
		}
	};
	dfs(x, -1);
	long long l = path.size() - 1;
	vector<bool> visited(n, false);
	visited[x] = true;

	for (int i: a) {
		if (path.count(i)) continue;
		while (!visited[i]){
			visited[i] = true;
			i = pr[i];
		}
	}

	int sm = 0;
	for (int i: visited) sm += i;
	sm--;
	cout << l + 2 * sm << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
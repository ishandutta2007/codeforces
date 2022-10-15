#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int p;
	cin >> p;
	int n = (1<<p);
	vector<vector<int> > g(n);
	vector<pair<int, int> > e;
	for (int i=0;i<n-1;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		e.emplace_back(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> cols(n);
	map<pair<int, int>, int> color;
	vector<int> small;
	for (int i=1;i<n;++i) small.push_back(i);
	function<void(int, int, int)> dfs = [&](int v, int p, int val) {
		for (int u: g[v]) {
			if (u == p) continue;
			if (val == n) {
				cols[u] = small.back();
				small.pop_back();
				// cout << v << " e " << u << endl;
				color[make_pair(u, v)] = cols[u] + n;
				color[make_pair(v, u)] = cols[u] + n;
				dfs(u, v, 0);
			} else {
				cols[u] = small.back() + n;
				small.pop_back();
				// cout << u << " e " << v << endl;
				color[make_pair(u, v)] = cols[u] - n;
				color[make_pair(v, u)] = cols[u] - n;
				dfs(u, v, n);
			}
		}
	};
	cols[0] = n;
	dfs(0, -1, n);
	cout << 1 << endl;
	for (int i=0;i<n;++i) {
		printf("%d ", cols[i]);
	}
	cout << endl;
	for (int i=0;i<n-1;++i) {
		printf("%d ", color[e[i]]);
	}
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
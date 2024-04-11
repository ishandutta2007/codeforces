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
	vector<vector<pair<pair<int, int>, bool> > > g(n);
	for (int i=0;i<m;++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;b--;
		g[a].push_back({{b, c}, true});
		g[b].push_back({{a, c}, true});
	}
	vector<bool> vis(n, false);
	int c = 0;
	function<void(int)> dfs = [&](int v){
		vis[v] = true;
		c++;
		for (auto &e: g[v]){
			if (!e.second) continue;
			if (vis[e.first.first]) continue;
			dfs(e.first.first);
		}
	};

	int ans = 0;
	for (int bt=29;bt>=0;--bt){
		vector<pair<int, int> > m;
		for (int i=0;i<n;++i){
			for (int j=0;j<g[i].size();++j){
				if (!g[i][j].second) continue;
				if ((g[i][j].first.second & (1<<bt)) == 0) continue;
				g[i][j].second = false;
				m.push_back({i, j});
			}
		}
		vis.assign(n, false);
		c = 0;
		dfs(0);
		if (c != n) {
			ans |= 1<<bt;
			for (pair<int, int> &p: m){
				g[p.first][p.second].second = true;
			}
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
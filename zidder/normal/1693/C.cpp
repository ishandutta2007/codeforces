#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > g(n);
	vector<int> gr(n);
	for (int i=0;i<m;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		g[v].push_back(u);
		gr[u]++;
	}
	vector<int> dist(n, -1);
	set<pair<int, int> > dists;

	map<int, set<int> > rdist;

	auto sett = [&](int v, int d){
		if (dist[v] != -1) {
			dists.erase({dist[v], v});
			rdist[dist[v]].erase(v);
		}
		dist[v] = d;
		dists.insert({d, v});
		rdist[d].insert(v);
	};

	sett(n-1, 0);
	vector<int> cnt(n, 0);

	int cmn = -1;
	// 1 2 2 2 2 = "3"
	// 1 2 2 2 2 -> 1 "4" = "6"

	while (!dists.empty()) {
		int v = dists.begin()->second;
		dists.erase(dists.begin());
		if (cmn != dist[v]) {
			cmn = dist[v];
			for (int u: rdist[cmn]) {
				for (int k: g[u]) {
					cnt[k]++;
				}
			}
		}
		for (int u: g[v]) {
			if (dist[u] == -1 || dist[u] > cmn + gr[u] - cnt[u] + 1) {
				// cout << cmn << " " << gr[u] << " " << cnt[u] << endl;
				sett(u, cmn + gr[u] - cnt[u] + 1);
			}
		}
	}

	cout << dist[0] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
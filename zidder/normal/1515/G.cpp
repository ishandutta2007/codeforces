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
	vector<vector<pair<int, int> > > g(n);
	vector<vector<int> > g1(n);
	vector<vector<int> > g2(n);
	vector<int> component(n, -1);
	for (int i=0;i<m;++i){
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		u--;v--;
		g[u].emplace_back(v, l);
		g1[u].push_back(v);
		g2[v].push_back(u);
	}

	vector<bool> visited(n, false);
	vector<int> S;
	function<void(int)> dfs_1 = [&](int v) {
		visited[v] = true;
		for (int i : g1[v]) if (!visited[i]) dfs_1(i);
		S.push_back(v);
	};

	int num = 0;
	function<void(int)> dfs_2 = [&](int v){
		component[v] = num;
		visited[v] = true;
		for (int i: g2[v]) if (!visited[i]) dfs_2(i);
	};

	for (int i = 0; i < n; i++)
		if (!visited[i]) dfs_1(i);

	for (int i = 0; i < n; i++)
		visited[i] = false;

	while (!S.empty()) {
		int v = S.back();
		S.pop_back();
		if (!visited[v]) {
			dfs_2(v);
			num++;
		}
	}
	map<int, int> c2c;
	for (int i=0;i<n;++i) if (c2c.find(component[i]) == c2c.end()) c2c[component[i]] = i;
	for (int i=0;i<n;++i) component[i] = c2c[component[i]];

	// for (int i: component) cout << i << " "; cout << endl;

	vector<long long> d(n, -1);
	vector<long long> gc(n, 0);
	function<void(int)> dfspar = [&](int x) {
		for (auto &p: g[x]) {
			if (component[p.first] != component[x]) continue;
			if (d[p.first] == -1) {
				d[p.first] = d[x] + p.second;
				dfspar(p.first);
			} else {
				if (p.first == component[x]) {
					gc[component[x]] = __gcd(gc[component[x]], p.second + d[x]);
				}
			}
		}
	};
	for (int i=0;i<n;++i) visited[i] = false;
	function<void(int)> dfs = [&](int x) {
		visited[x] = true;
		for (auto &p: g[x]) {
			if (component[p.first] != component[x]) continue;
			gc[component[x]] = __gcd(gc[component[x]], d[x] - d[p.first] + gc[component[x]] + p.second);
			if (!visited[p.first]) dfs(p.first);
			// cout << x << " " << p.first << " " << d[x] << " " << d[p.first] << " " << p.second << endl;
			// cout << component[x] << " " << gc[component[x]] << endl;
		}
	};

	for (int i=0;i<n;++i) if (d[i] == -1) {d[i] = 0; dfspar(i); dfs(i); }

	int q;
	cin >> q;
	for (int i=0;i<q;++i) {
		int si, ti, v;
		scanf("%d%d%d", &v, &si, &ti);
		v--;
		int g = __gcd(gc[component[v]], (long long)ti);
		// cout << gc[component[v]] << " " << g << " " << ti-si << " " << ti << endl;
		if (g == 0 || __gcd(ti-si, ti) % g) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
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
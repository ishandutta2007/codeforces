#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, m, x;
	cin >> n >> m >> x;
	vector<long long> a(n);
	for (long long &i: a) scanf("%lld", &i);
	map<pair<int, int>, int> e;
	vector<vector<int> > g(n);
	for (int i=0;i<m;++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
		e[{x, y}] = e[{y, x}] = i+1;
	}
	vector<bool> visited(n, false);
	vector<vector<int> > g1(n);
	function<void(int)> dfs = [&](int u){
		visited[u] = true;
		for (int i: g[u]) if (!visited[i]) {g1[i].push_back(u);g1[u].push_back(i);dfs(i);}
	};

	dfs(0);

	vector<set<pair<int, int> > > edges(n); // (vertex, edgind)
	for (int i=0;i<n;++i) for (int j: g1[i]) {edges[i].emplace(j, e[{i, j}]);}
	vector<int> par(n);
	for (int i=0;i<n;++i) par[i] = i;

	function<int(int)> dsu = [&](int v) {
		if (par[v] == v) return v;
		return par[v] = dsu(par[v]);
	};

	set<pair<long long, int> > vertices;
	for (int i=0;i<n;++i) vertices.emplace(a[i], i);
	auto merge = [&](int u, int v){
		u = dsu(u);
		v = dsu(v);
		if (edges[u].size() > edges[v].size()) swap(u, v);
	// cout << "I" << endl;
		// u into v
		vertices.erase({a[u], u});
		vertices.erase({a[v], v});
		a[v] += a[u];
		a[v] -= x;
		vertices.emplace(a[v], v);
		par[u] = v;
		for (auto &p: edges[u]) {
			// cout << p.first << " " << u << endl;
			if (p.first != v) {edges[v].insert(p);
			                   edges[p.first].insert({v, p.second});}
			edges[p.first].erase(edges[p.first].lower_bound({u, 0}));
		}
		// cout << v << " " << u << endl;
		// for (auto &p: edges[v]) cout << p.first << " " << p.second << endl;
		// cout << endl;
		edges[u].clear();
	// cout << "say" << endl;
		// edges[v].erase(edges[v].lower_bound({u, 0}));
	// cout << "oh" << endl;
	};
	vector<int> ans;

	while (1<vertices.size()) {
	// cout << "hey" << endl;
		int v = vertices.rbegin()->second;
	// cout << "yo" << endl;
		auto p = *edges[v].begin();
	// cout << "this" << " " << p.first << endl;
		int u = dsu(p.first);
	// cout << "is" << endl;
		if (a[u] + a[v] < x) {
			cout << "NO" << endl;
			return;
		}
	// cout << "what" << endl;
		merge(v, u);
		ans.push_back(p.second);
	}

	cout << "YES" << endl;
	for (int i: ans) printf("%d\n", i);
	return;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
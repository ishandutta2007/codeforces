#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int>(n));
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) cin >> v[i][j];

    vector<int> par(n);
    for (int i=0;i<n;++i) par[i] = i;
    vector<int> sz(n, 1);

    function<int(int)> dsu = [&](int v){
        if (par[v] == v) return v;
        return par[v] = dsu(par[v]);
    };

    vector<pair<pair<int, int>, bool> > edges;

    auto merge = [&](int v, int u, bool b) {
        edges.push_back({{u, v}, b});
        v = dsu(v);
        u = dsu(u);
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    };

    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (v[i][j] == v[j][i]) continue;
            if (dsu(i) == dsu(j)) continue;
            if ((v[i][j] < v[j][i]) == (i < j)) {
                merge(i, j, false);
                // cerr << i << " = " << j << endl;
            } else {
                merge(i, j, true);
                // cerr << i << " != " << j << endl;
            }
        }
    }

    vector<bool> flags(n, false);
    vector<bool> visited(n, false);

    vector<vector<pair<int, bool> > > g(n);
    for (auto &e: edges) {
        // cerr << e.first.first << " " << e.first.second << " " << e.second << endl;
        g[e.first.first].emplace_back(e.first.second, e.second);
        g[e.first.second].emplace_back(e.first.first, e.second);
    }

    function<void(int, bool)> dfs = [&](int v, bool flag) {
        visited[v] = true;
        flags[v] = flag;
        for (auto &p: g[v]) {
            if (visited[p.first]) continue;
            // cerr << v << " " << p.first << " " << p.second << " " << flag << endl;
            dfs(p.first, p.second ^ flag);
        }
    };
    
    for (int i=0;i<n;++i) if (!visited[i]) dfs(i, false);
    for (int i=0;i<n;++i) {
        if (flags[i]) {
            // cerr << "flip " << i << endl;
            for (int j=0;j<n;++j) {
                swap(v[i][j], v[j][i]);
            }
        }
    }
    for (int i=0;i<n;++i) {for (int j=0;j<n;++j) printf("%d ", v[i][j]); printf("\n");}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
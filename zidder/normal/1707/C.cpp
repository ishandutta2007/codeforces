#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int N = 200005;

int ST[4 * N];

int n;
void addd(int ql, int qr, int val, int l=0, int r=-1, int v=1){
    if (r == -1) r = n;
    if (ql >= r || qr <= l) return;
    if (ql <= l && qr >= r) {ST[v]+=val; return;}
    int m = (l + r) / 2;
    addd(ql, qr, val, l, m, 2*v);
    addd(ql, qr, val, m, r, 1+2*v);
}

int gett(int ind, int l=0, int r=-1, int v=1) {
    if (r == -1) r = n;
    if (l + 1 == r) return ST[v];
    int m = (l + r) / 2;
    if (ind < m) return gett(ind, l, m, 2*v) + ST[v];
    else return gett(ind, m, r, 1+2*v) + ST[v];
}

void solve(int test_ind){
    cin >> n;
    int m;
    cin >> m;
    vector<vector<pair<int, int> > > g(n);
    vector<pair<int, int> > e;
    for (int i=0;i<m;++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        g[u].emplace_back(i, v);
        g[v].emplace_back(i, u);
        e.emplace_back(u, v);
    }
    for (int i=0;i<n;++i) sort(g[i].begin(), g[i].end());

    set<int> tree;
    {
        // get tree
        vector<int> par(n, -1);
        for (int i=0;i<n;++i) par[i] = i;
        vector<int> sz(n, 1);
        function<int(int)> dsu = [&](int v){
            if (par[v] == v) return v;
            return par[v] = dsu(par[v]);
        };
        auto merge = [&](int u, int v, int ind) {
            u = dsu(u);
            v = dsu(v);
            if (u == v) return;
            if (sz[u] > sz[v]) swap(u, v);
            tree.insert(ind);
            sz[v] += sz[u];
            par[u] = v;
        };
        for (int i=0;i<m;++i) {
            merge(e[i].first, e[i].second, i);
        }
    }

    vector<int> pr(n, -1);
    vector<int> depth(n, 0);
    vector<pair<int, int> > lr(n);

    int c = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        pr[v] = p;
        lr[v].first = c;
        for (auto &e: g[v]) {
            if (e.second == p) continue;
            if (tree.find(e.first) == tree.end()) continue;
            depth[e.second] = depth[v] + 1;
            dfs(e.second, v);
        }
        c++;
        lr[v].second = c;
    };

    dfs(0, -1);

    vector<vector<int> > bpr(n, vector<int>(23, -2));
    function<int(int, int)> get_bpr = [&](int v, int deg) -> int {
        if (bpr[v][deg] == -2) {
            if (deg == 0) bpr[v][deg] = pr[v];
            else {
                int pr1 = get_bpr(v, deg-1);
                if (pr1 != -1) {
                    pr1 = get_bpr(pr1, deg-1);
                }
                bpr[v][deg] = pr1;
            }
        }
        return bpr[v][deg];
    };

    function<int(int, int, int)> get_pr = [&](int v, int d, int deg) -> int {
        if (d == 0) return v;
        if ((d&(1<<deg)) == 0) return get_pr(v, d, deg-1);
        d = (d^(1<<deg));
        v = get_bpr(v, deg);
        if (v == -1) return -1;
        return get_pr(v, d, deg-1);
    };

    auto lca = [&](int u, int v) {
        if (depth[u] > depth[v]) u = get_pr(u, depth[u] - depth[v], 19);
        if (depth[u] < depth[v]) v = get_pr(v, depth[v] - depth[u], 19);
        if (u == v) return v;
        int l = 0;
        int r = (1<<20);
        while (l + 1 != r) {
            // l < x <= r
            int m = (l + r) / 2;
            if (get_pr(v, m, 19) == get_pr(u, m, 19)) r = m;
            else l = m;
        }
        return get_pr(v, r, 19);
    };

    for (int i=0;i<m;++i) {
        if (tree.find(i) != tree.end()) continue;
        int u = e[i].first;
        int v = e[i].second;
        int p = lca(u, v);
        if (p == u || p == v) {
            if (p == u) {
                swap(u, v);
            }
            p = get_pr(u, depth[u] - depth[v] - 1, 19);
            // p == v;
            addd(lr[p].first, lr[p].second, -1);
            addd(lr[u].first, lr[u].second, 1);
        } else {
            addd(lr[0].first, lr[0].second, -1);
            addd(lr[u].first, lr[u].second, 1);
            addd(lr[v].first, lr[v].second, 1);
        }
    }

    string s = "";
    for (int i=0;i<n;++i) if (gett(lr[i].second-1) < 0) s += '0'; else s += '1';
    cout << s << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;

/**
 * SCC
 */
template<int V>
struct SCC {
    vector<int> g[V], rg[V];
    void init() {
        for (int i = 0; i < V; i++) {
            g[i].clear(); rg[i].clear();
        }
    }
    /// i-j
    void add(int i, int j) {
//        printf("%d %d\n", i, j);
        g[i].push_back(j);
        rg[j].push_back(i);
    }

    vector<int> vs;
    bool used[V];
    void dfs(int v) {
        used[v] = true;
        for (int d: g[v]) {
            if (!used[d]) dfs(d);
        }
        vs.push_back(v);
    }
    int res[V]; /// res[i] = iID
    vector<int> scc[V]; /// scc[i] = i
    void rdfs(int v, int k) {
        used[v] = true;
        res[v] = k; scc[k].push_back(v);
        for (int d: rg[v]) {
            if (!used[d]) rdfs(d, k);
        }
    }

    int exec(int v) {
        fill_n(used, v, false);
        for (int i = 0; i < v; i++) {
            if (!used[i]) dfs(i);
        }
        fill_n(used, v, false);
        int k = 0;
        for (int i = vs.size()-1; i >= 0; i--) {
            if (!used[vs[i]]) rdfs(vs[i], k++);
        }
        return k;
    }
};

template<int V>
struct TwoSat {
    SCC<2*V> scc;
    void init() {
        scc.init();
    }
    // (x_a == apos) v (x_b == bpos)
    void add(int a, bool apos, int b, bool bpos) {
        scc.add(a+(apos?V:0), b+(bpos?0:V));
        scc.add(b+(bpos?V:0), a+(apos?0:V));
    }
    bool res[V];
    bool exec() {
        scc.exec(2*V);
        for (int i = 0; i < V; i++) {
            if (scc.res[i] == scc.res[i+V]) return false;
            res[i] = scc.res[i] > scc.res[i+V];
        }
        return true;
    }
};

const int MN = 50100;
const int MM = 50100;

TwoSat<270000> ts;
int mc;
void one(vector<int> &v) {
    if (v.size() == 1) return;
    ts.add(mc, false, mc, false);
    mc++;
    for (int i : v) {
        ts.add(i, false, mc-1, false);
        ts.add(i, false, mc, true);
        ts.add(mc-1, false, mc, true);
        mc++;
    }
}

void none(vector<int> &v) {
    if (v.size() == 1) return;
    ts.add(v[0], true, v[1], true);
}

int main() {
    int n, m;
    cin >> n >> m;
    static map<int, vector<int>> mp[MN];
    static vector<int> g[MN];
    static int t[MM];
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c >> t[i]; u--; v--;
        mp[u][c].push_back(i);
        mp[v][c].push_back(i);
        g[u].push_back(i);
        g[v].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        int ma = 0, mc = 0;
        for (auto p : mp[i]) {
            ma = max(ma, (int)p.second.size());
            if (2 <= p.second.size()) mc++;
        }
        if (3 <= ma or 2 <= mc) {
            printf("No\n");
            return 0;
        }
    }
    int l = -1, r = 1e9+10;
    while (r-l > 1) {
        int md = (l+r)/2;
        ts.init();
        mc = m;
        for (int i = 0; i < n; i++) {
            one(g[i]);
            for (auto p: mp[i]) {
                none(p.second);
            }
        }
        for (int i = 0; i < m; i++) {
            if (t[i] > md) {
                ts.add(i, false, i, false);
            }
        }
        if (!ts.exec()) {
//            printf("%d no\n", md);
            l = md;
        } else {
//            printf("%d yes\n", md);
            r = md;
        }
    }
    if (r == 1e9+10) {
        printf("No\n");
        return 0;
    }

    do {
        int md = r;
        ts.init();
        mc = m;
        for (int i = 0; i < n; i++) {
            one(g[i]);
            for (auto p: mp[i]) {
                none(p.second);
            }
        }
        for (int i = 0; i < m; i++) {
            if (t[i] > md) {
                ts.add(i, false, i, false);
            }
        }        
        ts.exec();
    } while (false);

    vector<int> v;
    for (int i = 0; i < m; i++) {
        if (ts.res[i]) v.push_back(i);
    }
    printf("Yes\n");
    printf("%d %d\n", r, (int)v.size());
    for (int d: v) {
        printf("%d ", d+1);
    }
    printf("\n");
    return 0;
}
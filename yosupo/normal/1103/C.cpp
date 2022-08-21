#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

VV<int> g;
int n, k;
V<int> par, dps, vis, leafs;
int path_ans;
void dfs(int p, int b) {
    par[p] = b;
    dps[p] = (b == -1) ? 1 : dps[b] + 1;
    vis[p] = 1;
    if (ll(dps[p]) * k >= n) path_ans = p;
    bool nx = false;
    for (int d: g[p]) {
        if (d == b || vis[d]) continue;
        nx = true;
        dfs(d, p);
    }
    if (!nx) leafs.push_back(p);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int m;
    cin >> n >> m >> k;
    g = VV<int>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    par = V<int>(n); dps = V<int>(n); vis = V<int>(n);
    path_ans = -1;
    dfs(0, -1);
    if (path_ans != -1) {
        V<int> ans;
        int p = path_ans;
        while (p != -1) {
            ans.push_back(p);
            p = par[p];
        }
        cout << "PATH" << endl;
        cout << ans.size() << "\n";
        for (int d: ans) cout << d + 1 << " ";
        cout << "\n";
        return 0;
    }

    assert(int(leafs.size()) >= k);
    leafs.resize(k);

    cout << "CYCLES" << endl;

    for (auto p: leafs) {
        int sp = -1, tp = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x = g[p][i], y = g[p][j];
                if (dps[x] >= dps[y]) continue;
                int di = 2 + dps[y] - dps[x];
                if (di % 3 == 0) continue;
                sp = y; tp = x;
            }
        }
        assert(sp != -1);
        V<int> ans;
        ans.push_back(p);
        while (sp != par[tp]) {
            ans.push_back(sp);
            sp = par[sp];
        }

        cout << ans.size() << "\n";
        for (int d: ans) cout << d + 1 << " ";
        cout << "\n";
    }

    return 0;
}
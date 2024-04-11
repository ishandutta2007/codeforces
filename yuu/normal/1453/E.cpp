#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[200001];
bool done[200001];
int depth[200001];
int ans;
int k;
bool dfs(int u) {
    done[u] = 1;
    depth[u] = 0;
    for (auto&& v : g[u])
        if (done[v]) {
            swap(v, g[u].back());
            g[u].pop_back();
            break;
        }
    if (g[u].empty()) return true;
    for (auto&& v : g[u])
        if (!dfs(v)) return false;
    int max_depth = 0, min_depth = 1e9;
    for (auto&& v : g[u]) max_depth = max(max_depth, depth[v]);
    for (auto&& v : g[u]) min_depth = min(min_depth, depth[v]);
    if (max_depth + 1 > k) return false;
    if (max_depth + 2 <= k) {
        depth[u] = min_depth + 1;
        return true;
    }
    // max_depth + 2 > k
    // max_depth + 1 <= k
    // -> max_depth == k - 1
    depth[u] = max_depth + 1;
    for (auto&& v : g[u]) {
        if (depth[v] == max_depth) {
            max_depth = -1;
        } else {
            if (depth[v] + 2 > k) return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int low = 1, high = n, mid, res = 0;
    while (low <= high) {
        k = (low + high) / 2;
        for (int i = 1; i <= n; i++) done[i] = 0;
        if (dfs(1)) {
            res = k;
            high = k - 1;
        } else {
            low = k + 1;
        }
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
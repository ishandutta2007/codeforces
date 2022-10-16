#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> g[100001];
int ans[100001];
bool done[100001];

void dfs(int u, int val = 2) {
    done[u] = 1;
    for (auto&& [v, i] : g[u]) {
        if (!done[v]) {
            ans[i] = val;
            dfs(v, 5 - val);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 2) {
            cout << "-1\n";
            return;
        }
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1) {
            dfs(i);
            break;
        }
    for (int i = 1; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
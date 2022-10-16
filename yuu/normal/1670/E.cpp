#include <bits/stdc++.h>
using namespace std;
int p, n;
vector<pair<int, int>> g[(1 << 17) + 1];
int ver_number[(1 << 17) + 1];
int edge_number[(1 << 17) + 1];
bool done[(1 << 17) + 1];
int cnt;
void dfs(int u, int value = 0) {
    value ^= ver_number[u];
    assert((value == 0) || (value == n));
    done[u] = 1;
    for (auto&& [v, id] : g[u])
        if (!done[v]) {
            cnt++;
            if (value == n) {
                edge_number[id] = n + cnt;
                ver_number[v] = cnt;
            } else {
                edge_number[id] = cnt;
                ver_number[v] = n + cnt;
            }
            dfs(v, value ^ edge_number[id]);
        }
}
void solve() {
    cin >> p;
    n = (1 << p);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    cnt = 0;
    ver_number[1] = n;
    dfs(1);
    cout << 1 << '\n';
    for (int i = 1; i <= n; i++) cout << ver_number[i] << " \n"[i == n];
    for (int i = 1; i < n; i++) cout << edge_number[i] << " \n"[i + 1 == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
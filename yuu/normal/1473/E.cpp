#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> g[200001];
constexpr int64_t inf = 1e18;
int64_t first[200001][2];
int64_t second[200001][2];

void dijkstra(int64_t f[200001][2]) {
    priority_queue<tuple<int64_t, int, int>, vector<tuple<int64_t, int, int>>, greater<tuple<int64_t, int, int>>> q;
    for (int i = 1; i <= n; i++)
        for (int b = 0; b <= 1; b++)
            if (f[i][b] != inf) q.emplace(f[i][b], i, b);
    while (!q.empty()) {
        auto [weight, u, b] = q.top();
        q.pop();
        if (f[u][b] != weight) continue;
        for (auto&& [v, w] : g[u]) {
            if (f[v][b] > weight + w) {
                f[v][b] = weight + w;
                q.emplace(f[v][b], v, b);
            }
            if (b == 0) {
                if (f[v][1] > weight + w + w) {
                    f[v][1] = weight + w + w;
                    q.emplace(f[v][1], v, 1);
                }
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) first[i][0] = first[i][1] = inf;
    for (int i = 1; i <= n; i++) second[i][0] = second[i][1] = inf;
    first[1][0] = 0;
    dijkstra(first);
    for (int u = 1; u <= n; u++) {
        for (auto&& [v, w] : g[u]) {
            for (int b = 0; b <= 1; b++) second[v][b] = min(second[v][b], first[u][b]);
            second[v][1] = min(second[v][1], first[u][0] + w);
        }
    }
    dijkstra(second);
    for (int i = 2; i <= n; i++) cout << second[i][1] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
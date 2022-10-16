#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[100001];
bool done[100001][51];
int low[100001];
int64_t f[100001][51];
priority_queue<tuple<int64_t, int, int>, vector<tuple<int64_t, int, int>>, greater<tuple<int64_t, int, int>>> q;
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) low[i] = 1e9;
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= 50; w++) f[i][w] = 1e18;
    q.emplace(0, 1, 0);
    f[1][0] = 0;
    while (!q.empty()) {
        auto [weight, u, in_w] = q.top();
        q.pop();
        if (f[u][in_w] != weight) continue;
        if (in_w >= low[u]) continue;
        if (in_w) low[u] = in_w;
        if (in_w == 0) {
            for (auto&& [v, out_w] : g[u])
                if (out_w < low[v]) {
                    if (f[v][out_w] > weight + out_w * out_w) {
                        f[v][out_w] = weight + out_w * out_w;
                        q.emplace(f[v][out_w], v, out_w);
                    }
                }
        } else {
            for (auto&& [v, out_w] : g[u]) {
                if (f[v][0] > weight + out_w * out_w + in_w * out_w * 2) {
                    f[v][0] = weight + out_w * out_w + in_w * out_w * 2;
                    q.emplace(f[v][0], v, 0);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (f[i][0] == 1e18) f[i][0] = -1;
        cout << f[i][0] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
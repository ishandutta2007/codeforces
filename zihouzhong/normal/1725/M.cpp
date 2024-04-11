#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n), rG(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].emplace_back(v, w);
        rG[v].emplace_back(u, w);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
    vector dist(n, LLONG_MAX);
    Q.emplace(dist[0] = 0, 0);
    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        if (d != dist[u]) continue;
        for (auto &[v, w] : G[u]) {
            if (dist[v] > d + w) Q.emplace(dist[v] = d + w, v);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] < (ll)1e18) Q.emplace(dist[i], i);
    }
    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        if (d != dist[u]) continue;
        for (auto &[v, w] : rG[u]) {
            if (dist[v] > d + w) Q.emplace(dist[v] = d + w, v);
        }
    }
    for (int i = 1; i < n; i++) {
        if (dist[i] > (ll)1e18) cout << "-1 ";
        else cout << dist[i] << " ";
    }
    return 0;
}
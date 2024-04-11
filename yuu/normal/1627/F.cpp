#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int>> g[300000];
int wd[500][500];
int wr[500][500];
int vertex_count;
int f[300001];
void AddCost(int r_1, int c_1, int r_2, int c_2) {
    if (r_1 == r_2) {
        wd[r_1 - 1][min(c_1, c_2)]++;
    } else {
        wr[min(r_1, r_2)][c_1 - 1]++;
    }
}

int GetId(int r, int c) {
    if (r == 0 || r == k) return 0;
    if (c == 0 || c == k) return 0;
    return c + (r - 1) * (k - 1);
}

void AddEdge(int a, int b, int c) {
    if (b) g[b].emplace_back(a, c);
    if (a) g[a].emplace_back(b, c);
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int ShortestPath(int source) {
    for (int i = 0; i <= vertex_count; i++) f[i] = 1e9;
    f[source] = 0;
    while (!q.empty()) q.pop();
    q.push({0, source});
    while (!q.empty()) {
        auto [dist, u] = q.top();
        q.pop();
        if (dist > f[u]) continue;
        if (u == 0) return dist;
        for (auto&& [v, cost] : g[u]) {
            if (f[v] > f[u] + cost) {
                f[v] = f[u] + cost;
                q.push({f[v], v});
            }
        }
    }
    assert(false);
    return -1;
}

void solve() {
    cin >> n >> k;
    vertex_count = (k - 1) * (k - 1) + 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) wd[i][j] = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) wr[i][j] = 0;
    for (int i = 1, r_1, c_1, r_2, c_2; i <= n; i++) {
        cin >> r_1 >> c_1 >> r_2 >> c_2;
        AddCost(r_1, c_1, r_2, c_2);
        r_1 = k - r_1 + 1;
        r_2 = k - r_2 + 1;
        c_1 = k - c_1 + 1;
        c_2 = k - c_2 + 1;
        AddCost(r_1, c_1, r_2, c_2);
    }
    for (int i = 0; i <= vertex_count; i++) g[i].clear();
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            AddEdge(GetId(i, j), GetId(i + 1, j), wd[i][j]);
            AddEdge(GetId(i, j), GetId(i, j + 1), wr[i][j]);
        }
    }

    cout << n - ShortestPath(GetId(k / 2, k / 2)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int n;
int c[300001];
bool done[300001];
vector<int> g[300001];

int black_near[300001];
int black_total[300001];
int good_count[300001];

vector<int> path;

int ans[300001];
void dfs(int u) {
    done[u] = 1;
    black_near[u] = black_total[u] = c[u];
    good_count[u] = 0;
    path.push_back(u);
    for (int v : g[u])
        if (!done[v]) {
            dfs(v);
            path.push_back(u);
            black_total[u] += black_total[v];
            black_near[u] += c[v];
            good_count[u] += good_count[v];
        }
    if (black_near[u] && (black_total[u] > 1)) good_count[u]++;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int root = 1;
    path.erase(path.begin());
    for (int u : path) {  // make u the root
        if (black_near[root] && (black_total[root] > 1)) good_count[root]--;
        black_total[root] -= black_total[u];
        black_near[root] -= c[u];
        good_count[root] -= good_count[u];
        if (black_near[root] && (black_total[root] > 1)) good_count[root]++;

        if (black_near[u] && (black_total[u] > 1)) good_count[u]--;
        black_total[u] += black_total[root];
        black_near[u] += c[root];
        good_count[u] += good_count[root];
        if (black_near[u] && (black_total[u] > 1)) good_count[u]++;
        root = u;

        if (good_count[root] || black_near[root]) ans[root] = 1;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[200001];
int p[200001];
int a[200001];
bool done[200001];
vector<int> level[200001];
int64_t f[200001];
deque<pair<int, int64_t>> up;
void dfs(int u, int h = 1) {
    level[h].push_back(u);
    done[u] = 1;
    for (auto&& v : g[u])
        if (done[v]) {
            swap(v, g[u].back());
            g[u].pop_back();
            break;
        }
    for (auto&& v : g[u]) {
        p[v] = u;
        dfs(v, h + 1);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) level[i].clear();
    for (int i = 2, v; i <= n; i++) {
        cin >> v;
        g[i].push_back(v);
        g[v].push_back(i);
    }
    for (int i = 2; i <= n; i++) cin >> a[i];
    dfs(1);
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (level[i].empty()) break;
        sort(level[i].begin(), level[i].end(), [](const int& x, const int& y) { return a[x] < a[y]; });
        // no swap
        for (auto&& u : level[i - 1]) {
            for (auto&& v : g[u]) {
                f[v] = f[u] + max(abs(a[v] - a[level[i][0]]), abs(a[v] - a[level[i].back()]));
            }
        }
        // swap
        up.clear();
        for (auto&& v : level[i]) {
            int64_t weight = f[p[v]] + a[v];
            while ((!up.empty()) && (weight >= up.back().second)) up.pop_back();

            up.emplace_back(a[v], weight);
        }

        int64_t max_down = -1e18;
        for (auto&& v : level[i]) {
            f[v] = max(f[v], max_down + a[v]);
            max_down = max(max_down, f[p[v]] - a[v]);
            while ((!up.empty()) && (up.front().first < a[v])) up.pop_front();
            if (!up.empty()) f[v] = max(f[v], up.front().second - a[v]);
        }
    }
    cout << *max_element(f + 1, f + n + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
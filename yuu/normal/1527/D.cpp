#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[200000];
bool done[200000];
int p[200000];
int f[200000];
bool added[200000];
int64_t path[200001];
void dfs(int u) {
    done[u] = 1;
    f[u] = 1;
    for (auto&& v : g[u])
        if (done[v]) {
            swap(v, g[u].back());
            g[u].pop_back();
            break;
        }
    for (auto&& v : g[u]) {
        p[v] = u;
        dfs(v);
        f[u] += f[v];
    }
}
set<int> children[200001];
set<int> bottom;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < n; i++) done[i] = 0;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i <= n; i++) path[i] = 0;
    for (int i = 0; i < n; i++) added[i] = 0;
    path[0] = static_cast<int64_t>(n) * (n - 1) / 2;
    {
        int64_t sum = 1;
        for (auto&& u : g[0]) {
            path[1] += sum * f[u];
            sum += f[u];
        }
    }
    bottom.clear();
    for (int i = 0; i < n; i++) children[i].clear();
    added[0] = 1;
    for (int i = 1; i < n; i++) {
        int k = i;
        if (!added[k]) {
            bottom.insert(k);
            added[k] = 1;
            children[p[k]].insert(k);
            bottom.erase(p[k]);
            if ((p[k]) && (children[p[k]].size() > 1)) goto finalise;
            k = p[k];
            while (!added[k]) {
                added[k] = 1;
                children[p[k]].insert(k);
                bottom.erase(p[k]);
                if ((p[k]) && (children[p[k]].size() > 1)) goto finalise;
                k = p[k];
            }
        }
        if (bottom.size() > 2) break;
        if (bottom.size() == 2) {
            path[i + 1] = static_cast<int64_t>(f[*bottom.begin()]) * (f[*bottom.rbegin()]);
        } else {
            path[i + 1] = static_cast<int64_t>(f[*bottom.begin()]) * (f[0] - f[*children[0].begin()]);
        }
    }
finalise:;
    for (int i = 0; i < n; i++) path[i] -= path[i + 1];
    for (int i = 0; i <= n; i++) cout << path[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
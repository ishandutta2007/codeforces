#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[200001];
vector<int> part[2];
bool done[200001];
int ans[200001];
vector<int> lg[20];
void dfs(int u, int b) {
    done[u] = 1;
    part[b].push_back(u);
    for (int v : g[u])
        if (!done[v]) dfs(v, 1 - b);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    part[0].clear();
    part[1].clear();
    dfs(1, 0);
    if (part[0].size() > part[1].size()) swap(part[0], part[1]);
    for (int i = 1; i <= n; i++) lg[__lg(i)].push_back(i);

    while (!part[0].empty()) {
        int use = __lg(part[0].size());
        while (!lg[use].empty()) {
            ans[part[0].back()] = lg[use].back();
            part[0].pop_back();
            lg[use].pop_back();
        }
    }
    assert(part[0].empty());
    for (int use = 0; use < 20; use++)
        while (!lg[use].empty()) {
            ans[part[1].back()] = lg[use].back();
            part[1].pop_back();
            lg[use].pop_back();
        }
    assert(part[1].empty());
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
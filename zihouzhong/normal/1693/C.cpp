#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, f[maxn], cnt[maxn];
bool vis[maxn];
vector<int> G[maxn], rG[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        G[u].push_back(v), rG[v].push_back(u);
    }
    memset(f, 0x3f, sizeof(f));
    set<pair<int, int>> S;
    S.emplace(f[n] = 0, n);
    while (!S.empty()) {
        int u = S.begin()->second; S.erase(S.begin());
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v : rG[u]) cnt[v]--;
        for (int v : rG[u]) {
            if (f[v] > f[u] + 1 + cnt[v]) {
                S.emplace(f[v] = f[u] + 1 + cnt[v], v);
            }
        }
    }
    cout << f[1] << "\n";
    return 0;
}
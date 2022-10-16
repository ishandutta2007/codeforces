#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int b[200001];
vector<int> pos[200001];
vector<int> g[200001];
int done[200001];
bool dfs(int u, int b = 1) {
    // cerr << u << ' ' << b << '\n';
    if (done[u]) return done[u] == b;
    done[u] = b;
    for (auto&& v : g[u])
        if (!dfs(v, 3 - b)) return false;
    return true;
}
void solve() {
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) pos[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        pos[a[i]].emplace_back(i);
        pos[b[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
        if (pos[i].size() != 2) {
            cout << "NO\n";
            return;
        }
        g[pos[i][0]].emplace_back(pos[i][1]);
        g[pos[i][1]].emplace_back(pos[i][0]);
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (done[i]) continue;
        if (!dfs(i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
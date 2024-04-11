#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100001];
bool done[100001];
int x[100001];
vector <int> g[100001];
void dfs(int u) {
    done[u] = 1;
    x[u] = a[u];
    for (int v : g[u])
        if (!done[v]) {
            dfs(v);
            x[u] ^= x[v];
        }
}
int get(int u, bool p0 = 0) {
    done[u]=1;
    int res = 0;
    for (int v : g[u])
        if (!done[v]) {
            int val = get(v, p0 || (x[u] == 0));
            if (val > 0)
                return 1;
            else if (val < 0) {
                if (res == -1) return 1;
                res = -1;
            }
        }

    if (x[u] == x[1]) {
        if (p0)
            return 1;
        else
            res = -1;
    }
    return res;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    if (x[1] == 0) {
        cout << "YES\n";
        return;
    }
    if (k == 2) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    int res = get(1);
    if (res > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
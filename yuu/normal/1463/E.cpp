#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> g[300001];
int p[300001];
int pv[300001];
int nx[300001];
int r[300001];
int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}
void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (r[u] > r[v]) swap(u, v);
    r[u] += r[v];
    r[v] = u;
}
vector<int> order;
int done[300001];
bool dfs(int u) {
    done[u] = 1;
    for (auto&& v : g[u])
        if (!done[v]) {
            if (dfs(v)) return true;
        } else if (done[v] == 1) {
            return true;
        }
    done[u] = -1;
    order.push_back(u);
    return false;
}

void print_group(int u) {
    while (pv[u]) u = pv[u];
    do {
        cout << u << ' ';
        u = nx[u];
    } while (u);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++)
        if (p[i]) g[p[i]].push_back(i);
    for (int i = 1; i <= n; i++) r[i] = -1;
    for (int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
        pv[y] = x;
        nx[x] = y;
        g[x].push_back(y);
        unite(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (!done[i]) {
            if (dfs(i)) {
                cout << "0\n";
                return;
            }
        }
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) g[i].clear();
    order.clear();
    for (int i = 1; i <= n; i++)
        if (p[i]) {
            if (root(p[i]) != root(i)) g[root(p[i])].push_back(root(i));
        }
    for (int i = 1; i <= n; i++)
        if (i == root(i))
            if (!done[i]) {
                if (dfs(i)) {
                    cout << "0\n";
                    return;
                }
            }
    reverse(order.begin(), order.end());
    for (auto&& x : order) print_group(x);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
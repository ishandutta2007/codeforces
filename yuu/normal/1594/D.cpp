#include <bits/stdc++.h>
using namespace std;
int n, m;
int r[400001];
int f[400001];
bool done[400001];
int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}
void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (r[u] > r[v]) {
        swap(u, v);
    }
    r[u] += r[v];
    r[v] = u;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++) r[i] = -1;
    for (int i = 1; i <= n * 2; i++) f[i] = 0;
    for (int i = 1; i <= n * 2; i++) done[i] = 0;
    string s;
    for (int i = 1, j, k; i <= m; i++) {
        cin >> j >> k >> s;
        if (s == "imposter") {
            unite(j, k + n);
            unite(j + n, k);

        } else {
            unite(j, k);
            unite(j + n, k + n);
        }
    }
    for (int i = 1; i <= n; i++)
        if (root(i) == root(i + n)) {
            cout << "-1\n";
            return;
        }
    for (int i = 1; i <= n; i++) f[root(i + n)]++;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!done[root(i)]) {
            done[root(i)] = 1;
            done[root(i + n)] = 1;
            ans += max(f[root(i)], f[root(i + n)]);
        }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
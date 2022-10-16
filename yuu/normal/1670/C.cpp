#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int b[100001];
int d[100001];
int r[100001];
bool done[100001];
constexpr int base = 1e9 + 7;
int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (r[u] > r[v]) swap(u, v);
    r[u] += r[v];
    r[v] = u;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) r[i] = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) d[i] = a[i];
        unite(a[i], b[i]);
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++)
        if (d[i]) done[root(a[i])] = 1;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) {
            int r = root(a[i]);
            if (done[r]) continue;
            done[r] = 1;
            (ans *= 2) %= base;
        }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
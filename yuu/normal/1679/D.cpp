#include <bits/stdc++.h>
using namespace std;
int n, m;
int64_t k;
int a[200001];
int limit;
vector<int> g[200001];
int64_t f[200001];
bool done[200001];
int64_t F(int u) {
    if (done[u]) return f[u];
    done[u] = 1;
    f[u] = k;
    int64_t actual = 0;
    for (auto&& v : g[u])
        if (a[v] <= limit) actual = max(actual, F(v));
    f[u] = actual + 1;
    if (f[u] >= k) f[u] = k;
    return f[u];
}
bool check(int lim) {
    limit = lim;
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] <= limit) {
            int64_t res = F(i);
            if (res >= k) return 1;
        }
    return 0;
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    int low = 1, high = *max_element(a + 1, a + n + 1), mid, res = 1e9 + 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (res == 1e9 + 1) res = -1;
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
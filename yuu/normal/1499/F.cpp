#include <bits/stdc++.h>
using namespace std;
vector<int> g[5001];
int n, k;
bool done[5001];
int f[5001][5001];
constexpr int base = 998'244'353;
void dfs(int u) {
    done[u] = 1;
    for (auto&& v : g[u])
        if (done[v]) {
            swap(v, g[u].back());
            g[u].pop_back();
            break;
        }
    for (auto&& v : g[u]) {
        // cerr << "edge: " << u << ' ' << v << '\n';
        dfs(v);
    }
    f[u][0] = 1;
    static int64_t updated[5001];
    for (auto&& v : g[u]) {
        int64_t weight_u = 0;
        int64_t weight_v = 0;
        int high_u = -1;
        int high_v = -1;
        int64_t sum_v = 0;
        for (int i = 0; i <= k; i++) sum_v += f[v][i];
        sum_v %= base;
        for (int i = 0; i <= k; i++) {
            updated[i] = 0;
            updated[i] += sum_v * f[u][i];  // cut the u-v edge
            // no cut
            // reject case that would lead to diameter > k
            int bound_v = min(i - 1, k - i - 1);
            while (high_v > bound_v) {
                (weight_v -= f[v][high_v]) %= base;
                high_v--;
            }
            while (high_v < bound_v) {
                high_v++;
                (weight_v += f[v][high_v]) %= base;
            }
            updated[i] += (weight_v * f[u][i]);  // current edge to i is bigger or equal to edge from v

            int bound_u = min(i - 1, k - i);
            while (high_u > bound_u) {
                (weight_u -= f[u][high_u]) %= base;
                high_u--;
            }
            while (high_u < bound_u) {
                high_u++;
                (weight_u += f[u][high_u]) %= base;
            }
            if (i) updated[i] += (weight_u * f[v][i - 1]);  // current edge i is less than the edge from v
        }
        for (int i = 0; i <= k; i++) {
            f[u][i] = updated[i] % base;
            if (f[u][i] < 0) f[u][i] += base;
        }
    }
    // cerr << "vertex: " << u << '\n';
    // for (int i = 0; i <= k; i++) cerr << f[u][i] << " \n"[i == k];
}
void solve() {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int64_t ans = 0;
    for (int i = 0; i <= k; i++) (ans += f[1][i]) %= base;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
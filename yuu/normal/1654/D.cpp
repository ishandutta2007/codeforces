#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[200001];
int mx[200001];
int p[200001];
int inv[200001];
constexpr int base = 998'244'353;
int64_t power(int64_t a, int64_t x) {
    int64_t res = 1;
    while (x > 0) {
        if (x % 2) (res *= a) %= base;
        (a *= a) %= base;
        x /= 2;
    }
    return res;
}
void prepare() {
    int n = 2e5;
    for (int i = 2; i <= n; i++)
        if (p[i] == 0)
            for (int j = i; j <= n; j += i)
                if (p[j] == 0) p[j] = i;
    for (int i = 1; i <= n; i++) inv[i] = power(i, base - 2);
}

void factorise(int u, int v) {  // factorise u / v and add it to the sum
    // cerr << "u v : " << u << ' ' << v << '\n';
    while (u > 1) {
        cnt[p[u]]--;
        u /= p[u];
    }
    while (v > 1) {
        cnt[p[v]]++;
        mx[p[v]] = max(mx[p[v]], cnt[p[v]]);
        v /= p[v];
    }
}
vector<tuple<int, int, int>> g[200001];
bool done[200001];
void dfs(int u) {
    // cerr << u << '\n';
    done[u] = 1;
    for (auto&& p : g[u]) {
        auto&& [v, x, y] = p;
        if (done[v]) {
            swap(p, g[u].back());
            g[u].pop_back();
            break;
        }
    }
    for (auto&& [v, x, y] : g[u]) {
        factorise(y, x);
        dfs(v);
        factorise(x, y);
    }
}
int64_t ans = 0;
void calculate_sum(int u, int64_t w) {
    (ans += w) %= base;
    for (auto&& [v, x, y] : g[u]) calculate_sum(v, ((w * y) % base * inv[x]) % base);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int c = 1, i, j, x, y; c < n; c++) {
        cin >> i >> j >> x >> y;
        g[i].emplace_back(j, x, y);
        g[j].emplace_back(i, y, x);
    }
    for (int i = 1; i <= n; i++) done[i] = 0;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) mx[i] = 0;
    dfs(1);
    int64_t w_1 = 1;
    for (int i = 1; i <= n; i++) {
        // if (mx[i]) cerr << i << ' ' << mx[i] << '\n';
        for (int j = 0; j < mx[i]; j++) (w_1 *= i) %= base;
    }
    ans = 0;
    calculate_sum(1, w_1);
    cout << ans << '\n';
}
int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> zeros[31];
int n, m;
bool a[200001];
int cnt[200002];
constexpr int base = 1e9 + 7;
void solve() {
    cin >> n >> m;
    for (int i = 0; i <= 30; i++) zeros[i].clear();
    for (int i = 1, l, r, x; i <= m; i++) {
        cin >> l >> r >> x;
        for (int pos = 0; pos <= 30; pos++)
            if (((x >> pos) & 1) == 0) {
                zeros[pos].emplace_back(l, r);
            }
    }
    int64_t ans = 0;
    for (int i = 0; i <= 30; i++) {
        for (int j = 1; j <= n; j++) cnt[j] = 0;
        for (auto&& [l, r] : zeros[i]) {
            cnt[l]++;
            cnt[r + 1]--;
        }
        for (int j = 1; j <= n; j++) {
            cnt[j] += cnt[j - 1];
            if (cnt[j] == 0)
                a[j] = 1;
            else
                a[j] = 0;
        }
        int f[2];
        f[0] = 1;
        f[1] = 0;
        int g[2];
        g[0] = f[0];
        g[1] = f[1];
        for (int j = 1; j <= n; j++) {
            if (a[j] == 0) {
                g[0] += f[0];
                g[1] += f[1];
            } else {
                g[0] += f[1];
                g[1] += f[0];
            }
            if (g[0] >= base) g[0] -= base;
            if (g[1] >= base) g[1] -= base;
            f[0] = g[0];
            f[1] = g[1];
        }
        (ans += (static_cast<int64_t>(f[1]) << i)) %= base;
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
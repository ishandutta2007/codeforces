#include <bits/stdc++.h>
using namespace std;
int n, k;
int64_t f[251][251];
int64_t c[251][251];
constexpr int base = 998244353;
int triangle[251];
int64_t power[251][31376];
void solve() {
    for (int i = 1; i <= 250; i++) triangle[i] = triangle[i - 1] + i;
    for (int i = 1; i <= 250; i++) {
        power[i][0] = 1;
        for (int j = 1; j <= 31375; j++) (power[i][j] = power[i][j - 1] * i) %= base;
    }
    for (int i = 0; i <= 250; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) (c[i][j] = c[i - 1][j - 1] + c[i - 1][j]) %= base;
    }

    cin >> n >> k;
    f[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (f[i][j]) {
                for (int nj = j + 1; nj <= k; nj++) {
                    for (int ni = i + 1; ni <= n; ni++) {
                        (f[ni][nj] += (f[i][j] * c[n - i][ni - i]) % base *
                                      power[k - nj + 1][triangle[ni - 2] - (i >= 2 ? triangle[i - 2] : 0)]) %= base;
                    }
                }
            }
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= k; i++) ans += f[n][i];
    ans %= base;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
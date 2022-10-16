#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int base = 998244353;
int64_t f[500003][2];
void Add(int64_t& val, const int64_t& add) {
    val += add;
    while (val >= base) val -= base;
}
void solve() {
    cin >> n;
    for (int i = 0, a; i <= n; i++) f[i][0] = f[i][1] = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a == 0) {
            Add(f[0][1], f[0][1] + 1);
            Add(f[2][0], f[2][0]);
        } else if (a == 1) {
            Add(f[1][1], f[0][1] + f[1][1]);
            Add(f[1][0], f[1][0] + 1);
            Add(f[3][0], f[3][0]);
        } else {
            Add(f[a][1], f[a - 1][1] + f[a][1]);
            Add(f[a][0], f[a][0] + f[a - 2][1]);
            Add(f[a + 2][0], f[a + 2][0]);
        }
    }
    int64_t ans = 0;
    for (int i = 0; i <= n; i++) ans += f[i][0] + f[i][1];
    ans %= base;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
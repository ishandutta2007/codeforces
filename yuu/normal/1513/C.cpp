#include <bits/stdc++.h>
using namespace std;
int f[200001][10];
constexpr int base = 1e9 + 7;
int n, m;
void prepare() {
    for (int i = 0; i < 10; i++) f[0][i] = 1;
    for (int i = 1; i <= 200000; i++) {
        for (int j = 0; j <= 8; j++) f[i][j] = f[i - 1][j + 1];
        f[i][9] = f[i - 1][0] + f[i - 1][1];
        if (f[i][9] >= base) f[i][9] -= base;
    }
}
void solve() {
    cin >> n >> m;
    int ans = 0;
    while (n > 0) {
        (ans += f[m][n % 10]) %= base;
        n /= 10;
    }
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
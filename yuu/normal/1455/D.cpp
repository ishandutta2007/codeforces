#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[501][501];
int g[501][501];
void solve() {
    cin >> n >> x;
    for (int mx = 0; mx <= 500; mx++)
        for (int x = 0; x <= 500; x++) f[mx][x] = 1e9;
    f[0][x] = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        for (int mx = 0; mx <= 500; mx++)
            for (int x = 0; x <= 500; x++) g[mx][x] = 1e9;
        for (int mx = 0; mx <= 500; mx++)
            for (int x = 0; x <= 500; x++)
                if (f[mx][x] < 1e9) {
                    if (mx <= a) g[a][x] = min(g[a][x], f[mx][x]);
                    if ((x >= mx) && (x < a)) g[x][a] = min(g[x][a], f[mx][x] + 1);
                }
        for (int mx = 0; mx <= 500; mx++)
            for (int x = 0; x <= 500; x++) f[mx][x] = g[mx][x];
    }
    int ans = 1e9;
    for (int mx = 0; mx <= 500; mx++)
        for (int x = 0; x <= 500; x++) ans = min(ans, f[mx][x]);
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ;
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int n, l, k;
int d[502];
int a[502];
int f[502][502];
void solve() {
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++) f[i][j] = 1e9;
    f[0][0] = 0;
    d[n] = l;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int prev = i - 1; prev >= 0; prev--) {
                if (i - prev - 1 > j) break;
                f[i][j] = min(f[i][j], f[prev][j - (i - prev - 1)] + a[prev] * (d[i] - d[prev]));
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= k; i++) ans = min(ans, f[n][i]);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
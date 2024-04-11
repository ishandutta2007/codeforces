#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[5001];
int64_t b[5001];
int64_t sum[10001];
int64_t suffix[5002];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) sum[i + j] += a[i] * b[j];
    for (int i = n; i >= 1; i--) suffix[i] = suffix[i + 1] + a[i] * b[i];
    int64_t ans = sum[n + 1];  // reverse all
    int64_t prefix = 0;
    for (int i = 1; i <= n; i++) {
        // a[i] is the first element to be reversed
        for (int j = i; j <= n; j++) ans = max(ans, prefix + sum[i + j] + suffix[j + 1]);
        for (int j = i; j <= n; j++) sum[i + j] -= a[i] * b[j];
        for (int j = i + 1; j <= n; j++) sum[i + j] -= b[i] * a[j];
        prefix += a[i] * b[i];
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
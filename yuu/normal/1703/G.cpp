#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    int64_t f[32];
    cin >> n >> k;
    for (int i = 0; i <= 30; i++) f[i] = 0;
    int64_t ans = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        for (int j = 30; j >= 0; j--) {
            f[j + 1] = max(f[j + 1], f[j] + (a >> (j + 1)));
            f[j] += (a >> j) - k;
        }
        ans = max(ans, *max_element(f, f + 31));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int64_t n;
int c[100001];
int mi[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    mi[1] = c[1];
    mi[2] = c[2];
    for (int i = 3; i <= n; i++) mi[i] = min(c[i], mi[i - 2]);
    int64_t ans = 1e18;
    int64_t weight = c[1];
    for (int64_t last = 2; last <= n; last++) {
        weight += c[last];
        if (last % 2) {
            ans = min(ans, weight + (n - last / 2 - 1) * mi[last] + (n - last / 2) * (mi[last - 1]));
        } else {
            ans = min(ans, weight + (n - last / 2) * mi[last] + (n - last / 2) * (mi[last - 1]));
        }
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
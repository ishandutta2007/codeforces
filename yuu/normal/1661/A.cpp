#include <bits/stdc++.h>
using namespace std;
int n;
int a[26];
int b[26];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int64_t ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += min(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]), abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
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
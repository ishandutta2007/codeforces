#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mx = 0;
    for (int i = 2; i < n; i++) mx = max(mx, abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i - 1]));
    for (int i = n; i >= 1; i--) a[i] -= a[i - 1];
    mx = max(mx, abs(a[2]));
    mx = max(mx, abs(a[n]));
    int64_t ans = -mx;
    for (int i = 2; i <= n; i++) ans += abs(a[i]);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
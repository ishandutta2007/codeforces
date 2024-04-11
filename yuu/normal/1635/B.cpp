#include <bits/stdc++.h>
using namespace std;
int n;
int a[200002];
void solve() {
    cin >> n;
    a[0] = a[n + 1] = 1e9;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            a[i + 1] = max(a[i + 2], a[i]);
            ans++;
        }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
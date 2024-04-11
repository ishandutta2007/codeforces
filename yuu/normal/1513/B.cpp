#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
constexpr int base = 1e9 + 7;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int total_and = a[1];
    for (int i = 1; i <= n; i++) total_and &= a[i];
    int count_total_and = 0;
    for (int i = 1; i <= n; i++) count_total_and += a[i] == total_and;
    if (count_total_and < 2) {
        cout << "0\n";
        return;
    }
    int64_t ans = 1;
    ans *= count_total_and;
    ans *= count_total_and - 1;
    ans %= base;
    for (int i = 1; i <= n - 2; i++) (ans *= i) %= base;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
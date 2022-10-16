#include <bits/stdc++.h>
using namespace std;
int n, k;
constexpr int base = 1e9 + 7;
void solve() {
    cin >> n >> k;
    int64_t ans = 1;
    for (int i = 1; i <= k; i++) (ans *= n) %= base;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int64_t n, x, t;
void solve() {
    cin >> n >> x >> t;
    int64_t val = t / x;
    if (val >= n) {
        cout << n * (n - 1) / 2 << '\n';
        return;
    }
    int64_t ans = val * n;
    ans -= val * (val + 1) / 2;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
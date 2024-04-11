#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    // bn + n <= x
    // n < b
    // b <= y
    y++;
    int64_t ans = 0;
    for (int n = 1;; n++) {
        int high_b = min(x / n, y);
        int low_b = n + 2;
        if (high_b < low_b) break;
        ans += high_b - low_b + 1;
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
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, B, x, y;
    cin >> n >> B >> x >> y;
    int a = 0;
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a + x <= B) {
            a += x;
        } else {
            a -= y;
        }
        ans += a;
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
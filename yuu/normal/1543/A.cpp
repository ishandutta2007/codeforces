#include <bits/stdc++.h>
using namespace std;
int64_t a, b;
void solve() {
    cin >> a >> b;
    if (a == b) {
        cout << 0 << ' ' << 0 << '\n';
    } else {
        int64_t ans = abs(a - b);
        int64_t step = b % ans;
        if (step > ans - step) step = ans - step;
        cout << ans << ' ' << step << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
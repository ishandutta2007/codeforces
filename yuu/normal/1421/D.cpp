#include <bits/stdc++.h>
using namespace std;
void solve() {
    // z = x + y
    int64_t x, y, z = 0;
    cin >> x >> y;
    int c[7];
    for (int i = 0; i < 6; i++) cin >> c[i];
    for (int i = 1; i <= 100; i++)
        for (int j = 0; j < 6; j++) c[j] = min(c[j], c[(j + 5) % 6] + c[(j + 1) % 6]);
    auto get_cost = [&c](int64_t magnitude, int64_t direction) -> int64_t {
        if (direction == 0) {  // x
            if (magnitude > 0) return magnitude * c[5];
            else return -magnitude * c[2];
        } else if (direction == 1) {  // y
            if (magnitude > 0) return magnitude * c[1];
            else return -magnitude * c[4];
        } else {  // z
            if (magnitude > 0) return magnitude * c[0];
            else return -magnitude * c[3];
        }
    };
    int64_t ans = 2e18 + 1;
    ans = min(ans, get_cost(x, 0) + get_cost(y, 1) + get_cost(z, 2));
    // remove x
    z += x;
    y -= x;
    x = 0;
    ans = min(ans, get_cost(x, 0) + get_cost(y, 1) + get_cost(z, 2));
    // remove y
    z += y;
    x -= y;
    y = 0;
    ans = min(ans, get_cost(x, 0) + get_cost(y, 1) + get_cost(z, 2));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
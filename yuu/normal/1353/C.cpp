#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int64_t ans = 0;
    int64_t x = (n + 1) / 2;
    for (int64_t dist = 2, square_size = 3; dist <= x; dist++, square_size += 2) {
        int64_t ring_side = square_size * square_size - (square_size - 2) * (square_size - 2);
        ans += (dist - 1) * ring_side;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
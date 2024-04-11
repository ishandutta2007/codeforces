#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, p, q;
void solve() {
    cin >> n >> m >> x >> y >> p >> q;
    int dx = 1;
    int dy = 1;
    for (int ans = 0; true; ans++) {
        if (x == p || y == q) {
            cout << ans << '\n';
            return;
        }
        x += dx;
        if (x <= 0 || x > n) {
            x -= dx * 2;
            dx = -dx;
        }
        y += dy;
        if (y <= 0 || y > m) {
            y -= dy * 2;
            dy = -dy;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
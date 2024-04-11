#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll t;
    int x, y;
    cin >> t >> x >> y;
    t -= x + y;
    if (t < 0) { cout << "NO\n"; return; }
    const int n = 120;
    auto get = [&](ll t) {
        ll f[n][n]{};
        f[0][0] = t;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + 1 < n) f[i + 1][j] += f[i][j] / 2;
                if (j + 1 < n) f[i][j + 1] += (f[i][j] + 1) / 2;
            }
        }
        return f[x][y] % 2;
    };
    cout << (get(t) != get(t + 1) ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
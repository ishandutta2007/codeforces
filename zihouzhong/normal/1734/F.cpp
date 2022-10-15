#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll f[2][2][2]{};
    f[0][0][0] = 1;
    for (int i = 0; i <= 60; i++) {
        int cn = n >> i & 1, cm = m >> i & 1;
        ll g[2][2][2]{};
        for (int x : {0, 1}) for (int y : {0, 1}) for (int z : {0, 1}) {
            for (int t : {0, 1}) {
                int _t = (t + cn + z) % 2;
                g[t < cm ? 1 : t == cm ? x : 0][y ^ t ^ _t][t + cn + z > 1] += f[x][y][z];
            }
        }
        swap(f, g);
    }
    cout << f[1][1][0] << "\n";
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
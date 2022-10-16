#include <bits/stdc++.h>
using namespace std;
string x, y;
constexpr int base = 998'244'353;
int f[1001][1001][3];
bool done[1001][1001][3];
int F(int a, int b, int c) {
    if (done[a][b][c]) return f[a][b][c];
    done[a][b][c] = 1;
    char last = 0;
    if (c == 1)
        last = x[a - 1];
    else if (c == 2)
        last = y[b - 1];
    if (a == x.size()) {
        if (b == y.size()) {
        } else if (y[b] != last) {
            f[a][b][c] = F(a, b + 1, 2) + 1;
        }
    } else if (b == y.size()) {
        if (x[a] != last) f[a][b][c] = F(a + 1, b, 1) + 1;
    } else {
        if (x[a] != last) {
            f[a][b][c] += F(a + 1, b, 1) + 1;
        }
        if (y[b] != last) {
            f[a][b][c] += F(a, b + 1, 2) + 1;
        }
    }
    while (f[a][b][c] >= base) f[a][b][c] -= base;
    return f[a][b][c];
}

void solve() {
    cin >> x >> y;
    int ans = 0;
    for (int i = 0; i < x.size(); i++)
        for (int j = 0; j < y.size(); j++) {
            (ans += F(i, j, 0)) %= base;
            (ans -= F(i, y.size(), 0)) %= base;
            (ans -= F(x.size(), j, 0)) %= base;
        }
    (ans += base) %= base;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
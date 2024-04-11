#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[501][501];
int f[501][502];
bool check(int u, int v) {
    if ((u > 1) && (c[u - 1][v] == '*')) return false;
    for (int row = u; row <= n; row++) {
        int diff = row - u;
        char req = c[row][v];
        for (int i = 1; i <= diff; i++) {
            if (v - i > 0) {
                if (c[row][v - i] != req) return false;
            } else if (req == '*') {
                return false;
            }
            if (v + i <= m) {
                if (c[row][v + i] != req) return false;
            } else if (req == '*') {
                return false;
            }
        }
        if (req == '.') return true;
        if ((v > diff) && (c[row][v - diff] == '*')) return false;
        if ((v + diff <= m) && (c[row][v + diff] == '*')) return false;
    }
    return true;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    for (int j = 1; j <= m; j++) {
        if (c[n][j] == '*') f[n][j] = 1;
        else f[n][j] = 0;
    }
    f[n][0] = f[n][m + 1] = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == '*') {
                f[i][j] = f[i + 1][j];
                f[i][j] = min(f[i + 1][j], min(f[i + 1][j + 1], f[i + 1][j - 1])) + 1;
            } else {
                f[i][j] = 0;
            }
        }
        f[i][0] = f[i][m + 1] = 0;
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) ans += f[i][j];
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
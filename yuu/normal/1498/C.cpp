#include <bits/stdc++.h>
using namespace std;
int n, k;
int f[1001][1001][2];
bool done[1001][1001][2];
constexpr int base = 1e9 + 7;
int F(int i, int j, bool dir) {
    if (j == 0) return 0;
    if ((i < 1) || (i > n)) return 1;
    if (done[i][j][dir]) return f[i][j][dir];
    done[i][j][dir] = 1;
    if (dir == 1)
        return f[i][j][dir] = (F(i + 1, j, 1) + F(i - 1, j - 1, 0)) % base;
    else
        return f[i][j][dir] = (F(i - 1, j, 0) + F(i + 1, j - 1, 1)) % base;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) done[i][j][0] = done[i][j][1] = 0;
    cout << F(1, k, 1) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
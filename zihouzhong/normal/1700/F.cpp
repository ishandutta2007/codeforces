#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[2][maxn], b[2][maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i : {0, 1}) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i : {0, 1}) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    long long ans = 0;
    int u = 0, d = 0;
    for (int i = 1; i <= n; i++) {
        u += a[0][i] - b[0][i], d += a[1][i] - b[1][i];
        int t = min(abs(u), abs(d));
        if (u > 0 && d < 0) u -= t, d += t, ans += t;
        else if (u < 0 && d > 0) u += t, d -= t, ans += t;
        ans += abs(u) + abs(d);
    }
    if (u || d) ans = -1;
    cout << ans << "\n";
    return 0;
}
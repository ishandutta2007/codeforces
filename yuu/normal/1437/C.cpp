#include <bits/stdc++.h>
using namespace std;
int n;
int t[201];
int f[401];
int g[401];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n * 2; i++) f[i] = 0;
    for (int i = 1; i <= n; i++) {
        g[0] = (i == 1) ? 0 : 1e9;
        for (int j = 1; j <= n * 2; j++) g[j] = min(f[j], g[j - 1]);
        for (int j = n * 2; j >= 1; j--) f[j] = g[j - 1] + abs(t[i] - j);
    }
    cout << *min_element(f + 1, f + n * 2 + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
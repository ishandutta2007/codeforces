#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
char ans[50][50];
void solve() {
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans[i][j] = '0';
        for (int j = 0; j < a; j++) {
            ans[i][x] = '1';
            (x += 1) %= m;
        }
        for (int j = 0; j < m; j++) cout << ans[i][j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
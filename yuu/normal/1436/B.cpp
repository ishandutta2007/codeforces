#include <bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = 0;

    for (int i = 1; i <= n; i++) a[i][i] = a[i][n - i + 1] = 1;
    if (n % 2) {
        a[1][n / 2 + 1] = a[n][n / 2 + 1] = a[n / 2 + 1][1] = a[n / 2 + 1][n] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cout << a[i][j] << " \n"[j == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
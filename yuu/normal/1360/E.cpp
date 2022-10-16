#include <bits/stdc++.h>
using namespace std;
int n;
char c[51][51];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++) {
            if (c[i][j] == '1') {
                if ((c[i + 1][j] == '0') && (c[i][j + 1] == '0')) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
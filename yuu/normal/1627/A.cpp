#include <bits/stdc++.h>
using namespace std;
int n, m, r, c;
char a[51][51];
void solve() {
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    if (a[r][c] == 'B') {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if (a[i][c] == 'B') {
            cout << "1\n";
            return;
        }
    for (int i = 1; i <= m; i++)
        if (a[r][i] == 'B') {
            cout << "1\n";
            return;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'B') {
                cout << "2\n";
                return;
            }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
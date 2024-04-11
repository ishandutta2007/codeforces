#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[5];
void solve() {
    cin >> n >> m;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'R') {
                x = i;
                y = j;
                goto second_phase;
            }
second_phase:;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'R') {
                if (i < x || j < y) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
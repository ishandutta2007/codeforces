#include <bits/stdc++.h>
using namespace std;
int n, m;
string a[11];
string s;
bool test(const string& s) {
    for (int i = 1; i <= n; i++) {
        int diff = 0;
        for (int j = 0; j < m; j++) {
            diff += (a[i][j] != s[j]);
            if (diff > 1) return 0;
        }
    }
    return 1;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    s = a[1];
    if (test(s)) {
        cout << s << '\n';
        return;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 2; j <= n; j++) {
            s[i] = a[j][i];
            if (test(s)) {
                cout << s << '\n';
                return;
            }
        }
        s[i] = a[1][i];
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
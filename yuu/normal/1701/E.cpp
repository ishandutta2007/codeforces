#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, t;
int f[5001][3];
void solve() {
    cin >> n >> m >> s >> t;
    s = '0' + s;
    t = '0' + t;
    int ans = 0;
    int match = 1;
    for (int i = 1; i <= n; i++) {
        if ((match <= m) && (s[i] == t[match])) {
            match++;
        } else {
            // i is the first character to be deleted
            ans = max(ans, n - i + 1);
        }
    }
    if (match <= m) {
        // can't be matched
        cout << "-1\n";
        return;
    }
    // always use a home command
    // cerr << "homeress answer: " << ans << '\n';
    for (int i = 0; i <= m; i++) f[i][0] = f[i][1] = f[i][2] = 1e9;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            if ((j < m) && (t[j + 1] == s[i])) {  // match
                f[j + 1][0] = min(f[j + 1][0], f[j][0] + 1);
                f[j + 1][1] = min(f[j + 1][1], f[j][0]);
                f[j + 1][1] = min(f[j + 1][1], f[j][1]);
                f[j + 1][2] = min(f[j + 1][2], f[j][0] + n - i);
                f[j + 1][2] = min(f[j + 1][2], f[j][1] + n - i);
                f[j + 1][2] = min(f[j + 1][2], f[j][2]);
            }
            // not matched
            f[j][2] = min(f[j][2], f[j][0] + n - i + 1);
            f[j][2] = min(f[j][2], f[j][1] + n - i + 1);
            f[j][0] += 2;
            f[j][1] = 1e9;
        }
        // cerr << i << '\n';
        // for (int j = 0; j <= m; j++) cerr << f[j][0] << ' ' << f[j][1] << ' ' << f[j][2] << '\n';
    }
    ans = min(ans, f[m][2]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
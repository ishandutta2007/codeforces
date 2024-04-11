#include <bits/stdc++.h>
using namespace std;
template <typename T>
min(const T& a, const T& b, const T& c) {
    return min(min(a, b), c);
}
int n;
string s[2];
int l[200002][3];
int r[200002][3];
void solve() {
    cin >> n >> s[0] >> s[1];
    s[0] = '0' + s[0] + '0';
    s[1] = '0' + s[1] + '0';
    for (int i = 0; i <= n + 1; i++) l[i][0] = l[i][1] = l[i][2] = 1e9;
    for (int i = 0; i <= n + 1; i++) r[i][0] = r[i][1] = r[i][2] = 1e9;
    l[0][2] = r[n + 1][2] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[0][i] == '*') {
            if (s[1][i] == '*') {
                l[i][0] = l[i][1] = min(l[i - 1][0] + 2, l[i - 1][1] + 2, l[i - 1][2] + 1);
            } else {
                l[i][0] = min(l[i - 1][0] + 1, l[i - 1][1] + 2, l[i - 1][2]);
                l[i][1] = min(l[i - 1][0] + 2, l[i - 1][1] + 2, l[i - 1][2] + 1);
            }
        } else {
            if (s[1][i] == '*') {
                l[i][0] = min(l[i - 1][0] + 2, l[i - 1][1] + 2, l[i - 1][2] + 1);
                l[i][1] = min(l[i - 1][0] + 2, l[i - 1][1] + 1, l[i - 1][2]);
            } else {
                l[i][0] = min(l[i - 1][0] + 1, l[i - 1][1] + 2);
                l[i][1] = min(l[i - 1][1] + 1, l[i - 1][0] + 2);
                l[i][2] = l[i - 1][2];
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (s[0][i] == '*') {
            if (s[1][i] == '*') {
                r[i][0] = r[i][1] = min(r[i + 1][0] + 2, r[i + 1][1] + 2, r[i + 1][2] + 1);
            } else {
                r[i][0] = min(r[i + 1][0] + 1, r[i + 1][1] + 2, r[i + 1][2]);
                r[i][1] = min(r[i + 1][0] + 2, r[i + 1][1] + 2, r[i + 1][2] + 1);
            }
        } else {
            if (s[1][i] == '*') {
                r[i][0] = min(r[i + 1][0] + 2, r[i + 1][1] + 2, r[i + 1][2] + 1);
                r[i][1] = min(r[i + 1][0] + 2, r[i + 1][1] + 1, r[i + 1][2]);
            } else {
                r[i][0] = min(r[i + 1][0] + 1, r[i + 1][1] + 2);
                r[i][1] = min(r[i + 1][1] + 1, r[i + 1][0] + 2);
                r[i][2] = r[i + 1][2];
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, l[i][0] + r[i + 1][0] + 1);
        ans = min(ans, l[i][0] + r[i + 1][1] + 2);
        ans = min(ans, l[i][0] + r[i + 1][2]);

        ans = min(ans, l[i][1] + r[i + 1][0] + 2);
        ans = min(ans, l[i][1] + r[i + 1][1] + 1);
        ans = min(ans, l[i][1] + r[i + 1][2]);
    }

    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
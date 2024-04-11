#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int l[300001][2];
int r[300001][2];
void solve() {
    cin >> n >> s;
    s = '0' + s;
    l[0][0] = l[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            l[i][0] = l[i - 1][1] + 1;
            l[i][1] = 1;
        } else {
            l[i][1] = l[i - 1][0] + 1;
            l[i][0] = 1;
        }
    }
    r[n][0] = r[n][1] = 1;
    for (int i = n; i >= 1; i--) {
        if (s[i] == 'R') {
            r[i - 1][0] = r[i][1] + 1;
            r[i - 1][1] = 1;
        } else {
            r[i - 1][1] = r[i][0] + 1;
            r[i - 1][0] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) cout << (l[i][0] + r[i][0] - 1) << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
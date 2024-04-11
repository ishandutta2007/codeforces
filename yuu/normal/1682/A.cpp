#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() {
    cin >> n >> s;
    s = '0' + s;
    int pos = (n + 1) / 2;
    int ans = 1;
    for (int i = pos - 1; i > 0; i--) {
        if (s[i] != s[pos]) break;
        ans++;
    }
    for (int i = pos + 1; i <= n; i++) {
        if (s[i] != s[pos]) break;
        ans++;
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
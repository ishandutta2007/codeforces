#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, t;
int prefix[200002];
int suffix[200002];
void solve() {
    cin >> n >> m;
    cin >> s >> t;
    s = '0' + s;
    t = '0' + t;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1];
        if ((prefix[i] < m) && (s[i] == t[prefix[i] + 1])) prefix[i]++;
    }
    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i + 1];
        if ((suffix[i] < m) && (s[i] == t[m - suffix[i]])) suffix[i]++;
    }
    int ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while ((j < i) && (prefix[j] + suffix[i] < m)) j++;
        if (j < i) {
            if (prefix[j] && suffix[i]) ans = max(ans, i - j);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
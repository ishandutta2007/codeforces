#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() {
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0' && s[i - 1] == '0') ans += 2;
        if (i >= 2)
            if (s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '0') ans++;
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
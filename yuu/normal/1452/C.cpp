#include <bits/stdc++.h>
using namespace std;
int cnt[256];
string s;
void solve() {
    cin >> s;
    cnt['('] = cnt['['] = 0;
    int ans = 0;
    for (auto&& c : s) {
        if (c == ')') {
            if (cnt['(']) {
                ans++;
                cnt['(']--;
            }
        } else if (c == ']') {
            if (cnt['[']) {
                ans++;
                cnt['[']--;
            }
        } else {
            cnt[c]++;
        }
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
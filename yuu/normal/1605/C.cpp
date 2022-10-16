#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt[256];
void solve() {
    constexpr int lim = 10;
    cin >> n >> s;
    for (int ans = 2; ans <= lim; ans++) {
        cnt['a'] = cnt['b'] = cnt['c'] = 0;
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
            if (i + 1 >= ans) {
                if (cnt['a'] > cnt['b'] && cnt['a'] > cnt['c']) {
                    cout << ans << '\n';
                    return;
                }
                cnt[s[i - ans + 1]]--;
            }
        }
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
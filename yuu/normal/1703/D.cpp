#include <bits/stdc++.h>
using namespace std;
int n;
string s[100001];
set<string> all;
void solve() {
    cin >> n;
    all.clear();
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) all.insert(s[i]);
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1; j < s[i].size(); j++) {
            if (all.count(s[i].substr(0, j))) {
                if (all.count(s[i].substr(j))) {
                    res = 1;
                    break;
                }
            }
        }
        cout << res;
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
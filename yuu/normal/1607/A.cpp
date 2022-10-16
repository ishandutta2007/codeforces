#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int pos[256];
void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) pos[s[i]] = i;
    cin >> s;
    int ans = 0;
    char o = s[0];
    for (auto&& c : s) {
        ans += abs(pos[o] - pos[c]);
        o = c;
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
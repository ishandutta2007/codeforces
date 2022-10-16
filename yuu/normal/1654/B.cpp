#include <bits/stdc++.h>
using namespace std;
int cnt[256];
void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (auto&& c : s) cnt[c] = 0;
    for (auto&& c : s) cnt[c]++;
    while (!s.empty()) {
        cnt[s.back()]--;
        if (cnt[s.back()] == 0) break;
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
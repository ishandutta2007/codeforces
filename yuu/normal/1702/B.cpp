#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    while (!s.empty()) {
        set<char> ch;
        ans++;
        while (!s.empty()) {
            if (!ch.count(s.back())) {
                ch.insert(s.back());
                if (ch.size() == 4) break;
            }
            s.pop_back();
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
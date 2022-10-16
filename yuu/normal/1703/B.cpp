#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    set<char> d;
    cin >> s;
    cin >> s;
    for (auto&& x : s) d.insert(x);
    cout << s.size() + d.size() << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
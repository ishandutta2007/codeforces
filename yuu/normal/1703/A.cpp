#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (auto&& x : s)
        if (x >= 'a') x -= 32;
    if (s != "YES") s = "NO";
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
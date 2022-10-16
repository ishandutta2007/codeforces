#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if ((s.size() % 2) || (s[0] == ')') || (s.back() == '(')) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
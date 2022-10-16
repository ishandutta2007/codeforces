#include <bits/stdc++.h>
using namespace std;
string s, t;
void solve() {
    cin >> s >> t;
    int len = lcm(s.size(), t.size());
    string a, b;
    while (a.size() < len) a += s;
    while (b.size() < len) b += t;
    if (a != b) a = "-1";
    cout << a << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
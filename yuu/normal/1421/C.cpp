#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
    cin >> s;
    int n = s.size();
    cout << 3 << '\n';
    cout << "R " << n - 1 << '\n';
    n += 1;
    cout << "L " << n - 1 << '\n';
    cout << "L " << 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
    int nc = 0;
    cin >> s;
    for (auto&& c : s)
        if (c == 'N') nc++;
    if (nc == 1) {
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
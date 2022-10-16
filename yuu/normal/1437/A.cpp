#include <bits/stdc++.h>
using namespace std;
int l, r;
void solve() {
    cin >> l >> r;
    r++;
    if (l % r * 2 >= r) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
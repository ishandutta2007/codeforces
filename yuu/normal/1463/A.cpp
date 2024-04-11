#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 9) {
        cout << "NO\n";
    } else {
        int turn = (a + b + c) / 9;
        if ((a < turn) || (b < turn) || (c < turn)) cout << "NO\n";
        else cout << "YES\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
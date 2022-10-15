#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    int x, y;
    cin >> x >> y;
    int foo = (r1 + c1) % 2, bar = (r2 + c2) % 2, baz = (r3 + c3) % 2;
    if (foo != bar && bar != baz) r1 = r2, c1 = c2;
    if (foo != baz && bar != baz) r1 = r3, c1 = c3;
    if ((r1 == 1 || r1 == n) && (c1 == 1 || c1 == n)) {
        if (x == r1 || y == c1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if ((x - r1) % 2 && (y - c1) % 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
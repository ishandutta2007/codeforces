#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b;
    cin >> a >> b;
    if (a + 1 == b) {
        cout << a << ' ' << b << '\n';
    } else if (a == b) {
        cout << a << "0 " << a << "1\n";
    } else if ((a == 9) && (b == 1)) {
        cout << "9 10\n";
    } else {
        cout << "-1\n";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
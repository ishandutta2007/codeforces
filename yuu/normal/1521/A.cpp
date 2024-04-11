#include <bits/stdc++.h>
using namespace std;
int64_t a, b;
void solve() {
    cin >> a >> b;
    if (b == 1) {
        cout << "NO\n";
    } else if (b != 2) {
        cout << "YES\n";
        cout << a << ' ' << a * (b - 1) << ' ' << a * b << '\n';
    } else {
        cout << "YES\n";
        cout << a << ' ' << a * (b * 2 - 1) << ' ' << a * b * 2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    for (int a = 2; a <= n; a++) {
        int b = n - a - 1;
        if (a >= b) break;
        if (gcd(a, b) == 1) {
            cout << a << ' ' << b << ' ' << 1 << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
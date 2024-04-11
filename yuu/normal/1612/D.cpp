#include <bits/stdc++.h>
using namespace std;
int64_t a, b, x;
void solve() {
    cin >> a >> b >> x;
    if (a < b) swap(a, b);
    while (a >= x) {
        if (b == 0) break;
        if ((a - x) % b == 0 || (x == b)) {
            cout << "YES\n";
            return;
        }
        a %= b;
        swap(a, b);
    }
    if (a == x)
        cout << "YES";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
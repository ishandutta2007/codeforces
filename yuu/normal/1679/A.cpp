#include <bits/stdc++.h>
using namespace std;
int64_t n;
void solve() {
    cin >> n;
    if ((n % 2) || (n < 4)) {
        cout << "-1\n";
        return;
    }
    int64_t base = 0;
    if (n % 4 == 2) {
        n -= 6;
        base++;
    }
    int64_t y = base + n / 4;
    while (n % 6) {
        base++;
        n -= 4;
    }
    int64_t x = base + n / 6;
    cout << x << ' ' << y << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int64_t r, b, d;
void solve() {
    cin >> r >> b >> d;
    if (r > b) swap(r, b);
    if (r * (d + 1) < b) {
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
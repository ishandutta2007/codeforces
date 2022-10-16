#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int64_t value = 1;
    for (int i = 1; i < c; i++) value *= 10;
    int64_t x = value, y = value;
    for (int i = c; i < a; i++) x *= 10;
    x += value;
    for (int i = c; i < b; i++) y *= 10;
    cout << x << ' ' << y << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
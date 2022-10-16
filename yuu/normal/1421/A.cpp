#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b;
    cin >> a >> b;
    int weight = 1;
    int ans = 0;
    while (a || b) {
        if (a % 2 != b % 2) ans += weight;
        weight *= 2;
        a /= 2;
        b /= 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
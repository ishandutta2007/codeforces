#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int64_t rem = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        (rem += a) %= n;
    }
    cout << rem * (n - rem) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
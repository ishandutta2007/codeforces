#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
bitset<100001> dp;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int g = 0;
    for (int i = 1; i <= n; i++) g = gcd(g, a[i]);
    for (int i = 1; i <= n; i++) a[i] /= g;
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum % 2) {
        cout << "0\n";
        return;
    }
    sum /= 2;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) dp |= (dp << a[i]);
    if (!dp[sum]) {
        cout << "0\n";
        return;
    }
    cout << "1\n";
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2) {
            cout << i << '\n';
            return;
        }
    }
    assert(false);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int64_t n;
constexpr int64_t base = 1e9 + 7;
void solve() {
    cin >> n;
    int64_t ans = 0;
    int64_t div = 1;
    for (int64_t i = 1; div <= n; i++) {
        (ans += n / div) %= base;
        div = div / gcd(div, i) * i;
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
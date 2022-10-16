#include <bits/stdc++.h>
using namespace std;
int64_t n, k;
constexpr int64_t base = 1'000'000'007;
void solve() {
    cin >> n >> k;
    int64_t p = 1;
    int64_t ans = 0;
    for (int i = 0; i <= __lg(k); i++) {
        if ((k >> i) & 1) (ans += p) %= base;
        (p *= n) %= base;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
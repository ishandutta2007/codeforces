#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int base = 998'244'353;
constexpr int half = (base + 1) / 2;
void solve() {
    cin >> n;
    int64_t sum[2] = {1, 0};
    int64_t f;
    for (int i = 1; i <= n; i++) {
        (f = sum[1 - i % 2] * half) %= base;
        (sum[i % 2] *= half) %= base;
        (sum[i % 2] *= half) %= base;
        (sum[i % 2] += f) %= base;
    }
    cout << f << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
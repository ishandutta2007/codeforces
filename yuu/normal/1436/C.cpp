#include <bits/stdc++.h>
using namespace std;
constexpr int base = 1e9 + 7;
void solve() {
    int n, x, pos;
    cin >> n >> x >> pos;
    int64_t ans = 1;
    int left = 0, right = n;
    int lower = x - 1;
    int upper = n - x;
    while (left < right) {
        int middle = (left + right) / 2;
        if (middle > pos) {  // leq can only return [middle, n - 1]
            (ans *= upper--) %= base;
            right = middle;
        } else if (middle <= pos) {
            if (middle < pos) (ans *= lower--) %= base;
            left = middle + 1;
        }
    }
    int rem = upper + lower;
    for (int i = 1; i <= rem; i++) (ans *= i) %= base;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
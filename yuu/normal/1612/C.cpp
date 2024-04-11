#include <bits/stdc++.h>
using namespace std;
uint64_t k, x;
uint64_t count_total(uint64_t m) {
    if (m <= k) {
        return m * (m + 1) / 2;
    } else {
        uint64_t total = k * (k + 1) / 2;
        m -= k;
        return k * (k - 1) / 2 - (k - m - 1) * (k - m) / 2 + total;
    }
}

void solve() {
    cin >> k >> x;
    uint64_t low = 1, high = k * 2 - 1, mid, ans = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (count_total(mid) >= x) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    cout << min(ans + 1, k * 2 - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
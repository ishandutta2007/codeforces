#include <bits/stdc++.h>
using namespace std;
int n;
int h[300001];
int64_t Get(int target) {
    int odd = 0;
    int64_t total = 0;
    for (int i = 1; i <= n; i++) {
        odd += (target - h[i]) % 2;
        total += target - h[i];
    }
    total -= odd;
    int64_t low = 0, high = 1e18, mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        int64_t check_odd = (mid + 1) / 2;
        int64_t check_even = mid - check_odd;
        bool good = true;
        if (check_odd < odd) {
            good = false;
        } else {
            good = (check_odd - odd) + check_even * 2 >= total;
        }
        if (good) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    sort(h + 1, h + n + 1);
    int64_t ans = 1e18;
    ans = min(ans, Get(h[n]));
    ans = min(ans, Get(h[n] + 1));
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int n;
int64_t h;
int64_t a[101];
bool check(int64_t k) {
    int64_t total = h;
    for (int i = 1; i < n; i++) {
        total -= min(a[i + 1] - a[i], k);
        if (total <= 0) return true;
    }
    total -= k;
    return total <= 0;
}

void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int64_t low = 1, high = h, ans = -1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
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
#include <bits/stdc++.h>
using namespace std;
int n;
int64_t k;
int64_t a[3001];
int64_t offset[3002];
int zero[3002];
int64_t ans = 0;

bool check_good(int pos, int64_t so_far) {
    if (pos == n + 1) return (so_far == 0);
    so_far += offset[pos];
    return abs(so_far) <= k * zero[pos];
}

void low_first(int cnt) {
    int64_t low = 0, high = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            if (cnt) {
                current -= k;
                cnt--;
                if (!check_good(i + 1, current)) return;
            } else {
                // -k * zero[i+1] <= current + x + offset[i + 1] <= k * zero[i+1]
                int64_t low_x = max(-k, -k * zero[i + 1] - current - offset[i + 1]);
                int64_t high_x = min(k, k * zero[i + 1] - current - offset[i + 1]);
                if (low_x > high_x) return;
                current += high_x;
            }
        } else {
            current += a[i];
        }
        low = min(low, current);
        high = max(high, current);
    }
    assert(current == 0);
    ans = max(ans, high - low + 1);
}

void high_first(int cnt) {
    int64_t low = 0, high = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            if (cnt) {
                current += k;
                cnt--;
            } else {
                // -k * zero[i+1] <= current + x + offset[i + 1] <= k * zero[i+1]
                int64_t low_x = max(-k, -k * zero[i + 1] - current - offset[i + 1]);
                int64_t high_x = min(k, k * zero[i + 1] - current - offset[i + 1]);
                if (low_x > high_x) return;
                current += low_x;
            }
        } else {
            current += a[i];
        }
        if (!check_good(i + 1, current)) return;
        low = min(low, current);
        high = max(high, current);
    }
    assert(current == 0);
    ans = max(ans, high - low + 1);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    offset[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        offset[i] = offset[i + 1] + a[i];
        zero[i] = zero[i + 1] + (a[i] == 0);
    }
    if (abs(offset[1]) > k * zero[1]) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i <= zero[1]; i++) {
        low_first(i);
        high_first(i);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
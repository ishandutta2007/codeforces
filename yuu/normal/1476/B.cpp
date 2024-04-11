#include <bits/stdc++.h>
using namespace std;
int n;
int64_t k;
int64_t p[101];
bool check(int64_t value) {
    value += p[0];
    for (int i = 1; i < n; i++) {
        if (p[i] * 100 > k * value) return false;
        value += p[i];
    }
    return true;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> p[i];
    int64_t low = 0, high = 1e12, mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
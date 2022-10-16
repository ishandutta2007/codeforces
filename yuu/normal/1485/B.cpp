#include <bits/stdc++.h>
using namespace std;
int n, q, k;
int a[100002];
int64_t range[100001];
void solve() {
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0;
    a[n + 1] = k + 1;
    for (int i = 1; i <= n; i++) {
        range[i] = max(0, a[i + 1] - a[i - 1] - 2);
        range[i] += range[i - 1];
    }
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        if (l == r) {
            cout << k - 1 << '\n';
        } else if (l + 1 == r) {
            cout << max(0, a[r] - 1 - 1) + max(0, k - a[l] - 1) << '\n';
        } else {
            cout << max(0, a[l + 1] - 1 - 1) + max(0, k - a[r - 1] - 1) + range[r - 1] - range[l] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[200001];
int last_update, last_val;
int updated[200001];
int64_t sum;
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    last_update = 0;
    for (int i = 1; i <= n; i++) updated[i] = 0;
    for (int i = 1, t, pos, x; i <= q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> pos >> x;
            if (updated[pos] < last_update) {
                updated[pos] = last_update;
                a[pos] = last_val;
            }
            sum -= a[pos];
            a[pos] = x;
            sum += a[pos];
        } else {
            last_update = i;
            cin >> last_val;
            (sum = last_val) *= n;
        }
        cout << sum << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
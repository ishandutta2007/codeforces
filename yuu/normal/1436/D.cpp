#include <bits/stdc++.h>
using namespace std;
int n;
int p[200001];
int a[200001];
bool is_leaf[200001];
int64_t w[200001];
bool check(int64_t lim) {
    for (int i = 1; i <= n; i++) w[i] = 0;
    for (int i = n; i >= 1; i--) {
        if (is_leaf[i]) w[i] += lim;
        if (w[i] > 1e15) w[i] = 1e15;
        w[i] -= a[i];
        if (w[i] < 0) return false;
        w[p[i]] += w[i];
        if (w[p[i]] > 1e15) w[p[i]] = 1e15;
    }
    return true;
}
void solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) is_leaf[i] = 1;
    for (int i = 2; i <= n; i++) is_leaf[p[i]] = 0;
    int64_t low = 0, high = 3e14, mid, res;
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
    // cin >> t;
    while (t--) solve();
}
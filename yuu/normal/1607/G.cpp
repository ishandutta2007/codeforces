#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int n;
int64_t m;
int64_t a[200001][2];
int64_t total[2];
int64_t r[200001][2];
void solve() {
    cin >> n >> m;
    total[0] = total[1] = 0;
    for (int i = n; i >= 1; i--) cin >> a[i][0] >> a[i][1];
    for (int i = n; i >= 1; i--) total[0] += a[i][0];
    for (int i = n; i >= 1; i--) total[1] += a[i][1];
    for (int i = 1; i <= n; i++) {
        int64_t low = max(0LL, m - a[i][1]);
        int64_t high = min(m, a[i][0]);
        r[i][0] = r[i - 1][0] + low;
        r[i][1] = r[i - 1][1] + high;
    }

    // minimize diff[(total[0] - target),  total[1] + target - m*n]

    int64_t target = (total[0] - total[1] + m * n) / 2;
    if (r[n][0] > target)
        target = r[n][0];
    else if (r[n][1] < target)
        target = r[n][1];
    // cerr << target << '\n';
    cout << abs((total[0] - target) - (total[1] + target - m * n)) << '\n';
    for (int i = n; i >= 1; i--) {
        assert(target >= r[i][0]);
        assert(target <= r[i][1]);
        // eat x -> r[i-1][0] <= target - x
        // eat x -> r[i-1][1] >= target - x
        // -> target - r[i-1][1] <= x <= target - r[i-1][0]
        // -> low <= x <= high
        int64_t low = max(0LL, m - a[i][1]);
        int64_t high = min(m, a[i][0]);
        int64_t x = max(target - r[i - 1][1], low);
        assert(x <= min(high, target - r[i - 1][0]));
        target -= x;
        cout << x << ' ' << m - x << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
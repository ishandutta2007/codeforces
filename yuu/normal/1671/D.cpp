#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[200001];
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int max_val = *max_element(a + 1, a + n + 1);
    int min_val = *min_element(a + 1, a + n + 1);
    int min_cost_min = 1e9;
    int min_cost_max = 1e9;
    if (min_val == 1) min_cost_min = 0;
    if (max_val >= x) min_cost_max = 0;
    int ans = min_cost_min + min_cost_max;
    for (int i = 0; i <= n; i++) {  // insert after element i
        int cost_min = 0;
        if (min_val > 1) {
            if (i) cost_min += a[i] - 1;
            if (i != n) cost_min += a[i + 1] - 1;
            if (i && (i != n)) cost_min -= abs(a[i] - a[i + 1]);
        }
        int cost_max = 0;
        if (x > max_val) {
            if (i) cost_max += x - a[i];
            if (i != n) cost_max += x - a[i + 1];
            if (i && (i != n)) cost_max -= abs(a[i] - a[i + 1]);
        }
        ans = min(ans, cost_min + min_cost_max);
        ans = min(ans, cost_max + min_cost_min);
        min_cost_min = min(min_cost_min, cost_min);
        min_cost_max = min(min_cost_max, cost_max);
    }
    int64_t ans_base = 0;
    for (int i = 1; i < n; i++) ans_base += abs(a[i] - a[i + 1]);
    ans_base += ans;
    cout << ans_base << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
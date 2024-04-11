#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500001];
int low[500001];
int high[500002];
bool bad[500001];
int solve(int l, int r) {
    if (l > r) return 0;
    for (int i = l; i <= r; i++) {
        a[i] -= i;
        low[i] -= i;
        high[i] -= i;
    }
    for (int i = l + 1; i <= r; i++) assert(low[i] == low[i - 1]);
    for (int i = l + 1; i <= r; i++) assert(high[i] == high[i - 1]);
    vector<int> lis;
    for (int i = l; i <= r; i++) {
        if (a[i] < low[i] || a[i] > high[i]) continue;
        if (lis.empty()) {
            lis.emplace_back(a[i]);
        } else if (lis.back() <= a[i]) lis.emplace_back(a[i]);
        else {
            int last = upper_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[last] = min(lis[last], a[i]);
        }
    }
    return r - l + 1 - lis.size();
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, b; i <= k; i++) {
        cin >> b;
        bad[b] = 1;
    }
    low[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        low[i] = low[i - 1] + 1;
        if (bad[i]) {
            if (a[i] < low[i]) {
                cout << "-1\n";
                return;
            }
            low[i] = a[i];
        }
    }
    high[n + 1] = 2e9;
    for (int i = n; i >= 1; i--) {
        high[i] = high[i + 1] - 1;
        if (bad[i]) {
            if (a[i] > high[i]) {
                cout << "-1\n";
                return;
            }
            high[i] = a[i];
        }
    }
    int ans = 0;
    int last_bad = 0;
    for (int i = 1; i <= n; i++) {
        if (bad[i]) {
            ans += solve(last_bad + 1, i - 1);
            last_bad = i;
        }
    }
    ans += solve(last_bad + 1, n);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
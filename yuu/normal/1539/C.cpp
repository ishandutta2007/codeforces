#include <bits/stdc++.h>
using namespace std;
int n;
int64_t k, x;
int64_t a[200001];
priority_queue<int64_t, vector<int64_t>, greater<int64_t>> q;
void solve() {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) q.push(a[i + 1] - a[i]);
    int64_t ans = n;
    while (!q.empty()) {
        int64_t val = q.top();
        q.pop();
        int64_t needed = val / x;
        while (x * (needed + 1) > val) needed--;
        while (x * (needed + 1) < val) needed++;
        if (needed < 0) needed = 0;
        if (k < needed) break;
        k -= needed;
        ans--;
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
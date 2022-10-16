#include <bits/stdc++.h>
using namespace std;
int n;
int64_t x;
int64_t a[5001];
int64_t ans[5001];
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = 1; i <= n; i++) ans[i] = -1e18;
    ans[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) ans[j - i] = max(ans[j - i], a[j] - a[i]);
    for (int i = n - 1; i >= 0; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; i++) ans[i] += x * i;
    for (int i = 1; i <= n; i++) ans[i] = max(ans[i], ans[i - 1]);
    for (int i = 0; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
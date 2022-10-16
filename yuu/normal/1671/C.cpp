#include <bits/stdc++.h>
using namespace std;
int n;
int64_t x;
int64_t a[200001];
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    int64_t ans = 0;
    for (int i = n; i >= 1; i--) {
        // a[i] + i * day > x
        if (a[i] > x) continue;
        int64_t day = (x - a[i]) / i;
        while (a[i] + day * i <= x) day++;
        while (a[i] + day * i > x) day--;
        ans += day + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
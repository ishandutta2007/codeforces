#include <bits/stdc++.h>
using namespace std;
int n;
int64_t k;
int a[10];
int64_t p[10];
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    k++;
    int64_t ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        int64_t use = min(k, p[a[i + 1] - a[i]] - 1);
        ans += use * p[a[i]];
        k -= use;
    }
    ans += k * p[a[n-1]];
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1;
    for (int i = 1; i <= 9; i++) p[i] = p[i - 1] * 10;
    int t = 1;
    cin >> t;
    while (t--) solve();
}
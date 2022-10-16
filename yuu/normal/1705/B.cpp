#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int64_t ans = 0;
    bool good = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > 0) {
            good = 1;
        }
        if (good) ans += (a[i] == 0);
        ans += a[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
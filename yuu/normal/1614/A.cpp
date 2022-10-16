#include <bits/stdc++.h>
using namespace std;
int n, l, r, k;
int a[101];
void solve() {
    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if ((a[i] >= l) && (a[i] <= r)) {
            if (k >= a[i]) {
                ans++;
                k -= a[i];
            }
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
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int ans[2];
    for (int t = 0, n; t <= 1; t++) {
        ans[t] = 0;
        cin >> n;
        for (int i = 1, sum = 0, a; i <= n; i++) {
            cin >> a;
            sum += a;
            ans[t] = max(ans[t], sum);
        }
    }
    cout << ans[0] + ans[1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
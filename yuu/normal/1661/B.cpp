#include <bits/stdc++.h>
using namespace std;
int n;
int ans[32768];
void solve() {
    for (int i = 0; i < 32768; i++) ans[i] = 1e9;
    ans[0] = 0;
    for (int turn = 1; turn <= 20; turn++) {
        for (int j = 0; j < 32768; j++) {
            ans[j] = min(ans[j], ans[(j * 2) % 32768] + 1);
            ans[j] = min(ans[j], ans[(j + 1) % 32768] + 1);
        }
    }
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        cout << ans[a] << " \n"[i == n];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
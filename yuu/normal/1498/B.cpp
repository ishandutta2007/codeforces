#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[21];
void solve() {
    cin >> n >> m;
    for (int i = 1, w; i <= n; i++) {
        cin >> w;
        cnt[__lg(w)]++;
    }
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
        while (cnt[i]) {
            ans++;
            for (int j = i, now = m; j >= 0; j--) {
                while ((cnt[j]) && ((1 << j) <= now)) {
                    now -= (1 << j);
                    cnt[j]--;
                }
            }
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
#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
void solve() {
    m.clear();
    int n;
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        m[a]++;
    }
    int ans = 1e9;
    for (auto&& [x, cnt] : m) {
        int res = 0;
        while (cnt < n) {
            res++;
            res += min(cnt, n - cnt);
            cnt += min(cnt, n - cnt);
        }
        ans = min(ans, res);
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
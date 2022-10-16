#include <bits/stdc++.h>
using namespace std;
int n, k, d;
int a[200001];
void solve() {
    cin >> n >> k >> d;
    map<int, int> cnt;
    size_t ans = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (i > d) {
            cnt[a[i - d]]--;
            if (cnt[a[i - d]] == 0) cnt.erase(a[i - d]);
        }
        if (i >= d) ans = min(ans, cnt.size());
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
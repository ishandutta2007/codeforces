#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[100000];
int get_min(int a, int b) {
    if (a < b) swap(a, b);
    if (a == 0) return 0;
    if (a == b) return 1;

    return a - b;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cnt[i] = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        cnt[a % m]++;
    }
    int ans = 0;
    ans += (cnt[0] > 0);
    for (int i = 1; i < m; i++) {
        int j = m - i;
        if (j < i) break;
        if (i == j)
            ans += (cnt[i] > 0);
        else
            ans += get_min(cnt[i], cnt[j]);
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
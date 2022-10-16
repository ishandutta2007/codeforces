#include <bits/stdc++.h>
using namespace std;
int n;
int ft[200001];
void update(int u) {
    for (; u <= n; u += u & -u) ft[u]++;
}
int get(int u) {
    int res = 0;
    for (; u > 0; u -= u & -u) res += ft[u];
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) ft[i] = 0;
    int64_t ans = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a < i) {
            ans += get(a - 1);
            update(i);
        }
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
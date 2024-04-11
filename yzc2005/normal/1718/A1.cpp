#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], dp[N];
void solve() {
    map<int, int> last;
    last[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        dp[i] = dp[i - 1];
        if (last.count(a[i])) {
            dp[i] = max(dp[i], dp[last[a[i]]] + 1);
        }
        last[a[i]] = i;
    }
    cout << n - dp[n] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
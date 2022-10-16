#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int max_val = 2e7;
int total[max_val + 1];
int64_t sum[max_val + 1];
void solve() {
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        total[a] += 1;
    }

    for (int i = 1; i <= max_val; i++) {
        for (int j = i + i; j <= max_val; j += i) {
            if (total[j]) {
                total[i] += total[j];
            }
        }
    }

    int64_t ans = 0;
    for (int64_t i = 1; i <= max_val; i++)
        if (total[i]) {
            ans = max(ans, sum[i] + i * total[i]);
            for (int j = i + i; j <= max_val; j += i)
                if (total[j]) {
                    sum[j] = max(sum[j], sum[i] + i * (total[i] - total[j]));
                    if (total[j] == total[i]) break;
                }
        }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
constexpr int max_val = 5e6;
int total[max_val + 1];
int64_t sum[max_val + 1];
void solve() {
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        sum[a] += 1;
        total[1] += 1;
    }

    for (int i = 2; i <= max_val; i++) {
        for (int j = i; j <= max_val; j += i) {
            if (sum[j]) total[i] += sum[j];
        }
    }

    for (int i = 1; i <= max_val; i++) sum[i] = 0;
    int64_t ans = 0;
    for (int64_t i = 1; i <= max_val; i++) {
        ans = max(ans, sum[i] + i * total[i]);
        for (int j = i + i; j <= max_val; j += i) sum[j] = max(sum[j], sum[i] + i * (total[i] - total[j]));
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
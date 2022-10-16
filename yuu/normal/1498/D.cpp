#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans[100001];
int nx[100001];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) ans[i] = -1;
    int t;
    int64_t x, y;
    static constexpr int64_t BOT = 1e5;
    for (int i = 1; i <= n; i++) {
        cin >> t >> x >> y;

        if (t == 1) {
            for (int k = 0; k <= m; k++) {
                nx[k] = k ? nx[k - 1] : 0;
                while ((nx[k] <= m) && (BOT * nx[k] < BOT * k + x)) nx[k]++;
            }
        } else {
            for (int k = 0; k <= m; k++) {
                nx[k] = k ? nx[k - 1] : 0;
                while ((nx[k] <= m) && (BOT * nx[k] < x * k)) nx[k]++;
            }
        }

        for (int k = 0; k <= m; k++)
            if ((ans[k] != -1) && (ans[k] != i)) {
                int now = k;
                for (int j = 1; j <= y; j++) {
                    now = nx[now];
                    if (now > m) break;
                    if (ans[now] == -1)
                        ans[now] = i;
                    else
                        break;
                }
            }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
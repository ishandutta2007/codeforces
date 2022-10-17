#include <bits/stdc++.h>
using namespace std;

const int maxm = 5000010;
int T, n, m, a[maxm], mx[maxm], lst[maxm], f[maxm];
bool mark[maxm];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        fill(mx, mx + m + 1, 0);
        fill(lst, lst + m + 1, INT_MAX);
        fill(mark, mark + m + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i], mark[a[i]] = 1;
        }
        for (int mn = m; mn; mn--) {
            fill(f + 1, f + m / mn + 1, INT_MAX);
            f[1] = mn;
            for (int i = mn; i <= m / mn; i++) {
                for (int j = i; j <= m / mn; j += i) {
                    f[j] = min(f[j], max(i, f[j / i]));
                }
            }
            for (int i = mn; i <= m; i += mn) if (mark[i]) {
                mx[mn + 1] = max(mx[mn + 1], lst[i]);
                lst[i] = min(lst[i], f[i / mn]);
            }
        }
        for (int i = 1; i <= m; i++) if (mark[i]) {
            mx[1] = max(mx[1], lst[i]);
        }
        int ans = INT_MAX;
        for (int i = 1, mn = *min_element(a + 1, a + n + 1); i <= mn; i++) {
            mx[i] = max(mx[i], mx[i - 1]);
            ans = min(ans, max(0, mx[i] - i));
        }
        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int matched[200002];
int solve(int *a, int n, int *b, int m) {
    if (n == 0 || m == 0) return 0;
    {
        int j = m;
        matched[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            while (j && (b[j] > a[i])) j--;
            matched[i] = (a[i] == b[j]);
        }
    }
    for (int i = n - 1; i > 0; i--) matched[i] += matched[i + 1];
    int ans = 0;
    int j = 0;
    int prev = 1;
    a[n + 1] = b[m] + 1;
    for (int i = 1; i <= n + 1; i++) {  // first to stay intact
        int k = j;
        while ((k < m) && (b[k + 1] < a[i])) k++;
        for (int t = j + 1; t <= k; t++)
            if (b[t]) {
                while ((prev > 1) && (b[t] - b[prev] <= i - 1)) prev--;
                while (b[t] - b[prev] + 1 > i - 1) prev++;
                ans = max(ans, matched[i] + (t - prev + 1));
            }
        j = k;
    }
    return ans;
}
int n, m;
int a[200002];
int b[200002];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    a[n + 1] = b[m + 1] = 1;
    for (int i = 1; i <= n + 1; i++)
        if (a[i] > 0) {
            for (int j = 1; j <= m + 1; j++)
                if (b[j] > 0) {
                    reverse(a + 1, a + i);
                    reverse(b + 1, b + j);
                    for (int k = 1; k < i; k++) a[k] = -a[k];
                    for (int k = 1; k < j; k++) b[k] = -b[k];
                    int ans = solve(a + i - 1, n - i + 1, b + j - 1, m - j + 1);
                    ans += solve(a, i - 1, b, j - 1);
                    cout << ans << '\n';
                    return;
                }
        }
    assert(false);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
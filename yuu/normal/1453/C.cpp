#include <bits/stdc++.h>
using namespace std;
int n;
string s[2000];
int low_x[10], high_x[10];
int low_y[10], high_y[10];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (auto&& x : s[i]) x -= '0';

    for (int digit = 0; digit <= 9; digit++) low_x[digit] = low_y[digit] = n;
    for (int digit = 0; digit <= 9; digit++) high_x[digit] = high_y[digit] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            low_x[s[i][j]] = min(low_x[s[i][j]], i);
            low_y[s[i][j]] = min(low_y[s[i][j]], j);
            high_x[s[i][j]] = max(high_x[s[i][j]], i);
            high_y[s[i][j]] = max(high_y[s[i][j]], j);
        }
    for (int digit = 0; digit <= 9; digit++) {
        // if (low_x[digit] == n) {
        //     cout << 0 << " \n"[digit == 9];
        //     continue;
        // }
        int ans = 0;
        for (int x = 0; x < n; x++) {
            int low_y = n, high_y = -1;
            for (int y = 0; y < n; y++)
                if (s[x][y] == digit) {
                    low_y = y;
                    break;
                }
            if (low_y == n) continue;
            for (int y = n - 1; y >= 0; y--)
                if (s[x][y] == digit) {
                    high_y = y;
                    break;
                }
            assert(high_x[digit] >= x);
            assert(low_x[digit] <= x);
            assert(high_y >= low_y);
            ans = max(ans, (high_y - low_y) * max(x, n - 1 - x));
            ans = max(ans, max(high_y, n - 1 - low_y) * max(high_x[digit] - x, x - low_x[digit]));
        }
        for (int y = 0; y < n; y++) {
            int low_x = n, high_x = -1;
            for (int x = 0; x < n; x++)
                if (s[x][y] == digit) {
                    low_x = x;
                    break;
                }
            if (low_x == n) continue;
            for (int x = n - 1; x >= 0; x--)
                if (s[x][y] == digit) {
                    high_x = x;
                    break;
                }
            assert(high_y[digit] >= y);
            assert(low_y[digit] <= y);
            assert(high_x >= low_x);
            ans = max(ans, (high_x - low_x) * max(y, n - 1 - y));
            ans = max(ans, max(high_x, n - 1 - low_x) * max(high_y[digit] - y, y - low_y[digit]));
        }
        cout << ans << " \n"[digit == 9];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
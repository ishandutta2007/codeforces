#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int g[200001][21];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) g[i][0] = a[i];
    for (int j = 1, length = 2, half = 1; length <= n; j++, length *= 2, half *= 2)
        for (int i = length; i <= n; i++) g[i][j] = gcd(g[i][j - 1], g[i - half][j - 1]);
    int ans = 0;
    int lim = 0;
    for (int i = 1; i <= n; i++) {
        int length = 1;
        int idx = 0;
        while (i - length + 1 >= lim) {
            length *= 2;
            idx++;
        }
        int current_gcd = 0;
        int total_length = 0;
        bool bad = 0;
        while (idx >= 0) {
            int nxt_total_length = total_length + length;
            if (i - nxt_total_length >= lim) {
                int nxt_gcd = gcd(current_gcd, g[i - total_length][idx]);
                if (nxt_gcd == nxt_total_length) {
                    bad = 1;
                    break;
                } else if (nxt_gcd > nxt_total_length) {
                    total_length = nxt_total_length;
                    current_gcd = nxt_gcd;
                }
            }
            idx--;
            length /= 2;
        }
        if (bad) {
            ans++;
            lim = i;
        }
        cout << ans << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
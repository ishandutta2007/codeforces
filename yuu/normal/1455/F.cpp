#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
string f[501][2];
char min_single[256];
void solve() {
    cin >> n >> k >> s;
    min_single['a'] = 'a';
    for (int i = 'a' + 1; i < 'a' + k; i++) min_single[i] = i - 1;
    min_single['a' + k - 1] = 'a';
    for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = f[i - 1][0] + 'z';
    for (int i = 1; i <= n; i++) {
        // no op, can be used for double swap
        char c = s[i - 1];
        f[i][0] = min(f[i - 1][0], f[i - 1][1]) + c;
        if (i > 1) {
            // swap with previous
            f[i][1] = min(f[i][1], f[i - 1][1].substr(0, i - 2) + c + f[i - 1][1].back());
            // previous operation performed a swap, we decrease the value
            f[i][1] = min(f[i][1], f[i - 1][0].substr(0, i - 2) + min_single[c] + f[i - 1][0].back());
            // previous operation performed a swap, we perform a swap again
            if (i > 2) f[i][1] = min(f[i][1], f[i - 1][0].substr(0, i - 3) + c + f[i - 1][0][i - 3] + f[i - 1][0][i - 2]);
        }
        // no swap, just optimize in place
        f[i][1] = min(f[i][1], f[i][0].substr(0, i - 1) + min_single[f[i][0].back()]);
    }
    cout << f[n][1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ;
    int t = 1;
    cin >> t;
    while (t--) solve();
}
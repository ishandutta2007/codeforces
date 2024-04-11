#include <bits/stdc++.h>
using namespace std;
int n;
int tag[5001];
int s[5001];
int64_t f[5001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> tag[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int r = 1; r <= n; r++) {
        for (int l = r; l >= 1; l--) {
            if (tag[l] == tag[r]) continue;
            // study r after studying l
            int64_t f_r = max(f[r], f[l] + abs(s[l] - s[r]));
            f[l] = max(f[l], f[r] + abs(s[l] - s[r]));
            f[r] = f_r;
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
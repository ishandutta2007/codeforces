#include <bits/stdc++.h>
using namespace std;
int n;
int a[501];
constexpr int base = 998244353;
int f[501];
int64_t solve(int pos) {
    if (a[pos] == 0) return 0;
    for (int i = 0; i <= n; i++) f[i] = 0;
    f[0] = 1;
    for (int i = 1; i < pos; i++) {
        if (a[i] == 0) {
            f[0] += f[0];
            if (f[0] >= base) f[0] -= base;
            for (int j = 0; j < n; j++) {
                f[j] += f[j + 1];
                if (f[j] >= base) f[j] -= base;
            }
        } else if (a[i] <= a[pos]) {
            for (int j = n; j >= 1; j--) {
                f[j] += f[j - 1];
                if (f[j] >= base) f[j] -= base;
            }
        } else {
            for (int j = 0; j <= n; j++) {
                f[j] += f[j];
                if (f[j] >= base) f[j] -= base;
            }
        }
    }

    for (int i = pos + 1; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 0; j < n; j++) {
                f[j] += f[j + 1];
                if (f[j] >= base) f[j] -= base;
            }
        } else if (a[i] < a[pos]) {
            for (int j = n; j >= 1; j--) {
                f[j] += f[j - 1];
                if (f[j] >= base) f[j] -= base;
            }
        } else {
            for (int j = 0; j <= n; j++) {
                f[j] += f[j];
                if (f[j] >= base) f[j] -= base;
            }
        }
    }

    int64_t ans = 0;
    for (int i = 0; i <= n; i++) ans += f[i];
    return ans % base;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '-')
            a[i] = 0;
        else
            cin >> a[i];
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        (ans += solve(i) * a[i]) %= base;
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
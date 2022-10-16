#include <bits/stdc++.h>
using namespace std;
constexpr int64_t base = 998244353;
int n, m;
int a[50001][21];
int64_t power(int64_t a, int64_t x) {
    int64_t res = 1;
    while (x > 0) {
        if (x % 2) (res *= a) %= base;
        (a *= a) %= base;
        x /= 2;
    }
    return res;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[j][i];

    int64_t inv = 1, ans = 0;
    for (int i = 1; i <= n; i++) (inv *= i) %= base;
    inv = power(inv, base - 2);

    for (int i = 1; i <= m; i++) {
        sort(a[i] + 1, a[i] + n + 1);
        int check = n;
        int cnt = 0;
        int64_t chance = 1;
        for (int turn = 1; turn <= n; turn++) {
            int necessary = n + 2 - turn;
            while (check && (a[i][check] >= necessary)) {
                check--;
                cnt++;
            }
            (chance *= cnt) %= base;
            cnt--;
        }
        // cerr << i << ' ' << chance << ' ' << 6 - chance << '\n';
        (chance *= inv) %= base;
        ans += 1 - chance;
    }
    ans %= base;
    if (ans < 0) ans += base;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
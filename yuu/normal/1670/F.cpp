#include <bits/stdc++.h>
using namespace std;
int n;
int64_t l, r, z;
int64_t f[2048];
int64_t g[2048];
constexpr int inf = 2047;
constexpr int base = 1e9 + 7;
int choose[1001];
int c[1001][1001];
void prepare() {
    for (int i = 0; i <= n; i++) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; j++) {
            (c[i][j] = c[i - 1][j] + c[i - 1][j - 1]) %= base;
        }
    }
    for (int i = 0; i <= n; i++) choose[i] = c[n][i];
}
int64_t count(int64_t limit) {
    for (int i = 0; i <= inf; i++) f[i] = 0;
    for (int i = 0; i <= inf; i++) g[i] = 0;
    f[0] = 1;
    for (int i = 61; i >= 0; i--) {
        for (int j = 0; j <= inf; j++) g[j] = 0;
        for (int j = 0; j < inf; j++)
            if (f[j]) {
                for (int one_bit = ((z >> i) & 1); one_bit <= n; one_bit += 2) {
                    if (j < one_bit) break;
                    int next = (j - one_bit) * 2;
                    if (i) next += (limit >> (i - 1)) & 1;
                    if (next > inf) next = inf;
                    (g[next] += f[j] * choose[one_bit]) %= base;
                }
            }
        if (f[inf]) {
            for (int one_bit = ((z >> i) & 1); one_bit <= n; one_bit += 2) {
                (g[inf] += f[inf] * choose[one_bit]) %= base;
            }
        }
        for (int j = 0; j <= inf; j++) f[j] = g[j];
    }
    int64_t ans = 0;
    for (int i = 0; i <= inf; i++) (ans += f[i]) %= base;
    return ans;
}
void solve() {
    cin >> n >> l >> r >> z;
    prepare();
    cout << (count(r) + base - count(l - 1)) % base << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
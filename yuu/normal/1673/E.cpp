#include <bits/stdc++.h>
using namespace std;
int log_table[(1 << 20) + 1];
inline bool C_parity(int n, int k) {
    if (k < 0 || k > n) return 0;
    if ((n == 0) || (n == k)) return 1;
    int total_2 = 0;
    total_2 += log_table[n];
    total_2 -= log_table[n - k];
    total_2 -= log_table[k];
    return (total_2 == 0);
}
inline bool count_way(int n, int k) {  // number of way to choose at least k from n, check if this is odd or even
    if (k < 0) k = 0;
    // C(n, k) + C(n, k+1) + ... + C(n, n)
    if (k > n) return 0;
    if (k == 0) return (n == 0);
    // same parity as C(n - 1, k - 1)
    return C_parity(n - 1, k - 1);
}
int n, k;
int b[(1 << 20) + 1];
int ans[1 << 20];

void solve() {
    for (int i = 1; i <= (1 << 20); i++) log_table[i] = log_table[i - 1] + __builtin_ctz(i);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int64_t power = b[i];
        for (int j = i; j <= n; j++) {
            int used = (i != 1);
            used += (j != n);
            int remain = max(0, n - j - 1);
            remain += max(0, i - 1 - 1);
            if (count_way(remain, k - used)) {
                ans[power] ^= 1;
            }
            if (j == n) break;
            if (b[j + 1] >= 20) break;
            power *= (1 << b[j + 1]);
            if (power >= (1 << 20)) break;
        }
    }
    int last = 0;
    for (int i = 0; i < (1 << 20); i++) {
        if (ans[i]) last = i;
    }
    while (last >= 0) {
        cout << ans[last--];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
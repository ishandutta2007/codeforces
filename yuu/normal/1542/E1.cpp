#include <bits/stdc++.h>
using namespace std;
int n;
int64_t mod;
int64_t fact[501];
int64_t c[501][501];
int64_t f[124751];
int64_t prefix[124751];
int64_t prefix_of_prefix[124751];
int64_t weighted_prefix[124751];
queue<int64_t> tail;
int64_t get_weighted_sum(int first, int last) {
    int64_t weight = 1;
    if (first < 0) {
        weight -= first;
        first = 0;
    }
    int64_t shifted = weighted_prefix[last];
    if (first) shifted -= weighted_prefix[first - 1];

    int64_t constant = prefix_of_prefix[last];
    if (first) constant -= prefix_of_prefix[first - 1];
    return (shifted + constant * (weight - first)) % mod;
}
void solve() {
    cin >> n >> mod;
    if (mod == 1) {
        cout << "0\n";
        return;
    }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (int64_t(fact[i - 1]) * i) % mod;

    c[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            if (c[i][j] >= mod) c[i][j] -= mod;
        }
    }
    int64_t ans = 0;
    int max_inversion = 0;
    f[0] = 1;
    prefix[0] = 1;
    for (int rem = 2; rem <= n; rem++) {
        int64_t res = 0;
        for (int i = 2; i <= max_inversion; i++) {
            (res += get_weighted_sum(i - rem, i - 2) * f[i]) %= mod;
        }
        (res *= c[n][rem]) %= mod;
        (ans += res * fact[n - rem]) %= mod;
        (ans += mod) %= mod;

        while (!tail.empty()) tail.pop();
        max_inversion = (rem - 1) * rem / 2;
        int64_t sum = 0;
        for (int i = 0; i < rem; i++) {
            sum += f[max_inversion - i];
            tail.push(f[max_inversion - i]);
            if (sum >= mod) sum -= mod;
        }
        for (int i = max_inversion; i >= 0; i--) {
            f[i] = sum % mod;
            sum -= tail.front();
            if (sum < 0) sum += mod;
            tail.pop();
            if (i >= rem) {
                sum += f[i - rem];
                tail.push(f[i - rem]);
            }
        }

        prefix[0] = f[0];
        for (int i = 1; i <= max_inversion; i++) {
            prefix[i] = prefix[i - 1] + f[i];
            if (prefix[i] >= mod) prefix[i] -= mod;
        }

        prefix_of_prefix[0] = prefix[0];
        for (int i = 1; i <= max_inversion; i++) {
            prefix_of_prefix[i] = prefix_of_prefix[i - 1] + prefix[i];
            if (prefix_of_prefix[i] >= mod) prefix_of_prefix[i] -= mod;
        }

        weighted_prefix[0] = 0;
        for (int i = 1; i <= max_inversion; i++) weighted_prefix[i] = (prefix[i] * i + weighted_prefix[i - 1]) % mod;
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
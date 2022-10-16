#include <bits/stdc++.h>
using namespace std;

constexpr int64_t base = 1e9 + 7;
constexpr int64_t power(int64_t x, int64_t a) {
    int64_t res = 1;
    while (a) {
        if (a % 2) (res *= x) %= base;
        (x *= x) %= base;
        a /= 2;
    }
    return res;
}

constexpr int64_t inverse(int64_t x) { return power(x, base - 2); }
int n, k, max_item;
int64_t factor[201];
int64_t dp[401][201];

int64_t get_ans(int used) {
    int64_t ans = 0;
    int64_t npi = 1;
    for (int item = 1; item <= max_item; item++) {
        if (item > used * 2) break;
        (npi *= (n - item + 1)) %= base;
        (ans += npi * dp[item][used]) %= base;
    }
    (ans += dp[0][used]) %= base;
    return ans;
}
void solve() {
    cin >> n >> k;
    dp[0][0] = 1;
    max_item = min(n, k * 2);
    for (int cycle = 2; cycle <= k + 1; cycle++) {
        factor[0] = 1;
        for (int x = 1, item = cycle, cost = cycle - 1; (item <= max_item) && (cost <= k);
             x++, cost += (cycle - 1), item += cycle) {
            factor[x] = factor[x - 1];
            (factor[x] *= inverse(x)) %= base;
            (factor[x] *= inverse(cycle)) %= base;
        }

        for (int total = max_item; total >= 0; total--) {
            for (int used = k; used >= 0; used--) {
                if (!dp[total][used]) continue;
                for (int x = 1, item = cycle, cost = cycle - 1; (total + item <= max_item) && (used + cost <= k);
                     x++, cost += (cycle - 1), item += cycle) {
                    (dp[total + item][used + cost] += dp[total][used] * factor[x]) %= base;
                }
            }
        }
    }

    for (int item = 0; item <= max_item; item++) {
        for (int used = 0; used + 2 <= k; used++) {
            (dp[item][used + 2] += dp[item][used]) %= base;
        }
    }
    for (int i = 1; i <= k; i++) cout << get_ans(i) << " \n"[i == k];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
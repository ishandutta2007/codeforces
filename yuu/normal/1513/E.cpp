#include <bits/stdc++.h>
using namespace std;
constexpr int base = 1e9 + 7;
int n;
int a[100001];
map<int, int> cnt;

int64_t power(int64_t x, int64_t a) {
    int64_t res = 1;
    while (a) {
        if (a % 2) (res *= x) %= base;
        (x *= x) %= base;
        a /= 2;
    }
    return res;
}
int64_t inverse(int64_t value) { return power(value, base - 2); }

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int64_t sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum % n) {
        cout << "0\n";
        return;
    }
    sum /= n;
    int source_cnt = 0, sink_cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > sum)
            source_cnt++;
        else if (a[i] < sum)
            sink_cnt++;
    int64_t ans = 1;
    if ((source_cnt <= 1) || (sink_cnt <= 1)) {
        for (int i = 1; i <= n; i++) (ans *= i) %= base;
    } else {
        for (int i = 1; i <= source_cnt; i++) (ans *= i) %= base;
        for (int i = 1; i <= sink_cnt; i++) (ans *= i) %= base;
        (ans *= 2) %= base;
        for (int i = source_cnt + sink_cnt + 1; i <= n; i++) (ans *= i) %= base;
    }
    int64_t inv = 1;
    for (auto&& [value, time] : cnt) {
        for (int i = 1; i <= time; i++) (inv *= i) %= base;
    }
    (ans *= inverse(inv)) %= base;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
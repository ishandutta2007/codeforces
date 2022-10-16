#include <bits/stdc++.h>
using namespace std;
int n, k;
int s[200001];
int pos[200001];

bool leq(int a, int b) {
    if (a > n) return true;
    if (b > n) return false;
    return pos[a] <= pos[b];
}
constexpr int64_t base = 998244353;
int64_t power(int64_t x, int a) {
    int64_t res = 1;
    while (a > 0) {
        if (a % 2) (res *= x) %= base;
        (x *= x) %= base;
        a /= 2;
    }
    return res;
}

int64_t C(int n, int k) {
    int64_t top = 1;
    for (int i = 1; i <= n; i++) (top *= i) %= base;
    int64_t bot = 1;
    for (int i = 1; i <= k; i++) (bot *= i) %= base;
    for (int i = 1; i <= n - k; i++) (bot *= i) %= base;
    return (top * power(bot, base - 2)) % base;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i]++;
        pos[s[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        int p = pos[i];

        if (p > 1)
            if (leq(s[p] + 1, s[p - 1] + 1)) k--;
    }

    if (k <= 0)
        cout << "0\n";
    else
        cout << C(k + n - 1, n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
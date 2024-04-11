#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;

int64_t f[5001];
int64_t r[5001];
constexpr int64_t base = 998244353;
int64_t C(int n, int k) { return ((f[n] * r[k]) % base * r[n - k]) % base; }

int64_t power(int64_t x, int64_t a) {
    int64_t res = 1;
    while (a > 0) {
        if (a % 2) (res *= x) %= base;
        (x *= x) %= base;
        a /= 2;
    }
    return res;
}

void solve() {
    cin >> n >> k >> s;
    if (k == 0) {
        cout << "1\n";
        return;
    }
    s = 'a' + s;

    f[0] = 1;
    for (int i = 1; i <= n; i++) (f[i] = f[i - 1] * i) %= base;
    r[n] = power(f[n], base - 2);
    for (int i = n; i >= 1; i--) (r[i - 1] = r[i] * i) %= base;

    int cnt = 0;
    int j = 1;
    cnt = (s[1] == '1');
    int64_t ans = 1;
    for (int i = 1; i <= n; i++) {
        while ((cnt < k) && (j + 1 <= n)) {
            j++;
            if (s[j] == '1') cnt++;
        }
        if ((i == 1) && (cnt < k)) {
            cout << "1\n";
            return;
        }
        while ((j + 1 <= n) && (s[j + 1] == '0')) j++;

        int size = j - i + 1;
        if (size > cnt) {  // has both 0 and 1
            int count_0 = size - cnt;
            int count_1 = cnt;
            if (s[i] == '0') {
                count_1--;
            } else {
                count_0--;
            }
            (ans += C(count_0 + count_1, count_0)) %= base;
        }
        if (s[i] == '1') cnt--;
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
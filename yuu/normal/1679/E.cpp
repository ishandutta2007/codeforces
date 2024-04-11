#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
int weight[17][1 << 17];
constexpr int base = 998244353;
int64_t power(int64_t a, int64_t x) {
    int64_t res = 1;
    while (x) {
        if (x % 2) (res *= a) %= base;
        (a *= a) %= base;
        x /= 2;
    }
    return res;
}
void make_palin(int cl, int cr) {
    int req = 0;
    int64_t w[17];
    int inv[18];
    for (int i = 1; i <= 17; i++) inv[i] = power(i, base - 2);
    for (int i = 0; i < 17; i++) w[i] = 1;
    for (int i = 1; i <= n; i++)
        if (s[i] == '?') {
            for (int i = 0; i < 17; i++) (w[i] *= (i + 1)) %= base;
        }
    while ((cl >= 1) && (cr <= n)) {
        if (s[cl] == '?') {
            if (s[cr] == '?') {
                if (cr != cl)
                    for (int i = 0; i < 17; i++) (w[i] *= inv[i + 1]) %= base;
            } else {
                req |= (1 << s[cr]);
                for (int i = 0; i < 17; i++) (w[i] *= inv[i + 1]) %= base;
            }
        } else {
            if (s[cr] == '?') {
                req |= (1 << s[cl]);
                for (int i = 0; i < 17; i++) (w[i] *= inv[i + 1]) %= base;
            } else {
                if (s[cr] != s[cl]) return;
            }
        }
        for (int i = 0; i < 17; i++) (weight[i][req] += w[i]) %= base;
        cl--;
        cr++;
    }
}
void solve() {
    cin >> n >> s;
    for (auto&& x : s)
        if (x != '?') x -= 'a';
    s = '0' + s;
    for (int center = 1; center <= n; center++) {
        make_palin(center, center);
        make_palin(center, center + 1);
    }
    for (int w = 0; w < 17; w++) {
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < (1 << 17); j++) {
                if (((j >> i) & 1) == 0) {
                    (weight[w][j | (1 << i)] += weight[w][j]) %= base;
                }
            }
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> s;
        int pos = 0;
        for (auto&& x : s) pos |= (1 << (x - 'a'));
        cout << weight[s.size() - 1][pos] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
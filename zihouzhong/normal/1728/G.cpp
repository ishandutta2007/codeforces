#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

template <class T> T qp(T a, int b) {
    T c = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) c *= a;
    }
    return c;
}

struct mint {
    int x;
    mint(int _x = 0) : x(_x % P) { x < 0 ? x += P : 0; }
    int val() const { return x; }

    mint operator - () const {
        return !x ? 0 : P - x;
    }
    mint inv() const {
        assert(x != 0);
        return qp(*this, P - 2);
    }
    mint &operator += (const mint &rhs) {
        x += rhs.x - P, x += x >> 31 & P;
        return *this;
    }
    mint &operator -= (const mint &rhs) {
        x -= rhs.x, x += x >> 31 & P;
        return *this;
    }
    mint &operator *= (const mint &rhs) {
        x = (long long)x * rhs.x % P;
        return *this;
    }
    mint &operator /= (const mint &rhs) {
        return *this *= rhs.inv();
    }
    friend mint operator + (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res += rhs, res;
    }
    friend mint operator - (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res -= rhs, res;
    }
    friend mint operator * (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res *= rhs, res;
    }
    friend mint operator / (const mint &lhs, const mint &rhs) {
        mint res = lhs;
        return res /= rhs, res;
    }

    friend ostream &operator << (ostream &os, const mint &a) {
        return os << a.val();
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> l(n), p(m);
    for (int &x : l) {
        cin >> x;
    }
    sort(l.begin(), l.end());
    for (int &x : p) {
        cin >> x;
    }
    p.insert(p.end(), {-d, 2 * d});
    sort(p.begin(), p.end());
    vector coef(m + 2, vector<mint>(m + 2, 1));
    for (int k = 0; k < n; k++) {
        for (int i = 0; p[i] < l[k]; i++) {
            for (int j = m + 1; p[j] > l[k]; j--) {
                int dist = min(l[k] - p[i], p[j] - l[k]);
                if (i == 0 && j == m + 1) dist = d + 1;
                coef[i][j] *= dist;
            }
        }
    }
    vector dp(m + 2, vector<mint>(m + 2));
    for (int mask = 0; mask < 1 << m; mask++) {
        int u = (mask << 1) | 1 | (1 << (m + 1));
        mint val = __builtin_parity(mask) & 1 ? -1 : 1;
        while (__builtin_popcount(u) > 1) {
            int l = __builtin_ctz(u);
            int r = __builtin_ctz(u ^ (1 << l));
            val *= coef[l][r], u ^= 1 << l;
        }
        u = (mask << 1) | 1 | (1 << (m + 1));
        while (__builtin_popcount(u) > 1) {
            int l = __builtin_ctz(u);
            int r = __builtin_ctz(u ^ (1 << l));
            dp[l][r] += val, u ^= 1 << l;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int f;
        cin >> f;
        mint ans;
        for (int l = 0; p[l] < f; l++) {
            for (int r = m + 1; p[r] > f; r--) {
                int dist = min(f - p[l], p[r] - f);
                if (l == 0 && r == m + 1) dist = d + 1;
                ans += dp[l][r] * dist;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
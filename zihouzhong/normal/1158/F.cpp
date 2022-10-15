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

void solve1(int n, int c, vector<int> a) {
    vector<mint> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i < pw.size(); i++) {
        pw[i] = 2 * pw[i - 1];
    }
    vector<mint> coef(n + 1), coef_inv(coef);
    coef_inv[0] = 1;
    for (int i = 1; i < coef.size(); i++) {
        coef[i] = pw[i] - 1;
        coef_inv[i] = coef[i].inv();
    }
    vector f(n + 1, vector<mint>(n / c + 1));
    for (int i = n; ~i; i--) {
        for (int j = 1; j <= (n - i) / c; j++) {
            int occ = 0;
            vector<int> cnt(c);
            mint w = 1;
            for (int k = i; n - k - 1 >= c * (j - 1); k++) {
                w *= coef_inv[cnt[a[k]]];
                if (!cnt[a[k]]++) occ++;
                if (occ == c) f[i][j] += w * f[k + 1][j - 1];
                w *= coef[cnt[a[k]]];
            }
        }
        f[i][0] = pw[n - i] - accumulate(f[i].begin(), f[i].end(), mint());
    }
    f[0].resize(n + 1), f[0][0] -= 1;
    for (auto &x : f[0]) {
        cout << x << " ";
    }
    cout << "\n";
}

void solve2(int n, int c, vector<int> a) {
    vector f(n / c + 1, vector<mint>(1 << c));
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        auto g = f;
        for (int j = 0; j <= i / c; j++) {
            for (int S = 0; S < 1 << c; S++) {
                g[j][S | (1 << a[i])] += f[j][S];
            }
            if (g[j].back().val()) {
                g[j + 1][0] += g[j].back(), g[j].back() = 0;
            }
        }
        swap(f, g);
    }
    f.resize(n + 1), f[0][0] -= 1;
    for (auto &v : f) {
        cout << accumulate(v.begin(), v.end(), mint()) << " ";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x, x--;
    }
    c > 11 ? solve1(n, c, a) : solve2(n, c, a);
    return 0;
}
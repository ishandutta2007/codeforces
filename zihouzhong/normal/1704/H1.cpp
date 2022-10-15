#include <bits/stdc++.h>
using namespace std;

int P;

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
    int n;
    cin >> n >> P;
    vector<mint> fact(n + 1), finv(fact);
    fact[0] = finv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1];
        finv[i] = fact[i].inv();
    }
    auto binom = [&](int x, int y) -> mint {
        if (x < y) return 0;
        return fact[x] * finv[y] * finv[x - y];
    };
    vector<mint> f(n + 1);
    for (int i = 2; i <= n; i++) {
        f[i] = i * (i - 1);
        for (int j = 2; j < i; j++) {
            f[i] += i * f[j] * binom(i - 1, j);
        }
    }
    for (mint &x : f) {
        x *= n - 1;
    }
    vector<mint> res(n + 1);
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            res[i] += binom(i - 1, j - 1) * f[j] * res[i - j];
        }
    }
    cout << res[n] << "\n";
    return 0;
}
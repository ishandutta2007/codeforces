#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    for (ll &x : d) {
        cin >> x;
    }
    partial_sum(d.begin(), d.end(), d.begin());
    map<ll, int> occ;
    occ[0]++;
    for (int i = 0; i < n - 1; i++) {
        occ[d[i] % (d.back() / 2)]++;
    }
    int c1 = 0, c2 = 0;
    for (auto &[_, t] : occ) {
        (t == 1 ? c1 : c2)++;
    }
    if (d.back() % 2) c1 = n, c2 = 0;
    vector<mint> fact(max(c2, m) + 1), finv(fact);
    fact[0] = finv[0] = 1;
    for (int i = 1; i < fact.size(); i++) {
        fact[i] = i * fact[i - 1];
        finv[i] = fact[i].inv();
    }
    auto binom = [&](int x, int y) -> mint {
        if (x < y || y < 0) return 0;
        return fact[x] * finv[y] * finv[x - y];
    };
    mint ans;
    for (int i = 0; i <= min(m, c2); i++) {
        if (i == m && i < c2) continue;
        mint ways = binom(c2, i) * binom(m, i) * fact[i];
        ways *= qp(mint(m - i), c2 - i + c1) * qp(mint(m - i - 1), c2 - i);
        ans += ways;
    }
    cout << ans << "\n";
    return 0;
}
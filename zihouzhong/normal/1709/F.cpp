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
    friend mint operator + (const mint &a, const mint &b) {
        mint res = a;
        return res += b, res;
    }
    friend mint operator - (const mint &a, const mint &b) {
        mint res = a;
        return res -= b, res;
    }
    friend mint operator * (const mint &a, const mint &b) {
        mint res = a;
        return res *= b, res;
    }
    friend mint operator / (const mint &a, const mint &b) {
        mint res = a;
        return res /= b, res;
    }

    friend ostream &operator << (ostream &os, const mint &a) {
        return os << a.val();
    }
};

void DFT(vector<mint> &a) {
    static vector<int> rev;
    int n = a.size();
    if (rev.size() != n) {
        rev.resize(n);
        int k = __lg(n) - 1;
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    static vector<mint> w;
    if (w.size() != n) {
        w.resize(n), w[n / 2] = 1;
        mint t = qp(mint(3), (P - 1) / n);
        for (int i = n / 2 + 1; i < n; i++) w[i] = t * w[i - 1];
        for (int i = n / 2 - 1; i > 0; i--) w[i] = w[i * 2];
    }
    static vector<unsigned long long> c;
    if (c.size() < n) c.resize(n);
    for (int i = 0; i < n; i++) c[i] = a[i].val();
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                auto t = c[i + j + k] * w[j + k].val() % P;
                c[i + j + k] = c[i + j] + P - t, c[i + j] += t;
            }
        }
    }
    for (int i = 0; i < n; i++) a[i] = c[i] % P;
}

void IDFT(vector<mint> &a) {
    int n = a.size();
    reverse(a.begin() + 1, a.end()), DFT(a);
    mint inv = (1 - P) / n;
    for (int i = 0; i < n; i++) a[i] *= inv;
}

struct poly {
    vector<mint> a;
    poly() {}
    explicit poly(int n) : a(n) {}
    poly(const vector<mint> &x) : a(x) {}
    poly(const initializer_list<mint> &x) : a(x) {}

    int size() const { return a.size(); }
    void resize(int n) { a.resize(n); }
    mint operator [] (int idx) const {
        if (idx < 0 || idx >= size()) return 0;
        return a[idx];
    }
    mint &operator [] (int idx) { return a[idx]; }

    poly mulxk(int k) const {
        auto b = a;
        return b.insert(b.begin(), k, 0), b;
    }
    poly modxk(int k) const {
        k = min(k, size());
        return vector<mint>(a.begin(), a.begin() + k);
    }
    poly divxk(int k) const {
        if (size() <= k) return poly();
        return vector<mint>(a.begin() + k, a.end());
    }

    friend poly operator + (const poly &a, const poly &b) {
        poly c(max(a.size(), b.size()));
        for (int i = 0; i < c.size(); i++) c[i] = a[i] + b[i];
        return c;
    }
    friend poly operator - (const poly &a, const poly &b) {
        poly c(max(a.size(), b.size()));
        for (int i = 0; i < c.size(); i++) c[i] = a[i] - b[i];
        return c;
    }
    friend poly operator * (poly a, poly b) {
        if (!a.size() || !b.size()) return poly();
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot) sz *= 2;
        a.resize(sz), b.resize(sz);
        DFT(a.a), DFT(b.a);
        for (int i = 0; i < sz; i++) a.a[i] = a[i] * b[i];
        IDFT(a.a), a.resize(tot);
        return a;
    }
    friend poly operator * (mint a, poly b) {
        for (int i = 0; i < b.size(); i++) b[i] *= a;
        return b;
    }
    friend poly operator * (poly a, mint b) {
        for (int i = 0; i < a.size(); i++) a[i] *= b;
        return a;
    }
    poly &operator += (poly b) { return *this = *this + b; }
    poly &operator -= (poly b) { return *this = *this - b; }
    poly &operator *= (poly b) { return *this = *this * b; }

    poly deriv() const {
        if (a.empty()) return poly();
        poly res(size() - 1);
        for (int i = 0; i < size() - 1; i++) res[i] = (i + 1) * a[i + 1];
        return res;
    }
    poly integr() const {
        poly res(size() + 1);
        for (int i = 0; i < size(); i++) res[i + 1] = a[i] / (i + 1);
        return res;
    }
    poly inv(int m) const {
        poly x{a[0].inv()};
        for (int k = 1; k < m; ) {
            k *= 2;
            x = (x * (poly{2} - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }
    poly log(int m) const { return (deriv() * inv(m)).integr().modxk(m); }
    poly exp(int m) const {
        poly x{1};
        for (int k = 1; k < m; ) {
            k *= 2;
            x = (x * (poly{1} - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }
    poly pow(int k, int m) const {
        int i = 0;
        while (i < size() && !a[i].val()) i++;
        if (i == size() || 1LL * i * k >= m) return poly(vector<mint>(m));
        mint v = a[i];
        auto f = (divxk(i) * v.inv()).log(m - i * k) * k;
        return f.exp(m - i * k).mulxk(i * k) * qp(v, k);
    }
    poly sqrt(int m) const {
        poly x{1};
        for (int k = 1; k < m; ) {
            k *= 2;
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((P + 1) / 2);
        }
        return x.modxk(m);
    }

    poly mulT(poly b) const {
        if (!b.size()) return poly();
        int n = b.size();
        reverse(b.a.begin(), b.a.end());
        return (*this * b).divxk(n - 1);
    }
    vector<mint> eval(vector<mint> x) {
        if (!size()) return vector<mint>(x.size(), 0);
        const int n = max(int(x.size()), size());
        vector<poly> q(4 * n);
        vector<mint> ans(x.size());
        x.resize(n);
        auto build = [&](auto self, int p, int l, int r) {
            if (r - l == 1) { q[p] = poly{1, -x[l]}; return; }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m), self(self, 2 * p + 1, m, r);
            q[p] = q[2 * p] * q[2 * p + 1];
        };
        build(build, 1, 0, n);
        auto work = [&](auto self, int p, int l, int r, const poly &num) {
            if (r - l == 1) {
                if (l < ans.size()) ans[l] = num[0];
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
            self(self, 2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
        };
        work(work, 1, 0, n, mulT(q[1].inv(n)));
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, f;
    cin >> n >> k >> f;
    vector<poly> g(n, poly(max(k, f) + 1));
    for (int i = 0; i <= k; i++) {
        g[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        auto h = g[i - 1] * g[i - 1];
        poly hs(h.size() + 1);
        for (int j = h.size() - 1; ~j; j--) {
            hs[j] = hs[j + 1] + h[j];
        }
        for (int j = 0; j <= k; j++) {
            g[i][j] += h[j] * (k - j + 1) + hs[j + 1];
        }
    }
    g[n - 1] = g[n - 1] * g[n - 1];
    cout << g[n - 1][f] << "\n";
    return 0;
}
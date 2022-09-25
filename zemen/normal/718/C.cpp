#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

void addTo(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int mul(ll a, ll b) {
    return (a * b) % mod;
}

struct Matrix {
    int a[2][2];

    Matrix() {
        a[0][0] = a[1][1] = 1;
        a[0][1] = a[1][0] = 0;
    }

    Matrix &operator=(const Matrix &m) {
        forn (i, 2)
            forn (j, 2)
                a[i][j] = m.a[i][j];
        return *this;
    }

    Matrix operator*(const Matrix &m) const {
        Matrix res;
        res.a[0][0] = res.a[1][1] = 0;
        forn (i, 2)
            forn (j, 2)
                forn (k, 2)
                    addTo(res.a[i][j], mul(a[i][k], m.a[k][j]));
        return res;
    }

    Matrix operator+(const Matrix &m) const {
        Matrix res = *this;
        forn (i, 2)
            forn (j, 2)
                addTo(res.a[i][j], m.a[i][j]);
        return res;
    }

    bool isE() const {
        return a[0][0] == 1 && a[1][1] == 1 && a[0][1] == 0 && a[1][0] == 0;
    }
};

Matrix ZERO;

Matrix binpow(Matrix a, int deg) {
    Matrix res;
    while (deg) {
        if (deg & 1)
            res = res * a;
        deg /= 2;
        a = a * a;
    }
    return res;
}

const int base = 1 << 17;

namespace T {
    Matrix t[base * 2];
    Matrix upd[base * 2];

    void _put(int v, const Matrix &a) {
        t[v] = t[v] * a;
        upd[v] = upd[v] * a;
    }

    void push(int v) {
        if (upd[v].isE())
            return;
        _put(v * 2, upd[v]);
        _put(v * 2 + 1, upd[v]);
        upd[v] = Matrix();
    }

    void update(int v) {
        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    Matrix get(int l, int r, int v = 1, int cl = 0, int cr = base) {
        if (l <= cl && cr <= r)
            return t[v];
        if (r <= cl || cr <= l)
            return ZERO;
        push(v);
        int cc = (cl + cr) / 2;
        return get(l, r, v * 2, cl, cc) + get(l, r, v * 2 + 1, cc, cr);
    }

    void put(int l, int r, const Matrix &a, int v = 1, int cl = 0, int cr = base) {
        if (l <= cl && cr <= r) {
            _put(v, a);
            return;
        }
        if (r <= cl || cr <= l)
            return;
        push(v);
        int cc = (cl + cr) / 2;
        put(l, r, a, v * 2, cl, cc);
        put(l, r, a, v * 2 + 1, cc, cr);
        update(v);
    }

    void build(int n) {
        for (int i = n; i < base; ++i)
            t[i + base] = ZERO;
        for (int i = base - 1; i > 0; --i)
            update(i);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    ZERO.a[0][0] = ZERO.a[1][1] = 0;
    int n, m;
    cin >> n >> m;

    Matrix fib;
    fib.a[0][0] = 0;
    fib.a[0][1] = fib.a[1][0] = fib.a[1][1] = 1;

    forn (i, n) {
        int a;
        scanf("%d", &a);
        T::t[i + base] = binpow(fib, a);
    }
    T::build(n);
    forn (i, m) {
        int tp, l, r;
        scanf("%d%d%d", &tp, &l, &r);
        --l;
        if (tp == 1) {
            int x;
            scanf("%d", &x);
            T::put(l, r, binpow(fib, x));
        } else {
            cout << T::get(l, r).a[0][1] << '\n';
        }
    }
}
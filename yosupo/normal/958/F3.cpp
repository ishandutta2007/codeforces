#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

using R = double;
const R PI = 4*atan(R(1));
using Pc = complex<R>;

void fft(bool type, V<Pc> &c) {
    int N = int(c.size());
    if (N <= 1) return;
    int s = 0;
    while ((1<<s) < N) s++;
    assert(1<<s == N);

    static V<Pc> ep[30];
    if (!ep[s].size()) {
        for (int i = 0; i < N; i++) {
            ep[s].push_back(polar<R>(1, i*2*PI/N));
        }
    }
    V<Pc> a = c, b(N);
    for (int i = 1; i <= s; i++) {
        int W = 1<<(s-i);
        for (int y = 0; y < N/2; y += W) {
            Pc now = ep[s][y]; if (type) now = conj(now);
            for (int x = 0; x < W; x++) {
                auto l = a[y<<1 | x];
                auto u = now, v = a[y<<1 | x | W];
                auto r = Pc(u.real() * v.real() - u.imag() * v.imag(),
                    u.real() * v.imag() + u.imag() * v.real());
                b[y | x]        = l+r;
                b[y | x | N>>1] = l-r;
            }
        }
        swap(a, b);
    }
    c = a;
}

template<uint MD>
struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(uint x) {return (x<MD)?x:x-MD;};
    static M make(uint x) {M m; m.v = x; return m;}
    static M inv(const M &x) {return x.pow(MD-2); }
    M operator+(const M &r) const {return make(normS(v+r.v));}
    M operator-(const M &r) const {return make(normS(v+MD-r.v));}
    M operator*(const M &r) const {return make(ull(v)*r.v%MD);}
    M operator/(const M &r) const {return *this*inv(r);}
    M& operator+=(const M &r) {return *this=*this+r;}
    M& operator-=(const M &r) {return *this=*this-r;}
    M& operator*=(const M &r) {return *this=*this*r;}
    M& operator/=(const M &r) {return *this=*this/r;}
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
};
using Mint = ModInt<1009>;


V<Mint> multiply(const V<Mint> &a, const V<Mint> &b) {
    auto A = a.size(), B = b.size();
    assert(A && B);
    int lg = 0;
    while ((1<<lg) < A+B-1) lg++;
    int N = 1<<lg;
    V<Pc> ac(N, Pc(0, 0)), bc(N, Pc(0, 0));
    for (int i = 0; i < A; i++) ac[i] = a[i].v;
    for (int i = 0; i < B; i++) bc[i] = b[i].v;
    fft(false, ac);
    fft(false, bc);
    for (int i = 0; i < N; i++) {
        ac[i] *= bc[i];
    }
    fft(true, ac);
    V<Mint> c(A+B-1);
    for (int i = 0; i < A+B-1; i++) {
        c[i] = Mint(ll(round((ac[i] / R(N)).real())));
    }
    return c;
}

struct Comp {
    bool operator()(const V<Mint> &a, const V<Mint> &b) const {
        return a.size() > b.size();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n, m, k;
    cin >> n >> m >> k;
//    n = m = k = 200000;
    V<int> cnt(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; x--;
//        x = i;
        cnt[x]++;
    }


    priority_queue<V<Mint>, VV<Mint>, Comp> que;
    for (int d: cnt) {
        V<Mint> v(d+1, Mint(1));
        que.push(v);
    }

    while (que.size() > 1) {
        V<Mint> v1 = que.top(); que.pop();
        V<Mint> v2 = que.top(); que.pop();
//        cout << v1.size() << " " << v2.size() << endl;
        que.push(multiply(v1, v2));
    }

    auto v = que.top();

    cout << v[k].v << endl;
    return 0;
}
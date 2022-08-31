#pragma GCC target ("avx")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <complex>
#include <x86intrin.h>

#define ALIGN __attribute__((aligned(32)))

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }
int bsr(ll x) { return 63 - __builtin_clzll(x); }
int bsf(int x) { return __builtin_ctz(x); }
int bsf(ll x) { return __builtin_ctzll(x); }

template<class T>
T pow(T x, ll n, T r = 1) {
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}

template<uint MD>
struct ModInt {
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(const uint &x) {return (x<MD)?x:x-MD;};
    static ModInt make(const uint &x) {ModInt m; m.v = x; return m;}
    static ModInt inv(const ModInt &x) {return pow(ModInt(x), MD-2);} 
    ModInt operator+(const ModInt &r) const {return make(normS(v+r.v));}
    ModInt operator-(const ModInt &r) const {return make(normS(v+MD-r.v));}
    ModInt operator*(const ModInt &r) const {return make((ull)v*r.v%MD);}
    ModInt operator/(const ModInt &r) const {return *this*inv(r);}
    ModInt& operator+=(const ModInt &r) {return *this=*this+r;}
    ModInt& operator-=(const ModInt &r) {return *this=*this-r;}
    ModInt& operator*=(const ModInt &r) {return *this=*this*r;}
    ModInt& operator/=(const ModInt &r) {return *this=*this/r;}
};
template<uint MD> string to_string(ModInt<MD> m) {return to_string(m.v);}
using Mint = ModInt<TEN(9)+7>;

using R = double;
const R PI = 4*atan(R(1));
struct Pc {
    R x, y;
    Pc() : x(0), y(0) {}
    Pc(R x, R y) : x(x), y(y) {}
    Pc operator+(const Pc &r) const {return Pc(x+r.x, y+r.y);}
    Pc operator-(const Pc &r) const {return Pc(x-r.x, y-r.y);}
    Pc operator*(const Pc &r) const {return Pc(x*r.x-y*r.y, x*r.y+y*r.x);}
    Pc operator*(const R &r) const {return Pc(x*r, y*r);}
    Pc& operator+=(const Pc &r) {return *this=*this+r;}
    Pc& operator-=(const Pc &r) {return *this=*this-r;}
    Pc& operator*=(const Pc &r) {return *this=*this*r;}   
    Pc& operator*=(const R &r) {return *this=*this*r;}
    static Pc polar(R r, R th) {return Pc(cos(th)*r, sin(th)*r);}
};

void fft(bool type, vector<Pc> &c) {
    static vector<Pc> buf[30];
    int N = int(c.size());
    int s = bsr(N);
    assert(1<<s == N);
    if (!buf[s].size()) {
        buf[s] = vector<Pc>(N);
        for (int i = 0; i < N; i++) {
            buf[s][i] = Pc::polar(1, i*2*PI/N);
        }
    }
    vector<Pc> a = c, b(N);
    for (int i = 1; i <= s; i++) {
        int W = 1<<(s-i); //W
        for (int y = 0; y < N/2; y += W) {
            Pc now = buf[s][y]; if (type) now.y *= -1;
            for (int x = 0; x < W; x++) {
                auto l =       a[y<<1 | x];
                auto r = now * a[y<<1 | x | W];
                b[y | x]        = l+r;
                b[y | x | N>>1] = l-r;
            }
        }
        swap(a, b);
    }
    c = a;
}

template<class Mint>
vector<Mint> multiply(vector<Mint> x, vector<Mint> y) {
    constexpr int B = 3, SHIFT = 10;
    int S = x.size()+y.size()-1;
    int N = 2<<bsr(S-1);
    vector<Pc> a[B], b[B];
    for (int fe = 0; fe < B; fe++) {
        a[fe] = vector<Pc>(N);
        b[fe] = vector<Pc>(N);
        vector<Pc> c(N);
        for (int i = 0; i < int(x.size()); i++) {
            c[i].x = (x[i].v >> (fe*SHIFT)) & ((1<<SHIFT)-1);
        }
        for (int i = 0; i < int(y.size()); i++) {
            c[i].y = (y[i].v >> (fe*SHIFT)) & ((1<<SHIFT)-1);
        }
        fft(false, c);
        for (int i = 0; i < N; i++) {
            c[i] *= 0.5;
        }
        for (int i = 0; i < N; i++) {
            int j = (N-i)%N;
            a[fe][i] = Pc(c[i].x+c[j].x, c[i].y-c[j].y);
            b[fe][i] = Pc(c[i].y+c[j].y, -c[i].x+c[j].x);
        }
    }
    vector<Mint> z(S);
    vector<Pc> c[B];
    for (int fe = 0; fe < B; fe++) {
        c[fe] = vector<Pc>(N);
    }
    for (int af = 0; af < B; af++) {
        for (int bf = 0; bf < B; bf++) {
            int cf = (af+bf)%B;
            for (int i = 0; i < N; i++) {
                if (af+bf<B) {
                    c[cf][i] += a[af][i]*b[bf][i];
                } else {
                    c[cf][i] += a[af][i]*b[bf][i]*Pc(0, 1);
                }
            }
        }
    }
    for (int fe = 0; fe < B; fe++) {
        fft(true, c[fe]);
    }
    Mint base = 1;
    for (int fe = 0; fe < 2*B-1; fe++) {
        for (int i = 0; i < S; i++) {
            if (fe < B) {
                c[fe][i].x *= 1.0/N;
                z[i] += Mint(ll(round(c[fe][i].x)))*base;
            } else {       
                c[fe-B][i].y *= 1.0/N;
                z[i] += Mint(ll(round(c[fe-B][i].y)))*base;
            }
        }
        base *= 1<<SHIFT;
    }
    return z;
}



template<class D>
struct Poly {
    V<D> v;
    int size() const {return int(v.size());}
    Poly(int N = 0) : v(V<D>(N)) {}
    Poly(const V<D> &v) : v(v) {shrink();}
    Poly& shrink() {while (v.size() && !v.back()) v.pop_back(); return *this;}
    D freq(int p) const { return (p < size()) ? v[p] : D(0); }

    Poly operator+(const Poly &r) const {
        int N = size(), M = r.size();
        V<D> res(max(N, M));
        for (int i = 0; i < max(N, M); i++) res[i] = freq(i)+r.freq(i);
        return Poly(res);
    }
    Poly operator-(const Poly &r) const {
        int N = size(), M = r.size();
        V<D> res(max(N, M));
        for (int i = 0; i < max(N, M); i++) res[i] = freq(i)-r.freq(i);
        return Poly(res);
    }
    Poly operator*(const Poly &r) const {
        int N = size(), M = r.size();
        if (min(N, M) == 0) return Poly();
        assert(N+M-1 >= 0);
        V<D> res = multiply(v, r.v);
        return Poly(res);
    }
    Poly operator*(const D &r) const {
        V<D> res(size());
        for (int i = 0; i < size(); i++) res[i] = v[i]*r;
        return Poly(res);
    }
    Poly& operator+=(const Poly &r) {return *this = *this+r;}
    Poly& operator-=(const Poly &r) {return *this = *this-r;}
    Poly& operator*=(const Poly &r) {return *this = *this*r;}
    Poly& operator*=(const D &r) {return *this = *this*r;}

    Poly operator<<(const int n) const {
        assert(n >= 0);
        V<D> res(size()+n);
        for (int i = 0; i < size(); i++) {
            res[i+n] = v[i];
        }
        return Poly(res);
    }
    Poly operator>>(const int n) const {
        assert(n >= 0);
        if (size() <= n) return Poly();
        V<D> res(size()-n);
        for (int i = n; i < size(); i++) {
            res[i-n] = v[i];
        }
        return Poly(res);
    }

    // x % y
    Poly rem(const Poly &y) const {
        return *this - y * div(y);
    }
    Poly rem_inv(const Poly &y, const Poly &ny, int B) const {
        return *this - y * div_inv(ny, B);
    }
    Poly div(const Poly &y) const {
        int B = max(size(), y.size());
        return div_inv(y.inv(B), B);
    }
    Poly div_inv(const Poly &ny, int B) const {
        return (*this*ny)>>(B-1);
    }
    // this * this.inv() = x^n + r(x) (size())
    Poly strip(int n) const {
        V<D> res = v;
        res.resize(min(n, size()));
        return Poly(res);
    }
    Poly rev(int n = -1) const {
        V<D> res = v;
        if (n != -1) res.resize(n);
        reverse(begin(res), end(res));
        return Poly(res);
    }
    // f * f.inv() = x^B + r(x) (B >= n)
    Poly inv(int n) const {
        int N = size();
        assert(N >= 1);
        assert(n >= N-1);
        Poly c = rev();
        Poly d = Poly(V<D>({D(1)/c.freq(0)}));
        int i;
        for (i = 1; i+N-2 < n; i *= 2) {
            auto u = V<D>({2});
            d = (d * (Poly(V<D>{2})-c*d)).strip(2*i);
        }
        return d.rev(n+1-N);
    }
};
template<class D>
string to_string(const Poly<D> &p) {
    if (p.size() == 0) return "0";
    string s = "";
    for (int i = 0; i < p.size(); i++) {
        if (p.v[i]) {
            s += to_string(p.v[i])+"x^"+to_string(i);
            if (i != p.size()-1) s += "+";
        }
    }
    return s;
}
// x^n % mod
template<class D>
Poly<D> nth_mod(ll n, const Poly<D> &mod) {
    int B = mod.size() * 2 - 1;
    Poly<D> mod_inv = mod.inv(B);
    Poly<D> p = V<D>{Mint(1)};
    int m = (!n) ? -1 : bsr(n);
    for (int i = m; i >= 0; i--) {
        if (n & (1LL<<i)) {
            // += 1
            p = (p<<1).rem_inv(mod, mod_inv, B);
        }
        if (i) {
            // *= 2
            p = (p*p).rem_inv(mod, mod_inv, B);
        }
    }
    return p;
}

template<class D>
Poly<D> berlekamp_massey(const V<D> &s) {
    int N = int(s.size());
    V<D> b = {D(-1)}, c = {D(-1)};
    D y = D(1);
    for (int ed = 1; ed <= N; ed++) {
        int L = int(c.size()), M = int(b.size());
        D x = 0;
        for (int i = 0; i < L; i++) {
            x += c[i]*s[ed-L+i];
        }
        b.push_back(0); M++;
        if (!x) {
            continue;
        }
        D freq = x/y;
        if (L < M) {
            //use b
            auto tmp = c;
            c.insert(begin(c), M-L, D(0));
            for (int i = 0; i < M; i++) {
                c[M-1-i] -= freq*b[M-1-i];
            }
            b = tmp;
            y = x;
        } else {
            //use c
            for (int i = 0; i < M; i++) {
                c[L-1-i] -= freq*b[M-1-i];
            }
        }
    }
    return Poly<D>(c);
}

ll rand_int(ll l, ll r) { //[l, r]
    using D = uniform_int_distribution<ll>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l, r)(gen);
}
template<class Mint>
V<Mint> randV(int N) {
    V<Mint> res(N);
    for (int i = 0; i < N; i++) {
        res[i] = Mint(rand_int(1, Mint(-1).v));
    }
    return res;
}

using P = pair<int, int>;

template<class Mint>
Mint det(const V<Mint> &diag, const V<P> &edges) {
    int N = int(diag.size());
    if (N == 0) return 1;
    V<Mint> c = randV<Mint>(N), l = randV<Mint>(N), r = randV<Mint>(N);
/*    cout << "diag : ";
    for (int i = 0; i < N; i++) {
        cout << diag[i].v << ", ";
    } cout << endl;
    cout << "edges : ";
    for (auto p: edges) {
        cout << "(" << p.first << " " << p.second << "), ";
    } cout << endl;*/
    // l * mat * r
    V<Mint> buf(2*N);
    for (int fe = 0; fe < 2*N; fe++) {
        for (int i = 0; i < N; i++) {
            buf[fe] += l[i]*r[i];
        }
        for (int i = 0; i < N; i++) {
            r[i] *= c[i];
        }
        V<Mint> tmp(N);
        for (int i = 0; i < N; i++) {
            tmp[i] = diag[i] * r[i];
        }
        for (auto e: edges) {
            tmp[e.first] -= r[e.second];
            tmp[e.second] -= r[e.first];
        }
        r = tmp;
    }
    auto u = berlekamp_massey(buf);
//    cout << to_string(u) << endl;
    auto acdet = u.freq(0) * Mint(-1);
    if (!acdet) return 0;
    if (u.size() != N+1) return det(diag, edges);
    Mint cdet = 1;
    for (int i = 0; i < N; i++) {
        cdet *= c[i];
    }
    if (N % 2) acdet *= Mint(-1);
    return acdet / cdet;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    V<Mint> diag(n-1);
    V<P> edges;
    auto add_edge = [&](int s, int t) {
        if (s < n-1) diag[s] += 1;
        if (t < n-1) diag[t] += 1;
        if (s == n-1 || t == n-1) return;
        edges.push_back(P(s, t));
    };
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            add_edge(i, j);
        }
    }
    for (int i = k; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x); x--;
            add_edge(x, i);
        }
    }
    cout << to_string(det(diag, edges)) << endl;;
    return 0;
}
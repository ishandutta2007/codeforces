//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL




#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <complex>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;



#include <unistd.h>

struct Scanner {
    int fd = -1;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += ::read(fd, line + ed, (1 << 15) - ed);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) {
            bool sep = false;
            for (size_t i = st; i < ed; i++) {
                if (isspace(line[i])) {
                    sep = true;
                    break;
                }
            }
            if (!sep) reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] & 0xf);
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    int read_unsafe() { return 0; }
    template <class H, class... T> int read_unsafe(H& h, T&... t) {
        bool f = read_single(h);
        if (!f) return 0;
        return 1 + read_unsafe(t...);
    }
    Scanner(FILE* fp) : fd(fileno(fp)) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char(0x30 | (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(__int128 val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char(0x30 | (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }

    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
using D = double;
const D PI = acos(D(-1));
using Pc = complex<D>;

void fft(bool type, V<Pc>& a) {
    int n = int(a.size()), s = 0;
    while ((1 << s) < n) s++;
    assert(1 << s == n);

    static V<Pc> ep[30];
    if (!ep[s].size()) {
        for (int i = 0; i < n; i++) {
            ep[s].push_back(polar<D>(1, i * 2 * PI / n));
        }
    }
    V<Pc> b(n);
    for (int i = 1; i <= s; i++) {
        int w = 1 << (s - i);
        for (int y = 0; y < n / 2; y += w) {
            Pc now = ep[s][y];
            if (type) now = conj(now);
            for (int x = 0; x < w; x++) {
                auto l = a[y << 1 | x];
                auto u = now, v = a[y << 1 | x | w];
                auto r = Pc(u.real() * v.real() - u.imag() * v.imag(),
                            u.real() * v.imag() + u.imag() * v.real());
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
        }
        swap(a, b);
    }
}

V<Pc> multiply(const V<Pc>& a, const V<Pc>& b) {
    int A = int(a.size()), B = int(b.size());
    if (!A || !B) return {};
    int lg = 0;
    while ((1 << lg) < A + B - 1) lg++;
    int N = 1 << lg;
    V<Pc> ac(N), bc(N);
    for (int i = 0; i < A; i++) ac[i] = a[i];
    for (int i = 0; i < B; i++) bc[i] = b[i];
    fft(false, ac);
    fft(false, bc);
    for (int i = 0; i < N; i++) {
        ac[i] *= bc[i];
    }
    fft(true, ac);
    V<Pc> c(A + B - 1);
    for (int i = 0; i < A + B - 1; i++) {
        c[i] = ac[i] / D(N);
    }
    return c;
}

V<D> multiply(const V<D>& a, const V<D>& b) {
    int A = int(a.size()), B = int(b.size());
    if (!A || !B) return {};
    int lg = 0;
    while ((1 << lg) < A + B - 1) lg++;
    int N = 1 << lg;
    V<Pc> d(N);
    for (int i = 0; i < N; i++) d[i] = Pc(i < A ? a[i] : 0, i < B ? b[i] : 0);
    fft(false, d);
    for (int i = 0; i < N / 2 + 1; i++) {
        auto j = i ? (N - i) : 0;
        Pc x = Pc(d[i].real() + d[j].real(), d[i].imag() - d[j].imag());
        Pc y = Pc(d[i].imag() + d[j].imag(), -d[i].real() + d[j].real());
        d[i] = x * y / D(4);
        if (i != j) d[j] = conj(d[i]);
    }
    fft(true, d);
    V<D> c(A + B - 1);
    for (int i = 0; i < A + B - 1; i++) {
        c[i] = d[i].real() / N;
    }
    return c;
}

template <class Mint, int K = 3, int SHIFT = 11>
V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {
    int A = int(a.size()), B = int(b.size());
    if (!A || !B) return {};
    int lg = 0;
    while ((1 << lg) < A + B - 1) lg++;
    int N = 1 << lg;

    VV<Pc> x(K, V<Pc>(N)), y(K, V<Pc>(N));
    for (int ph = 0; ph < K; ph++) {
        V<Pc> z(N);
        for (int i = 0; i < N; i++) {
            D nx = 0, ny = 0;
            if (i < A) nx = (a[i].v >> (ph * SHIFT)) & ((1 << SHIFT) - 1);
            if (i < B) ny = (b[i].v >> (ph * SHIFT)) & ((1 << SHIFT) - 1);
            z[i] = Pc(nx, ny);
        }
        fft(false, z);
        for (int i = 0; i < N; i++) {
            z[i] *= 0.5;
        }
        for (int i = 0; i < N; i++) {
            int j = (i) ? N - i : 0;
            x[ph][i] = Pc(z[i].real() + z[j].real(), z[i].imag() - z[j].imag());
            y[ph][i] =
                Pc(z[i].imag() + z[j].imag(), -z[i].real() + z[j].real());
        }
    }
    VV<Pc> z(K, V<Pc>(N));
    for (int xp = 0; xp < K; xp++) {
        for (int yp = 0; yp < K; yp++) {
            int zp = (xp + yp) % K;
            for (int i = 0; i < N; i++) {
                if (xp + yp < K) {
                    z[zp][i] += x[xp][i] * y[yp][i];
                } else {
                    z[zp][i] += x[xp][i] * y[yp][i] * Pc(0, 1);
                }
            }
        }
    }
    for (int ph = 0; ph < K; ph++) {
        fft(true, z[ph]);
    }
    V<Mint> c(A + B - 1);
    Mint base = 1;
    for (int ph = 0; ph < 2 * K - 1; ph++) {
        for (int i = 0; i < A + B - 1; i++) {
            if (ph < K) {
                c[i] += Mint(ll(round(z[ph][i].real() / N))) * base;
            } else {
                c[i] += Mint(ll(round(z[ph - K][i].imag() / N))) * base;
            }
        }
        base *= 1 << SHIFT;
    }
    return c;
}

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
    int n, m, q;
    sc.read(n, m, q);

    V<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        sc.read(a[i]);
    }
    for (int i = 0; i < m; i++) {
        sc.read(b[i]);
    }

    V<D> v0(1<<17), v1(1<<17);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            v0[a[i]]++;
            v0[a[i + 1]]--;
        } else {
            v0[a[i]]--;
            v0[a[i + 1]]++;
        }
    }
    for (int i = 0; i < m - 1; i++) {
        if (b[i] < b[i + 1]) {
            v1[b[i]]--;
            v1[b[i + 1]]++;
        } else {
            v1[b[i]]++;
            v1[b[i + 1]]--;
        }
    }

    auto v = multiply(v0, v1);

    V<ll> imos(1 << 18);
    for (int i = 0; i < int(v.size()); i++) {
        imos[i] = ll(round(v[i]));
    }
                                                ;
    imos[0] += 2;
    imos[a.front() + b.front()]--;
    imos[a.front() + b.back()]--;
    imos[a.back() + b.front()]--;
    imos[a.back() + b.back()]--;
                                                ;
    for (int i = 1; i < (1 << 18); i++) {
        imos[i] += imos[i - 1];
    }


    for (int ph = 0; ph < q; ph++) {
        int x;
        sc.read(x);
        pr.writeln(imos[x - 1] / 2);
    }
    return 0;
}
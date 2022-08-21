//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
       
       
#include <algorithm>
       
#include <array>
       
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
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}
template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}
       
struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
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
        if (ed - st <= 50) reread();
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
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
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
    Scanner(FILE* _fp) : fp(_fp) {}
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
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
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
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        reverse(small, small + len);
        memcpy(line + pos, small, len);
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
       
template <class T> struct Fenwick {
    int n;
    V<T> seg;
    Fenwick(int _n = 0) : n(_n), seg(n) {}
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= n) {
            seg[i - 1] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += seg[i - 1];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) { return sum(b) - sum(a); }
    /// sum[0, idx) >= xidx(sum[0, n) < x  n+1)
    int sum_lower_bound(T x) {
        if (x <= 0) return 0;
        int res = 0, len = 1;
        while (2 * len <= n) len *= 2;
        for (; len >= 1; len /= 2) {
            if (res + len <= n && seg[res + len - 1] < x) {
                res += len;
                x -= seg[res - 1];
            }
        }
        return res + 1;
    }
};
Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);
int main() {
    int n;
    sc.read(n);
    V<int> a(n), ra(n);
    for (int i = 0; i < n; i++) {
        sc.read(a[i]);
        a[i]--;
        ra[a[i]] = i;
    }
    Fenwick<ll> f0(n), f1(n), fen(n);
    for (int i = 0; i < n; i++) {
        f0.add(i, i);
        f1.add(i, n - 1 - i);
    }
    ll off = 0;
    for (int tm = 0; tm < n; tm++) {
        int p = ra[tm];
        off += fen.sum(p, n);
        fen.add(p, 1);
        f0.add(p, -p);
        f1.add(p, -(n - 1 - p));
        int mid = fen.sum_lower_bound(tm / 2 + 1);
        ll ans = off;
        ans += f0.sum(mid);
        ans += f1.sum(mid, n);
        ll lc = mid - fen.sum(mid);
        ans -= lc * (lc - 1) / 2;
        ll rc = (n - mid) - fen.sum(mid, n);
        ans -= rc * (rc - 1) / 2;
        pr.write(ans);
        pr.write(' ');
    }
    pr.writeln();
    return 0;
}
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL




#include <algorithm>

#include <array>

#include <cassert>

#include <complex>

#include <cstdio>

#include <bitset>

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




template <class D, class I> struct StaticRangeSum {
    struct P {
        I x, y;
        D val;
    };

    StaticRangeSum(V<P> ps) {
        if (!ps.size()) return;
        sort(ps.begin(), ps.end(), [&](P l, P r) { return l.x < r.x; });
        for (auto p : ps) {
            xs.push_back(p.x);
            ys.push_back(p.y);
        }
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int n = int(xs.size());
        int m = int(ys.size());

        lg = 1;
        while ((1 << lg) < m) lg++;

        mid = V<int>(lg);
        bits = VV<int>(lg, V<int>(n + 1));
        sums = VV<D>(lg + 1, V<D>(n + 1));

        struct Q {
            int y;
            D val;
        };
        V<Q> v;
        for (auto p : ps) {
            int y = int(lower_bound(ys.begin(), ys.end(), p.y) - ys.begin());
            v.push_back({y, p.val});
        }
        for (int i = 0; i < n; i++) {
            Q q = v[i];
            sums[lg][i + 1] = sums[lg][i] + q.val;
        }
        for (int lv = lg - 1; lv >= 0; lv--) {
            array<V<Q>, 2> nx;
            for (int i = 0; i < n; i++) {
                Q q = v[i];
                bool f = (q.y >> lv) & 1;
                bits[lv][i + 1] = bits[lv][i] + (f ? 0 : 1);
                nx[f].push_back(q);
            }
            mid[lv] = int(nx[0].size());
            v.clear();
            v.insert(v.end(), nx[0].begin(), nx[0].end());
            v.insert(v.end(), nx[1].begin(), nx[1].end());
            for (int i = 0; i < n; i++) {
                Q q = v[i];
                sums[lv][i + 1] = sums[lv][i] + q.val;
            }
        }
    }
    // (lx <= x < ux), (ly <= y < uy)
    D sum(I lx, I ly, I ux, I uy) {
        int _lx = int(lower_bound(xs.begin(), xs.end(), lx) - xs.begin());
        int _ux = int(lower_bound(xs.begin(), xs.end(), ux) - xs.begin());
        int _ly = int(lower_bound(ys.begin(), ys.end(), ly) - ys.begin());
        int _uy = int(lower_bound(ys.begin(), ys.end(), uy) - ys.begin());
        if (_lx >= _ux || _ly >= _uy) return D(0);
        return sum(_lx, _ux, _uy) - sum(_lx, _ux, _ly);
    }

  private:
    int lg;
    V<I> xs, ys;

    V<int> mid;
    VV<int> bits;
    VV<D> sums;
    D sum(int l, int r, int u) {
        if (u == (1 << lg)) return sums[lg][r] - sums[lg][l];
        D ans = 0;
        for (int lv = lg - 1; lv >= 0; lv--) {
            bool f = (u >> lv) & 1;
            int l0 = bits[lv][l], r0 = bits[lv][r];
            if (f) {
                ans += sums[lv][r0] - sums[lv][l0];
                l = l - l0 + mid[lv];
                r = r - r0 + mid[lv];
            } else {
                l = l0;
                r = r0;
            }
        }
        return ans;
    }
};

#include <random>

#include <chrono>
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

using P = StaticRangeSum<ull, int>::P;

V<ull> solve(V<P> ps) {
    int n = int(ps.size());
    StaticRangeSum<ull, int> fw(ps);
    V<ull> res(n);
    for (int i = 0; i < n; i++) {
        auto p = ps[i];
        res[i] = fw.sum(0, p.x, p.y + 1, TEN(9));
    }
    return res;
}

int main() {
    int n;
    sc.read(n);
    V<P> fi(n), se(n);
    for (int i = 0; i < n; i++) {
        sc.read(fi[i].x, fi[i].y, se[i].x, se[i].y);
    }
    for (int tm = 0; tm < 3; tm++) {
        for (int i = 0; i < n; i++) {
            ull x = rng();
            fi[i].val = se[i].val = x;
        }
        auto v1 = solve(fi);
        auto v2 = solve(se);
        if (v1 != v2) {
            pr.writeln("NO");
            return 0;
        }
    }
    pr.writeln("YES");
    return 0;
}
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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

const int INF = TEN(9);

struct Node {
    using NP = Node*;
    NP l = nullptr, r = nullptr;
    int sz = 0;

    int cnt = 1, mi, ma, lw, up, ls = 0, rs = 0;
    Node(const V<int>& fi, int off, int _sz) : sz(_sz) {
        if (sz == 1) {
            mi = ma = fi[off];
            lw = up = fi[off];
            return;
        }
        l = new Node(fi, off, sz / 2);
        r = new Node(fi, off + sz / 2, sz - sz / 2);
        update();
    }
    void set(int k, int a) {
        if (sz == 1) {
            mi = ma = a;
            lw = up = a;
            return;
        }
        if (k < sz / 2) l->set(k, a);
        else r->set(k - sz / 2, a);
        update();
    }

    using Q = pair<pair<int, int>, int>;
    Q query(int x) { // (hit range, strict low)
        // hit!
        if (lw <= x && x <= up) {
            return {{lw, up}, rs};
        }
        if (sz == 1) {
            if (x < ma) {
                return {{INF, -INF}, 0};
            } else {
                return {{INF, -INF}, 1};
            }
        }
        if (x < lw) {
            return r->query(x);
        } else {
            Q res = l->query(x);
            int uc = l->cnt - res.second;
            res.second = cnt - uc;
            return res;
        }
    }

    void update() {
        mi = min(l->mi, r->mi);
        ma = max(l->ma, r->ma);
        auto que = r->query(l->mi);
        lw = min(l->mi, que.first.first);
        rs = que.second;

        que = l->query(max(l->mi, r->ma));
        up = max(r->ma, que.first.second);

        ls = l->cnt - que.second;
        if (que.first.first != INF) ls--;

        assert(lw <= up);
        cnt = 1 + ls + rs;

    }

};

int main() {
    int n, q;
    sc.read(n, q);
    V<int> a(n);
    for (int i = 0; i < n; i++) sc.read(a[i]);

    auto tr = new Node(a, 0, n);
    for (int ph = 0; ph < q; ph++) {
        int p, x;
        sc.read(p, x); p--;
        tr->set(p, x);
        pr.writeln(tr->cnt);
    }
    return 0;
}
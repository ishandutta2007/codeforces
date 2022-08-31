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
        assert(0 <= i && i <= n);
        T s = 0;
        while (i > 0) {
            s += seg[i - 1];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        return sum(b) - sum(a);
    }
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


ll ans = 0;

struct Node {
    using NP = Node*;
    NP l = nullptr, r = nullptr;
    int sz, midx;
    V<int> used;
    Node(const V<int>& v, const V<int>& w, int li, int ri) : sz(ri - li) {
        used = {v.begin() + li, v.begin() + ri};
        if (sz == 1) return;
        int mi = TEN(9);
        midx = -1;
        for (int i = li; i < ri - 1; i++) {
            if (w[i] < mi) {
                mi = w[i];
                midx = i;
            }
        }
        midx++;
        l = new Node(v, w, li, midx);
        r = new Node(v, w, midx, ri);
    }

    void add(int p, int x) {
        if (sz == 1) return;
        used.push_back(x);
        if (p < midx) l->add(p, x);
        else r->add(p, x);
    }
    int geti(int p) {
        int idx = int(lower_bound(used.begin(), used.end(), p) - used.begin());
        assert(used[idx] == p);
        return idx;
    }

    int k;
    Fenwick<int> fw0, fw1;
    ll c0 = 0, c1 = 0, all = 0;
    void init(const V<int>& v, int li, int ri) {
        if (sz == 1) return;

        all = ll(midx - li) * (ri - midx);
        sort(used.begin(), used.end());
        used.erase(unique(used.begin(), used.end()), used.end());
        k = int(used.size());
        fw0 = Fenwick<int>(k);
        fw1 = Fenwick<int>(k);
        for (int i = li; i < midx; i++) {
            fw0.add(geti(v[i]), 1);
        }
        for (int i = midx; i < ri; i++) {
            int id = geti(v[i]);
                      ;
            c0 += fw0.sum(0, id);
            fw1.add(id, 1);
        }
        c1 = all - c0;
        ans += min(c0, c1);
        l->init(v, li, midx);
        r->init(v, midx, ri);
    }

    void cng(int p, int a, int b) {
        if (sz == 1) return;
        ans -= min(c0, c1);

        int ida = geti(a), idb = geti(b);
        if (p < midx) {
            l->cng(p, a, b);
            fw0.add(ida, -1);
            fw0.add(idb, +1);
            c0 -= fw1.sum(ida + 1, k);
            c0 += fw1.sum(idb + 1, k);
        } else {
            r->cng(p, a, b);
            fw1.add(ida, -1);
            fw1.add(idb, +1);
            c0 -= fw0.sum(0, ida);
            c0 += fw0.sum(0, idb);
        }
        c1 = all - c0;
        ans += min(c0, c1);
    }
};

int main() {
    int n;
    sc.read(n);
    V<int> v(n);
    for (int i = 0; i < n; i++) {
        sc.read(v[i]);
        v[i]--;
    }
    V<int> w(n - 1);
    for (int i = 0; i < n - 1; i++) {
        sc.read(w[i]);
    }

    auto tr = new Node(v, w, 0, n);

    int q;
    sc.read(q);

    V<int> xv(q), yv(q);
    for (int i = 0; i < q; i++) {
        sc.read(xv[i], yv[i]);
        xv[i]--;
        yv[i]--;
    }

    {
        auto v2 = v;
        for (int i = 0; i < q; i++) {
            int l = xv[i], r = yv[i];
            swap(v2[l], v2[r]);
            tr->add(l, v2[l]);
            tr->add(r, v2[r]);
        }
    }

    tr->init(v, 0, n);

            ;
    for (int i = 0; i < q; i++) {
        int l = xv[i], r = yv[i];
        tr->cng(l, v[l], v[r]);
        tr->cng(r, v[r], v[l]);
        swap(v[l], v[r]);
        pr.writeln(ans);
    }
    return 0;
}
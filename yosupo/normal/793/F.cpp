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




template <class D, class Op> struct SimpleSeg {
    D e;
    Op op;
    int n, sz, lg; // size(extended to 2^i), lg
    V<D> d;

    SimpleSeg(const V<D>& v, D _e, Op _op) : e(_e), op(_op) {
        n = int(v.size());
        lg = 1;
        while ((1 << lg) < n) lg++;
        sz = 1 << lg;
        d = V<D>(2 * sz, e);
        for (int i = 0; i < n; i++) d[sz + i] = v[i];
        for (int i = sz - 1; i >= 0; i--) {
            update(i);
        }
    }

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

    void set(int p, D x) {
        assert(0 <= p && p < n);
        p += sz;
        d[p] = x;
        for (int i = 1; i <= lg; i++) update(p >> i);
    }

    D single(int p) const {
        assert(0 <= p && p < n);
        return d[p + sz];
    }

    D sum(int a, int b) const {
        assert(a <= b);
        D sml = e, smr = e;
        a += sz;
        b += sz;

        while (a < b) {
            if (a & 1) sml = op(sml, d[a++]);
            if (b & 1) smr = op(d[--b], smr);
            a >>= 1;
            b >>= 1;
        }
        return op(sml, smr);
    }

    D all_sum() const {
        return d[1];
    }

    // min i s.t. f(d[a] + d[a+1] + ... d[i]) == true (or return n + 1)
    template <class Comp> int search_left(int a, Comp f) {
        a += sz;
        D sm = e;
        if (f(e)) return a;
        while (true) {
            if (f(op(sm, d[a]))) {
                while (a < sz) {
                    a *= 2;
                    if (!f(op(sm, d[a]))) {
                        sm = op(sm, d[a]);
                        a++;
                    }
                }
                a = a + 1 - sz;
                return a;
            }
            if (a & 1) {
                sm = op(sm, d[a]);
                a++;
                if ((a & -a) == a) break;
            }
            a >>= 1;
        }
        return n + 1;
    }
};

template <class D, class Op>
SimpleSeg<D, Op> get_simple_seg(V<D> v, D e, Op op) {
    return SimpleSeg<D, Op>(v, e, op);
}

template <class D, class L, class OpDD, class OpDL, class OpLL> struct SegTree {
    D e_d;
    L e_l;
    OpDD op_dd;
    OpDL op_dl;
    OpLL op_ll;
    int sz, lg; //(2^lg), lg
    V<D> d;
    V<L> lz;

    SegTree(const V<D>& v,
            D _e_d,
            L _e_l,
            OpDD _op_dd,
            OpDL _op_dl,
            OpLL _op_ll)
        : e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {
        int n = int(v.size());
        lg = 1;
        while ((1 << lg) < n) lg++;
        sz = 1 << lg;
        d = V<D>(2 * sz, e_d);
        lz = V<L>(2 * sz, e_l);
        for (int i = 0; i < n; i++) d[sz + i] = v[i];
        for (int i = sz - 1; i >= 0; i--) {
            update(i);
        }
    }

    void all_add(int k, L x) {
        d[k] = op_dl(d[k], x);
        lz[k] = op_ll(lz[k], x);
    }
    void push(int k) {
        all_add(2 * k, lz[k]);
        all_add(2 * k + 1, lz[k]);
        lz[k] = e_l;
    }
    void update(int k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }

    void set(int p, D x) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= lg; i++) update(p >> i);
    }

    void add(int a, int b, L x, int l, int r, int k) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            all_add(k, x);
            return;
        }
        push(k);
        int mid = (l + r) / 2;
        add(a, b, x, l, mid, 2 * k);
        add(a, b, x, mid, r, 2 * k + 1);
        update(k);
    }
    void add(int a, int b, L x) { add(a, b, x, 0, sz, 1); }

    D single(int p) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        return d[p];
    }

    D sum(int a, int b, int l, int r, int k) {
        if (b <= l || r <= a) return e_d;
        if (a <= l && r <= b) return d[k];
        push(k);
        int mid = (l + r) / 2;
        return op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid, r, 2 * k + 1));
    }
    D sum(int a, int b) { return sum(a, b, 0, sz, 1); }

    D all_sum() const { return d[1]; }
};

template <class D, class L, class OpDD, class OpDL, class OpLL>
SegTree<D, L, OpDD, OpDL, OpLL> get_seg(V<D> v,
                                        D e_d,
                                        L e_l,
                                        OpDD op_dd,
                                        OpDL op_dl,
                                        OpLL op_ll) {
    return SegTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);
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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

V<int> ls;
VV<int> rs;
struct Q {
    int s, t, p;
};
V<Q> ques;

void solve(int l, int r, const V<int>& idxs) {
    if (l == r) return;

    // calc [l, md], [md + 1, r]
    int md = (l + r) / 2;
    int ldi = md - l + 1, di = r - l + 1;
    {
        auto seg = get_simple_seg(V<int>(ldi, -1), -1,
                                [&](int a, int b) { return max(a, b); });
        V<int> dp(ldi, -1);
        for (int i = md; i >= l; i--) {
            int j = i;
            for (int x : rs[i]) {
                if (x <= md) j = max(j, x);
            }
            dp[i - l] = max(i, seg.sum(i - l, j - l + 1));
            seg.set(i - l, dp[i - l]);
        }
        for (auto i: idxs) {
            auto& q = ques[i];
            if (q.s <= md && md + 1 <= q.t) {
                // check!
                q.p = max(q.p, dp[q.s - l]);
            }
        }
    }

    VV<int> rqv(di);
    for (auto i : idxs) {
        const auto& q = ques[i];
        rqv[q.t - l].push_back(i);
    }
    auto seg = get_simple_seg(V<int>(di, -1), -1,
                              [&](int a, int b) { return max(a, b); });
    for (int x = l; x <= r; x++) {
        if (l <= ls[x]) {
            seg.set(ls[x] - l, x);
        }
        for (int i: rqv[x - l]) {
            auto& q = ques[i];
            q.p = max(q.p, seg.sum(q.s - l, q.p - l + 1));
            q.p = max(q.p, seg.sum(q.s - l, q.p - l + 1));
        }
    }

    // remove unused
    for (int i = l; i <= md; i++) {
        while (rs[i].size() && md < rs[i].back()) rs[i].pop_back();
    }
    V<int> lidxs, ridxs;
    for (auto i: idxs) {
        auto& q = ques[i];
        if (q.p <= md) {
            lidxs.push_back(i);
            q.t = min(q.t, md);
        } else {
            ridxs.push_back(i);
            q.s = max(q.s, md + 1);
        }
    }
    solve(l, md, lidxs);
    solve(md + 1, r, ridxs);
}

int main() {
    int n, m;
    sc.read(n, m);
    ls = V<int>(n + 1);
    iota(ls.begin(), ls.end(), 0);
    rs = VV<int>(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        sc.read(l, r);
        ls[r] = l;
        rs[l].push_back(r);
    }
    for (int i = 0; i <= n; i++) {
        sort(rs[i].begin(), rs[i].end());
    }
    int q;
    sc.read(q);
    ques = V<Q>(q);
    V<int> idxs;
    for (int i = 0; i < q; i++) {
        int s, t;
        sc.read(s, t);
        ques[i] = Q{s, t, s};
        idxs.push_back(i);
    }
    solve(0, n, idxs);

    for (int i = 0; i < q; i++) {
        pr.writeln(ques[i].p);
    }
    return 0;
}
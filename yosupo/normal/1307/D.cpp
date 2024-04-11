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
template <class D> struct MinDist {
    V<D> dist;
    V<int> from;
};

template <class D, class E>
MinDist<D> mindist(const VV<E>& g, int s, D inf = numeric_limits<D>::max()) {
    int n = (int)g.size();
    V<D> dist = V<D>(n, inf);
    V<int> from = V<int>(n);
    struct P {
        D key;
        int to;
        bool operator<(P r) const { return key > r.key; }
    };
    priority_queue<P> q;
    q.push(P{0, s});
    dist[s] = D(0);
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        if (dist[p.to] < p.key) continue;
        for (E e : g[p.to]) {
            if (p.key + e.dist < dist[e.to]) {
                dist[e.to] = p.key + e.dist;
                from[e.to] = p.to;
                q.push(P{dist[e.to], e.to});
            }
        }
    }
    return MinDist<D>{dist, from};
}




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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

struct E {
    int to, dist;
};
int main() {
    int n, m, k;
    sc.read(n, m, k);
    V<int> a(k);
    for (int i = 0; i < k; i++) {
        sc.read(a[i]); a[i]--;
    }
    VV<E> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        sc.read(u, v); u--; v--;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }
    auto ds = mindist<int>(g, 0).dist;
    auto dt = mindist<int>(g, n - 1).dist;

    auto rmqs = get_simple_seg(V<int>(2 * n, -TEN(9)), -int(TEN(9)), [&](int a, int b) {
        return max(a, b);
    });
    auto rmqt = get_simple_seg(V<int>(2 * n, -TEN(9)), -int(TEN(9)), [&](int a, int b) {
        return max(a, b);
    });

    int ans = -TEN(9);
    for (int p: a) {
        int di = ds[p] - dt[p] + n;
        ans = max(ans, ds[p] + 1 + rmqt.sum(di, 2 * n));
        ans = max(ans, dt[p] + 1 + rmqs.sum(0, di));

        rmqs.set(di, max(rmqs.single(di), ds[p]));
        rmqt.set(di, max(rmqt.single(di), dt[p]));
    }

    ans = min(ans, ds[n - 1]);

    pr.writeln(ans);
    return 0;
}
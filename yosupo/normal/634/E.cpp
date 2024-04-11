# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.cpp"



# 1 "/Users/yosupo/Programs/Algorithm/expander/dummy_include/bits/stdc++.h" 1
       

#include <bits/stdc++.h>
# 5 "main.cpp" 2
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
# 38 "main.cpp"
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

# 1 "/Users/yosupo/Programs/Algorithm/src/util/fast_io.h" 1
       
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
            succ();
            size_t sz = 1;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (st != ed) break;
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
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    void write_single(const T& val) {
        for (char c : val) write_single(c);
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
            val = -val;
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
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
# 50 "main.cpp" 2

template <class N, class E> struct AllTree {
    int n;
    const VV<E>& g;
    V<N> sm;
    VV<N> dp;
    void dfs1(int p, int b) {
        sm[p] = N();
        for (auto e : g[p]) {
            int d = e.to;
            if (d == b) continue;
            dfs1(d, p);
            sm[p] = sm[p] + sm[d].to_subs(p, e);
        }
        sm[p] = sm[p].join(p);
    }
    void dfs2(int p, int b, N top) {
        int deg = int(g[p].size());
        dp[p] = V<N>(deg + 1);
        dp[p][0] = N();
        for (int i = 0; i < deg; i++) {
            int d = g[p][i].to;
            dp[p][i + 1] =
                dp[p][i] + (d == b ? top : sm[d]).to_subs(p, g[p][i]);
        }
        N rnode = N();
        dp[p].back() = dp[p].back().join(p);
        for (int i = deg - 1; i >= 0; i--) {
            dp[p][i] = (dp[p][i] + rnode).join(p);
            int d = g[p][i].to;
            if (d != b) dfs2(d, p, dp[p][i]);
            rnode = rnode + (d == b ? top : sm[d]).to_subs(p, g[p][i]);
        }
    }
    AllTree(const VV<E>& _g) : n(int(_g.size())), g(_g), sm(n), dp(n) {
        dfs1(0, -1);
        dfs2(0, -1, N());
    }
};

template <class N, class E> VV<N> get_all_tree(const VV<E>& g) {
    return AllTree<N, E>(g).dp;
}

V<bool> col;
struct Node {
    bool hasw = false;
    int sz = 0;
    int ins = 0;

    int up = 0, down = 0;

    array<int, 4> dp = {0, 0, 0, 0};
    template <class E> Node to_subs(int, const E&) const {

        return {hasw, sz, ins, -1, -1, {hasw ? 0 : sz, up, down, max(up, down)}};
    }
    Node operator+(const Node& r) const {

        array<int, 4> ndp = {0, 0, 0, 0};
        for (int f = 0; f < 4; f++) {
            for (int g = 0; g < 4; g++) {
                if (f & g) continue;
                ndp[f | g] = max(ndp[f | g], dp[f] + r.dp[g]);
            }
        }
        return {hasw || r.hasw, sz + r.sz, max(ins, r.ins), -1, -1, ndp};
    }
    Node join(int v) const {

        if (col[v]) {

            return {hasw, 1 + sz, max(ins, 1 + dp[3]), 1 + dp[1], 1 + dp[2], {-1, -1, -1, -1}};
        } else {

            return {true, 1 + sz, ins, 0, 0, {-1, -1, -1, -1}};
        }
        return {};
    }
};

int main() {
    Scanner sc(stdin);
    Printer pr(stdout);

    int n, k;
    sc.read(n, k);
    V<int> a(n);
    sc.read(a);
    struct E { int to; };
    VV<E> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        sc.read(u, v); u--; v--;
        g[u].push_back({v});
        g[v].push_back({u});
    }
    int lw = 1, up = 1'000'100;
    while (up - lw > 1) {
        int md = (lw + up) / 2;
        col = V<bool>(n);
        for (int i = 0; i < n; i++) {
            col[i] = (md <= a[i]);
        }
        auto tr = get_all_tree<Node>(g);
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (k <= tr[i].back().ins) {
                ok = true;
                break;
            }
        }
        if (ok) {
            lw = md;
        } else {
            up = md;
        }
    }
    pr.writeln(lw);
    return 0;
}
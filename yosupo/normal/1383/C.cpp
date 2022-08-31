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
struct UnionFind {
    int n;
    V<int> p, r;
    int gn;
    UnionFind(int _n = 0) : n(_n), p(n, -1), r(n, 1), gn(n) {}
    void merge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        int x = group(a), y = group(b);
        if (x == y) return; // same
        gn--;
        if (r[x] < r[y]) swap(x, y);
        p[y] = x;
        r[x] += r[y];
    }
    int group(int a) {
        assert(0 <= a && a < n);
        if (p[a] == -1) return a;
        return p[a] = group(p[a]);
    }
    bool same(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        return group(a) == group(b);
    }
};
struct SCC {
    V<int> id;
    VV<int> groups;
};

template <class E> struct SCCExec : SCC {
    int n;
    const VV<E>& g;
    int tm = 0;
    V<bool> flag;
    V<int> low, ord, st;
    void dfs(int v) {
        low[v] = ord[v] = tm++;
        st.push_back(v);
        flag[v] = true;
        for (auto e : g[v]) {
            if (ord[e.to] == -1) {
                dfs(e.to);
                low[v] = min(low[v], low[e.to]);
            } else if (flag[e.to]) {
                low[v] = min(low[v], ord[e.to]);
            }
        }
        if (low[v] == ord[v]) {
            V<int> gr;
            while (true) {
                int u = st.back();
                st.pop_back();
                gr.push_back(u);
                if (u == v) break;
            }
            for (int x : gr) flag[x] = false;
            groups.push_back(gr);
        }
    }
    SCCExec(const VV<E>& _g)
        : n(int(_g.size())), g(_g), flag(n), low(n), ord(n, -1) {
        id = V<int>(n);
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) dfs(i);
        }
        reverse(groups.begin(), groups.end());
        for (int i = 0; i < int(groups.size()); i++) {
            for (int x : groups[i]) {
                id[x] = i;
            }
        }
    }
};

template <class E> SCC get_scc(const VV<E>& g) { return SCCExec<E>(g); }

template <size_t N> struct BitsetSCCExec : SCC {
    using B = bitset<N>;
    int n;
    const V<B>& g;
    const V<B>& rg;
    V<int> vs;
    B unvis;
    void dfs(int v) {
        unvis.reset(v);
        while (true) {
            int d = (unvis & g[v])._Find_first();
            if (d >= n) break;
            dfs(d);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k) {
        unvis.reset(v);
        id[v] = k;
        groups[k].push_back(v);
        while (true) {
            int d = (unvis & rg[v])._Find_first();
            if (d >= n) break;
            rdfs(d, k);
        }
    }

    BitsetSCCExec(const V<B>& _g, const V<B>& _rg)
        : n(int(_g.size())), g(_g), rg(_rg) {
        unvis.set();
        for (int i = 0; i < n; i++) {
            if (unvis[i]) dfs(i);
        }
        reverse(vs.begin(), vs.end());
        unvis.set();
        id = V<int>(n);
        int k = 0;
        for (int i : vs) {
            if (unvis[i]) {
                groups.push_back({});
                rdfs(i, k++);
            }
        }
    }
};

template <size_t N>
SCC get_bitset_scc(const V<bitset<N>>& g, const V<bitset<N>>& rg) {
    return BitsetSCCExec<N>(g, rg);
}

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);


int solve_single(V<int> g) {
    int n = int(g.size());
//    dbg(n, g);
    V<int> dp(1 << n);
    for (int f = 0; f < (1 << n); f++) {
        for (int i = 0; i < n; i++) {
            if (~f & g[i]) continue;
            // f >= g[i]
            dp[f] = max(dp[f], 1 + dp[f ^ (1 << i)]);
        }
    }
    int ans = 0;
    for (int f = 0; f < (1 << n); f++) {
        ans = max(ans, dp[f]);
    }
    assert(ans);
    return 2 * (n - 1) - (ans - 1);
}

void solve() {
    int n;
    sc.read(n);

    string s, t;
    sc.read(s, t);

    auto uf = UnionFind(20);
    VV<int> g(20, V<int>(20));
    for (int i = 0; i < 20; i++) {
        g[i][i] = true;
    }
    for (int i = 0; i < n; i++) {
        int a = s[i] - 'a', b = t[i] - 'a';
        g[a][b] = true;
        uf.merge(a, b);
    }

    VV<int> groups(20);
    for (int i = 0; i < 20; i++) {
        groups[uf.group(i)].push_back(i);
    }

    int ans = 0;
    for (auto v: groups) {
        if (v.empty()) continue;
        int k = int(v.size());
        V<int> g2(k, 0);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (g[v[i]][v[j]]) g2[i] |= 1 << j;
            }
        }
        ans += solve_single(g2);
    }

    pr.writeln(ans);
}

int main() {
    int t;
    sc.read(t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
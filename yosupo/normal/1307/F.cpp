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
        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            p[y] = x;
            if (r[x] == r[y]) r[x]++;
        }
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


struct LCA {
    int lg;
    VV<int> anc;
    V<int> dps;
    /// lrLCA
    int query(int l, int r) {
        if (dps[l] < dps[r]) swap(l, r);
        int dd = dps[l] - dps[r];
        for (int i = lg - 1; i >= 0; i--) {
            if (dd < (1 << i)) continue;
            dd -= 1 << i;
            l = anc[i][l];
        }
        if (l == r) return l;
        for (int i = lg - 1; i >= 0; i--) {
            if (anc[i][l] == anc[i][r]) continue;
            tie(l, r) = tie(anc[i][l], anc[i][r]);
        }
        return anc[0][l];
    }
    int up(int p, int dist) {
        for (int i = lg - 1; i >= 0; i--) {
            if (dist >= (1 << i)) {
                dist -= 1 << i;
                p = anc[i][p];
            }
        }
        return p;
    }
    int dist(int l, int r) {
        int z = query(l, r);
        return dps[l] + dps[r] - 2 * dps[z];
    }
};

template <class E> struct LCAExec : LCA {
    const VV<E>& g;

    ///  rrootid
    LCAExec(const VV<E>& _g, int r) : g(_g) {
        int N = int(g.size());
        lg = 1;
        while ((1 << lg) < N) lg++;
        anc = VV<int>(lg, V<int>(N, -1));
        dps = V<int>(N);
        dfs(r, -1, 0);
        for (int i = 1; i < lg; i++) {
            for (int j = 0; j < N; j++) {
                anc[i][j] =
                    (anc[i - 1][j] == -1) ? -1 : anc[i - 1][anc[i - 1][j]];
            }
        }
    }

    void dfs(int p, int b, int now) {
        anc[0][p] = b;
        dps[p] = now;
        for (E e : g[p]) {
            if (e.to == b) continue;
            dfs(e.to, p, now + 1);
        }
    }
};

template <class E> LCA get_lca(const VV<E>& g, int r) {
    return LCAExec<E>(g, r);
}
Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

struct E {
    int to;
};

int main() {
    int n, k, r;
    sc.read(n, k, r);
    VV<E> g(2 * n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        sc.read(x, y); x--; y--;
        g[x].push_back({n + i});
        g[n + i].push_back({x});
        g[y].push_back({n + i});
        g[n + i].push_back({y});
    }
    n = 2 * n - 1;
    k *= 2;

    queue<int> que;
    V<int> on(n, -1);
    V<int> dist(n, TEN(9));
    for (int i = 0; i < r; i++) {
        int p;
        sc.read(p); p--;
        que.push(p);
        on[p] = i;
        dist[p] = 0;
    }
    UnionFind uf(r);
    while (!que.empty()) {
        int p = que.front(); que.pop();
                          ;
        if (dist[p] == k / 2) break;
        for (auto e: g[p]) {
            int d = e.to;
            if (on[d] != -1) {
                uf.merge(on[p], on[d]);
                continue;
            }
            on[d] = on[p];
            dist[d] = dist[p] + 1;
            que.push(d);
        }
    }
           ;
             ;
    int q;
    sc.read(q);

    auto lca = get_lca(g, 0);
    for (int i = 0; i < q; i++) {
        int u, v;
        sc.read(u, v); u--; v--;
        int z = lca.query(u, v);
        int di = lca.dist(u, v);
        auto mv = [&](int p, int q) {
            int di0 = lca.dps[p] - lca.dps[z];
            int di1 = lca.dps[q] - lca.dps[z];
            if (k / 2 <= di0) {
                return lca.up(p, k / 2);
            }
                                                                                    ;
            return lca.up(q, di1 - (k / 2 - di0));
        };
        if (di <= k) {
            pr.writeln("YES");
            continue;
        }

        int u2 = mv(u, v), v2 = mv(v, u);
                                         ;
        if (on[u2] != -1 && on[v2] != -1 && uf.same(on[u2], on[v2])) {
            pr.writeln("YES");
            continue;
        }

        pr.writeln("NO");
    }
    return 0;
}
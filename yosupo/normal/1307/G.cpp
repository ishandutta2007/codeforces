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
/*
struct E {
    int to, rev, cap, dist;
};
VV<E> g;
auto add_edge = [&](int from, int to, int cap, int dist) {
    g[from].push_back(E{to, int(g[to].size()), cap, dist});
    g[to].push_back(E{from, int(g[from].size())-1, 0, -dist});
};

auto res = min_cost_flow<int, int>(g, s, t, false);
res.max_flow(TEN(9));

// cap_flow : 
// flow : 
*/

template<class C, class D, class E>
struct MinCostFlow {
    static constexpr D INF = numeric_limits<D>::max();
    int n;
    VV<E> g;
    int s, t;
    C nc, cap_flow = 0;
    D nd, flow = 0;

    V<D> dual;
    V<int> pv, pe;

    MinCostFlow(VV<E> _g, int _s, int _t, bool neg)
        : n(int(_g.size())), g(_g), s(_s), t(_t) {
        assert(s != t);
        dual = V<D>(n);
        pv = pe = V<int>(n);
        if (neg) {
            V<D> dist(n, D(INF));
            dist[s] = 0;
            for (int ph = 0; ph < n; ph++) {
                bool update = false;
                for (int i = 0; i < n; i++) {
                    if (dist[i] == INF) continue;
                    for (auto e: g[i]) {
                        if (!e.cap) continue;
                        if (dist[i] + e.dist < dist[e.to]) {
                            dist[e.to] = dist[i] + e.dist;
                            update = true;
                        }
                    }
                }
                if (!update) break;
            }
            for (int v = 0; v < n; v++) {
                dual[v] += dist[v];
            }
        }
        dual_ref();
    }

    C single_flow(C c) {
        if (nd == INF) return nc;
        c = min(c, nc);
        for (int v = t; v != s; v = pv[v]) {
            E& e = g[pv[v]][pe[v]];
            e.cap -= c;
            g[v][e.rev].cap += c;
        }
        cap_flow += c;
        flow += nd * c;
        nc -= c;
        if (!nc) dual_ref();
        return c;
    }

    void max_flow(C c) {
        while (c) {
            C f = single_flow(c);
            if (!f) break;
            c -= f;
        }
    }

    void dual_ref() {
        V<D> dist(g.size(), D(INF));
        pv = pe = V<int>(n, -1);
        struct Q {
            D key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        priority_queue<Q> que;
        dist[s] = 0;
        que.push(Q{D(0), s});
        V<char> vis(n);
        while (!que.empty()) {
            int v = que.top().to; que.pop();
            if (v == t) break;
            if (vis[v]) continue;
            vis[v] = true;
            for (int i = 0; i < int(g[v].size()); i++) {
                E e = g[v][i];
                if (vis[e.to] || !e.cap) continue;
                D cost = dist[v] + e.dist + dual[v] - dual[e.to];
                if (dist[e.to] > cost) {
                    dist[e.to] = cost;
                    pv[e.to] = v; pe[e.to] = i;
                    que.push(Q{dist[e.to], e.to});
                }
            }
        }
        if (dist[t] == INF) {
            nd = INF; nc = 0;
            return;
        }
        for (int v = 0; v < n; v++) {
            if (!vis[v]) continue;
            dual[v] += dist[v] - dist[t];
        }
        nd = dual[t] - dual[s];
        nc = numeric_limits<C>::max();
        for (int v = t; v != s; v = pv[v]) {
            nc = min(nc, g[pv[v]][pe[v]].cap);
        }
    }
};

template<class C, class D, class E>
MinCostFlow<C, D, E> get_mcf(const VV<E>& g, int s, int t, bool neg = false) {
    return MinCostFlow<C, D, E>(g, s, t, neg);
}

Scanner sc = Scanner(stdin);

int main() {
    int n, m;
    sc.read(n, m);
    struct E {
        int to, rev, cap; ll dist;
    };
    VV<E> g(n);
    auto add_edge = [&](int from, int to, int cap, ll dist) {
        g[from].push_back(E{to, int(g[to].size()), cap, dist});
        g[to].push_back(E{from, int(g[from].size())-1, 0, -dist});
    };
    for (int i = 0; i < m; i++) {
        int u, v; ll di;
        sc.read(u, v, di); u--; v--;
        add_edge(u, v, 1, di);
    }
    auto res = get_mcf<int, ll>(g, 0, n - 1, false);

    using F = tuple<ll, int, ll, ll>; // (cap * dist - flow, cap, flow, dist)
    V<F> evs;
    while (true) {
        ll nd = res.nd;
        res.single_flow(res.nc);
        ll nc = res.cap_flow;
        ll nf = res.flow;
                                     ;
        evs.push_back({nc * nd - nf, nc, nf, nd});
        if (res.nc == 0) break;
    }

    int q;
    sc.read(q);
    for (int i = 0; i < q; i++) {
        ll x;
        sc.read(x);

        auto e = *prev(upper_bound(evs.begin(), evs.end(), F{x + 1, -1, -1, -1}));
        ll dummy, flow, dist;
        int cap;
        tie(dummy, cap, flow, dist) = e;
                                   ;
        double ans = (double)(x + flow) / cap;
        printf("%.10lf\n", ans);
    }
    return 0;
}
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
struct UnionFind {
    V<int> p, r;
    int gn;
    UnionFind(int n = 0) : p(n, -1), r(n, 1), gn(n) {}
    void merge(int a, int b) {
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
        if (p[a] == -1) return a;
        return p[a] = group(p[a]);
    }
    bool same(int a, int b) { return group(a) == group(b); }
};

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

/*
elements: matroid elements
on: used elements
f: lambda, f(on, g1(i, j), g2(i, j))
g(i, -1)g(i, j)
*/
template <class E, class F>
bool matroid_intersection(const V<E>& elements, V<bool>& on, F& f) {
    int m = int(elements.size());
    assert(int(on.size()) == m);
    VV<int> g(m);
    V<bool> st(m), ed(m);
    f(on,
      [&](int u, int v) {
          assert(0 <= u && u < m && !on[u]);
          if (v == -1)
              st[u] = true;
          else {
              assert(0 <= v && v < m && on[v]);
              g[v].push_back(u);
          }
      },
      [&](int u, int v) {
          assert(0 <= u && u < m && !on[u]);
          if (v == -1)
              ed[u] = true;
          else {
              assert(0 <= v && v < m && on[v]);
              g[u].push_back(v);
          }
      });
    V<int> prev(m, -1);
    V<int> dist(m, TEN(9));
    queue<int> que;
    for (int i = 0; i < m; i++) {
        if (st[i]) {
            dist[i] = 0;
            que.push(i);
        }
    }

    while (que.size()) {
        int p = que.front();
        que.pop();
        if (ed[p]) {
            int now = p;
            while (now != -1) {
                on[now] = !on[now];
                now = prev[now];
            }
            return true;
        }
        for (int d : g[p]) {
            if (dist[d] > dist[p] + 1) {
                dist[d] = dist[p] + 1;
                prev[d] = p;
                que.push(d);
            }
        }
    }
    return false;
}
template <class E, class F>
V<bool> matroid_intersection(const V<E>& elements, F f) {
    int m = int(elements.size());
    V<bool> on(m);
    while (matroid_intersection(elements, on, f)) {
    }
    return on;
}

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

const int d4[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

void solve() {
    int h, w;
    sc.read(h, w);
    auto bc = [&](int r, int c) {
        return (0 <= r && r < h && 0 <= c && c < w);
    };
    auto id = [&](int r, int c) { return r * w + c; };
    V<string> mp(h);
    for (int i = 0; i < h; i++) {
        sc.read(mp[i]);
    }

    int n = h * w;

    struct E {
        int from, to, id;
    };

    V<E> es;
    int black = 0;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if ((r + c) % 2) continue;
            if (r == 0 && c == 0) continue;
            if (mp[r][c] == 'X') continue;
            black++;
            V<int> ws;
            for (int d = 0; d < 4; d++) {
                int nr = r + d4[d][0];
                int nc = c + d4[d][1];
                if (!bc(nr, nc)) continue;
                if (mp[nr][nc] != 'O') continue;
                ws.push_back(id(nr, nc));
            }
            if (ws.size() == 1) {
                pr.writeln("NO");
                return;
            }
            int k = int(ws.size());
            for (int i = 0; i < k; i++) {
                for (int j = i + 1; j < k; j++) {
                    es.push_back({ws[i], ws[j], id(r, c)});
                }
            }
        }
    }
    int m = int(es.size());

    auto used =
        matroid_intersection(es, [&](const V<bool>& on, auto g1, auto g2) {
            auto base = UnionFind(n);
            V<int> cnt(n);
            for (int l = 0; l < m; l++) {
                if (!on[l]) continue;
                base.merge(es[l].from, es[l].to);
                cnt[es[l].id]++;
            }
            for (int r = 0; r < m; r++) {
                if (on[r]) continue;
                if (!base.same(es[r].from, es[r].to)) g1(r, -1);
                if (cnt[es[r].id] == 0) g2(r, -1);
            }
            for (int l = 0; l < m; l++) {
                if (!on[l]) continue;
                auto uf = UnionFind(n);
                for (int i = 0; i < m; i++) {
                    if (!on[i] || i == l) continue;
                    uf.merge(es[i].from, es[i].to);
                }
                for (int r = 0; r < m; r++) {
                    if (on[r]) continue;
                    if (!uf.same(es[r].from, es[r].to)) g1(r, l);
                    if (es[l].id == es[r].id) g2(r, l);
                }
            }
        });

    int uc = 0;
    for (auto x : used)
        if (x) uc++;
                  ;
    if (uc != black) {
        pr.writeln("NO");
        return;
    }
    V<string> ans(2 * h - 1, string(2 * w - 1, ' '));
    int ec = 0, wc = 0;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            ans[2 * r][2 * c] = mp[r][c];
            if (mp[r][c] == 'O') wc++;
        }
    }

    auto uf = UnionFind(n);
    auto adde = [&](int from, int to) {
        uf.merge(from, to);
        ec++;
        int fr = from / w, fc = from % w;
        int tr = to / w, tc = to % w;
        ans[fr + tr][fc + tc] = 'O';
    };
    for (int i = 0; i < m; i++) {
        if (!used[i]) continue;
        E e = es[i];
        adde(e.from, e.id);
        adde(e.to, e.id);
    }
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (mp[r][c] != 'O') continue;
            for (int d = 0; d < 4; d++) {
                int nr = r + d4[d][0];
                int nc = c + d4[d][1];
                if (!bc(nr, nc)) continue;
                if (mp[nr][nc] != 'O') continue;
                if (uf.same(id(r, c), id(nr, nc))) continue;
                adde(id(r, c), id(nr, nc));
            }
        }
    }

    if (ec != wc - 1) {
        pr.writeln("NO");
        return;
    }
    pr.writeln("YES");
    for (auto s : ans) {
        pr.writeln(s);
    }
}

int main() {
    int t;
    sc.read(t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
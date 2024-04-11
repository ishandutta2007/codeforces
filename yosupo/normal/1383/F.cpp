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

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

} // namespace internal

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);

        std::vector<int> level, iter;

        auto bfs = [&]() {
            internal::simple_queue<int> que;
            level = std::vector<int>(_n, -1);
            level[s] = 0;
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == t) return up;
            Cap res = 0;
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (e.cap == 0 || level[v] >= level[e.to]) continue;
                Cap d = self(self, e.to, std::min(up, e.cap));
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                res += d;
                up -= d;
                if (up == 0) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            iter = std::vector<int>(_n, 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, s, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);
const int MAX_W = 25;

int main() {
    int n, m, k, q;
    sc.read(n, m, k, q);

    mf_graph<int> g(n + 2 * k);

    for (int i = 0; i < k; i++) {
        int a, b, c;
        sc.read(a, b, c); a--; b--;
        g.add_edge(a, n + 2 * i, MAX_W);
        g.add_edge(n + 2 * i + 1, b, MAX_W);
    }

    for (int i = k; i < m; i++) {
        int a, b, c;
        sc.read(a, b, c); a--; b--;
        g.add_edge(a, b, c);
    }

    int basic = g.flow(0, n - 1);
    V<int> mincut(1 << k, basic);
    V<int> edge_id(k, -1);
    int extra_flow = 0;
    for (int f = 1; f < (1 << k); f++) {
        // i-th edge must not be cut

/*        auto g2 = g;
        for (int i = 0; i < k; i++) {
            if (f & (1 << i)) {
                g2.add_edge(n + 2 * i, n + 2 * i + 1, MAX_W);
            }
        }
        mincut[((1 << k) - 1) ^ f] += g2.flow(0, n - 1);*/

        for (int i = 0; i < k; i++) {
            if (f & (1 << i)) {
                // add edge
                edge_id[i] = g.add_edge(n + 2 * i, n + 2 * i + 1, MAX_W);
                extra_flow += g.flow(0, n - 1);
                break;
            } else {
                // remove edge
                auto e = g.get_edge(edge_id[i]);
                // reverse e.flow
                g.change_edge(edge_id[i], 0, 0);
                extra_flow -= e.flow;

                int rem = e.flow;
                rem -= g.flow(n + 2 * i, n + 2 * i + 1, rem);
                int deb;
                deb = g.flow(n + 2 * i, 0, rem);
                assert(deb == rem);
                deb = g.flow(n - 1, n + 2 * i + 1, rem);
                assert(deb == rem);
            }
        }
        mincut[((1 << k) - 1) ^ f] = basic + extra_flow;
    }

    // TL OK
    for (int ph = 0; ph < q; ph++) {
        V<int> cost(k);
        for (int i = 0; i < k; i++) {
            sc.read(cost[i]);
        }
        int ans = mincut[0];
        int extra_cut = 0;
        for (int f = 1; f < (1 << k); f++) {
/*            int cut = mincut[f];
            for (int i = 0; i < k; i++) {
                if (f & (1 << i)) {
                    cut += cost[i];
                }
            }*/
            for (int i = 0; i < k; i++) {
                if (f & (1 << i)) {
                    extra_cut += cost[i];
                    break;
                } else {
                    extra_cut -= cost[i];
                }
            }
            ans = min(ans, mincut[f] + extra_cut);
        }
        pr.writeln(ans);
    }

    return 0;
}
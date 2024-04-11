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
template <uint MD> struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
// using Mint = ModInt<998244353>;
// template<> const Mint Mint::G = Mint(3);
using Mint = ModInt<998244353>;
const int MN = 2020;
using B = bitset<MN>;
Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);
bool ok(const V<B>& g, int st) {
    int n = int(g.size());
    B unvis = B();
    for (int i = 0; i < n; i++) unvis.set(i);
    unvis.reset(st);
    auto dfs = [&](auto self, int p) -> void {
        while (true) {
            int u = int((g[p] & unvis)._Find_first());
            if (u >= n) break;
            unvis.reset(u);
            self(self, u);
        }
    };
    dfs(dfs, st);
    return unvis.none();
}
int ok(const V<B>& _g, V<int> ids) {
    int m = int(ids.size());
    if (m == 1) return 0;
    V<B> g(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = _g[ids[i]][ids[j]];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            g[i].flip(j);
            g[j].flip(i);
        }
        if (ok(g, i)) ans++;
        for (int j = 0; j < m; j++) {
            g[i].flip(j);
            g[j].flip(i);
        }
    }
    return ans;
}
pair<int, Mint> solve() {
    struct E { int to; };
    int n;
    sc.read(n);
    V<B> g(n), rg(n);
    for (int i = 0; i < n; i++) {
        string s;
        sc.read(s);
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                g[i].set(j);
                rg[j].set(i);
            }
        }
    }
    auto scc = get_bitset_scc(g, rg);
    int gn = int(scc.groups.size());
    if (gn == 1) {
        return {0, Mint(1)};
    }
    int ans = 0;
    ans += ok(g, scc.groups[0]);
    ans += ok(rg, scc.groups[gn - 1]);
    for (int i = 1; i < gn - 1; i++) {
        ans += int(scc.groups[i].size());
    }
    if (ans) {
        return {1, Mint(ans)};
    }
    assert(gn == 2);
    int ls = int(scc.groups[0].size());
    int rs = int(scc.groups[gn - 1].size());
    if (ls == 3 && rs == 3) return {2, 18};
    return {-1, 0};
}
int main() {
    auto ans = solve();
    pr.write(ans.first);
    if (ans.first == -1) {
        pr.writeln();
        return 0;
    }
    pr.write(' ');
    pr.writeln(ans.second.v);
    return 0;
}
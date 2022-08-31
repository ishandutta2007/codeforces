//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
       
       
#include <algorithm>
       
#include <array>
       
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
struct QuickFind {
    V<int> id;
    VV<int> groups;
    int gc; // group count
    QuickFind(int n = 0) {
        id = V<int>(n);
        groups = VV<int>(n);
        for (int i = 0; i < n; i++) {
            id[i] = i;
            groups[i] = {i};
        }
        gc = n;
    }
    void merge(int a, int b) {
        if (same(a, b)) return;
        gc--;
        int x = id[a], y = id[b];
        if (groups[x].size() < groups[y].size()) swap(x, y);
        for (int j : groups[y]) {
            id[j] = x;
            groups[x].push_back(j);
        }
        groups[y].clear();
    }
    bool same(int a, int b) { return id[a] == id[b]; }
};
Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);
int main() {
    int n, m;
    sc.read(n, m);
    auto uf = QuickFind(n);
    V<ll> deg(n);
    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        sc.read(a, b, c); a--; b--;
        uf.merge(a, b);
        deg[a] += c;
        deg[b] -= c;
    }
    struct E {
        int from, to;
        ll cost;
    };
    V<E> ans;
    for (auto vv: uf.groups) {
        using P = pair<int, ll>;
        V<P> pos;
        for (int v: vv) {
            if (deg[v] > 0) {
                pos.push_back({v, deg[v]});
            }
        }
        for (int v: vv) {
            ll x = -deg[v];
            while (x > 0) {
                P p = pos.back();
                ll u = min(x, p.second);
                ans.push_back({p.first, v, u});
                pos.back().second -= u;
                x -= u;
                if (pos.back().second == 0) pos.pop_back();
            }
        }
    }
    pr.writeln(ans.size());
    for (auto e: ans) {
        pr.writeln(e.from + 1, e.to + 1, e.cost);
    }
    return 0;
}
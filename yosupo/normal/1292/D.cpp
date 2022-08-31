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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

const int MK = 5020; //020;//5020;
V<int> prs;
void init() {
    V<bool> is_pr(MK + 1, true);
    is_pr[0] = is_pr[1] = false;
    for (int i = 2; i <= MK; i++) {
        if (!is_pr[i]) continue;
        prs.push_back(i);
        for (int j = 2 * i; j <= MK; j += i) {
            is_pr[j] = false;
        }
    }
}

int main() {
    init();
    int m = int(prs.size());
          ;
    VV<int> v(MK + 1, V<int>(m));
    for (int i = 1; i <= MK; i++) {
        v[i] = v[i - 1];
        int x = i;
        for (int j = 0; j < m; j++) {
            while (x % prs[j] == 0) {
                v[i][j]++;
                x /= prs[j];
            }
        }
        // dbg(v[i]);
    }
    for (auto& x: v) {
        reverse(x.begin(), x.end());
    }
    struct E {
        int to; ll dist;
    };
    VV<E> g(MK + 1);
    auto add_e = [&](int a, int b, ll c) {
        g[a].push_back(E{b, c});
        g[b].push_back(E{a, c});
        // dbg(a, b, c);
    };
    add_e(0, 1, 0);
    auto dfs = [&](auto self, int l, int r, int mid, int h) -> void {
        if (r - l == 1) {
            int sm = 0;
            for (int i = h; i < m; i++) {
                sm += v[l][i];
            }
            add_e(mid, l, sm);
            return;
        }
        int bk = 0;
        while (l < r) {
            int i = l;
            while (i < r && v[l][h] == v[i][h]) i++;
            int uid = int(g.size());
            g.push_back({});
            add_e(mid, uid, v[l][h] - bk);
            self(self, l, i, uid, h + 1);
            mid = uid;
            bk = v[l][h];
            l = i;
        }
    };
    dfs(dfs, 1, MK, MK, 0);
    int n = int(g.size());
                 ;

    V<ll> sz(n), cnt(n);
    int tm;
    sc.read(tm);
    for (int i = 0; i < tm; i++) {
        int x;
        sc.read(x);
        cnt[x]++;
        sz[x]++;
    }
    V<ll> cma(n, -1);
    auto cent = [&](auto self, int p, int b) -> void {
        for (E e : g[p]) {
            int d = e.to;
            if (d == b) continue;
            self(self, d, p);
            sz[p] += sz[d];
            cma[p] = max(cma[p], sz[d]);
        }
    };

    cent(cent, 0, -1);
    using P = pair<int, int>;
    P mi = P(TEN(9), -1);
    for (int i = 0; i < n; i++) {
        if (sz[0] - sz[i] <= sz[i] && cma[i] <= sz[0] - cma[i]) {
            mi = min(mi, {sz[i], i});
        }
    }
           ;

    auto last = [&](auto self, int p, int b, ll di) -> ll {
        if (cnt[p]) {
                                 ;
        }
        ll sm = di * cnt[p];
        for (E e: g[p]) {
            int d = e.to;
            if (d == b) continue;
            sm += self(self, d, p, di + e.dist);
        }
        return sm;
    };

    pr.writeln(last(last, mi.second, -1, 0));
    return 0;
}
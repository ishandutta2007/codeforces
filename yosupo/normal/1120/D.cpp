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

int main() {
    int n;
    sc.read(n);
    V<ll> c(n);
    V<bool> opt(n);
    for (int i = 0; i < n; i++) {
        sc.read(c[i]);
        if (!c[i]) opt[i] = true;
    }
    VV<int> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        sc.read(a, b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    using P = pair<ll, ll>;
    V<bool> leaf(n);
    V<P> dp(n), dps(n, P(0, TEN(18)));
    auto dfs = [&](auto self, int p, int b) -> void {
        leaf[p] = true;
        for (auto d: g[p]) {
            if (d == b) continue;
            leaf[p] = false;
            self(self, d, p);
            dps[p].second = min(
                dps[p].second + dp[d].first,
                dps[p].first + dp[d].second
            );
            dps[p].first += dp[d].first;
        }
        if (leaf[p]) {
            dps[p] = P(TEN(18), 0);
        }
        dp[p].first = min(dps[p].first, dps[p].second + c[p]);
        dp[p].second = dps[p].second;
        return;
    };
    dfs(dfs, 0, -1);
           ;
    V<array<bool, 2>> vis(n);
    auto mark = [&](auto self, int p, int b, int f) -> void {
                                      ;
        if (vis[p][f]) return;
        vis[p][f] = true;
        if (leaf[p]) {
            if (f == 0) opt[p] = true;
            return;
        }
        ll mdif = -1;
        int uniq = -1;
        for (auto d : g[p]) {
            if (d == b) continue;
            ll dif = dp[d].first - dp[d].second;
            if (mdif == dif) uniq = -1;
            if (mdif < dif) {
                mdif = dif;
                uniq = d;
            }
        }
        if (f == 0) {
            bool all_zero = (dp[p].first == dps[p].first);
            bool one_one = (dp[p].first == (dps[p].second + c[p]));
            if (one_one) opt[p] = true;
            for (auto d : g[p]) {
                if (d == b) continue;
                if (all_zero) self(self, d, p, 0);
                if (one_one) {
                    if (uniq != d) self(self, d, p, 0);
                    if (dp[d].first - dp[d].second == mdif) self(self, d, p, 1);
                }
            }
        } else {
                           ;
            for (auto d : g[p]) {
                if (d == b) continue;
                if (uniq != d) {
                    self(self, d, p, 0);
                }
                if (dp[d].first - dp[d].second == mdif) {
                    self(self, d, p, 1);
                }
            }
        }
    };
    mark(mark, 0, -1, 0);
    V<int> ans;
    for (int i = 0; i < n; i++) {
        if (opt[i]) ans.push_back(i);
    }
    pr.writeln(dp[0].first, ans.size());
    for (int d: ans) {
        pr.write(d + 1);
        pr.write(' ');
    }
    pr.writeln();
    return 0;
}
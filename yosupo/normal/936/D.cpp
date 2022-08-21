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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
    int n, m0, m1, t;
    sc.read(n, m0, m1, t);

    V<int> preds = {0, n + 1};
    V<int> x0(m0), x1(m1);
    for (int i = 0; i < m0; i++) {
        sc.read(x0[i]);
        preds.push_back(x0[i] - 1);
        preds.push_back(x0[i]);
        preds.push_back(x0[i] + 1);
    }
    for (int i = 0; i < m1; i++) {
        sc.read(x1[i]);
        preds.push_back(x1[i] - 1);
        preds.push_back(x1[i]);
        preds.push_back(x1[i] + 1);
    }
    sort(preds.begin(), preds.end());
    preds.erase(unique(preds.begin(), preds.end()), preds.end());

    int n2 = int(preds.size());
    V<int> obs(n2);
    for (int x: x0) {
        int idx = int(lower_bound(preds.begin(), preds.end(), x) - preds.begin());
        obs[idx] |= 1;
    }
    for (int x: x1) {
        int idx = int(lower_bound(preds.begin(), preds.end(), x) - preds.begin());
        obs[idx] |= 2;
    }

    V<array<int, 4>> nxt(n2, {-1, -1, -1, -1});
    V<array<int, 4>> dp(n2);
    auto solve = [&](auto self, int pos, int ty, int mv) -> int {
        if (pos == n2 - 1) return n + 10;
        int key = ty * 2 + mv;
        if (nxt[pos][key] != -1) return dp[pos][key];
        nxt[pos][key] = 0;
        int ans = -1;
        int nty = 1 - ty;
        // move
        if (mv && !(obs[pos] & (1 << nty))) {
            int nx = self(self, pos, 1 - ty, 0);
            if (preds[pos] - t <= nx && ans <= nx) {
                ans = nx;
                nxt[pos][key] = 0;
            }
        }
        if (!(obs[pos + 1] & (1 << ty))) {
            int nx = self(self, pos + 1, ty, 1);
            if (ans <= nx) {
                ans = nx;
                nxt[pos][key] = 1;
            }
        } else {
            int nx = min(preds[pos + 1] - 1, self(self, pos + 1, ty, 1)) - t;
            if (ans <= nx) {
                ans = nx;
                nxt[pos][key] = 2;
            }
        }
        ans = min(ans, preds[pos]);
        assert(nxt[pos][key] != -1);
        return dp[pos][key] = ans;
    };
            ;
    for (int i = n2 - 1; i >= 0; i--) {
        solve(solve, i, 0, 0);
        solve(solve, i, 1, 0);
        solve(solve, i, 0, 1);
        solve(solve, i, 1, 1);
    }
//    dbg(solve(solve, 3, 0, 0));
//    dbg(solve(solve, 3, 1, 1));


//    dbg(solve(solve, 0, 0, 1));

    if (solve(solve, 0, 0, 1) < 0) {
        pr.writeln("No");
        return 0;
    }
    pr.writeln("Yes");
    int pos = 0;
    int ty = 0;
    int mv = 1;

           ;
    V<int> lines;
    using P = pair<int, int>;
    V<P> shoots;
    int ok = t;
    while (pos < n2 - 1) {
        int key = ty * 2 + mv;
        int nx = nxt[pos][key];
        //assert(nx != -1);
        if (nx == 0) {
                                        ;
            lines.push_back(preds[pos]);
            ok = max(ok, preds[pos]);
            ty = 1 - ty;
            mv = 0;
        } else if (nx == 1) {
                                    ;
            pos++;
            mv = 1;
        } else {
                                    ;
            assert(ok <= preds[pos]);
            shoots.push_back({ok, ty});
            ok = ok + t;
            pos++;
            mv = 1;
        }
    }

    pr.writeln(lines.size());
    for (int l: lines) {
        pr.write(l);
        pr.write(' ');
    }
    pr.writeln();
    pr.writeln(shoots.size());
    for (auto p: shoots) {
        pr.writeln(p.first, p.second + 1);
    }
    return 0;
}
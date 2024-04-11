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

const int MC = 500500;
int main() {
    int flower, len, num, sp;
    sc.read(flower, len, num, sp);
    V<int> cols(flower);
    for (int i = 0; i < flower; i++) {
        sc.read(cols[i]);
    }
    V<int> trg(MC);
    for (int i = 0; i < sp; i++) {
        int a;
        sc.read(a);
        trg[a]++;
    }
    int conds = 0;
    for (int i = 0; i < MC; i++) {
        if (trg[i]) conds++;
    }

    V<V<int>> uses(MC);
    V<int> us(MC);
    multiset<int> ok;

    for (int i = flower - 1; i >= 0; i--) {
        int c = cols[i];
        if (trg[c]) {
            uses[c].push_back(i);
            int uc = int(uses[c].size()) - us[c];
            if (uc == trg[c] + 1) {
                ok.erase(ok.find(uses[c][us[c]]));
                us[c]++;
                uc--;
            }
            if (uc == trg[c]) {
                ok.insert(uses[c][us[c]]);
            }
        }
        if (int(ok.size()) == conds) {
            int j = *ok.rbegin() + 1;
            j = max(j, i + len);
            if (j > flower) continue;
            int lc = i / len;
            lc = min(lc, num - 1);
            int rc = (flower - j) / len;
            rc = min(rc, num - 1 - lc);
            if (lc + rc + 1 >= num) {
                V<int> res;
                for (int k = lc * len; k < i; k++) {
                    res.push_back(k);
                }
                set<int> st;
                for (int k = 0; k < MC; k++) {
                    for (int s = us[k]; s < int(uses[k].size()); s++) {
                        st.insert(uses[k][s]);
                    }
                }
                for (int k = i; k < j; k++) {
                    if (int(st.size()) < len) {
                        st.insert(k);
                    }
                }
                for (int k = i; k < j; k++) {
                    if (!st.count(k)) res.push_back(k);
                }
                for (int k = j + rc * len; k < flower; k++) {
                    res.push_back(k);
                }
                pr.writeln(res.size());
                for (int d: res) {
                    pr.write(d + 1);
                    pr.write(' ');
                }
                pr.writeln();
                return 0;
            }
        }
    }
    pr.writeln(-1);
    return 0;
}
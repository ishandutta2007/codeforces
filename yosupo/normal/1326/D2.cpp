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
template <class S> V<int> manacher(const S& s) {
    int n = int(s.size());
    V<int> r(n);
    if (n == 0) return r;
    r[0] = 1;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = r[i];
        k = (j + r[j] <= i) ? 0 : min(j + r[j] - i, r[2 * j - i]);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        if (j + r[j] < i + r[i]) j = i;
    }
    return r;
}


template <class S> V<int> manacher_even(const S& s) {
    int n = int(s.size());
    V<int> r(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        int& k = r[i];
        k = (j + r[j] <= i) ? 0 : min(j + r[j] - i, r[2 * j - i]);
        while (0 <= i - 1 - k && i + k < n && s[i - 1 - k] == s[i + k]) k++;
        if (j + r[j] < i + r[i]) j = i;
    }
    return r;
}



// s[0..r[i]] == s[i..i+r[i]]
template <class S> V<int> z_algo(const S& s) {
    int n = int(s.size());
    V<int> r(n + 1);
    r[0] = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        int& k = r[i];
        k = (j + r[j] <= i) ? 0 : min(j + r[j] - i, r[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + r[j] < i + r[i]) j = i;
    }
    r[0] = n;
    return r;
}

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

string solveo(string s) {
    int n = int(s.size());

    auto manao = manacher(s);

    int k = -1;
    for (int i = 0; i < n; i++) {
        if (manao[i] == i + 1) {
            k = i;
        }
    }

    auto t = s.substr(0, k + 1);
    auto rt = t;
    reverse(rt.begin(), rt.end());
    t += rt.substr(1);
    return t;
}

string solvee(string s) {
    int n = int(s.size());

    auto manae = manacher_even(s);

    int k = 0;
    for (int i = 1; i < n; i++) {
        if (manae[i] == i) {
            k = i;
        }
    }

    auto t = s.substr(0, k);
    auto rt = t;
    reverse(rt.begin(), rt.end());
    t += rt;
    return t;
}

string solve3(string s) {
    auto a1 = solveo(s);
    auto a2 = solvee(s);
    if (a1.size() > a2.size()) return a1;
    return a2;
}

string solve2(string s) {
    auto a1 = solve3(s);
    reverse(s.begin(), s.end());
    auto a2 = solve3(s);
    if (a1.size() > a2.size()) return a1;
    return a2;
}

string solve() {
    string s;
    sc.read(s);
    string rs = s;
    reverse(rs.begin(), rs.end());
    if (s == rs) return s;
    int n = int(s.size());
    int l = 0, r = n - 1;
    while (l <= r && s[l] == s[r]) {
        l++; r--;
    }
    string t = s.substr(l, r - l + 1);
    auto pre = s.substr(0, l), suf = pre;
    reverse(suf.begin(), suf.end());
    return pre + solve2(t) + suf;
}

int main() {
    int t;
    sc.read(t);
    for (int ph = 0; ph < t; ph++) {
        pr.writeln(solve());
    }
    return 0;
}
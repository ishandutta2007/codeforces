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
    string s;
    string t;
    sc.read(n, s, t);
    V<int> now(n);
    for (int i = 0; i < n; i++) now[i] = s[i] - '0';
    V<ll> a(n + 1), b(n + 1);
    a[0] = s[0] - '0';
    b[0] = t[0] - '0';
    for (int i = 1; i < n; i++) {
        a[i] = s[i] - s[i - 1];
        b[i] = t[i] - t[i - 1];
    }
    a[n] = -(s[n - 1] - '0');
    b[n] = -(t[n - 1] - '0');

    V<ll> sm(n + 1);
    for (int i = 0; i <= n; i++) {
        sm[i] = b[i] - a[i];
        if (i >= 2) sm[i] += sm[i - 2];
    }
    if (sm[n - 1] != 0 && sm[n] != 0) {
        pr.writeln(-1);
        return 0;
    }
    ll ans = 0;
    for (ll x: sm) ans += abs(x);
    pr.writeln(ans);

    queue<int> que;
    for (int i = 0; i < n - 1; i++) {
        que.push(i);
    }
    for (int ph = 0; ph < min(TEN(5), ans); ph++) {
        while (true) {
            int i = que.front(); que.pop();
            if (i < 0 || n - 1 <= i) continue;
            if (sm[i] == 0) continue;
            if (sm[i] > 0 && now[i] < 9 && now[i + 1] < 9) {
                //+, +
                pr.writeln(i + 1, 1);
                now[i]++;
                now[i + 1]++;
                sm[i]--;
                for (int d = -3; d <= 3; d++) que.push(i + d);
                break;
            }
            if (sm[i] < 0 && now[i] && now[i + 1]) {
                pr.writeln(i + 1, -1);
                now[i]--;
                now[i + 1]--;
                sm[i]++;
                for (int d = -3; d <= 3; d++) que.push(i + d);
                break;
            }
        }
    }
    return 0;
}
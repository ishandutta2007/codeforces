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
Printer pr = Printer(stdout);
void solve() {
    ll r;
    cin >> r;
    string s;
    getline(cin, s);
    int n = int(s.size());
    int cnt = 0;
    auto top = [&]() -> char {
        while (cnt < n && s[cnt] == ' ') cnt++;
        return s[cnt];
    };
    auto pop = [&]() -> char {
        top();
        assert(cnt != n);
        return s[cnt++];
    };
    int ids = 0;
    auto dig = [&]() -> int {
        char c = pop();
        assert(c == '*');
        return ids++;
    };
    auto expr = [&](auto self) -> V<int> {
        if (top() == '*') {
            return {dig()};
        }
        assert(top() == '(');
        pop();
        auto v = self(self);
        char op = pop();
        assert(op == 'S' || op == 'P');
        while (true) {
            auto w = self(self);
            if (op == 'S') {
                if (v.size() > w.size()) swap(v, w);
            } else {
                v.insert(v.end(), w.begin(), w.end());
            }
            if (top() == ')') break;
            assert(top() == op);
            pop();
        }
        pop();
        return v;
    };
    auto ans = expr(expr);
    V<ll> buf(ids);
    for (int id: ans) buf[id] = r * int(ans.size());
    pr.write("REVOLTING");
    for (ll d: buf) {
        pr.write(" ");
        pr.write(d);
    }
    pr.writeln();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
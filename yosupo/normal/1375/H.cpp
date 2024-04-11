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

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

void all256() {
    ll sum = 0;
    for (ll n = 256; n >= 2; n >>= 1) {
        sum += n * (n + 1) / 2;
    }
            ;
}

void test() {
    all256();
    ll n = 1 << 12;
    ll q = 1 << 16;
    for (ll bs = 2; bs <= 100; bs++) {
        ll bn = (n + bs - 1) / bs;
        ll sum_pre = bs * (bs + 1) / 2 * bs * bn;
        ll sum_que = q * bn;
        ll sum = sum_pre + sum_que;
                                          ;
    }
}

using P = pair<int, int>;

V<int> v;

struct Comp {
    V<int> to;
    Comp() {}
    Comp(V<int> pos, int low, int up) {
//        dbg(pos, low, up);
        int n = int(pos.size());
        to = V<int>(n + 1);
        for (int i = 0; i < n; i++) {
            to[i + 1] = to[i];
            int x = v[pos[i]];
            if (low <= x && x < up) to[i + 1]++;
        }
    }
    P down(int l, int r) {
        assert(0 <= l && l <= int(to.size()));
        assert(0 <= r && r <= int(to.size()));
        return {to[l], to[r]};
    }
};

const int B = 256;
int BN;


int cnt = 0;
V<P> ans;

int query(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    ans.push_back({a, b});
    return cnt++;
}

VV<int> gen(int low, int up, V<int> pos) {
    int m = int(pos.size());
    VV<int> res(m + 1, V<int>(m + 1, -1));

    if (m == 0) return res;
    if (m == 1) {
        res[0][1] = pos[0];
        return res;
    }

    int mid = (low + up) / 2;
    Comp lcomp(pos, low, mid), ucomp(pos, mid, up);

    V<int> lpos, upos;
    for (int i = 0; i < m; i++) {
        int p = pos[i];
        if (v[p] < mid) {
            lpos.push_back(p);
        } else {
            upos.push_back(p);
        }
    }

    auto lres = gen(low, mid, lpos);
    auto ures = gen(mid, up, upos);

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j <= m; j++) {
            int ll, lr;
            tie(ll, lr) = lcomp.down(i, j);
            int ul, ur;
            tie(ul, ur) = ucomp.down(i, j);
            res[i][j] = query(lres[ll][lr], ures[ul][ur]);
        }
    }

    return res;
}

int main() {
    int n, q;
    sc.read(n, q);
    //n = 1 << 12;
    //q = 1 << 16;

    BN = (n + B - 1) / B;

    cnt = n;
    v = V<int>(n);
    VV<int> poss(BN);
    for (int i = 0; i < n; i++) {
        sc.read(v[i]);
        v[i]--;
        //v[i] = i;
        poss[v[i] / B].push_back(i);
    }

    V<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    V<Comp> comps(BN);
    V<VV<int>> bks(BN);
    for (int i = 0; i < BN; i++) {
        bks[i] = gen(i * B, min(i * B + B, n), poss[i]);
        comps[i] = Comp(idx, i * B, i * B + B);
    }

    V<int> qans(q, -1);
    for (int ph = 0; ph < q; ph++) {
        int l, r;
        sc.read(l, r);
        l--;
        //l = 0; r = n;

        for (int i = 0; i < BN; i++) {
            int ll, rr;
            tie(ll, rr) = comps[i].down(l, r);
            qans[ph] = query(qans[ph], bks[i][ll][rr]);
        }
    }

    pr.writeln(cnt);
    for (auto p: ans) {
        pr.writeln(p.first + 1, p.second + 1);
    }
    for (int x: qans) {
        pr.write(x + 1);
        pr.write(' ');
    }
    pr.writeln();
}
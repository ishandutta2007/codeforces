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

template <class N> struct LCNode {
    using NP = LCNode*;
    using D = typename N::D;
    NP p = nullptr, l = nullptr, r = nullptr;
    int sz = 1;
    bool rev = false;
    D v = N::e_d(), sm = N::e_d();

    void single_set(D x) {
        v = x;
        update();
    }
    void single_add(D x) {
        v = N::op_dd(v, x);
        update();
    }

    void init_node(D _v) {
        v = _v;
        sm = _v;
    }
    void update() {
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;
        sm = l ? N::op_dd(l->sm, v) : v;
        if (r) sm = N::op_dd(sm, r->sm);
    }
    void push() {
        if (rev) {
            if (l) l->revdata();
            if (r) r->revdata();
            rev = false;
        }
    }
    void revdata() {
        rev ^= true;
        swap(l, r);
        sm = N::rev(sm);
    }

    inline int pos() {
        if (p) {
            if (p->l == this) return -1;
            if (p->r == this) return 1;
        }
        return 0;
    }
    void rot() {
        NP q = p->p;
        int pps = p->pos();
        if (pps == -1) q->l = this;
        if (pps == 1) q->r = this;
        if (p->l == this) {
            p->l = r;
            if (r) r->p = p;
            r = p;
        } else {
            p->r = l;
            if (l) l->p = p;
            l = p;
        }
        p->p = this;
        p->update();
        update();
        p = q;
        if (q) q->update();
    }
    void all_push() {
        if (pos()) p->all_push();
        push();
    }
    void splay() {
        all_push();
        int ps;
        while ((ps = pos())) {
            int pps = p->pos();
            if (!pps) {
                rot();
            } else if (ps == pps) {
                p->rot();
                rot();
            } else {
                rot();
                rot();
            }
        }
    }
    void expose() {
        NP u = this, ur = nullptr;
        do {
            u->splay();
            u->r = ur;
            u->update();
            ur = u;
        } while ((u = u->p));
        splay();
    }
    void link(NP np) {
        evert();
        np->expose();
        p = np;
    }
    void cut() {
        expose();
        l->p = nullptr;
        l = nullptr;
        update();
    }
    void evert() {
        expose();
        revdata();
    }

    NP lca(NP n) {
        n->expose();
        expose();
        NP t = n;
        while (n->p != nullptr) {
            if (!n->pos()) t = n->p;
            n = n->p;
        }
        return (this == n) ? t : nullptr;
    }
};

struct Node {
    using D = pair<int, int>;
    static D e_d() { return {-1, -1}; }
    static D op_dd(const D& l, const D& r) {
        if (l.first == -1) return r;
        if (r.second == -1) return l;
        return {l.first, r.second};
    }
    static D rev(const D& v) {
        return {v.second, v.first};
    }
};

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
    int n;
    sc.read(n);

    VV<int> tr(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        sc.read(a, b); a--; b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    V<LCNode<Node>> lcv(n), lce(n - 1);
    for (int i = 0; i < n; i++) {
        lcv[i].init_node({-1, -1});
    }
    V<int> ea(n - 1), eb(n - 1);
    for (int i = 0; i < n - 1; i++) {
        sc.read(ea[i], eb[i]); ea[i]--; eb[i]--;
        lce[i].init_node({i, i});
        lcv[ea[i]].link(&lce[i]);
        lce[i].link(&lcv[eb[i]]);
    }

    pr.writeln(n - 1);
    auto dfs = [&](auto self, int p, int b) -> void {
        for (auto d: tr[p]) {
            if (d == b) continue;
            self(self, d, p);
        }
        if (b == -1) return;
        // add edge(p -> b)
        lcv[b].evert();
        lcv[p].expose();
        int id = lcv[p].sm.second;
        pr.writeln(p + 1, b + 1, ea[id] + 1, eb[id] + 1);
        lce[id].expose();
        lce[id].single_set({-1, -1});
        lce[id].cut();
        lce[id].link(&lcv[b]);
        return;
    };
    dfs(dfs, 0, -1);
    return 0;
}
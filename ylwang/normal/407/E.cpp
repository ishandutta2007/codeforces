#include <bits/stdc++.h>

using namespace std;

#define FILE(Name) freopen(Name"in", "r", stdin), freopen("out", "w", stdout)

namespace io {
    const int __SIZE = (1 << 21) + 1;
    char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
    #define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
    inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
    inline void gc (char &x) { x = Gc(); }
    inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
    inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
    inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
        for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
    template <class I> inline bool gi (I &x) { _eof = 0;
        for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
        for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
    template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
        while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
    struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }

typedef unsigned uit;
typedef long long ll;
typedef double db;

const int MAXN = 200100;

int n, k, d;
int a[MAXN];

int res = 1;
int res_l = 1;
int res_r = 1;

struct Segment_Tree {
#define ls (x << 1)
#define rs (x << 1 | 1)

    struct Node { ll v, t; } T[MAXN << 2];

    inline void pushup(int x) { T[x].v = min(T[ls].v, T[rs].v); }
    inline void pushdown(int x) {
        ll&t = T[x].t; if(!t) return ;
        T[ls].v += t, T[ls].t += t;
        T[rs].v += t, T[rs].t += t;
        t = 0;
    }

    inline void build(int x, int l, int r) {
        T[x].v = T[x].t = 0; if(l == r) return ;
        int mid = (l + r) >> 1; build(ls, l, mid), build(rs, mid + 1, r);
    }

    inline void Modify(int x, int l, int r, int L, int R, ll v) {
        if(L <= l && r <= R) return T[x].v += v, T[x].t += v, void();
        int mid = (l + r) >> 1; pushdown(x);
        if(L <= mid) Modify(ls, l, mid, L, R, v);
        if(mid < R) Modify(rs, mid + 1, r, L, R, v);
        pushup(x);
    }

    inline int Find(int x, int l, int r, int p) {
        if(l == r) return T[x].v <= k ? l : -1;
        int mid = (l + r) >> 1; pushdown(x);
        if(T[ls].v <= k) return Find(ls, l, mid, p);
        if(mid < p) return Find(rs, mid + 1, r, p);
        return -1;
    }

#undef ls
#undef rs
}seg;

int b[MAXN];
map<int, int>pos;
stack<int>up, down;

inline void solve(int l, int r) {
    for(int i = l; i <= r; i++) a[i - l + 1] = b[i] / d;
    int n = r - l + 1, las = 0; seg.build(1, 1, n), pos.clear();
    for(int i = 1; i <= n; i++) {
        int v = a[i];
        if(pos.count(v)) {
            seg.Modify(1, 1, n, las + 1, pos[v], 1000000000);
            las = pos[v];
        } pos[v] = i;
        seg.Modify(1, 1, n, 1, n, -1);
        seg.Modify(1, 1, n, i, i, i);
        while(up.top() && a[up.top()] > v) {
            int p = up.top(); up.pop();
            seg.Modify(1, 1, n, up.top() + 1, p, a[p]);
        } seg.Modify(1, 1, n, up.top() + 1, i, -v); up.push(i);
        while(down.top() && a[down.top()] < v) {
            int p = down.top(); down.pop();
            seg.Modify(1, 1, n, down.top() + 1, p, -a[p]);
        } seg.Modify(1, 1, n, down.top() + 1, i, v); down.push(i);
        int L = seg.Find(1, 1, n, i);
        if((~L) && res < i - L + 1) res = i - L + 1, res_l = L + l - 1, res_r = i + l - 1;
    } while(up.top()) up.pop(); while(down.top()) down.pop();
}

int main() {
    gi(n), gi(k), gi(d);
    if(d == 0) {
        int len = 1, now = -1, x = 0, pos = 0, L = 1, R = 1;
        for(int i = 1; i <= n; i++) {
            gi(x);
            if(x != now) {
                if(len < i - pos)
                    len = i - pos, L = pos, R = i - 1;
                now = x, pos = i;
            }
        } if(len < n - pos + 1) L = pos, R = n;
        print(L), pc(' '), print(R), pc('\n');
        return 0;
    } int mi = 2147483647;
    for(int i = 1; i <= n; i++) gi(b[i]), chkmin(mi, b[i]);
    for(int i = 1; i <= n; i++) b[i] -= mi - 1;
    int las = b[1] % d, pos = 1;
    up.push(0), down.push(0);
    for(int i = 2; i <= n + 1; i++)
        if(las != b[i] % d || i == n + 1)
            solve(pos, i - 1), pos = i, las = b[i] % d;
    print(res_l), pc(' '), print(res_r), pc('\n');
    return 0;
}
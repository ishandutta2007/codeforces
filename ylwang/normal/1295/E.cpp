#include <bits/stdc++.h>
using namespace std;
 
using LL = long long;
 
namespace _buff {
 
const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
    if (ib == ie) {
        ib = ibuf;
        ie = ibuf + fread(ibuf, 1, BUFF, stdin);
    }
    return ib == ie ? -1 : *ib++;
}
 
}
 
LL read() {
    using namespace _buff;
    LL ret = 0;
    bool pos = true;
    char c = getc();
    for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
        assert(~c);
    }
    if (c == '-') {
        pos = false;
        c = getc();
    }
    for (; c >= '0' && c <= '9'; c = getc()) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    }
    return pos ? ret : -ret;
}
 
const size_t N = 2e5 + 5;
const size_t V = N << 2;
 
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
 
LL val[V], tag[V];
 
void pushup(int x) {
    val[x] = min(val[lc(x)], val[rc(x)]);
}
 
void update(int x, LL v) {
    val[x] += v;
    tag[x] += v;
}
 
void pushdown(int x) {
    if (tag[x]) {
        update(lc(x), tag[x]);
        update(rc(x), tag[x]);
        tag[x] = 0;
    }
}
 
void modify(int x, int tl, int tr, int l, int r, LL v) {
    if (tl >= r || tr <= l) return;
    if (l <= tl && tr <= r) {
        return update(x, v);
    }
    pushdown(x);
    int mid = (tl + tr) >> 1;
    modify(lc(x), tl, mid, l, r, v);
    modify(rc(x), mid, tr, l, r, v);
    pushup(x);
}
 
int p[N], a[N];
 
int main() {
    int n = read();
    generate_n(p, n, read);
    generate_n(a, n, read);
    for (int i = 0; i < n; ++i) {
        modify(1, 0, n + 1, p[i], n + 1, a[i]);
    }
    LL ans = 1e18;
    for (int i = 0; i + 1 < n; ++i) {
        modify(1, 0, n + 1, p[i], n + 1, -a[i]);
        modify(1, 0, n + 1, 0, p[i], a[i]);
        ans = min(ans, val[1]);
    }
    cout << ans;
    return 0;
}
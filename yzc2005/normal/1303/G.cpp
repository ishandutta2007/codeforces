#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define go(G, u) for(int o = G.head[u], v = G.to[o]; o; o = G.nxt[o], v = G.to[o])
typedef long long ll;
typedef pair <ll, ll> PLL;
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 150005, M = N << 1;
struct Graph {
    int to[M], nxt[M], head[N], cnt;
    inline void add(int u, int v) {
        to[++cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt;
    }
} G;

#define mid (t[p].l + t[p].r >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
struct Segment {
    int l, r;
    PLL a;
}t[N << 2];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r, t[p].a = PLL(0, 0);
    if(l == r) return;
    build(ls, l, mid), build(rs, mid + 1, r);
}

inline ll calc(PLL a, int x) {
    return a.first * x + a.second;
}

void modify(int p, PLL a) {
    if(calc(a, mid) >= calc(t[p].a, mid)) swap(a, t[p].a);
    if(t[p].l == t[p].r) return;
    if(calc(t[p].a, t[p].l) >= calc(a, t[p].l) && calc(t[p].a, t[p].r) >= calc(a, t[p].r)) return;
    calc(t[p].a, t[p].l) < calc(a, t[p].l) ? modify(ls, a) : modify(rs, a);
}

ll query(int p, int x) {
    if(t[p].l == t[p].r) return calc(t[p].a, x);
    return max(calc(t[p].a, x), mid >= x ? query(ls, x) : query(rs, x));
}

int n, x, y, a[N];
int sz[N], mxs[N], rt, siz;
int tot, maxd, cnt;
bool used[N];
ll ans;

struct node {
    int d, bel;
    ll s, s1, s2;
    inline friend bool operator < (const node &n1, const node &n2) {
        return n1.bel < n2.bel;
    }
} info[N], tmp[N]; 

void get_sz(int u, int fa) {
    sz[u] = 1;
    go(G, u) {
        if(v == fa || used[v]) continue;
        get_sz(v, u);
        sz[u] += sz[v];
    }
}

void get_rt(int u, int fa) {
    mxs[u] = 0;
    go(G, u) {
        if(v == fa || used[v]) continue;
        get_rt(v, u);
        ckmax(mxs[u], sz[v]);
    }
    ckmax(mxs[u], siz - sz[u]);
    if(!rt || mxs[u] < mxs[rt]) rt = u;
}

void dfs(int u, int fa) {
    bool flg = 0;
    go(G, u) {
        if(v == fa || used[v]) continue;
        flg = 1;
        info[v].bel = info[u].bel;
        info[v].d = info[u].d + 1;
        info[v].s = info[u].s + a[v];
        info[v].s1 = info[u].s1 + 1LL * (info[v].d + 1) * a[v];
        info[v].s2 = info[u].s2 + info[v].s - a[rt];
        dfs(v, u);
    }
    if(!flg) {
        tmp[++tot] = info[u];
        ckmax(ans, info[u].s1);
        ckmax(ans, info[u].s2 + a[rt] * (info[u].d + 1));
        ckmax(maxd, info[u].d);
    }
} 

void solve(int u) {
    get_sz(u, 0), siz = sz[u];
    rt = 0, get_rt(u, 0), u = rt;
    used[u] = 1; 
    if(siz == 1) return;
    tot = 0, maxd = 0;
    go(G, u) {
        if(used[v]) continue;
        info[v].bel = v, info[v].d = 1;
        info[v].s = a[u] + a[v];
        info[v].s1 = a[u] + (a[v] << 1);
        info[v].s2 = a[v];
        dfs(v, u);
    }
    sort(tmp + 1, tmp + tot + 1);
    build(1, 1, maxd); 
    for(int i = 1, r = 1; i <= tot; i = r + 1) {
        while(r < tot && tmp[r + 1].bel == tmp[i].bel) ++r;
        fu(k, i, r) ckmax(ans, tmp[k].s2 + query(1, tmp[k].d));
        fu(k, i, r) modify(1, PLL(tmp[k].s, tmp[k].s1));
    }
    build(1, 1, maxd);
    for(int i = tot, l = tot; i; i = l - 1) {
        while(l > 1 && tmp[l - 1].bel == tmp[i].bel) --l;
        fu(k, l, i) ckmax(ans, tmp[k].s2 + query(1, tmp[k].d));
        fu(k, l, i) modify(1, PLL(tmp[k].s, tmp[k].s1));
    }
    go(G, u) if(!used[v]) solve(v); 
}

int main() {
    rd(n);
    fu(i, 1, n - 1) rd(x), rd(y), G.add(x, y), G.add(y, x);
    fu(i, 1, n) rd(a[i]);
    solve(1);
    printf("%lld\n", ans);
    return 0;   
}
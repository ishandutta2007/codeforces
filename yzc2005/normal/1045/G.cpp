#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
#define go(G, u) for(int i = G.head[u], v = G.to[i]; i; i = G.nxt[i], v = G.to[i])
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

const int N = 100005;
struct node {
    int x, r, q, lp, rp;
    inline bool operator < (const node &n1) const {
        return r > n1.r;
    }
} a[N], tp[N];
int n, k, b[N], cnt, s[N];
long long ans;

inline void add(int p, int val) {
    for(; p <= cnt; p += p & -p) s[p] += val;
}
inline int query(int p) {
    int res = 0;
    for(; p; p -= p & -p) res += s[p];
    return res;
}

void solve(int l, int r) {
    if(l == r) return;
    int mid = l + r >> 1;
    solve(l, mid), solve(mid + 1, r);
    int L = l, R = L;
    fu(i, mid + 1, r) {
        while(L <= mid && a[i].q - a[L].q > k) add(a[L++].x, -1);
        while(R <= mid && a[R].q - a[i].q <= k) add(a[R++].x, 1);
        ans += query(a[i].rp) - query(a[i].lp - 1);
    }
    fu(i, L, R - 1) add(a[i].x, -1);
    L = l, R = mid + 1;
    fu(i, l, r) {
        if(L > mid || (R <= r && a[L].q > a[R].q)) tp[i] = a[R++];
        else tp[i] = a[L++];
    }
    fu(i, l, r) a[i] = tp[i];
}

int main() {
    rd(n), rd(k);
    fu(i, 1, n) {
        rd(a[i].x), rd(a[i].r), rd(a[i].q);
        b[i] = a[i].x;
    }
    sort(b + 1, b + n + 1), sort(a + 1, a + n + 1);
    cnt = unique(b + 1, b + n + 1) - b - 1;
    fu(i, 1, n) {
        a[i].lp = lower_bound(b + 1, b + cnt + 1, max(a[i].x - a[i].r, b[1])) - b;
        a[i].rp = upper_bound(b + 1, b + cnt + 1, a[i].x + a[i].r) - b - 1;
        a[i].x = lower_bound(b + 1, b + cnt + 1, a[i].x) - b;
    }
    solve(1, n);
    cout << ans;
}
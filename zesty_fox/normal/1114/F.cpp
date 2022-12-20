#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 400010, M = 310, MOD = 1e9 + 7;

int p[M], pcnt, v[M], id[M];
void init(int lim) {
    v[1] = 1;
    for(int i = 2; i <= lim; i++) {
        if(!v[i]) v[i] = i, p[++pcnt] = i;
        for(int j = 1; j <= pcnt; j++) {
            if(p[j] > v[i] || p[j] > lim / i) break;
            v[p[j] * i] = p[j];
        }
    }
    for(int i = 1; i <= pcnt; i++) id[p[i]] = i;
}

inline ll qpow(ll x, int y = MOD - 2) {
    ll res = 1;
    while(y) {
        if(y & 1) (res *= x) %= MOD;
        (x *= x) %= MOD;
        y >>= 1;
    }
    return res;
}

using bs = bitset <64>;
inline bs fact(int x) {
    bs ret;
    for(int i = 1; p[i] <= x / p[i]; i++) {
        if(x % p[i] == 0) {
            while (x % p[i] == 0) x /= p[i];
            ret[i] = 1;
        }
    }
    if(x > 1) ret[id[x]] = 1;
    return ret;
}

namespace SegTree {
#define lson (now << 1)
#define rson (now << 1 | 1)
#define mid ((l + r) >> 1)

bs s[N << 2], tag[N << 2];
ll mul[N << 2],tagm[N << 2];
void pushup(int now) {
    s[now] = s[lson] | s[rson];
    mul[now] = mul[lson] * mul[rson] % MOD;
}

void pushdown(int now, int l, int r) {
    if(tag[now].any()) {
        s[lson] |= tag[now], s[rson] |= tag[now];
        tag[lson] |= tag[now], tag[rson] |= tag[now];

        (mul[lson] *= qpow(tagm[now], mid - l + 1)) %= MOD;
        (mul[rson] *= qpow(tagm[now], r - mid)) %= MOD;
        (tagm[lson] *= tagm[now]) %= MOD;
        (tagm[rson] *= tagm[now]) %= MOD;

        tag[now].reset(), tagm[now] = 1;
    }
}

void build(int now, int l, int r, int *a){
    if(l == r) {
        mul[now] = a[l], s[now] = fact(a[l]);
        return;
    }
    tagm[now] = 1;
    build(lson, l, mid, a), build(rson, mid + 1, r, a);
    pushup(now);
}

void modify(int now, int l, int r, int x, int y, int val, const bs &b) {
    if(x <= l && r <= y){
        tag[now] |= b, s[now] |= b;
        mul[now] = mul[now] * qpow(val, r - l + 1) % MOD, tagm[now] = tagm[now] * val %MOD;
        return;
    }
    pushdown(now, l, r);
    if(x <= mid) modify(lson, l, mid, x, y, val, b);
    if(y > mid) modify(rson, mid + 1, r, x, y, val, b);
    pushup(now);
}

pair <ll, bs> query(int now, int l, int r, int x, int y) {
    if(x <= l && r <= y) return mp(mul[now], s[now]);
    pushdown(now, l, r);
    pair <ll, bs> ret{1,bs()};
    if(x <= mid) {
        auto tmp = query(lson, l, mid, x, y);
        ret.fi = ret.fi * tmp.fi % MOD;
        ret.se = ret.se | tmp.se;
    }
    if(y > mid) {
        auto tmp = query(rson, mid + 1, r, x, y);
        ret.fi = ret.fi * tmp.fi % MOD;
        ret.se = ret.se | tmp.se;
    }
    return ret;
}
}

int n, q, a[N];
int main(){
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init(M - 10);
    n = rdi(), q = rdi();
    for(int i = 1; i <= n; i++) a[i] = rdi();
    SegTree::build(1, 1, n, a);
    while(q--) {
        char s[10];
        int l, r, x;
        scanf("%s", s);
        l = rdi(), r = rdi();
        if(s[0] == 'M') {
            x = rdi();
            SegTree::modify(1, 1, n, l, r, x, fact(x));
        } else {
            auto tmp = SegTree::query(1, 1, n, l, r);
            for(int i = 1; i <= pcnt; i++){
                if(!tmp.se[i]) continue;
                tmp.fi = tmp.fi * qpow(p[i]) % MOD * (p[i] - 1) % MOD;
            }
            printf("%lld\n", tmp.fi);
        }
    }
    return 0;
}
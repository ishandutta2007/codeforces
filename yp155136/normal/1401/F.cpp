#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (1 << 18) + 167;

struct BIT {
    ll a[N];
    int n;
    void init(int _n) {
        memset(a, 0, sizeof(a));
        n = _n + 2;
    }
    void update(int pos, int val) {
        pos += 1;
        for (int i = pos; i <= n; i += i & (-i)) {
            a[i] += val;
        }
    }
    ll query(int pos) {
        ll ret = 0;
        for (int i = pos; i > 0; i -= i & (-i)) {
            ret += a[i];
        }
        return ret;
    }
    ll queryLR(int l, int r) {
        ++l, ++r;
        return query(r) - query(l - 1);
    }
} bit;

int gao1[N], gao2[N];

ll query(int L, int R, int l, int r, int dep, int xor_val) {
    if (L > r || l > R) return 0;
    if (gao1[dep]) xor_val ^= ((1 << dep) - 1);
    if (gao2[dep]) xor_val ^= (1 << dep);
    if (l <= L && R <= r) {
        L ^= xor_val;
        R ^= xor_val;
        if (L > R) swap(L, R);
        return bit.queryLR(L, R);
    }
    int mid = (L + R) >> 1;
    return query(L, mid, l, r, dep - 1, xor_val) + query(mid + 1, R, l, r, dep - 1, xor_val);
}

int main () {
    int n, q; scanf("%d%d", &n, &q);
    bit.init((1 << n));
    for (int i = 0; i < (1 << n); ++i) {
        ll x; scanf("%lld", &x);
        bit.update(i, x);
    }
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int pos, val; scanf("%d%d", &pos, &val);
            --pos;
            for (int i = n; i >= 0; --i) {
                if (gao1[i]) {
                    pos ^= ((1 << i) - 1);
                }
                if (gao2[i]) {
                    pos ^= (1 << i);
                }
            }
            int ori = bit.queryLR(pos, pos);
            bit.update(pos, val - ori);
        }
        else if (t == 2) {
            int k; scanf("%d", &k);
            gao1[k] ^= 1;
        }
        else if (t == 3) {
            int k; scanf("%d", &k);
            gao2[k] ^= 1;
        }
        else if (t == 4) {
            int l, r; scanf("%d%d", &l, &r);
            --l, --r;
            printf("%lld\n", query(0, (1 << n) - 1, l, r, n, 0));
        }
    }
}
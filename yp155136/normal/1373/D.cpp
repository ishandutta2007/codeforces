#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
const ll INF = (1ll << 60);

ll a[N];
ll b[N], c[N];
ll preb[N], prec[N];

ll Qb(int l, int r) {
    return preb[r] - preb[l - 1];
}

ll Qc(int l, int r) {
    return prec[r] - prec[l - 1];
} 

ll dc(ll l, ll r, ll pre) {
    if (l == r) {
        if ((l & 1) == 0) {
            return pre + a[l];
        }
        else {
            return pre;
        }
    }
    int mid = (l + r) >> 1;
    ll ret = 0;
    ll tmp1 = 0, tmp2 = 0;
    for (int i = l; i <= r; ++i) {
        if ((i & 1) == 0) {
            c[i] = a[i];
            b[i] = 0;
            if (i <= mid) {
                tmp1 += a[i];
            }
            else {
                tmp2 += a[i];
            }
        }
        else {
            c[i] = 0;
            b[i] = a[i];
        }
    }
    ret = max(dc(l, mid, pre + tmp2), dc(mid + 1, r, pre + tmp1));
    preb[l - 1] = prec[l - 1] = 0;
    for (int i = l; i <= r; ++i) {
        preb[i] = preb[i - 1] + b[i];
        prec[i] = prec[i - 1] + c[i];
    }
    // c is odd
    // both have odd len
    ll odd_l = -INF, odd_r = -INF, even_l = -INF, even_r = -INF;
    for (int i = mid; i >= l; --i) {
        if (mid & 1) {
            if ((mid - i + 1) & 1) odd_l = max(odd_l, Qb(i, mid) + Qc(l, i - 1));
            else even_l = max(even_l, Qb(i, mid) + Qc(l, i - 1));
        }
        else {
            if ((mid - i + 1) & 1) odd_l = max(odd_l, Qb(i, mid) + Qc(l, i - 1));
            else even_l = max(even_l, Qb(i, mid) + Qc(l, i - 1));
        }
    }
    for (int i = mid + 1; i <= r; ++i) {
        if ((mid + 1) & 1) {
            if ((i - mid) & 1) odd_r = max(odd_r, Qb(mid + 1, i) + Qc(i + 1, r));
            else even_r = max(even_r, Qb(mid + 1, i) + Qc(i + 1, r));
            // cerr << "Qb = " << Qb(mid + 1, i) << " , Qc = " << Qc(i + 1, r) << endl;
            
        }
        else {
            if ((i - mid) & 1) odd_r = max(odd_r, Qb(mid + 1, i) + Qc(i + 1, r));
            else even_r = max(even_r, Qb(mid + 1, i) + Qc(i + 1, r));
        }
    }
    // cerr << "odd_l = " << odd_l << " , odd_r = " << odd_r << " , l = " << l << " , r = " << r << endl;
    // cerr << "even_l = " << even_l << " , even_r = " << even_r << " , l = " << l << " , r = " << r << endl;
    ret = max(ret, max(even_l + even_r, odd_l + odd_r) + pre);
    return ret;
}

void go() {
    int n; scanf("%d", &n);
    for (int i = 2; i <= n + 1; ++i) {
        scanf("%lld", &a[i]);
    }
    printf("%lld\n", dc(2, n + 1, 0));
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}
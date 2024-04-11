#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, q, a[N];

char s[N];

namespace Sgt {
    int mx[N<<2], mn[N<<2], L[N<<2], R[N<<2], ad[N<<2], val[N<<2];

    void up_(int o) {
        int lc = o<<1, rc = o<<1|1;
        mx[o] = max(mx[lc], mx[rc]);
        mn[o] = min(mn[lc], mn[rc]);
        L[o] = max(max(L[lc], L[rc]), mx[lc] - 2*mn[rc]);
        R[o] = max(max(R[lc], R[rc]), mx[rc] - 2*mn[lc]);
        val[o] = max(max(val[lc], val[rc]), max(L[lc] + mx[rc], mx[lc] + R[rc]));
    }

    void add_(int o, int v) {
        ad[o] += v;
        mx[o] += v;
        mn[o] += v;
        L[o] -= v;
        R[o] -= v;
    } 

    void down_(int o) {
        if (ad[o]) {
            add_(o<<1, ad[o]);
            add_(o<<1|1, ad[o]);
            ad[o] = 0;
        } 
    }

    void upd_(int o, int l, int r, int x, int y, int k) {
        if (x <= l && r <= y) {
            add_(o, k);
            return;
        }

        int mid = (l + r)>>1;
        down_(o);

        if (x <= mid) {
            upd_(o<<1, l, mid, x, y, k);
        }

        if (mid < y) {
            upd_(o<<1|1, mid + 1, r, x, y, k);
        }

        up_(o);
    }
 
    void build_(int o, int l, int r) {
        if (l == r) {
            mx[o] = mn[o] = a[l];
            L[o] = R[o] = -a[l];
            val[o] = 0;
            return;
        }

        int mid = (l + r)>>1;
        build_(o<<1, l, mid);
        build_(o<<1|1, mid + 1, r);
        up_(o);
    }
}

int main() {
    scanf("%d%d%s", &n, &q, s + 1);
    n = 2*n - 2;
    
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1];

        if (s[i] == '(') {
            a[i]++;
        } else {
            a[i]--;
        }
    }

    Sgt :: build_(1, 0, n);
    printf("%d\n", Sgt :: val[1]);

    for (int l, r, i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);

        if (l > r) {
            swap(l, r);
        }

        swap(s[l], s[r]);
        Sgt :: upd_(1, 0, n, l, r - 1, s[l] == '(' ? 2 : -2);
        printf("%d\n", Sgt :: val[1]);
    }
}
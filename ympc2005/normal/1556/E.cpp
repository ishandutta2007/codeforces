#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, q, a[N], b[N];

ll s[N];

struct Node {
    ll mn, mx, sum;
} t[N<<2];

Node merge_(Node A, Node B) {
    Node C;
    C.mn = min(A.mn, A.sum + B.mn);
    C.mx = max(A.mx, A.sum + B.mx);
    C.sum = A.sum + B.sum;
    return C;
}

void build_(int o, int l, int r) {
    if (l == r) {
        t[o].mx = t[o].mn = t[o].sum = a[l];
        return;
    }

    int mid = (l + r)>>1;
    build_(o<<1, l, mid), build_(o<<1|1, mid + 1, r);
    t[o] = merge_(t[o<<1], t[o<<1|1]);
}

Node ask_(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y)
        return t[o];
    
    int mid = (l + r)>>1;
    Node res; res = {0, 0, 0};

    if (x <= mid)
        res = merge_(res, ask_(o<<1, l, mid, x, y));
    
    if (mid < y)
        res = merge_(res, ask_(o<<1|1, mid + 1, r, x, y));
    
    return res;
}

int main() {
    scanf("%d%d", &n, &q);

    for (int x, i = 1; i <= n; i++)
        scanf("%d", &x), a[i] -= x;
    
    for (int x, i = 1; i <= n; i++)
        scanf("%d", &x), a[i] += x, s[i] = a[i] + s[i - 1];
    
    build_(1, 1, n);

    for (int l, r, i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);

        if (s[r] - s[l - 1]) {
            puts("-1");
            continue;
        }

        Node ans = ask_(1, 1, n, l, r);

        if (ans.mn < 0)
            puts("-1");
        else
            printf("%lld\n", ans.mx);
    }
}
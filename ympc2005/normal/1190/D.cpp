#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, b[N], tot, c[N], t[N];

struct Node {
    int x, y;

    bool operator < (const Node &tmp) const {
        return x == tmp.x ? y < tmp.y : x < tmp.x;
    }
} a[N];

ll ans;

void upd_(int x, int k) {
    for (; x <= tot; x += x&-x) {
        t[x] += k;
    }
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x) {
        res += t[x];
    }

    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        swap(a[i].x, a[i].y);
        b[i] = a[i].y;
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - b - 1;

    for (int i = 1; i <= n; i++) {
        a[i].y = lower_bound(b + 1, b + tot + 1, a[i].y) - b;
        c[a[i].y]++;
    }

    for (int i = 1; i <= tot; i++) {
        if (c[i]) {
            upd_(i, 1);
        }
    }

    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;

        while (r < n && a[r + 1].x == a[l].x) {
            r++;
        }

        for (int i = l, p = 0; i <= r; i++) {
            ans += 1ll*(ask_(a[i].y) - ask_(p))*(ask_(tot) - ask_(a[i].y) + 1);
            //cout<<ask_(a[i].y) - ask_(p)<<' '<<ask_(tot) - ask_(a[i].y) + 1<<'\n';
            p = a[i].y;
        }       

        for (int i = l; i <= r; i++) {
            if (!--c[a[i].y]) {
                upd_(a[i].y, -1);
            }
        }
    }

    printf("%lld\n", ans);
}
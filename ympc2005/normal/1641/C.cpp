#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 2e5 + 10;

int n, q, mn[N<<2];

set <int> s;

set <int> :: iterator it;

void build_(int o, int l, int r) {
    mn[o] = n + 1;

    if (l == r) {
        return;
    }

    int mid = (l + r)>>1;
    build_(o<<1, l, mid);
    build_(o<<1|1, mid + 1, r);
}

void upd_(int o, int l, int r, int x, int y) {
    if (l == r) {
        mn[o] = min(mn[o], y);
        return;
    }

    int mid = (l + r)>>1;

    if (x <= mid) {
        upd_(o<<1, l, mid, x, y);
    } else {
        upd_(o<<1|1, mid + 1, r, x, y);
    }

    mn[o] = min(mn[o<<1], mn[o<<1|1]);
}

int ask_(int o, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return mn[o];
    }

    int mid = (l + r)>>1, res = n + 1;

    if (x <= mid) {
        res = min(res, ask_(o<<1, l, mid, x, y));
    } 

    if (mid < y) {
        res = min(res, ask_(o<<1|1, mid + 1, r, x, y));
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &q);
    build_(1, 1, n);

    for (int i = 0; i <= n + 1; i++) {
        s.insert(i);
    }

    for (int op, x, y, z, i = 1; i <= q; i++) {
        scanf("%d", &op);

        if (!op) {
            scanf("%d%d%d", &x, &y, &z);

            if (!z) {
                while (1) {
                    it = s.lower_bound(x);

                    if (it == s.end() || *it > y) {
                        break;
                    }

                    s.erase(it);
                }
            } else {
                upd_(1, 1, n, x, y);
            }
        } else {
            scanf("%d", &x);

            if (s.find(x) == s.end()) {
                puts("NO");
            } else {
                int r = *s.upper_bound(x);
                int l = *(--s.lower_bound(x));
                printf("%s\n", ask_(1, 1, n, l + 1, x) < r ? "YES" : "N/A");
            }
        }
    }
}
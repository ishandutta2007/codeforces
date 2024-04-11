#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
const int P = 2 * N;

int lc[P], rc[P];
ll mn[P], tag[P];
int ptr = 0;

void build(int now, int L, int R) {
    if (L == R) {
        return;
    }
    int mid = (L + R) >> 1;
    lc[now] = (++ptr);
    build(lc[now], L, mid);
    rc[now] = (++ptr);
    build(rc[now], mid + 1, R);
    return;
}

void pull(int now) {
    mn[now] = min(mn[ lc[now] ], mn[ rc[now] ]);
}

void push(int now, int L, int R) {
    if (L == R) return;
    if (tag[now] == 0) return;
    tag[ lc[now] ] += tag[now];
    tag[ rc[now] ] += tag[now];
    mn[ lc[now] ] += tag[now];
    mn[ rc[now] ] += tag[now];
    tag[now] = 0;
}

void modify(int now, int L, int R, int l, int r, ll del) {
    if (l > R || L > r) return;
    else if (l <= L && R <= r) {
        tag[now] += del;
        mn[now] += del;
        return;
    }
    push(now, L, R);
    int mid = (L + R) >> 1;
    modify(lc[now], L, mid, l, r, del);
    modify(rc[now], mid + 1, R, l, r, del);
    pull(now);
    return;
}

int a[N], w[N];
int pos[N];

int main () {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; ++i) {
        pos[ a[i] ] = i;
    }
    int root = (++ptr);
    int nn = n - 1;
    build(root, 1, nn);
    ll ans = min(w[1], w[n]);
    //all in the right
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= 1) {
            modify(root, 1, nn, i, nn, w[i]);
        }
        else {
            modify(root, 1, nn, 1, i - 1, w[i]);
        }
    }
    ans = min(ans, mn[root]);
    for (int i = 1; i <= n; ++i) {
        modify(root, 1, nn, 1, pos[i] - 1, w[ pos[i] ]);
        modify(root, 1, nn, pos[i], nn, -w[ pos[i] ]);
        ans = min(ans, mn[root]);
    }
    printf("%lld\n", ans);
}
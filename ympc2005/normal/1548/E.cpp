#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

typedef long long ll;

const int N = 2e5 + 10, inf = 0x3f3f3f3f;

int n, m, x, c[N], d[N], stk[N], top, mx[N];

int t[N], V[N], tot, ida[N], idb[N];

pii a[N], b[N];

ll ans;

bool cmpa_(int u, int v) {
    return a[u] < a[v];
}

bool cmpb_(int u, int v) {
    return d[u] > d[v];
}

void upd_(int x, int k) {
    for (; x <= tot; x += x&-x)
        t[x] += k;
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x)
        res += t[x];
    
    return res;
}

void work_() {
    for (int i = 1; i <= m; i++)
        V[i] = b[i].first, idb[i] = i;
    
    for (int i = 1; i <= n; i++)    
        ida[i] = i;
    
    sort(ida + 1, ida + n + 1, cmpa_);
    sort(idb + 1, idb + m + 1, cmpb_);
    
    sort(V + 1, V + m + 1), tot = unique(V + 1, V + m + 1) - V - 1;

    for (int i = 1; i <= m; i++)
        b[i].first = lower_bound(V + 1, V + tot + 1, b[i].first) - V;

    for (int i = 1, j = 0; i <= n; i++) {
        int u = ida[i], v, l, r;

        while (j < m && d[idb[j + 1]] + a[u].first > x) {
            v = idb[++j];
            upd_(b[v].first, 1);
        }

        l = upper_bound(V + 1, V + tot + 1, x - c[u]) - V;
        r = upper_bound(V + 1, V + tot + 1, x - a[u].first) - V - 1;

        if (l <= r)
            ans += ask_(r) - ask_(l - 1);
    }

    printf("%lld\n", ans);
}

void init_(int n, pii *a, int *b) {
    for (int i = 1; i <= n; i++)    
        scanf("%d", &a[i].first), a[i].second = i, b[i] = inf;
    
    stk[top = 0] = 0, mx[0] = inf;

    for (int i = 1; i <= n; i++) {
        while (top && a[stk[top]] > a[i]) {
            mx[stk[top - 1]] = max(mx[stk[top - 1]], mx[stk[top]]);
            top--;
        }

        b[i] = min(b[i], max(a[i].first, mx[stk[top]]));
        mx[stk[++top] = i] = a[i].first;
    }

    stk[top = 0] = n + 1, mx[n + 1] = inf;

    for (int i = n; i; i--) {
        while (top && a[stk[top]] > a[i]) {
            mx[stk[top - 1]] = max(mx[stk[top - 1]], mx[stk[top]]);
            top--;
        }

        b[i] = min(b[i], max(a[i].first, mx[stk[top]]));
        mx[stk[++top] = i] = a[i].first;
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &x);
    init_(n, a, c);
    init_(m, b, d);
    work_();
}
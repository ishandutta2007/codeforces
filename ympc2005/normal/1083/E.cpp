#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, q[N], ql, qr;

ll f[N], ans;

struct Node {
    int x, y;
    ll v;

    bool operator < (const Node &tmp) const {
        return x < tmp.x;
    }
} a[N];

double calc_(int u, int v) {
    return 1.0*(f[u] - f[v])/(a[u].x - a[v].x);
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>a[i].x>>a[i].y>>a[i].v;
    }

    sort(a + 1, a + n + 1);
    ql = 1, qr = 0;

    for (int i = 1; i <= n; i++) {
        while (ql < qr && calc_(q[ql], q[ql + 1]) >= a[i].y) {
            ql++;
        }

        f[i] = 1ll*a[i].x*a[i].y - a[i].v;

        if (ql <= qr) {
            f[i] = max(f[i], 1ll*a[i].y*(a[i].x - a[q[ql]].x) - a[i].v + f[q[ql]]);
        }

        ans = max(ans, f[i]);

        while (ql < qr && calc_(q[qr - 1], q[qr]) <= calc_(q[qr - 1], i)) {
            qr--;
        }

        q[++qr] = i;
    }

    cout<<ans<<'\n';
}
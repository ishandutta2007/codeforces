#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, a[N], id[N], rt[N];

bool cmp_(int u, int v) {
    return a[u] == a[v] ? u < v : a[u] > a[v];
}

namespace Sgt {
    int tot;
    
    struct Node {
        int lc, rc, sum;
    } t[N<<5];

    void upd_(int &o, int l, int r, int x) {
        t[++tot] = t[o];
        o = tot;
        t[o].sum++;

        if (l == r) {
            return;
        }

        int mid = (l + r)>>1;

        if (x <= mid) {
            upd_(t[o].lc, l, mid, x);
        } else {
            upd_(t[o].rc, mid + 1, r, x);
        }
    }

    int ask_(int o, int l, int r, int k) {
        if (l == r) {
            return l;
        }

        int mid = (l + r)>>1;

        if (t[t[o].lc].sum >= k) {
            return ask_(t[o].lc, l, mid, k);
        }

        return ask_(t[o].rc, mid + 1, r, k - t[t[o].lc].sum);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp_);
    
    for (int i = 1; i <= n; i++) {
        rt[i] = rt[i - 1];
        Sgt :: upd_(rt[i], 1, n, id[i]);
    }

    cin>>m;

    for (int x, p, i = 1; i <= m; i++) {
        cin>>x>>p;
        cout<<a[Sgt :: ask_(rt[x], 1, n, p)]<<'\n';
    }
}
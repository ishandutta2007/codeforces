#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, a[N], f[N], tot, rt[N];

ll ans;

struct Node {
    int lc, rc;
} t[N<<5];

int ask_(int o, int l, int r, int x) {
    if (!o || l == r) {
        return t[o].lc;
    }

    int mid = (l + r)>>1;

    if (x <= mid) {
        return ask_(t[o].lc, l, mid, x);
    } else {
        return ask_(t[o].rc, mid + 1, r, x);
    }
}

void upd_(int &o, int l, int r, int x, int y) {
    t[++tot] = t[o];
    o = tot;

    if (l == r) {
        t[o].lc = y;
        return;
    }

    int mid = (l + r)>>1;

    if (x <= mid) {
        upd_(t[o].lc, l, mid, x, y);
    } else {
        upd_(t[o].rc, mid + 1, r, x, y);
    }
}

void work_() {
    cin>>n;
    ans = tot = 0;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    rt[n + 1] = 0;
    f[n + 1] = 0;

    for (int i = n; i; i--) {
        int p = ask_(rt[i + 1], 1, n, a[i]);

        if (!p) {
            rt[i] = 0;
            f[i] = 0;
            upd_(rt[i], 1, n, a[i], i);
        } else {
            f[i] = f[p + 1] + 1;
            rt[i] = rt[p + 1];
            upd_(rt[i], 1, n, a[i], i);
        }

        ans += f[i];
    }

    cout<<ans<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}
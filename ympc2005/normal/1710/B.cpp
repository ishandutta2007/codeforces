#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 6e5 + 10;

int n, m, a[N], b[N], p[N], cnt;

ll t0[N], t1[N], val[N], pre[N], suf[N];

int find_(int x) {
    return lower_bound(p + 1, p + cnt + 1, x) - p;
}

void upd_(ll *t, int x, ll v) {
    for (; x <= cnt; x += x&-x) {
        t[x] += v;
    }
}

ll ask_(ll *t, int x, ll res = 0) {
    for (; x; x -= x&-x) {
        res += t[x];
    }

    return res;
}

void init_() {
    cin>>n>>m;
    cnt = 0;

    for (int i = 1; i <= n; i++) {
        cin>>a[i]>>b[i];
        p[++cnt] = a[i];
        p[++cnt] = a[i] - b[i];
        p[++cnt] = a[i] + b[i];
    }

    sort(p + 1, p + cnt + 1);
    cnt = unique(p + 1, p + cnt + 1) - p - 1;

    for (int i = 1; i <= cnt; i++) {
        t0[i] = t1[i] = 0;
    }
}

void work_() {
    for (int i = 1; i <= n; i++) {
        int l = find_(a[i] - b[i]);
        int x = find_(a[i]);
        int r = find_(a[i] + b[i]);
        upd_(t0, l, b[i] - a[i]);
        upd_(t0, x, -b[i] + a[i]);
        upd_(t1, l, 1);
        upd_(t1, x, -1);

        upd_(t0, x, b[i] + a[i]);
        upd_(t0, r + 1, -b[i] - a[i]);
        upd_(t1, x, -1);
        upd_(t1, r + 1, 1);
    }

    for (int i = 1; i <= cnt; i++) {
        val[i] = ask_(t0, i) + ask_(t1, i)*p[i] - m;
        //cout<<p[i]<<' '<<val[i] + m<<'\n';

        if (val[i] <= 0) {
            val[i] = -2e18;
        }
    }

    pre[0] = suf[cnt + 1] = -2e18;

    for (int i = 1; i <= cnt; i++) {
        pre[i] = max(pre[i - 1], val[i] - p[i]);
    }

    for (int i = cnt; i; i--) {
        suf[i] = max(suf[i + 1], val[i] + p[i]);
    }

    for (int i = 1; i <= n; i++) {
        int pos = find_(a[i]);

        if (pre[pos] + a[i] <= b[i] && suf[pos] - a[i] <= b[i]) {
            cout<<1;
        } else {
            cout<<0;
        }
    }

    cout<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        init_();
        work_();
    }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10, M = 1<<12;

int n, q, mod, a[N], cnt, p[10], f[10][M], g[10][M], cur[10];

void exgcd_(int a, int b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }

    exgcd_(b, a%b, y, x);
    y -= x*(a/b);
}

int inv_(int v) {
    ll x, y;
    exgcd_(v, mod, x, y);
    return (x%mod + mod)%mod;
}

void init_(int x) {
    for (int i = 2; 1ll*i*i <= x; i++) {
        if (x%i == 0) {
            p[cnt++] = i;

            while (x%i == 0) {
                x /= i;
            }
        }
    }

    if (x > 1) {
        p[cnt++] = x;
    }

    for (int i = 0; i < cnt; i++) {
        f[i][0] = g[i][0] = 1;

        for (int j = 1; j < M; j++) {
            g[i][j] = 1ll*g[i][j - 1]*p[i]%mod;
        }

        int v = 1ll*g[i][M - 1]*p[i]%mod;

        for (int j = 1; j < M; j++) {
            f[i][j] = 1ll*f[i][j - 1]*v%mod;
        }
    }
}

int pow_(int x, int y) {
    return 1ll*g[x][y%M]*f[x][y/M]%mod;
}

namespace Sgt {
    int s[N<<2], tag1[N<<2][10], tag2[N<<2];

    void up_(int o) {
        s[o] = (s[o<<1] + s[o<<1|1])%mod;
    }

    void build_(int o, int l, int r) {
        if (l == r) {
            s[o] = tag2[o] = a[l];

            for (int i = 0; i < cnt; i++) {
                while (tag2[o]%p[i] == 0) {
                    tag2[o] /= p[i];
                    tag1[o][i]++;
                }
            }

            return;
        }

        int mid = (l + r)>>1;
        tag2[o] = 1;
        build_(o<<1, l, mid);
        build_(o<<1|1, mid + 1, r);
        up_(o);
    }

    void mul_(int o, int *x, int y) {
        for (int i = 0; i < cnt; i++) {
            tag1[o][i] += x[i];
            s[o] = 1ll*s[o]*pow_(i, x[i])%mod;
        }

        s[o] = 1ll*s[o]*y%mod;
        tag2[o] = 1ll*tag2[o]*y%mod;
    }

        void down_(int o) {
        mul_(o<<1, tag1[o], tag2[o]);
        mul_(o<<1|1, tag1[o], tag2[o]);

        for (int i = 0; i < cnt; i++) {
            tag1[o][i] = 0;
        }

        tag2[o] = 1;
    }

    void upd_(int o, int l, int r, int x, int y, int v) {
        if (x <= l && r <= y) {
            mul_(o, cur, v);
            return;
        }

        int mid = (l + r)>>1;
        down_(o);

        if (x <= mid) {
            upd_(o<<1, l, mid, x, y, v);
        }

        if (mid < y) {
            upd_(o<<1|1, mid + 1, r, x, y, v);
        }

        up_(o);
    }

    void div_(int o, int l, int r, int x, int y) {
        if (l == r) {
            s[o] = tag2[o] = 1ll*tag2[o]*y%mod;

            for (int i = 0; i < cnt; i++) {
                tag1[o][i] -= cur[i];
                s[o] = 1ll*s[o]*pow_(i, tag1[o][i])%mod;
            }

            return;
        }

        int mid = (l + r)>>1;
        down_(o);

        if (x <= mid) {
            div_(o<<1, l, mid, x, y);
        } else {
            div_(o<<1|1, mid + 1, r, x, y);
        }

        up_(o);
    }

    int ask_(int o, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            return s[o];
        }

        int mid = (l + r)>>1, res = 0;
        down_(o);

        if (x <= mid) {
            res = (res + ask_(o<<1, l, mid, x, y))%mod;
        }

        if (mid < y) {
            res = (res + ask_(o<<1|1, mid + 1, r, x, y))%mod;
        }

        return res;
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>mod;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    init_(mod);
    Sgt :: build_(1, 1, n);
    cin>>q;

    for (int op, l, r, x, y, k, i = 1; i <= q; i++) {
        cin>>op;

        if (op == 1) {
            cin>>l>>r>>x;
            y = x;
            
            for (int j = 0; j < cnt; j++) {
                cur[j] = 0;

                while (y%p[j] == 0) {
                    cur[j]++;
                    y /= p[j];
                }
            }

            Sgt :: upd_(1, 1, n, l, r, y);
        }

        if (op == 2) {
            cin>>k>>x;
            y = x;

            for (int j = 0; j < cnt; j++) {
                cur[j] = 0;

                while (y%p[j] == 0) {
                    cur[j]++;
                    y /= p[j];
                }
            }

            y = inv_(y);
            Sgt :: div_(1, 1, n, k, y);
        }

        if (op == 3) {
            cin>>l>>r;
            cout<<(Sgt :: ask_(1, 1, n, l, r)%mod + mod)%mod<<'\n';
        }
    }
}
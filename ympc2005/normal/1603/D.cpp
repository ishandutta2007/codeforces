#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n = 1e5, m = 18, p[N], tot, phi[N];

ll s[N], f[N][20];

bool vis[N];

ll calc_(int l, int r) {
    ll res = 0;

    for (int i = l, j; i <= r; i = j + 1) {
        j = r/(r/i);
        res += (j - i + 1)*s[r/i];
    }

    return res;
}

void solve_(int l, int r, int x, int y, int k) {
    if (l > r) {
        return;
    }

    int mid = (l + r)>>1, p = x;
    ll res = calc_(x, mid);
    f[mid][k] = f[p - 1][k - 1] + res;

    for (int i = x + 1; i <= y && i <= mid; i++) {
        res -= s[mid/(i - 1)];

        if (res + f[i - 1][k - 1] < f[mid][k]) {
            f[mid][k] = res + f[i - 1][k - 1];
            p = i;
        }
    }

    solve_(l, mid - 1, x, p, k);
    solve_(mid + 1, r, p, y, k);
}

void init_() {
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p[++tot] = i;
            phi[i] = i - 1;
        }

        for (int j = 1; j <= tot && p[j]*i <= n; j++) {
            vis[p[j]*i] = 1;
            
            if (i%p[j] == 0) {
                phi[p[j]*i] = phi[i]*p[j];
                break;
            }

            phi[p[j]*i] = phi[i]*(p[j] - 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + phi[i];
    }

    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        solve_(1, n, 1, n, i);
    }
}

void work_() {
    int T; scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);
        
        if (m > 18) {
            printf("%d\n", n);
        } else {
            printf("%lld\n", f[n][m]);
        }
    }
}

int main() {
    init_();
    work_();

    return 0;
}
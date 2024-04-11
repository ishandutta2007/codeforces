#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, x[N], y[N], f[N<<1][20];

double z[N], d[N], l, r = 1e9, Pi = acos(-1);

struct Seg {
    double l, r;

    bool operator < (const Seg &tmp) const {
        return l < tmp.l;
    }
} a[N<<1];

int solve_(double R) {
    for (int i = 1; i <= n; i++) {
        double k = acos(R/d[i]);
        a[i].l = z[i] - k, a[i].r = z[i] + k;

        if (a[i].l < 0) {
            a[i].l += 2*Pi;
            a[i].r += 2*Pi;
        }

        a[i + n].l = a[i].l + 2*Pi, a[i + n].r = a[i].r + 2*Pi;
    }

    sort(a + 1, a + 2*n + 1);
    f[2*n][0] = 2*n + 1, f[2*n + 1][0] = 2*n + 1;
    double mn = 1e9;

    for (int i = 2*n - 1, j = 2*n; i; i--) {
        mn = min(mn, a[i].r);

        while (a[j].l > mn) {
            j--;
        }

        f[i][0] = j + 1;
    }

    for (int k = 1; k < 20; k++) {
        for (int i = 1; i <= 2*n + 1; i++) {
            f[i][k] = f[f[i][k - 1]][k - 1];
        }
    }

    int ans = 1e9;

    for (int i = 1; i <= n; i++) {
        int res = 1, x = i;

        for (int j = 19; j >= 0; j--) {
            if (f[x][j] < i + n) {
                res += 1<<j;
                x = f[x][j];
            }
        }

        ans = min(ans, res);
    }

    return ans;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        d[i] = sqrt(1ll*x[i]*x[i] + 1ll*y[i]*y[i]);
        r = min(r, d[i]), z[i] = atan2(y[i], x[i]);
    }

    while (r - l > 1e-7) {
        double mid = (l + r)/2;

        if (solve_(mid) > m) {
            r = mid;
        } else {
            l = mid;
        }
    }

    printf("%.7f\n", l);
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N], tot, x[N<<5], y[N<<5], cnt;

void solve_(int n, int k) {
    if (n <= 2) {
        for (int i = 1; i <= n; i++) {
            a[++tot] = i<<k;
        }

        return;
    }

    int lim = 1;

    while (lim*2 <= n) {
        lim <<= 1;
    }

    if (lim == n) {
        a[++tot] = n<<k;
        solve_(n - 1, k);
        return;
    }

    for (int i = 0; i <= (n - lim); i++) {
        a[++tot] = lim<<k + (i > 0);
    }

    for (int i = 1; i <= n - lim; i++) {
        ++cnt, x[cnt] = (lim - i)<<k, y[cnt] = (lim + i)<<k;
    }

    solve_(lim - (n - lim) - 1, k);
    solve_(n - lim, k + 1);

}

void work_() {
    scanf("%d", &n);

    if (n == 2) {
        puts("-1");
        return;
    }

    solve_(n, 0);
    sort(a + 1, a + n + 1);

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) {
            ++cnt, x[cnt] = a[i], y[cnt] = a[i + 1];
            a[i + 1] <<= 1;
            a[i] = 0;
            break;
        }
    }

    int lim = 1;

    while (lim < n) {
        lim <<= 1;
    }

    for (int i = 1; i <= n; i++) {
        while (a[i] && a[i] < lim) {
            ++cnt, x[cnt] = a[i], y[cnt] = 0;
            ++cnt, x[cnt] = a[i], y[cnt] = a[i];
            a[i] <<= 1;
        }
    }

    ++cnt, x[cnt] = lim, y[cnt] = 0;
    printf("%d\n", cnt);

    for (int i = 1; i <= cnt; i++) {
        printf("%d %d\n", x[i], y[i]);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        cnt = tot = 0;
        work_();
    }
}
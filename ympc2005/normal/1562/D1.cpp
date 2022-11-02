#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int T, n, q, a[N], b[N], c[N], tot, f[N], g[N];

char s[N];

void work_() {
    scanf("%d%d%s", &n, &q, s + 1);

    for (int i = 1; i <= n; i++) {
        a[i] = s[i] == '+' ? 1 : -1;
        b[i] = a[i]*(i&1 ? 1 : -1) + b[i - 1];
        c[i] = c[i - 1] + a[i];
    }

    tot = 0;

    for (int l = 1, r; l <= n; l = r + 1) {
        for (r = l; r < n && a[l] == a[r + 1]; )
            r++;
        
        if ((r - l + 1)&1)
            ++tot, f[tot] = l, g[tot] = r;
    }

    for (int l, r, i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);

        if (b[r] - b[l - 1] == 0) {
            puts("0");
            continue;
        }

        if (abs(c[r] - c[l - 1]) == r - l + 1) {
            printf("%d\n", (r - l + 1)&1);
            continue;
        }

        int L = l, R = r;

        while (L < R) {
            int mid = (L + R + 1)>>1;

            if (abs(c[mid] - c[l - 1]) == mid - l + 1)
                L = mid;
            else
                R = mid - 1;
        }

        int cnt = (L - l + 1)&1, lp = L, rp;

        L++, R = r;

        while (L < R) {
            int mid = (L + R)>>1;

            if (abs(c[r] - c[mid - 1]) == r - mid + 1)
                R = mid;
            else
                L = mid + 1;
        } 

        cnt += (r - L + 1)&1, rp = L;

        lp = upper_bound(f + 1, f + tot + 1, lp) - f;
        rp = lower_bound(g + 1, g + tot + 1, rp) - g - 1;

        cnt += rp - lp + 1;

        if (cnt&1) printf("%d\n", 1);
        else printf("%d\n", 2);
    }
}

int main() {
    scanf("%d", &T);

    while (T--)
        work_();
}
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

char s[N];

int n, x[N], y[N], cx, cy;

void check_(int k) {
    int L, R, mx[2], mn[2];
    L = mn[0] = mn[1] = -1e9;
    R = mx[0] = mx[1] = 1e9;

    for (int i = 1; i <= n; i++) {
        L = max(L, y[i] - x[i] - k);
        R = min(R, y[i] - x[i] + k);
        mn[0] = max(mn[0], x[i] - k);
        mn[1] = max(mn[1], y[i] - k);
        mx[0] = min(mx[0], x[i] + k);
        mx[1] = min(mx[1], y[i] + k);
    }

    cx = cy = -1;

    mn[0] = max(0, mn[0]);
    mn[1] = max(0, mn[1]);

    if (L > R || mn[0] > mx[0] || mn[1] > mx[1]) {
        return;
    }

    for (int i = mn[0]; i <= mx[0]; i++) {
        int l = max(i + L, mn[1]), r = min(i + R, mx[1]);

        if (l <= r) {
            cx = i;
            cy = l;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);

        for (int j = 1; s[j]; j++) {
            if (s[j] == 'B') {
                x[i]++;
            } else {
                y[i]++;
            }
        }
    }

    int l = 0, r = 1e6;

    while (l < r) {
        int mid = (l + r)>>1;
        check_(mid);

        if (~cx) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    check_(l);

    printf("%d\n", l);

    for (int i = 1; i <= cx; i++) {
        putchar('B');
    }

    for (int i = 1; i <= cy; i++) {
        putchar('N');
    }
}
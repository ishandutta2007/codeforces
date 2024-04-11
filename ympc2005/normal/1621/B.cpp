#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, T;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        int l = 1e9, cl = 1e9, r = -1e9, cr = 1e9, len = 0, clen = 1e9;

        for (int i = 1, a, b, c; i <= n; i++) {
            scanf("%d%d%d", &a, &b, &c);

            if (a < l) {
                cl = c;
                l = a;
            } else if (a == l) {
                cl = min(cl, c);
            }

            if (r < b) {
                cr = c;
                r = b;
            } else if (r == b) {
                cr = min(cr, c);
            }

            if (b - a + 1 > len) {
                len = b - a + 1;
                clen = c;
            } else if (b - a + 1 == len) {
                clen = min(clen, c);
            }

            printf("%d\n", r - l + 1 == len ? min(cl + cr, clen) : cl + cr);
        }
    }
}
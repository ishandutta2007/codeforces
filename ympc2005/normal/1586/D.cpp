#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N], b[N], c[N], n;

int ask_(int x, int y) {
    printf("? ");

    for (int i = 1; i <= n; i++) {
        if (i == x) {
            printf("%d ", y);
        } else {
            printf("%d ", 3^y);
        }
    }

    fflush(stdout);

    scanf("%d", &y);
    return y;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        a[i] = ask_(i, 1); // smaller id
        b[i] = ask_(i, 2); // bigger id

        if (!a[i]) {
            c[i] = 1;
        } else if (a[i] != i) {
            b[a[i]] = i;
        }

        if (!b[i]) {
            c[i] = n;
        } else if (b[i] != i) {
            a[b[i]] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) {
            printf("! ");

            for (int j = 1; j <= n; j++) {
                c[b[i]] = c[i] + 1;
                i = b[i];
            }

            for (int j = 1; j <= n; j++) {
                printf("%d ", c[j]);
            }

            return 0;
        }
    }
}
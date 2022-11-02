#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int T, n, p[N], q[N], a[N], len;

int ask_(int x, int res = 0) {
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &res);
    return res;
}

void solve_() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        q[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (q[i]) {
            continue;
        }

        a[len = 0] = ask_(i);

        do {
            a[++len] = ask_(i);
        } while (a[len] != a[0]);

        for (int j = 1; j <= len; j++) {
            q[a[j]] = a[j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        p[q[i]] = i;
    }

    printf("! ");

    for (int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }

    puts("");
    fflush(stdout);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        solve_();
    }
}
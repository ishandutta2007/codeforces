#include <bits/stdc++.h>
using namespace std;

const int N = 65;

int T, n, x, a[N];

int gcd_(int a, int b) {
    return b ? gcd_(b, a%b) : a;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));

        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);

            for (int j = 0; j < 30; j++) {
                if (x&(1<<j)) {
                    a[j]++;
                }
            }
        }

        int d = 0;

        for (int i = 0; i < 30; i++) {
            d = gcd_(d, a[i]);
        }

        for (int i = 1; i <= n; i++) {
            if (d%i == 0) {
                printf("%d ", i);
            }
        }

        puts("");
    }
}
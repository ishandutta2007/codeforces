#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, T, a[N], s;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), s = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s ^= a[i];
        }

        if (!s) {
            puts("DRAW");
            continue;
        }

        for (int i = 30; i >= 0; i--) {
            if (s&(1<<i)) {
                int c0 = 0, c1 = 0;

                for (int j = 1; j <= n; j++) {
                    if (a[j]&(1<<i)) {
                        c1++;
                    } else {
                        c0++;
                    }
                }            

                c0 &= 1;

                if (!c0) {
                    printf("%s\n", c1%4 == 1 ? "WIN" : "LOSE");
                } else {
                    puts("WIN");
                }

                break;
            }
        }
    }
}
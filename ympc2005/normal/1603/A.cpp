#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int T, n, a[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        bool ok = 1;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);

            bool k = 0;

            for (int j = i; j; j--) {
                if (a[i]%(j + 1)) {
                    k = 1;
                    break;
                }
            }

            if (!k) {
                ok = 0;
            }
        }

        printf("%s\n", ok ? "YES" : "NO");
    }
}
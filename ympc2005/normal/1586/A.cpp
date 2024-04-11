#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int T, n, a[N], sum;

bool chk_(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        sum = 0;
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        bool ok = chk_(sum);

        printf("%d\n", ok ? n : n - 1);

        for (int i = 1; i <= n; i++) {
            if (a[i]&1) {
                if (!ok) {
                    ok = 1;
                } else {
                    printf("%d ", i);
                }
            } else {
                printf("%d ", i);
            }
        }

        puts("");
    }
}
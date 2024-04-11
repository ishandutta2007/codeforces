#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int T, n;

ll L, R;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%lld", &n, &R);
        L = (R + 1)>>1;
        vector <int> ans;
        int pos = 0;
        ll sum = 0;

        for (int i = 1; i <= n; i++) {
            ll x;
            scanf("%lld", &x);

            if (x >= L && x <= R) {
                pos = i;
            }

            if (sum + x <= R) {
                sum += x;
                ans.push_back(i);
            }
        }

        if (pos) {
            printf("1\n%d\n", pos);
        } else if (sum >= L) {
            printf("%u\n", ans.size());

            for (int x : ans) {
                printf("%d ", x);
            }

            putchar('\n');
        } else {
            puts("-1");
        }
    }
}
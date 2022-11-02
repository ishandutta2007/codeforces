#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n, a[N], T;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        int ans = 1;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int cnt = 2;

                for (int k = j + 1; k <= n; k++) {
                    if (1ll*(a[k] - a[j])*(j - i) == 1ll*(a[j] - a[i])*(k - j)) {
                        cnt++;
                    }
                }

                ans = max(ans, cnt);
            }
        }

        printf("%d\n", n - ans);
    }
}
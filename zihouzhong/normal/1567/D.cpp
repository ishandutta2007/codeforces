#include <bits/stdc++.h>
using namespace std;

int T, s, n;
long long a[11], x[110];

int main() {
    scanf("%d", &T);
    for (int i = a[0] = 1; i <= 10; i++) {
        a[i] = 11 * a[i - 1];
    }
    while (T--) {
        scanf("%d %d", &s, &n);
        memset(x, 0, sizeof(x));
        long long ans = 0;
        int rem = n;
        for (int pw = 1000000000, cur = 9; pw; pw /= 10, cur--) {
            int num = s / pw;
            for (int i = min(n * 9, num); ~i; i--) {
                if (s - i * pw >= max(0, rem - i)) {
                    int tmp = i;
                    for (int j = rem; j > max(0, rem - i); j--) {
                        x[j] += pw, tmp--;
                    }
                    for (int j = n; j > max(0, rem - i); j--) {
                        x[j] += min(8 + (j > rem), tmp) * pw;
                        tmp -= min(8 + (j > rem), tmp);
                    }
                    rem = max(0, rem - i);
                    ans += i * a[cur], s -= i * pw; break;
                }
            }
        }
        for (int i = 1; i <= n; i++) printf("%lld ", x[i]);
        putchar('\n');
    }
    return 0;
}
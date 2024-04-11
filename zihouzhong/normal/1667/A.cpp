#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        long long s1 = 0, s2 = 0;
        long long cur = 0;
        for (int j = i - 1; j; j--) {
            long long k = cur / a[j] + 1;
            s1 += k, cur = k * a[j];
        }
        cur = 0;
        for (int j = i + 1; j <= n; j++) {
            long long k = cur / a[j] + 1;
            s2 += k, cur = k * a[j];
        }
        ans = min(ans, s1 + s2);
    }
    printf("%lld\n", ans);
    return 0;
}
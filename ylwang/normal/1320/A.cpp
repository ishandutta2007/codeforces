#include <cstdio>
#include <algorithm>

int n;
int a[200005];
long long ans;
long long f[600005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) ans = std::max(ans, f[a[i] - i + n] += a[i]);
    printf("%lld\n", ans);
    return 0;
}
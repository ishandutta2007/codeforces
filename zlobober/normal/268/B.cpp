#include <cstdio>
using namespace std;

typedef long long llong;

int main()
{
    int n;
    scanf("%d", &n);
    llong ans = 0;
    for (llong i = 1; i <= n; i++)
        ans += i + (n - i) * (i - 1);
    #ifdef LOCAL
        printf("%lld\n", ans);
    #else
        printf("%I64d\n", ans);
    #endif
}
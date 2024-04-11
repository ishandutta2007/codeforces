#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int one = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        if (!t)
            ans += one;
        one += t;
    }
#ifdef LOCAL42
    printf("%lld\n", ans);
#else
    printf("%I64d\n", ans);
#endif
    return 0;
}
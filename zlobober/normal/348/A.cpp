#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llong;

#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

int main()
{
    int n;
    scanf("%d", &n);
    llong mx = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        llong t;
        scanf(LLD, &t);
        sum += t;
        mx = max(mx, t);
    }
    mx = max(mx, (sum + n - 2) / (n - 1));
    printf(LLD "\n", mx);
    return 0;
}
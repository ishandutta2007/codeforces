#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int q, k;
        scanf("%d %d", &q, &k);
        int r;
        for (r = 1; (1LL << (2 * r)) < k; r++);
        ans = max(ans, r + q);
    }
    printf("%d\n", ans);
    return 0;
}
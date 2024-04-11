# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 3e5 + 44;
int x[MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", x + i);
    sort(x + 1, x + n + 1);
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        res += abs(i - x[i]);
    printf("%I64d\n", res);
}
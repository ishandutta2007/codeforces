# include <cstdio>
# include <set>
using namespace std;
int main()
{
    int h, t, n;
    scanf("%d%d%d", &h, &t, &n);
    int res = 0;
    for (int i = 0; i <= min(min(2, h), min(t, n)); ++i)
        res = max(res, i + (t - i) / 3 + (h - i) / 3 + (n - i) / 3);
    printf("%d\n", res);
}
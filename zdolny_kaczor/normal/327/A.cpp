# include <cstdio>
const int MN = 111;
int a[MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    int res = 0;
    int cou = 0;
    for (int i = 0; i < n; ++i)
        cou += a[i];
    for (int i = 0; i < n; ++i)
        for (int k = i + 1; k <= n; ++k)
        {
            int curr = cou;
            for (int l = i; l < k; ++l)
                curr += 1 - 2 * a[l];
            if (res < curr)
                res = curr;
        }
    printf("%d\n", res);
}
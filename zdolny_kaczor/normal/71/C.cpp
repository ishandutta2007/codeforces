# include <cstdio>
const int MN = 1e5 + 44;
int a[MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int d = 1; d <= n / 3; ++d)
        if (n % d == 0)
        {
            for (int i = 0; i < d; ++i)
            {
                bool all = true;
                for (int k = i; k < n; k += d)
                    if (a[k] == 0)
                        all = false;
                if (all)
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    printf("NO\n");
}
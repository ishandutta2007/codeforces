# include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (n / 2) * ((n + 1) / 2));
    for (int i = 1; i <= n / 2; ++i)
        for (int k = n / 2 + 1; k <= n; ++k)
            printf("%d %d\n", i, k);
}
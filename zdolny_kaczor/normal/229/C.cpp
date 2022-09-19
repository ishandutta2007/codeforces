# include <cstdio>
const int MN = 1e6 + 44;
int deg[MN];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        deg[a]++;
        deg[b]++;
    }
    long long bad = 0;
    for (int i = 1; i <= n; ++i)
        bad += deg[i] * (n - 1 - deg[i]);
    printf("%I64d\n", n * (n - 1LL) * (n - 2LL) / 6 - bad / 2);
}
# include <cstdio>
const int MN = 1e6 + 44;
int ans[MN];
int main()
{
    int n;
    scanf("%d", &n);
    int last = 1;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        for (int k = 0; k < x; ++k)
            ans[last++] = i;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
}
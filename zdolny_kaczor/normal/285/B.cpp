# include <cstdio>
int p[100010];
int main()
{
    int n, s, t;
    scanf("%d%d%d", &n, &s, &t);
    for (int i=1; i<=n; ++i)
        scanf("%d", p+i);
    for (int nr=0; nr<n; ++nr)
    {
        if (s==t)
        {
            printf("%d\n", nr);
            return 0;
        }
        s=p[s];
    }
    printf("-1\n");
}
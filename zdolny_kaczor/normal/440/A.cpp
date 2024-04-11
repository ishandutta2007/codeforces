# include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    int res=0;
    for (int i=1; i<=n; ++i)
        res^=i;
    for (int i=1; i<n; ++i)
    {
        int x;
        scanf("%d", &x);
        res^=x;
    }
    printf("%d\n", res);
}
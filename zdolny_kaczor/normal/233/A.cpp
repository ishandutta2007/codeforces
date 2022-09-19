# include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2)
        printf("-1\n");
    else
    {
        for (int i = 0; i < n; ++i)
            printf("%d ", (i ^ 1) + 1);
    }
}
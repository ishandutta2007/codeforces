# include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; n > 0; ++i)
        n -= i;
    if (n)
        printf("NO\n");
    else
        printf("YES\n");
}
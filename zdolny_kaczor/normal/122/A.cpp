# include <cstdio>
bool lucky(int a)
{
    if (a==0)
        return 1;
    if (a%10!=4 && a%10!=7)
        return 0;
    return lucky(a/10);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        if (lucky(i) && n%i==0)
        {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
}
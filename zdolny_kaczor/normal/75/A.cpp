# include <cstdio>
int denullify(int x)
{
    int pow=1;
    int res=0;
    while (x)
    {
        if (x%10)
        {
            res+=pow*(x%10);
            pow*=10;
        }
        x/=10;
    }
    return res;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (denullify(a)+denullify(b)==denullify(a+b))
        printf("YES\n");
    else
        printf("NO\n");
}
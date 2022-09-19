# include <cstdio>
int exteuc(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = y = 1;
        return a;
    }
    else
    {
        int x2, y2;
        int ret = exteuc(b, a % b, x2, y2);
        x = y2;
        y = x2 - (a / b) * y2;
        return ret;
    }
}
long long inv(int a, int p)
{
    int x, y;
    exteuc(a, p, x, y);
    x %= p;
    if (x < 0)
        x += p;
    return x;
}
int main()
{
    int p;
    scanf("%d", &p);
    if (p == 1)
    {
        printf("YES\n1\n");
        return 0;
    }
    else if (p == 4)
    {
        printf("YES\n1\n3\n2\n4\n");
        return 0;
    }
    for (int i = 2; i * i <= p; ++i)
        if (p % i == 0)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    printf("1\n");
    for (int i = 2; i < p; ++i)
        printf("%d\n", i * inv(i - 1, p) % p);
    printf("%d\n", p);
}
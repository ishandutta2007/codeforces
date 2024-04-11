# include <cstdio>
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
int a[4];
int main()
{
    for (int i = 0; i < 4; ++i)
        scanf("%d", a + i);
    int d;
    scanf("%d", &d);
    int res = 0;
    for (int i = 1; i < (1 << 4); ++i)
    {
        int div = 1;
        int sign = -1;
        for (int k = 0; k < 4; ++k)
            if ((1 << k) & i)
            {
                div = lcm(div, a[k]);
                sign = -sign;
            }
        res += sign * (d / div);
    }
    printf("%d\n", res);
}
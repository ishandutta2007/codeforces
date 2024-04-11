# include <cstdio>
int main()
{
    int x1, y1, x2, y2, res = 0, n;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
    while (n--)
    {
        long long a, b, c;
        scanf("%I64d%I64d%I64d", &a, &b, &c);
        long long q = a * x1 + b * y1 + c, r = a * x2 + b * y2 + c;
        if (q > 0 xor r > 0)
            res++;
    }
    printf("%d\n", res);
}
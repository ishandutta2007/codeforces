# include <cstdio>
int main()
{
    long long s, x;
    scanf("%I64d%I64d", &s, &x);
    if (x > s || (x - s) % 2 || (((s - x) / 2) & x))
        printf("0\n");
    else
    {
        long long res = 1;
        long long dr = (x == s) ? -2 : 0;
        while (x)
        {
            if (x % 2)
                res *= 2;
            x /= 2;
        }
        printf("%I64d\n", res + dr);
    }
}
# include <cstdio>
int mod[9];
int main()
{
    int n;
    scanf("%d", &n);
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        res -= n / i;
    for (int i = 1; i <= n; ++i)
        mod[i % 9] ++;
    for (int i = 0; i < 9; ++i)
        for (int k = 0; k < 9; ++k)
            res += mod[i] * (long long) mod[k] * mod[(i * k) % 9];
    printf("%I64d\n", res);
}
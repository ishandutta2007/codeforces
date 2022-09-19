# include <cstdio>
long long bin(int a)
{
    return a * (a - 1ll) / 2;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%I64d %I64d\n", bin(n / m + 1) * (n % m) + bin(n / m) * (m - n % m), bin(n - m + 1));
}
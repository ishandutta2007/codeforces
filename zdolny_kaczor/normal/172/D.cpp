# include <cstdio>
const int MN = 1e7 + 44;
int cou[MN];
int main()
{
    for (int i = 1; i * i < MN; ++i)
        for (int k = i * i; k < MN; k += i * i)
            cou[k] = k / i / i;
    int n, a;
    scanf("%d%d", &a, &n);
    long long res = 0;
    for (int i = 0; i < n; ++i)
        res += cou[a + i];
    printf("%I64d\n", res);
}
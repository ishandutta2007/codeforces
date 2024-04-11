# include <cstdio>
const int MN = 222;
int a[MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 2 - 1; ++i)
        scanf("%d", a + i);
    int sum = 0, mmin = 1111, neg = 0;
    for (int i = 0; i < n * 2 - 1; ++i)
    {
        if (a[i] < 0)
        {
            neg++;
            a[i] = -a[i];
        }
        if (mmin > a[i])
            mmin = a[i];
        sum += a[i];
    }
    if (n % 2 == 1 || neg % 2 == 0)
        printf("%d\n", sum);
    else
        printf("%d\n", sum - 2 * mmin);
}
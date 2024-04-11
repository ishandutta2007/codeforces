# include <cstdio>
const int MN = 1e5 + 44;
int tab [MN];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", tab + i);
    int t1 = 0, t2 = 0;
    int a = 0, b = 0;
    while (a + b < n)
    {
        if (t1 <= t2)
        {
            t1 += tab[a];
            a++;
        }
        else
        {
            t2 += tab[n - b - 1];
            b++;
        }
    }
    printf("%d %d\n", a, b);
}
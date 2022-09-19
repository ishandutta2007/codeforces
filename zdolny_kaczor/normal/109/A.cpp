# include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 7; ++i)
        if (i * 4 <= n && (n - 4 * i) % 7 == 0)
        {
            for (int k = 0; k < i; ++k)
                putchar('4');
            for (int k = 0; k < (n - 4 * i) / 7; ++k)
                putchar('7');
            return 0;
        }
    printf("-1\n");
}
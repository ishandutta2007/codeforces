# include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2)
        printf("-1\n");
    else
        for (int i = 0; i < n; ++i)
        {
            for (int k = 0; k < n; ++k)
            {
                for (int l = 0; l < n; ++l)
                    printf("%c", ((i / 2 + k / 2 + l) % 2) ? 'w' : 'b');
                printf("\n");
            }
            printf("\n");
        }
}